#include "tgbot/types/InlineQueryResultContact.h"
#include "tools/Tools.h"
#include <iostream>

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
			//assignments
			if(doc.HasMember("type"))
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"type\"." << std::endl;

			if(doc.HasMember("id"))
				if(doc["id"].IsString())
					id = doc["id"].GetString();
				else
					std::cerr << "Error: Field \"id\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"id\"." << std::endl;

			if(doc.HasMember("phone_number"))
				if(doc["phone_number"].IsString())
					phone_number = doc["phone_number"].GetString();
				else
					std::cerr << "Error: Field \"phone_number\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"phone_number\"." << std::endl;

			if(doc.HasMember("first_name"))
				if(doc["first_name"].IsString())
					first_name = doc["first_name"].GetString();
				else
					std::cerr << "Error: Field \"first_name\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"first_name\"." << std::endl;

			if(doc.HasMember("last_name"))
				if(doc["last_name"].IsString())
					last_name = doc["last_name"].GetString();
				else
					std::cerr << "Error: Field \"last_name\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"last_name\"." << std::endl;

			if(doc.HasMember("vcard"))
				if(doc["vcard"].IsString())
					vcard = doc["vcard"].GetString();
				else
					std::cerr << "Error: Field \"vcard\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"vcard\"." << std::endl;

			if(doc.HasMember("reply_markup"))
				if(doc["reply_markup"].IsObject())
					reply_markup = std::make_shared<InlineKeyboardMarkup>(tools::Tools::get_json_as_string(doc["reply_markup"]));
				else
					std::cerr << "Error: Field \"reply_markup\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"reply_markup\"." << std::endl;

			if(doc.HasMember("thumb_url"))
				if(doc["thumb_url"].IsString())
					thumb_url = doc["thumb_url"].GetString();
				else
					std::cerr << "Error: Field \"thumb_url\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"thumb_url\"." << std::endl;

			if(doc.HasMember("thumb_width"))
				if(doc["thumb_width"].IsInt())
					thumb_width = doc["thumb_width"].GetInt();
				else
					std::cerr << "Error: Field \"thumb_width\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"thumb_width\"." << std::endl;

			if(doc.HasMember("thumb_height"))
				if(doc["thumb_height"].IsInt())
					thumb_height = doc["thumb_height"].GetInt();
				else
					std::cerr << "Error: Field \"thumb_height\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"thumb_height\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string InlineQueryResultContact::parse_to_json() const
	{
		std::string json = "{";

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field id
		json.append("\"id\": \"" + id + "\"");
		json.append(", ");

		//field phone_number
		json.append("\"phone_number\": \"" + phone_number + "\"");
		json.append(", ");

		//field first_name
		json.append("\"first_name\": \"" + first_name + "\"");
		json.append(", ");

		//field last_name
		json.append("\"last_name\": " + last_name + "\"");
		json.append(", ");

		//field vcard
		json.append("\"vcard\": \"" + vcard + "\"");
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
		json.append("\"thumb_width\": " + thumb_width);
		json.append(", ");

		//field thumb_height
		json.append("\"thumb_height\": " + thumb_height);

		json.append("}");

		return json;
	}
}
