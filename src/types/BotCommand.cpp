#include "tgbot/types/BotCommand.h"
#include <rapidjson/document.h>
#include "tgbot/constants/Messages.h"
#include <iostream>
#include "tools/Tools.h"

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
			//Assignments
			if(doc.HasMember("command"))
			{
				if(doc["command"].IsString())
					command = doc["command"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("command"));
			}

			if(doc.HasMember("description"))
			{
				if(doc["description"].IsString())
					description = doc["description"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("description"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string BotCommand::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field command
		json.append("\"command\": \"" + command + "\"");
		json.append(", ");

		//Field description
		json.append("\"description\": \"" + description + "\"");

		json.append("}");
		return json;
	}
}
