#include "tgbot/types/ResponseParameters.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	ResponseParameters::ResponseParameters() : migrate_to_chat_id(), retry_after()
	{}

	ResponseParameters::ResponseParameters(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("migrate_to_chat_id"))
			{
				if(doc["migrate_to_chat_id"].IsInt())
					migrate_to_chat_id = doc["migrate_to_chat_id"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("migrate_to_chat_id") << std::endl;
			}

			if(doc.HasMember("retry_after"))
			{
				if(doc["retry_after"].IsInt())
					retry_after = doc["retry_after"].GetInt();
				else
					std::cerr << Messages::field_does_not_contain_int("retry_after") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string ResponseParameters::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field migrate_to_chat_id
		json.append("\"migrate_to_chat_id\": " + migrate_to_chat_id);
		json.append(", ");

		//field retry_after
		json.append("\"retry_after\": " + retry_after);

		json.append("}");

		return json;
	}
}
