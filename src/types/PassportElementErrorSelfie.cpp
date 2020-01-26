#include "tgbot/types/PassportElementErrorSelfie.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	PassportElementErrorSelfie::PassportElementErrorSelfie() : source(), type(), file_hash(), message()
	{}

	PassportElementErrorSelfie::PassportElementErrorSelfie(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("source"))
				if(doc["source"].IsString())
					source = doc["source"].GetString();
				else
					std::cerr << "Error: Field \"source\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"source\"." << std::endl;

			if(doc.HasMember("type"))
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"type\"." << std::endl;

			if(doc.HasMember("file_hash"))
				if(doc["file_hash"].IsString())
					file_hash = doc["file_hash"].GetString();
				else
					std::cerr << "Error: Field \"file_hash\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"file_hash\"." << std::endl;

			if(doc.HasMember("message"))
				if(doc["message"].IsString())
					message = doc["message"].GetString();
				else
					std::cerr << "Error: Field \"message\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"message\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string PassportElementErrorSelfie::parse_to_json() const
	{
		std::string json = "{";

		//field source
		json.append("\"source\": \"" + source + "\"");
		json.append(", ");

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field file_hash
		json.append("\"file_hash\": \"" + file_hash + "\"");
		json.append(", ");

		//field message
		json.append("\"message\": \"" + message + "\"");

		json.append("}");

		return json;
	}
}
