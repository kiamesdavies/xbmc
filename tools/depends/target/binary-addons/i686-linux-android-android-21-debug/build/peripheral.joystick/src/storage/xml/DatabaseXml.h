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
#pragma once

#include "storage/JustABunchOfFiles.h"

#include <string>
#include <vector>

class TiXmlElement;

namespace JOYSTICK
{
  class CDatabaseXml : public CJustABunchOfFiles
  {
  public:
    CDatabaseXml(const std::string& strBasePath, bool bReadWrite, IDatabaseCallbacks* callbacks);

    virtual ~CDatabaseXml(void) { }

    // implementation of CJustABunchOfFiles
    virtual CButtonMap* CreateResource(const std::string& resourcePath) const override;
    virtual CButtonMap* CreateResource(const std::string& resourcePath, const DevicePtr& deviceInfo) const override;
  };
}
