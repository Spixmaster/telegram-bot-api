#include "tgbot/types/KeyboardButton.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	KeyboardButton::KeyboardButton() : text(), request_contact(), request_location(), request_poll()
	{}

	KeyboardButton::KeyboardButton(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("text"))
			{
				if(doc["text"].IsString())
					text = doc["text"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("text") << std::endl;
			}

			if(doc.HasMember("request_contact"))
			{
				if(doc["request_contact"].IsBool())
					request_contact = doc["request_contact"].GetBool();
				else
					std::cerr << Messages::field_does_not_contain_bool("request_contact") << std::endl;
			}

			if(doc.HasMember("request_location"))
			{
				if(doc["request_location"].IsBool())
					request_location = doc["request_location"].GetBool();
				else
					std::cerr << Messages::field_does_not_contain_bool("request_location") << std::endl;
			}

			if(doc.HasMember("request_poll"))
			{
				if(doc["request_poll"].IsObject())
					request_poll = std::make_shared<KeyboardButtonPollType>(tools::Tools::get_json_as_string(doc["request_poll"]));
				else
					std::cerr << Messages::field_does_not_contain_json_obj("request_poll") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string KeyboardButton::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field text
		json.append("\"text\": \"" + text + "\"");
		json.append(", ");

		//field request_contact
		std::string request_contact_bool = request_contact ? "true" : "false";
		json.append("\"request_contact\": " + request_contact_bool);
		json.append(", ");

		//field request_location
		std::string request_location_bool = request_location ? "true" : "false";
		json.append("\"request_location\": " + request_location_bool);
		json.append(", ");

		//field request_poll
		json.append("\"request_poll\": " + request_poll->parse_to_json());

		json.append("}");

		return json;
	}
}
