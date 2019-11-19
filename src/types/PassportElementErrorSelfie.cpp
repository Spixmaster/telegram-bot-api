#include "tgbot/types/PassportElementErrorSelfie.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	PassportElementErrorSelfie::PassportElementErrorSelfie() : source(), type(), file_hash(), message()
	{}

	PassportElementErrorSelfie::PassportElementErrorSelfie(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("source"))
				source = doc["source"].GetString();

			if(doc.HasMember("type"))
				type = doc["type"].GetString();

			if(doc.HasMember("file_hash"))
				file_hash = doc["file_hash"].GetString();

			if(doc.HasMember("message"))
				message = doc["message"].GetString();
		}
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
