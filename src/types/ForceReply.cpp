#include "tgbot/types/ForceReply.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

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
			//Assignments
			if(doc.HasMember("force_reply"))
			{
				if(doc["force_reply"].IsBool())
					force_reply = doc["force_reply"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("force_reply"));
			}

			if(doc.HasMember("selective"))
			{
				if(doc["selective"].IsBool())
					selective = doc["selective"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("selective"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string ForceReply::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field force_reply
		std::string force_reply_bool = force_reply ? "true" : "false";
		json.append("\"force_reply\": " + force_reply_bool);
		json.append(", ");

		//Field selective
		std::string selective_bool = selective ? "true" : "false";
		json.append("\"selective\": " + selective_bool);

		json.append("}");
		return json;
	}
}
