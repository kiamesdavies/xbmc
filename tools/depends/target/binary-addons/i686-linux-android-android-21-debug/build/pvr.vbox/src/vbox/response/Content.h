#pragma once
/*
*      Copyright (C) 2015 Sam Stenvall
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
*  along with XBMC; see the file COPYING.  If not, write to
*  the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
*  MA 02110-1301  USA
*  http://www.gnu.org/copyleft/gpl.html
*
*/

#include <string>
#include <vector>
#include "../Channel.h"
#include "../Recording.h"
#include "../SeriesRecording.h"
#include "../../xmltv/Guide.h"

namespace tinyxml2 {
  // Forward declarations
  class XMLElement;
}

namespace vbox {
  namespace response {

    /**
     * The base class for all response contents
     */
    class Content
    {
    public:
      Content(tinyxml2::XMLElement *content)
        : m_content(content) {}
      virtual ~Content() {};

      /**
       * Returns the specified parameter as a string
       * @param name the parameter
       * @return the value
       */
      std::string GetString(const std::string &parameter) const;

      /**
      * Returns the specified parameter as an integer
      * @param name the parameter
      * @return the value
      */
      int GetInteger(const std::string &parameter) const;

      /**
       * Returns the specified parameter as an unsigned integer
       * @param name the parameter
       * @return the value
       */
      unsigned int GetUnsignedInteger(const std::string &parameter) const;

    protected:

      /**
       * The request content
       */
      tinyxml2::XMLElement *m_content;

    private:

      tinyxml2::XMLElement* GetParameterElement(const std::string &parameter) const;
    };

    /**
     * Represents the contents of an XMLTV response
     */
    class XMLTVResponseContent : public Content
    {
    public:
      XMLTVResponseContent(tinyxml2::XMLElement *content)
        : Content(content) {}
      virtual ~XMLTVResponseContent() {};

      /**
       * Returns the list of channels contained in the response
       * @return the channels
       */
      std::vector<ChannelPtr> GetChannels() const;

      /**
       * Returns the complete guide
       * @return the guide
       */
      ::xmltv::Guide GetGuide() const;

    private:
      ChannelPtr CreateChannel(const tinyxml2::XMLElement *xml) const;

    };

    /**
     * Represents the contents of a recording response
     */
    class RecordingResponseContent : public Content
    {
    public:
      RecordingResponseContent(tinyxml2::XMLElement *content)
        : Content(content) {}
      virtual ~RecordingResponseContent() {};

      std::vector<RecordingPtr> GetRecordings() const;
      std::vector<SeriesRecordingPtr> GetSeriesRecordings() const;

    private:
      RecordingPtr CreateRecording(const tinyxml2::XMLElement *xml) const;
      SeriesRecordingPtr CreateSeriesRecording(const tinyxml2::XMLElement *xml) const;
      RecordingState GetState(const std::string &state) const;
    };
  }
}
