#include "tgbot/types/InputTextMessageContent.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	InputTextMessageContent::InputTextMessageContent() : message_text(), parse_mode(), disable_web_page_preview()
	{}

	InputTextMessageContent::InputTextMessageContent(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("message_text"))
				if(doc["message_text"].IsString())
					message_text = doc["message_text"].GetString();
				else
					std::cerr << "Error: Field \"message_text\" does not contain a string." << std::endl;

			if(doc.HasMember("parse_mode"))
				if(doc["parse_mode"].IsString())
					parse_mode = doc["parse_mode"].GetString();
				else
					std::cerr << "Error: Field \"parse_mode\" does not contain a string." << std::endl;

			if(doc.HasMember("disable_web_page_preview"))
				if(doc["disable_web_page_preview"].IsBool())
					disable_web_page_preview = doc["disable_web_page_preview"].GetBool();
				else
					std::cerr << "Error: Field \"disable_web_page_preview\" does not contain a bool." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string InputTextMessageContent::parse_to_json() const
	{
		std::string json = "{";

		//field message_text
		json.append("\"message_text\": \"" + message_text + "\"");
		json.append(", ");

		//field parse_mode
		json.append("\"parse_mode\": \"" + parse_mode + "\"");
		json.append(", ");

		//field parse_mode
		std::string disable_web_page_preview_bool = disable_web_page_preview ? "true" : "false";
		json.append("\"disable_web_page_preview\": \"" + disable_web_page_preview_bool + "\"");

		json.append("}");

		return json;
	}
}
