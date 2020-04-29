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
			//Assignments
			if(doc.HasMember("data"))
			{
				if(doc["data"].IsString())
					data = doc["data"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("data"));
			}

			if(doc.HasMember("hash"))
			{
				if(doc["hash"].IsString())
					hash = doc["hash"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("hash"));
			}

			if(doc.HasMember("secret"))
			{
				if(doc["secret"].IsString())
					secret = doc["secret"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("secret"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string EncryptedCredentials::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field data
		json.append("\"data\": \"" + data + "\"");
		json.append(", ");

		//Field hash
		json.append("\"hash\": \"" + hash + "\"");
		json.append(", ");

		//Field secret
		json.append("\"secret\": \"" + secret + "\"");

		json.append("}");

		return json;
	}
}
