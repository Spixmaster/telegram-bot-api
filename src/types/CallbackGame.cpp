#include "tgbot/types/CallbackGame.h"
#include <rapidjson/document.h>
#include <iostream>

namespace tgbot
{
	CallbackGame::CallbackGame()
	{}

	CallbackGame::CallbackGame(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string CallbackGame::parse_to_json() const
	{
		std::string json = "{";

		json.append("}");

		return json;
	}
}
