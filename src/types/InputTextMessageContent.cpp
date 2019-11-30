#include "tgbot/types/InputTextMessageContent.h"
#include "tools/Tools.h"

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
			if(doc.HasMember("message_tex"))
				message_text = doc["message_tex"].GetString();

			if(doc.HasMember("parse_mode"))
				parse_mode = doc["parse_mode"].GetString();

			if(doc.HasMember("disable_web_page_preview"))
				disable_web_page_preview = doc["disable_web_page_preview"].GetBool();
		}
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
