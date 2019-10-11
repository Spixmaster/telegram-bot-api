#include <rapidjson/document.h>
#include "tgbot/types/InputMediaAnimation.h"

namespace tgbot
{
	InputMediaAnimation::InputMediaAnimation() : media(), thumb(), caption(), parse_mode(), width(), height(), duration()
	{}

	InputMediaAnimation::InputMediaAnimation(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

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
	}

	InputMediaAnimation::InputMediaAnimation(const std::variant<std::string, InputFile::ptr> &media, const std::variant<std::string, InputFile::ptr> &thumb, const std::string &caption,
			const std::string &parse_mode, const int &width, const int &height, const int &duration) : media(media), thumb(thumb), caption(caption),
					parse_mode(parse_mode), width(width), height(height), duration(duration)
	{}

	std::string InputMediaAnimation::parse_to_json() const
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
		json.append(", ");

		//field width
		json.append("\"width\": " + std::to_string(width));
		json.append(", ");

		//field height
		json.append("\"height\": " + std::to_string(height));
		json.append(", ");

		//field duration
		json.append("\"duration\": " + std::to_string(duration));

		json.append("}");

		return json;
	}
}

