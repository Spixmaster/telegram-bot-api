#include <rapidjson/document.h>
#include "tgbot/types/Contact.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	Contact::Contact() : phone_number(), first_name(), last_name(), user_id(), vcard()
	{}

	Contact::Contact(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
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

			if(doc.HasMember("user_id"))
				if(doc["user_id"].IsInt())
					user_id = doc["user_id"].GetInt();
				else
					std::cerr << "Error: Field \"user_id\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"user_id\"." << std::endl;

			if(doc.HasMember("vcard"))
				if(doc["vcard"].IsString())
					vcard = doc["vcard"].GetString();
				else
					std::cerr << "Error: Field \"vcard\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"vcard\"." << std::endl;
		}
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
