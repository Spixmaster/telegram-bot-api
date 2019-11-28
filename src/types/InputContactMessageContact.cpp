#include <rapidjson/document.h>
#include "tgbot/types/InputContactMessageContent.h"
#include "tgbot/Tools.h"

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
				phone_number = doc["phone_number"].GetString();

			if(doc.HasMember("first_name"))
				first_name = doc["first_name"].GetString();

			if(doc.HasMember("last_name"))
				last_name = doc["last_name"].GetString();

			if(doc.HasMember("vcard"))
				vcard = doc["vcard"].GetString();
		}
	}
}
