#include <rapidjson/document.h>
#include "tgbot/types/EncryptedCredentials.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	EncryptedCredentials::EncryptedCredentials() : data(), hash(), secret()
	{}

	EncryptedCredentials::EncryptedCredentials(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("data"))
				if(doc["data"].IsString())
					data = doc["data"].GetString();
				else
					std::cerr << "Error: Field \"data\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"data\"." << std::endl;

			if(doc.HasMember("hash"))
				if(doc["hash"].IsString())
					hash = doc["hash"].GetString();
				else
					std::cerr << "Error: Field \"hash\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"hash\"." << std::endl;

			if(doc.HasMember("secret"))
				if(doc["secret"].IsString())
					secret = doc["secret"].GetString();
				else
					std::cerr << "Error: Field \"secret\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"secret\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string EncryptedCredentials::parse_to_json() const
	{
		std::string json = "{";

		//field data
		json.append("\"data\": \"" + data + "\"");
		json.append(", ");

		//field hash
		json.append("\"hash\": \"" + hash + "\"");
		json.append(", ");

		//field secret
		json.append("\"secret\": \"" + secret + "\"");

		json.append("}");

		return json;
	}
}
