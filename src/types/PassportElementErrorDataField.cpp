#include "tgbot/types/PassportElementErrorDataField.h"
#include "tgbot/Tools.h"

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
				source = doc["source"].GetString();

			if(doc.HasMember("type"))
				type = doc["type"].GetString();

			if(doc.HasMember("field_name"))
				field_name = doc["field_name"].GetString();

			if(doc.HasMember("data_hash"))
				data_hash = doc["data_hash"].GetString();

			if(doc.HasMember("message"))
				message = doc["message"].GetString();
		}
	}

	std::string PassportElementErrorDataField::parse_to_json() const
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
