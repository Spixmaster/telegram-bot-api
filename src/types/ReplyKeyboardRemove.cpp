#include "tgbot/types/ReplyKeyboardRemove.h"
#include "tgbot/Tools.h"

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
				remove_keyboard = doc["remove_keyboard"].GetBool();

			if(doc.HasMember("selective"))
				selective = doc["selective"].GetBool();
		}
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
