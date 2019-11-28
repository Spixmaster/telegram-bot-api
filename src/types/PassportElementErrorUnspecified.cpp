#include "tgbot/types/PassportElementErrorUnspecified.h"
#include "tgbot/Tools.h"

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
				source = doc["source"].GetString();

			if(doc.HasMember("type"))
				type = doc["type"].GetString();

			if(doc.HasMember("element_hash"))
				element_hash = doc["element_hash"].GetString();

			if(doc.HasMember("message"))
				message = doc["message"].GetString();
		}
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
