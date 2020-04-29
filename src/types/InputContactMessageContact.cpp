#include <rapidjson/document.h>
#include "tgbot/types/InputContactMessageContent.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	InputContactMessageContent::InputContactMessageContent() : phone_number(), first_name(), last_name(), vcard()
	{}

	InputContactMessageContent::InputContactMessageContent(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("phone_number"))
			{
				if(doc["phone_number"].IsString())
					phone_number = doc["phone_number"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("phone_number") << std::endl;
			}

			if(doc.HasMember("first_name"))
			{
				if(doc["first_name"].IsString())
					first_name = doc["first_name"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("first_name") << std::endl;
			}

			if(doc.HasMember("last_name"))
			{
				if(doc["last_name"].IsString())
					last_name = doc["last_name"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("last_name") << std::endl;
			}

			if(doc.HasMember("vcard"))
			{
				if(doc["vcard"].IsString())
					vcard = doc["vcard"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("vcard") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string InputContactMessageContent::parse_to_json() const noexcept
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

		//field vcard
		json.append("\"vcard\": \"" + vcard + "\"");

		json.append("}");

		return json;
	}
}
