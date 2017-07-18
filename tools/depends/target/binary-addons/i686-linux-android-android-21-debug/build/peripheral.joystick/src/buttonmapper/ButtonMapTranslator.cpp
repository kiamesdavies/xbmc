/*
 *      Copyright (C) 2015-2017 Garrett Brown
 *      Copyright (C) 2015-2017 Team Kodi
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

#include "ButtonMapTranslator.h"
#include "api/JoystickTranslator.h"

#include <cstdlib>
#include <cctype>
#include <sstream>

using namespace JOYSTICK;

#define HAT_CHAR  'h'
#define MOTOR_CHAR  'm'

std::string ButtonMapTranslator::ToString(const kodi::addon::DriverPrimitive& primitive)
{
  std::stringstream strPrimitive;
  switch (primitive.Type())
  {
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_BUTTON:
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_MOTOR:
    {
      strPrimitive << primitive.DriverIndex();
      break;
    }
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_HAT_DIRECTION:
    {
      strPrimitive << HAT_CHAR;
      strPrimitive << primitive.DriverIndex();
      strPrimitive << JoystickTranslator::TranslateHatDir(primitive.HatDirection());
      break;
    }
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_SEMIAXIS:
    {
      const char* dir = JoystickTranslator::TranslateSemiAxisDir(primitive.SemiAxisDirection());
      if (*dir != '\0')
      {
        strPrimitive << dir;
        strPrimitive << primitive.DriverIndex();
      }
      break;
    }
    default:
      break;
  }
  return strPrimitive.str();
}

kodi::addon::DriverPrimitive ButtonMapTranslator::ToDriverPrimitive(const std::string& strPrimitive, JOYSTICK_DRIVER_PRIMITIVE_TYPE type)
{
  kodi::addon::DriverPrimitive primitive;

  if (!strPrimitive.empty())
  {
    switch (type)
    {
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_BUTTON:
    {
      if (std::isdigit(strPrimitive[0]))
        primitive = kodi::addon::DriverPrimitive::CreateButton(std::atoi(strPrimitive.c_str()));
      break;
    }
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_HAT_DIRECTION:
    {
      if (strPrimitive[0] == HAT_CHAR)
      {
        unsigned int hatIndex = std::atoi(strPrimitive.substr(1).c_str());
        size_t dirPos = strPrimitive.find_first_not_of("0123456789", 1);
        if (dirPos != std::string::npos)
        {
          JOYSTICK_DRIVER_HAT_DIRECTION hatDir = JoystickTranslator::TranslateHatDir(strPrimitive.substr(dirPos));
          if (hatDir != JOYSTICK_DRIVER_HAT_UNKNOWN)
            primitive = kodi::addon::DriverPrimitive(hatIndex, hatDir);
        }
      }
      break;
    }
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_SEMIAXIS:
    {
      JOYSTICK_DRIVER_SEMIAXIS_DIRECTION dir = JoystickTranslator::TranslateSemiAxisDir(strPrimitive[0]);
      if (dir != JOYSTICK_DRIVER_SEMIAXIS_UNKNOWN)
        primitive = kodi::addon::DriverPrimitive(std::atoi(strPrimitive.substr(1).c_str()), 0, dir, 1);
      break;
    }
    case JOYSTICK_DRIVER_PRIMITIVE_TYPE_MOTOR:
    {
      if (std::isdigit(strPrimitive[0]))
        primitive = kodi::addon::DriverPrimitive::CreateMotor(std::atoi(strPrimitive.c_str()));
      break;
    }
    default:
      break;
    }
  }

  return primitive;
}
