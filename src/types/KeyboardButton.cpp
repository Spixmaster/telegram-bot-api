#include "tgbot/types/KeyboardButton.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	KeyboardButton::KeyboardButton() : text(), request_contact(), request_location()
	{}

	KeyboardButton::KeyboardButton(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("text"))
				text = doc["text"].GetString();

			if(doc.HasMember("request_contact"))
				request_contact = doc["request_contact"].GetBool();

			if(doc.HasMember("request_location"))
				request_location = doc["request_location"].GetBool();
		}
	}

	std::string KeyboardButton::parse_to_json() const
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

		json.append("}");

		return json;
	}
}
