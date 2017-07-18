/*
 *      Copyright (C) 2016-2017 Garrett Brown
 *      Copyright (C) 2016-2017 Team Kodi
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "DeviceConfiguration.h"
#include "Device.h"

#include <algorithm>

using namespace JOYSTICK;

void CDeviceConfiguration::Reset(void)
{
  m_axes.clear();
  m_buttons.clear();
}

bool CDeviceConfiguration::IsEmpty() const
{
  return m_axes.empty() &&
         m_buttons.empty();
}

const AxisConfiguration& CDeviceConfiguration::Axis(unsigned int index) const
{
  static AxisConfiguration defaultConfig{ };

  auto it = m_axes.find(index);
  if (it != m_axes.end())
    return it->second;

  return defaultConfig;
}

const ButtonConfiguration& CDeviceConfiguration::Button(unsigned int index) const
{
  static ButtonConfiguration defaultConfig{ };

  auto it = m_buttons.find(index);
  if (it != m_buttons.end())
    return it->second;

  return defaultConfig;
}

PrimitiveVector CDeviceConfiguration::GetIgnoredPrimitives() const
{
  PrimitiveVector primitives;

  for (const auto& axisConfig : m_axes)
  {
    if (axisConfig.second.bIgnore)
    {
      primitives.emplace_back(axisConfig.first, 0, JOYSTICK_DRIVER_SEMIAXIS_POSITIVE, 1);
      primitives.emplace_back(axisConfig.first, 0, JOYSTICK_DRIVER_SEMIAXIS_NEGATIVE, 1);
    }
  }

  for (const auto& buttonConfig : m_buttons)
  {
    if (buttonConfig.second.bIgnore)
      primitives.emplace_back(kodi::addon::DriverPrimitive::CreateButton(buttonConfig.first));
  }

  return primitives;
}

void CDeviceConfiguration::GetAxisConfigs(FeatureVector& features) const
{
  for (auto& feature : features)
  {
    for (auto& primitive : feature.Primitives())
      GetAxisConfig(primitive);
  }
}

void CDeviceConfiguration::GetAxisConfig(kodi::addon::DriverPrimitive& primitive) const
{
  if (primitive.Type() == JOYSTICK_DRIVER_PRIMITIVE_TYPE_SEMIAXIS)
  {
    auto it = m_axes.find(primitive.DriverIndex());
    if (it != m_axes.end())
    {
      const AxisConfiguration& config = it->second;
      primitive = kodi::addon::DriverPrimitive(primitive.DriverIndex(),
                                         config.trigger.center,
                                         primitive.SemiAxisDirection(),
                                         config.trigger.range);
    }
  }
}

void CDeviceConfiguration::SetAxisConfigs(const FeatureVector& features)
{
  for (const auto& feature : features)
  {
    for (const auto& primitive : feature.Primitives())
      SetAxisConfig(primitive);
  }
}

void CDeviceConfiguration::SetAxisConfig(const kodi::addon::DriverPrimitive& primitive)
{
  if (primitive.Type() == JOYSTICK_DRIVER_PRIMITIVE_TYPE_SEMIAXIS)
  {
    AxisConfiguration& config = m_axes[primitive.DriverIndex()];
    config.trigger.center = primitive.Center();
    config.trigger.range = primitive.Range();
  }
}

void CDeviceConfiguration::SetIgnoredPrimitives(const PrimitiveVector& primitives)
{
  // Reset known axes
  for (auto& axisConfig : m_axes)
    axisConfig.second.bIgnore = false;

  for (auto& buttonConfig : m_buttons)
    buttonConfig.second.bIgnore = false;

  // Update ignore status
  for (const auto& primitive : primitives)
  {
    switch (primitive.Type())
    {
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_BUTTON:
      m_buttons[primitive.DriverIndex()].bIgnore = true;
      break;
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_SEMIAXIS:
      m_axes[primitive.DriverIndex()].bIgnore = true;
      break;
    default:
      break;
    }
  }
}
