#include <rapidjson/document.h>
#include "tgbot/types/Contact.h"

namespace tgbot
{
	Contact::Contact() : phone_number(), first_name(), last_name(), user_id(), vcard()
	{}

	Contact::Contact(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("phone_number"))
			phone_number = doc["phone_number"].GetString();

		if(doc.HasMember("first_name"))
			first_name = doc["first_name"].GetString();

		if(doc.HasMember("last_name"))
			last_name = doc["last_name"].GetString();

		if(doc.HasMember("user_id"))
			user_id = doc["user_id"].GetInt();

		if(doc.HasMember("vcard"))
			vcard = doc["vcard"].GetString();
	}

	std::string Contact::parse_to_json() const
	{
		std::string json = "{";

		//field phone_number
		json.append("\"phone_number\": \"" + phone_number + "\"");
		json.append(", ");

		//field first_name
		json.append("\"first_name\": \"" + first_name + "\"");
		json.append(", ");

		//field last_name
		json.append("\"last_name\": \"" + last_name + "\"");
		json.append(", ");

		//field user_id
		json.append("\"user_id\": " + user_id);
		json.append(", ");

		//field vcard
		json.append("\"vcard\": \"" + vcard + "\"");

		json.append("}");

		return json;
	}
}
