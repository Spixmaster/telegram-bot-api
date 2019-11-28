#include "tgbot/types/ResponseParameters.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	ResponseParameters::ResponseParameters() : migrate_to_chat_id(), retry_after()
	{}

	ResponseParameters::ResponseParameters(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("migrate_to_chat_id"))
				migrate_to_chat_id = doc["migrate_to_chat_id"].GetInt();

			if(doc.HasMember("retry_after"))
				retry_after = doc["retry_after"].GetInt();
		}
	}

	std::string ResponseParameters::parse_to_json() const
	{
		std::string json = "{";

		//field migrate_to_chat_id
		json.append("\"migrate_to_chat_id\": " + migrate_to_chat_id);
		json.append(", ");

		//field retry_after
		json.append("\"retry_after\": " + retry_after);

		json.append("}");

		return json;
	}
}
