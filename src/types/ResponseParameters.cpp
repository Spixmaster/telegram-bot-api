#include "tgbot/types/ResponseParameters.h"
#include "tools/Tools.h"
#include <iostream>

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
				if(doc["migrate_to_chat_id"].IsInt())
					migrate_to_chat_id = doc["migrate_to_chat_id"].GetInt();
				else
					std::cerr << "Error: Field \"migrate_to_chat_id\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"migrate_to_chat_id\"." << std::endl;

			if(doc.HasMember("retry_after"))
				if(doc["retry_after"].IsInt())
					retry_after = doc["retry_after"].GetInt();
				else
					std::cerr << "Error: Field \"retry_after\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"retry_after\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string ResponseParameters::parse_to_json() const
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
