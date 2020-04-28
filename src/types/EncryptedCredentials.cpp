#include <rapidjson/document.h>
#include "tgbot/types/EncryptedCredentials.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			{
				if(doc["data"].IsString())
					data = doc["data"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("data") << std::endl;
			}

			if(doc.HasMember("hash"))
			{
				if(doc["hash"].IsString())
					hash = doc["hash"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("hash") << std::endl;
			}

			if(doc.HasMember("secret"))
			{
				if(doc["secret"].IsString())
					secret = doc["secret"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("secret") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string EncryptedCredentials::parse_to_json() const noexcept
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
