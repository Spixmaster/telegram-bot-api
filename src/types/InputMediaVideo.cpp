#include <rapidjson/document.h>
#include "tgbot/types/InputMediaVideo.h"
#include "tools/Tools.h"

namespace tgbot
{
	InputMediaVideo::InputMediaVideo() : media(), thumb(), caption(), parse_mode(), width(), height(), duration(), supports_streaming()
	{}

	InputMediaVideo::InputMediaVideo(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("media"))
				media = doc["media"].GetString();

			if(doc.HasMember("thumb"))
				thumb = doc["thumb"].GetString();

			if(doc.HasMember("caption"))
				caption = doc["caption"].GetString();

			if(doc.HasMember("parse_mode"))
				parse_mode = doc["parse_mode"].GetString();

			if(doc.HasMember("width"))
				width = doc["width"].GetInt();

			if(doc.HasMember("height"))
				height = doc["height"].GetInt();

			if(doc.HasMember("duration"))
				duration = doc["duration"].GetInt();

			if(doc.HasMember("supports_streaming"))
				supports_streaming = doc["supports_streaming"].GetBool();
		}
	}

	InputMediaVideo::InputMediaVideo(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb, const std::string &caption,
				const std::string &parse_mode, const int &width, const int &height, const int &duration, const bool & supports_streaming) : media(media), thumb(thumb),
						caption(caption), parse_mode(parse_mode), width(width), height(height), duration(duration), supports_streaming(supports_streaming)
	{}

	std::string InputMediaVideo::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field media
		if(std::holds_alternative<std::string>(media))
		{
			json.append("\"media\": \"" + std::get<std::string>(media) + "\"");
			json.append(", ");
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(media))
		{
			json.append("\"media\": \"attach://" + std::get<tools::InputFile::ptr>(media)->m_path + "\"");
			json.append(", ");
		}

		//field thumb
		if(std::holds_alternative<std::string>(thumb))
		{
			json.append("\"thumb\": \"" + std::get<std::string>(thumb) + "\"");
			json.append(", ");
		}
		else if(std::holds_alternative<tools::InputFile::ptr>(thumb))
		{
			json.append("\"thumb\": \"attach://" + std::get<tools::InputFile::ptr>(thumb)->m_path + "\"");
			json.append(", ");
		}


		//field caption
		json.append("\"caption\": \"" + caption + "\"");
		json.append(", ");

		//field parse_mode
		json.append("\"parse_mode\": \"" + parse_mode + "\"");
		json.append(", ");

		//field width
		json.append("\"width\": " + std::to_string(width));
		json.append(", ");

		//field height
		json.append("\"height\": " + std::to_string(height));
		json.append(", ");

		//field duration
		json.append("\"duration\": " + std::to_string(duration));
		json.append(", ");

		//field supports_streaming
		bool bool_supports_streaming = supports_streaming ? true : false;
		json.append("\"bool_supports_streaming\": " + bool_supports_streaming);

		json.append("}");

		return json;
	}
}
