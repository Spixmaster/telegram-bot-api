#include "tgbot/types/InlineQueryResultContact.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InlineQueryResultContact::InlineQueryResultContact() : type(), id(), phone_number(), first_name(), last_name(), vcard(), reply_markup(), input_message_content(),
	thumb_url(), thumb_width(), thumb_height()
	{}

	InlineQueryResultContact::InlineQueryResultContact(const std::string &json)
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

			if(doc.HasMember("phone_number"))
			{
				if(doc["phone_number"].IsString())
					phone_number = doc["phone_number"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("phone_number"));
			}

			if(doc.HasMember("first_name"))
			{
				if(doc["first_name"].IsString())
					first_name = doc["first_name"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("first_name"));
			}

			if(doc.HasMember("last_name"))
			{
				if(doc["last_name"].IsString())
					last_name = doc["last_name"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("last_name"));
			}

			if(doc.HasMember("vcard"))
			{
				if(doc["vcard"].IsString())
					vcard = doc["vcard"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("vcard"));
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

	std::string InlineQueryResultContact::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//Field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//Field phone_number
		json.append("\"phone_number\": \"" + phone_number + "\"");
		json.append(", ");

		//Field first_name
		json.append("\"first_name\": \"" + first_name + "\"");
		json.append(", ");

		//Field last_name
		json.append("\"last_name\": " + last_name + "\"");
		json.append(", ");

		//Field vcard
		json.append("\"vcard\": \"" + vcard + "\"");
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
		json.append("\"thumb_width\": " + thumb_width);
		json.append(", ");

		//Field thumb_height
		json.append("\"thumb_height\": " + thumb_height);

		json.append("}");

		return json;
	}
}
