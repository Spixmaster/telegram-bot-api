#include "tgbot/types/ReplyKeyboardRemove.h"
#include "tools/Tools.h"
#include <iostream>

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
					std::cerr << "Error: Field \"remove_keyboard\" does not contain a bool." << std::endl;
			}

			if(doc.HasMember("selective"))
			{
				if(doc["selective"].IsBool())
					selective = doc["selective"].GetBool();
				else
					std::cerr << "Error: Field \"selective\" does not contain a bool." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string ReplyKeyboardRemove::parse_to_json() const
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
