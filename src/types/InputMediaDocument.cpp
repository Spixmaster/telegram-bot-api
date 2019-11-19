#include <rapidjson/document.h>
#include "tgbot/types/InputMediaDocument.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	InputMediaDocument::InputMediaDocument() : media(), thumb(), caption(), parse_mode()
	{}

	InputMediaDocument::InputMediaDocument(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
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
		}
	}

	InputMediaDocument::InputMediaDocument(const std::variant<std::string, InputFile::ptr> &media, const std::variant<std::string, InputFile::ptr> &thumb, const std::string &caption,
				const std::string &parse_mode) : media(media), thumb(thumb), caption(caption), parse_mode(parse_mode)
	{}

	std::string InputMediaDocument::parse_to_json() const
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

		//field thumb
		if(std::holds_alternative<std::string>(thumb))
		{
			json.append("\"thumb\": \"" + std::get<std::string>(thumb) + "\"");
			json.append(", ");
		}
		//of type InputFile
		else
		{
			json.append("\"thumb\": \"attach://" + std::get<InputFile::ptr>(thumb)->m_path + "\"");
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
