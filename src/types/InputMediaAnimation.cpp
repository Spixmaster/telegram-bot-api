#include <rapidjson/document.h>
#include "tgbot/types/InputMediaAnimation.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InputMediaAnimation::InputMediaAnimation() : type(), media(), thumb(), caption(), parse_mode(), width(), height(), duration()
	{}

	InputMediaAnimation::InputMediaAnimation(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("type") << std::endl;
			}

			if(doc.HasMember("media"))
			{
				if(doc["media"].IsString())
					media = doc["media"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("media") << std::endl;
			}

			if(doc.HasMember("thumb"))
			{
				if(doc["thumb"].IsString())
					thumb = doc["thumb"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("thumb") << std::endl;
			}

			if(doc.HasMember("caption"))
			{
				if(doc["caption"].IsString())
					caption = doc["caption"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("caption") << std::endl;
			}

			if(doc.HasMember("parse_mode"))
			{
				if(doc["parse_mode"].IsString())
					parse_mode = doc["parse_mode"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("parse_mode") << std::endl;
			}

			if(doc.HasMember("width"))
			{
				if(doc["width"].IsInt())
					width = doc["width"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("width") << std::endl;
			}

			if(doc.HasMember("height"))
			{
				if(doc["height"].IsInt())
					height = doc["height"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("height") << std::endl;
			}

			if(doc.HasMember("duration"))
			{
				if(doc["duration"].IsInt())
					duration = doc["duration"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("duration") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	InputMediaAnimation::InputMediaAnimation(const std::variant<std::string, tools::InputFile::ptr> &media, const std::variant<std::string, tools::InputFile::ptr> &thumb,
			const std::string &caption, const std::string &parse_mode, const int &width, const int &height, const int &duration) : media(media), thumb(thumb),
					caption(caption), parse_mode(parse_mode), width(width), height(height), duration(duration)
	{}

	std::string InputMediaAnimation::parse_to_json() const noexcept
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

		json.append("}");

		return json;
	}
}

