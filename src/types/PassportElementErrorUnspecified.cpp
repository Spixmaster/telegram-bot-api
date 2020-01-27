#include "tgbot/types/PassportElementErrorUnspecified.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	PassportElementErrorUnspecified::PassportElementErrorUnspecified() : source(), type(), element_hash(), message()
	{}

	PassportElementErrorUnspecified::PassportElementErrorUnspecified(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("source"))
			{
				if(doc["source"].IsString())
					source = doc["source"].GetString();
				else
					std::cerr << "Error: Field \"source\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("element_hash"))
			{
				if(doc["element_hash"].IsString())
					element_hash = doc["element_hash"].GetString();
				else
					std::cerr << "Error: Field \"element_hash\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("message"))
			{
				if(doc["message"].IsString())
					message = doc["message"].GetString();
				else
					std::cerr << "Error: Field \"message\" does not contain a string." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string PassportElementErrorUnspecified::parse_to_json() const
	{
		std::string json = "{";

		//field source
		json.append("\"source\": \"" + source + "\"");
		json.append(", ");

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field element_hash
		json.append("\"element_hash\": \"" + element_hash + "\"");
		json.append(", ");

		//field message
		json.append("\"message\": \"" + message + "\"");

		json.append("}");

		return json;
	}
}
