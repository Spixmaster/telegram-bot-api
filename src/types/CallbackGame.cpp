#include "tgbot/types/CallbackGame.h"
#include <rapidjson/document.h>
#include <iostream>
#include "tgbot/constants/Messages.h"
#include "tools/Tools.h"

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
			//Assignments
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string CallbackGame::parse_to_json() const noexcept
	{
		std::string json = "{";

		json.append("}");
		return json;
	}
}
