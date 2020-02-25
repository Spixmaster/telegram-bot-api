#include "tgbot/types/InlineQueryResultLocation.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineQueryResultLocation::InlineQueryResultLocation() : type(), id(), latitude(), longitude(), title(), live_period(), reply_markup(), input_message_content(),
			thumb_url(), thumb_width(), thumb_height()
	{}

	InlineQueryResultLocation::InlineQueryResultLocation(const std::string &json)
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

			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("id") << std::endl;
			}

			if(doc.HasMember("latitude"))
			{
				if(doc["latitude"].IsFloat())
					latitude = doc["latitude"].GetFloat();
				else
					std::cerr << Messages::field_does_not_contain_float("latitude") << std::endl;
			}

			if(doc.HasMember("longitude"))
			{
				if(doc["longitude"].IsFloat())
					longitude = doc["longitude"].GetFloat();
				else
					std::cerr << Messages::field_does_not_contain_float("longitude") << std::endl;
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("title") << std::endl;
			}

			if(doc.HasMember("live_period"))
			{
				if(doc["live_period"].IsInt())
					live_period = doc["live_period"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("live_period") << std::endl;
			}

			if(doc.HasMember("reply_markup"))
			{
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("reply_markup") << std::endl;
			}

			if(doc.HasMember("input_message_content"))
			{
				if(doc["input_message_content"].IsObject())
					input_message_content = std::make_shared<InputMessageContent>(tools::Tools::get_json_as_string(doc["input_message_content"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("input_message_content") << std::endl;
			}

			if(doc.HasMember("thumb_url"))
			{
				if(doc["thumb_url"].IsString())
					thumb_url = doc["thumb_url"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("thumb_url") << std::endl;
			}

			if(doc.HasMember("thumb_width"))
			{
				if(doc["thumb_width"].IsInt())
					thumb_width = doc["thumb_width"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("thumb_width") << std::endl;
			}

			if(doc.HasMember("thumb_height"))
			{
				if(doc["thumb_height"].IsInt())
					thumb_height = doc["thumb_height"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("thumb_height") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string InlineQueryResultLocation::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field latitude
		json.append("\"latitude\": " + std::to_string(latitude));
		json.append(", ");

		//field longitude
		json.append("\"longitude\": " + std::to_string(longitude));
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field live_period
		json.append("\"live_period\": " + live_period);
		json.append(", ");

		//field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());
		json.append(", ");

		//field input_message_content
		json.append("\"input_message_content\": " + input_message_content->parse_to_json());
		json.append(", ");

		//field thumb_url
		json.append("\"thumb_url\": \"" + thumb_url + "\"");
		json.append(", ");

		//field thumb_width
		json.append("\"thumb_url\": " + thumb_width);
		json.append(", ");

		//field thumb_height
		json.append("\"thumb_height\": " + thumb_height);

		json.append("}");

		return json;
	}
}
