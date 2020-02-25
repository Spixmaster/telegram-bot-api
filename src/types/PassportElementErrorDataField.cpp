#include "tgbot/types/PassportElementErrorDataField.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	PassportElementErrorDataField::PassportElementErrorDataField() : source(), type(), field_name(), data_hash(), message()
	{}

	PassportElementErrorDataField::PassportElementErrorDataField(const std::string &json)
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

			if(doc.HasMember("field_name"))
			{
				if(doc["field_name"].IsString())
					field_name = doc["field_name"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("field_name") << std::endl;
			}

			if(doc.HasMember("data_hash"))
			{
				if(doc["data_hash"].IsString())
					data_hash = doc["data_hash"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("data_hash") << std::endl;
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

	std::string PassportElementErrorDataField::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field source
		json.append("\"source\": \"" + source + "\"");
		json.append(", ");

		//field type
		json.append("\"type\": \"" + type + "\"");
		json.append(", ");

		//field field_name
		json.append("\"field_name\": \"" + field_name + "\"");
		json.append(", ");

		//field data_hash
		json.append("\"data_hash\": \"" + data_hash + "\"");
		json.append(", ");

		//field message
		json.append("\"message\": \"" + message + "\"");

		json.append("}");

		return json;
	}
}
