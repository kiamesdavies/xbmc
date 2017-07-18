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

#include "ButtonMapUtils.h"

#include <kodi/addon-instance/PeripheralUtils.h>

#include <array>
#include <map>

#include <array>
#include <map>

using namespace JOYSTICK;

bool ButtonMapUtils::PrimitivesEqual(const kodi::addon::JoystickFeature& lhs, const kodi::addon::JoystickFeature& rhs)
{
  if (lhs.Type() == rhs.Type())
  {
    switch (lhs.Type())
    {
    case JOYSTICK_FEATURE_TYPE_SCALAR:
    case JOYSTICK_FEATURE_TYPE_MOTOR:
    {
      return lhs.Primitive(JOYSTICK_SCALAR_PRIMITIVE) == rhs.Primitive(JOYSTICK_SCALAR_PRIMITIVE);
    }
    case JOYSTICK_FEATURE_TYPE_ANALOG_STICK:
    {
      return lhs.Primitive(JOYSTICK_ANALOG_STICK_UP)    == rhs.Primitive(JOYSTICK_ANALOG_STICK_UP) &&
             lhs.Primitive(JOYSTICK_ANALOG_STICK_DOWN)  == rhs.Primitive(JOYSTICK_ANALOG_STICK_DOWN) &&
             lhs.Primitive(JOYSTICK_ANALOG_STICK_RIGHT) == rhs.Primitive(JOYSTICK_ANALOG_STICK_RIGHT) &&
             lhs.Primitive(JOYSTICK_ANALOG_STICK_LEFT)  == rhs.Primitive(JOYSTICK_ANALOG_STICK_LEFT);
    }
    case JOYSTICK_FEATURE_TYPE_ACCELEROMETER:
    {
      return lhs.Primitive(JOYSTICK_ACCELEROMETER_POSITIVE_X) == rhs.Primitive(JOYSTICK_ACCELEROMETER_POSITIVE_X) &&
             lhs.Primitive(JOYSTICK_ACCELEROMETER_POSITIVE_Y) == rhs.Primitive(JOYSTICK_ACCELEROMETER_POSITIVE_Y) &&
             lhs.Primitive(JOYSTICK_ACCELEROMETER_POSITIVE_Z) == rhs.Primitive(JOYSTICK_ACCELEROMETER_POSITIVE_Z);
    }
    default:
      break;
    }
  }
  return false;
}

bool ButtonMapUtils::PrimitivesConflict(const kodi::addon::DriverPrimitive& lhs, const kodi::addon::DriverPrimitive& rhs)
{
  if (lhs.Type() != JOYSTICK_DRIVER_PRIMITIVE_TYPE_UNKNOWN &&
      lhs.Type() == rhs.Type() &&
      lhs.DriverIndex() == rhs.DriverIndex())
  {
    switch (lhs.Type())
    {
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_HAT_DIRECTION:
    {
      if (lhs.HatDirection() == rhs.HatDirection())
        return true;
      break;
    }
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_SEMIAXIS:
    {
      std::array<float, 2> points = { { -0.5f, 0.5f } };
      for (auto point : points)
      {
        if (SemiAxisIntersects(lhs, point) && SemiAxisIntersects(rhs, point))
          return true;
      }
      break;
    }
    default:
      return true;
    }
  }

  return false;
}

bool ButtonMapUtils::SemiAxisIntersects(const kodi::addon::DriverPrimitive& semiaxis, float point)
{
  if (semiaxis.Type() == JOYSTICK_DRIVER_PRIMITIVE_TYPE_SEMIAXIS)
  {
    int endpoint1 = semiaxis.Center();
    int endpoint2 = semiaxis.Center() + semiaxis.Range() * semiaxis.SemiAxisDirection();

    if (endpoint1 <= endpoint2)
      return endpoint1 <= point && point <= endpoint2;
    else
      return endpoint2 <= point && point <= endpoint1;
  }
  return false;
}

const std::vector<JOYSTICK_FEATURE_PRIMITIVE>& ButtonMapUtils::GetPrimitives(JOYSTICK_FEATURE_TYPE featureType)
{
  static const std::map<JOYSTICK_FEATURE_TYPE, std::vector<JOYSTICK_FEATURE_PRIMITIVE>> m_primitiveMap = {
    {
      JOYSTICK_FEATURE_TYPE_SCALAR, {
        JOYSTICK_SCALAR_PRIMITIVE,
      }
    },
    {
      JOYSTICK_FEATURE_TYPE_ANALOG_STICK, {
        JOYSTICK_ANALOG_STICK_UP,
        JOYSTICK_ANALOG_STICK_DOWN,
        JOYSTICK_ANALOG_STICK_RIGHT,
        JOYSTICK_ANALOG_STICK_LEFT,
      }
    },
    {
      JOYSTICK_FEATURE_TYPE_ACCELEROMETER, {
        JOYSTICK_ACCELEROMETER_POSITIVE_X,
        JOYSTICK_ACCELEROMETER_POSITIVE_Y,
        JOYSTICK_ACCELEROMETER_POSITIVE_Z,
      }
    },
    {
      JOYSTICK_FEATURE_TYPE_MOTOR, {
        JOYSTICK_MOTOR_PRIMITIVE,
      }
    }
  };

  auto itPair = m_primitiveMap.find(featureType);
  if (itPair != m_primitiveMap.end())
    return itPair->second;

  static const std::vector<JOYSTICK_FEATURE_PRIMITIVE> empty;
  return empty;
}
