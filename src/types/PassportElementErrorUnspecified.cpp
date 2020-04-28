#include "tgbot/types/PassportElementErrorUnspecified.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
					std::cerr << Messages::field_does_not_contain_string("source") << std::endl;
			}

			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("type") << std::endl;
			}

			if(doc.HasMember("element_hash"))
			{
				if(doc["element_hash"].IsString())
					element_hash = doc["element_hash"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("element_hash") << std::endl;
			}

			if(doc.HasMember("message"))
			{
				if(doc["message"].IsString())
					message = doc["message"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("message") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string PassportElementErrorUnspecified::parse_to_json() const noexcept
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
