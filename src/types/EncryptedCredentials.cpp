#include <rapidjson/document.h>
#include "tgbot/types/EncryptedCredentials.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	EncryptedCredentials::EncryptedCredentials() : data(), hash(), secret()
	{}

	EncryptedCredentials::EncryptedCredentials(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("data"))
				data = doc["data"].GetString();

			if(doc.HasMember("hash"))
				hash = doc["hash"].GetString();

			if(doc.HasMember("secret"))
				secret = doc["secret"].GetString();
		}
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
