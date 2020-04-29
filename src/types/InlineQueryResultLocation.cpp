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
			//Assignments
			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("type"));
			}

			if(doc.HasMember("id"))
			{
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("id"));
			}

			if(doc.HasMember("latitude"))
			{
				if(doc["latitude"].IsFloat())
					latitude = doc["latitude"].GetFloat();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_float("latitude"));
			}

			if(doc.HasMember("longitude"))
			{
				if(doc["longitude"].IsFloat())
					longitude = doc["longitude"].GetFloat();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_float("longitude"));
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("title"));
			}

			if(doc.HasMember("live_period"))
			{
				if(doc["live_period"].IsInt())
					live_period = doc["live_period"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("live_period"));
			}

			if(doc.HasMember("reply_markup"))
			{
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("reply_markup"));
			}

			if(doc.HasMember("input_message_content"))
			{
				if(doc["input_message_content"].IsObject())
					input_message_content = std::make_shared<InputMessageContent>(tools::Tools::get_json_as_string(doc["input_message_content"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("input_message_content"));
			}

			if(doc.HasMember("thumb_url"))
			{
				if(doc["thumb_url"].IsString())
					thumb_url = doc["thumb_url"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("thumb_url"));
			}

			if(doc.HasMember("thumb_width"))
			{
				if(doc["thumb_width"].IsInt())
					thumb_width = doc["thumb_width"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("thumb_width"));
			}

			if(doc.HasMember("thumb_height"))
			{
				if(doc["thumb_height"].IsInt())
					thumb_height = doc["thumb_height"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("thumb_height"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string InlineQueryResultLocation::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field latitude
		json.append("\"latitude\": " + std::to_string(latitude));
		json.append(", ");

		//Field longitude
		json.append("\"longitude\": " + std::to_string(longitude));
		json.append(", ");

		//Field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//Field live_period
		json.append("\"live_period\": " + live_period);
		json.append(", ");

		//Field reply_markup
		json.append("\"reply_markup\": " + reply_markup->parse_to_json());
		json.append(", ");

		//Field input_message_content
		json.append("\"input_message_content\": " + input_message_content->parse_to_json());
		json.append(", ");

		//Field thumb_url
		json.append("\"thumb_url\": \"" + thumb_url + "\"");
		json.append(", ");

		//Field thumb_width
		json.append("\"thumb_url\": " + thumb_width);
		json.append(", ");

		//Field thumb_height
		json.append("\"thumb_height\": " + thumb_height);

		json.append("}");

		return json;
	}
}
