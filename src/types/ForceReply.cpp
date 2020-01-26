#include "tgbot/types/ForceReply.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	ForceReply::ForceReply() : force_reply(), selective()
	{}

	ForceReply::ForceReply(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("force_reply"))
				if(doc["force_reply"].IsBool())
					force_reply = doc["force_reply"].GetBool();
				else
					std::cerr << "Error: Field \"force_reply\" does not contain a bool." << std::endl;

			if(doc.HasMember("selective"))
				if(doc["selective"].IsBool())
					selective = doc["selective"].GetBool();
				else
					std::cerr << "Error: Field \"selective\" does not contain a bool." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
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
