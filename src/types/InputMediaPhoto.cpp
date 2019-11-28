#include <rapidjson/document.h>
#include "tgbot/types/InputMediaPhoto.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	InputMediaPhoto::InputMediaPhoto() : media(), caption(), parse_mode()
	{}

	InputMediaPhoto::InputMediaPhoto(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("media"))
				media = doc["media"].GetString();

			if(doc.HasMember("caption"))
				caption = doc["caption"].GetString();

			if(doc.HasMember("parse_mode"))
				parse_mode = doc["parse_mode"].GetString();
		}
	}

	InputMediaPhoto::InputMediaPhoto(const std::variant<std::string, InputFile::ptr> &media, const std::string &caption, const std::string &parse_mode) : media(media),
			caption(caption), parse_mode(parse_mode)
	{}

	std::string InputMediaPhoto::parse_to_json() const
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
		//of type InputFile
		else
		{
			json.append("\"media\": \"attach://" + std::get<InputFile::ptr>(media)->m_path + "\"");
			json.append(", ");
		}

		//field caption
		json.append("\"caption\": \"" + caption + "\"");
		json.append(", ");

		//field parse_mode
		json.append("\"parse_mode\": \"" + parse_mode + "\"");

		json.append("}");

		return json;
	}
}
