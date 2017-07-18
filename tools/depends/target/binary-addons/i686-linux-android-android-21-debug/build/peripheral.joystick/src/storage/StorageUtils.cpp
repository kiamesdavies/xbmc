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

#include "StorageUtils.h"
#include "Device.h"
#include "filesystem/DirectoryUtils.h"
#include "log/Log.h"
#include "utils/StringUtils.h"

#include <algorithm>
#include <set>
#include <sstream>
#include <stdio.h>

using namespace JOYSTICK;

std::set<std::string> CStorageUtils::m_existingDirs;

bool CStorageUtils::EnsureDirectoryExists(const std::string& path)
{
  if (m_existingDirs.find(path) != m_existingDirs.end())
    return true; // Already exists

  if (!CDirectoryUtils::Exists(path))
  {
    dsyslog("Creating directory: %s", path.c_str());
    if (!CDirectoryUtils::Create(path))
    {
      esyslog("Failed to create directory!");
      return false;
    }
  }

  m_existingDirs.insert(path);

  return true;
}

std::string CStorageUtils::RootFileName(const kodi::addon::Joystick& device)
{
  std::string baseFilename = StringUtils::MakeSafeUrl(device.Name());

  // Limit filename to a sane number of characters.
  if (baseFilename.length() > 50)
    baseFilename.erase(baseFilename.begin() + 50, baseFilename.end());

  // Append remaining properties
  std::stringstream filename;

  filename << baseFilename;
  if (device.IsVidPidKnown())
  {
    filename << "_v" << CStorageUtils::FormatHexString(device.VendorID());
    filename << "_p" << CStorageUtils::FormatHexString(device.ProductID());
  }
  if (device.ButtonCount() != 0)
    filename << "_" << device.ButtonCount() << "b";
  if (device.HatCount() != 0)
    filename << "_" << device.HatCount() << "h";
  if (device.AxisCount() != 0)
    filename << "_" << device.AxisCount() << "a";
  if (device.Index() != 0)
    filename << "_" << device.Index();

  return filename.str();
}

int CStorageUtils::HexStringToInt(const char* strHex)
{
  int iVal;
  sscanf(strHex, "%x", &iVal);
  return iVal;
};

std::string CStorageUtils::FormatHexString(int iVal)
{
  if (iVal < 0)
    iVal = 0;
  if (iVal > 65536)
    iVal = 65536;

  return StringUtils::Format("%04X", iVal);
};

std::string CStorageUtils::PrimitiveToString(const kodi::addon::DriverPrimitive& primitive)
{
  switch (primitive.Type())
  {
  case JOYSTICK_DRIVER_PRIMITIVE_TYPE_BUTTON:
    return StringUtils::Format("button %u", primitive.DriverIndex());
  case JOYSTICK_DRIVER_PRIMITIVE_TYPE_HAT_DIRECTION:
    switch (primitive.HatDirection())
    {
    case JOYSTICK_DRIVER_HAT_UP:
      return StringUtils::Format("hat up");
    case JOYSTICK_DRIVER_HAT_RIGHT:
      return StringUtils::Format("hat right");
    case JOYSTICK_DRIVER_HAT_DOWN:
      return StringUtils::Format("hat down");
    case JOYSTICK_DRIVER_HAT_LEFT:
      return StringUtils::Format("hat left");
    default:
      break;
    }
    break;
  case JOYSTICK_DRIVER_PRIMITIVE_TYPE_SEMIAXIS:
    return StringUtils::Format("axis %s%u",
        primitive.SemiAxisDirection() == JOYSTICK_DRIVER_SEMIAXIS_POSITIVE ? "+" : "-",
        primitive.DriverIndex());
  case JOYSTICK_DRIVER_PRIMITIVE_TYPE_MOTOR:
    return StringUtils::Format("motor %u", primitive.DriverIndex());
  default:
    break;
  }

  return "";
}
