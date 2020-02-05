#include "tgbot/types/PassportElementErrorDataField.h"
#include "tools/Tools.h"
#include <iostream>

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
					std::cerr << "Error: Field \"source\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("type"))
			{
				if(doc["type"].IsString())
					type = doc["type"].GetString();
				else
					std::cerr << "Error: Field \"type\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("field_name"))
			{
				if(doc["field_name"].IsString())
					field_name = doc["field_name"].GetString();
				else
					std::cerr << "Error: Field \"field_name\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("data_hash"))
			{
				if(doc["data_hash"].IsString())
					data_hash = doc["data_hash"].GetString();
				else
					std::cerr << "Error: Field \"data_hash\" does not contain a string." << std::endl;
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
