#include "tgbot/types/InlineQueryResultContact.h"

namespace tgbot
{
	InlineQueryResultContact::InlineQueryResultContact() : type(), id(), phone_number(), first_name(), last_name(), vcard(), reply_markup(), input_message_content(),
	thumb_url(), thumb_width(), thumb_height()
	{}

	InlineQueryResultContact::InlineQueryResultContact(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("type"))
			type = doc["type"].GetString();

		if(doc.HasMember("id"))
			id = doc["id"].GetString();

		if(doc.HasMember("phone_number"))
			phone_number = doc["phone_number"].GetString();

		if(doc.HasMember("first_name"))
			first_name = doc["first_name"].GetString();

		if(doc.HasMember("last_name"))
			last_name = doc["last_name"].GetString();

		if(doc.HasMember("vcard"))
			vcard = doc["vcard"].GetString();

		if(doc.HasMember("reply_markup"))
			reply_markup = std::make_shared<InlineKeyboardMarkup>(SpecialTools::get_json_obj_as_string(doc["reply_markup"]));

		if(doc.HasMember("thumb_url"))
			thumb_url = doc["thumb_url"].GetString();

		if(doc.HasMember("thumb_width"))
			thumb_width = doc["thumb_width"].GetInt();

		if(doc.HasMember("thumb_height"))
			thumb_height = doc["thumb_height"].GetInt();
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
