#include "tgbot/types/ReplyKeyboardRemove.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	ReplyKeyboardRemove::ReplyKeyboardRemove() : remove_keyboard(), selective()
	{}

	ReplyKeyboardRemove::ReplyKeyboardRemove(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("remove_keyboard"))
			{
				if(doc["remove_keyboard"].IsBool())
					remove_keyboard = doc["remove_keyboard"].GetBool();
				else
					std::cerr << Messages::field_does_not_contain_bool("remove_keyboard") << std::endl;
			}

			if(doc.HasMember("selective"))
			{
				if(doc["selective"].IsBool())
					selective = doc["selective"].GetBool();
				else
					std::cerr << Messages::field_does_not_contain_bool("selective") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string ReplyKeyboardRemove::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field remove_keyboard
		std::string remove_keyboard_bool = remove_keyboard ? "true" : "false";
		json.append("\"remove_keyboard\": " + remove_keyboard_bool);
		json.append(", ");

		//field selective
		std::string selective_bool = selective ? "true" : "false";
		json.append("\"selective\": " + selective_bool);

		json.append("}");

		return json;
	}
}
