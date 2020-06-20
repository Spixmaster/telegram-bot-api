#include "tgbot/types/PollAnswer.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	PollAnswer::PollAnswer() : poll_id(), user(), option_ids()
	{}

	PollAnswer::PollAnswer(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("poll_id"))
			{
				if(doc["poll_id"].IsString())
					poll_id = doc["poll_id"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("poll_id"));
			}

			if(doc.HasMember("user"))
			{
				if(doc["user"].IsObject())
					user = std::make_shared<User>(tools::Tools::get_json_as_string(doc["user"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("user"));
			}

			if(doc.HasMember("option_ids"))
			{
				if(doc["option_ids"].IsArray())
				{
					for(std::size_t j = 0; j < doc["option_ids"].GetArray().Size(); ++j)
					{
						if(doc["option_ids"][j].IsInt())
							option_ids.push_back(doc["option_ids"][j].GetInt());
						else
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_int("option_ids"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("option_ids"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string PollAnswer::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field poll_id
		json.append("\"poll_id\": \"" + poll_id + "\"");
		json.append(", ");

		//Field user
		json.append("\"user\": " + user->parse_to_json());
		json.append(", ");

		//Field option_ids
		std::string option_ids_cont = "[";

		for(std::size_t j = 0; j < option_ids.size(); ++j)
		{
			option_ids_cont.append(std::to_string(option_ids.at(j)));

			if(j != option_ids.size() - 1)
				option_ids_cont.append(", ");
		}

		option_ids_cont.append("]");

		json.append("\"option_ids\": " + option_ids_cont);

		json.append("}");
		return json;
	}
}
