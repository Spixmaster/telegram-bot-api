#include "tgbot/types/InputTextMessageContent.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
			if(doc.HasMember("message_text"))
			{
				if(doc["message_text"].IsString())
					message_text = doc["message_text"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("message_text"));
			}

			if(doc.HasMember("parse_mode"))
			{
				if(doc["parse_mode"].IsString())
					parse_mode = doc["parse_mode"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("parse_mode"));
			}

			if(doc.HasMember("disable_web_page_preview"))
			{
				if(doc["disable_web_page_preview"].IsBool())
					disable_web_page_preview = doc["disable_web_page_preview"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("disable_web_page_preview"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string InputTextMessageContent::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field message_text
		json.append("\"message_text\": \"" + message_text + "\"");
		json.append(", ");

		//Field parse_mode
		json.append("\"parse_mode\": \"" + parse_mode + "\"");
		json.append(", ");

		//Field parse_mode
		std::string disable_web_page_preview_bool = disable_web_page_preview ? "true" : "false";
		json.append("\"disable_web_page_preview\": \"" + disable_web_page_preview_bool + "\"");

		json.append("}");
		return json;
	}
}
