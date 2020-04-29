#include "tgbot/types/BotCommand.h"
#include <rapidjson/document.h>
#include "tgbot/constants/Messages.h"
#include <iostream>

namespace tgbot
{
	BotCommand::BotCommand(): command(), description()
	{}

	BotCommand::BotCommand(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("command"))
			{
				if(doc["command"].IsString())
					command = doc["command"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("command") << std::endl;
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("description") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string BotCommand::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field command
		json.append("\"command\": \"" + command + "\"");
		json.append(", ");

		//field description
		json.append("\"description\": \"" + description + "\"");

		json.append("}");

		return json;
	}
}
