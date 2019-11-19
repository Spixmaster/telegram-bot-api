#include "tgbot/types/ForceReply.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	ForceReply::ForceReply() : force_reply(), selective()
	{}

	ForceReply::ForceReply(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("force_reply"))
				force_reply = doc["force_reply"].GetBool();

			if(doc.HasMember("selective"))
				selective = doc["selective"].GetBool();
		}
	}

	std::string ForceReply::parse_to_json() const
	{
		std::string json = "{";

		//field force_reply
		std::string force_reply_bool = force_reply ? "true" : "false";
		json.append("\"force_reply\": " + force_reply_bool);
		json.append(", ");

		//field selective
		std::string selective_bool = selective ? "true" : "false";
		json.append("\"selective\": " + selective_bool);

		json.append("}");

		return json;
	}
}
