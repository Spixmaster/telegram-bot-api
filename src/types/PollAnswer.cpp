#include "tgbot/types/PollAnswer.h"
#include "tools/Tools.h"
#include <iostream>

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
			//assignments
			if(doc.HasMember("poll_id"))
				if(doc["poll_id"].IsString())
					poll_id = doc["poll_id"].GetString();
				else
					std::cerr << "Error: Field \"poll_id\" does not contain a string." << std::endl;

			if(doc.HasMember("user"))
				if(doc["user"].IsObject())
					user = std::make_shared<User>(tools::Tools::get_json_as_string(doc["user"]));
				else
					std::cerr << "Error: Field \"user\" does not contain a json object." << std::endl;

			if(doc.HasMember("option_ids"))
				if(doc["option_ids"].IsArray())
				{
					option_ids.resize(doc["option_ids"].GetArray().Size());

					for(std::size_t j = 0; j < doc["option_ids"].GetArray().Size(); ++j)
					{
						if(doc["option_ids"][j].IsInt())
							option_ids.at(j) = doc["option_ids"][j].GetInt();
						else
							std::cerr << "Error: Field \"option_ids\"'s json array's element is not an int." << std::endl;
					}
				}
				else
					std::cerr << "Error: Field \"option_ids\" does not contain a json array." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string PollAnswer::parse_to_json() const
	{
		std::string json = "{";

		//field poll_id
		json.append("\"poll_id\": \"" + poll_id + "\"");
		json.append(", ");

		//field user
		json.append("\"user\": " + user->parse_to_json());
		json.append(", ");

		//field option_ids
		std::string option_ids_cont = "[";
		for(std::size_t j = 0; j < option_ids.size(); ++j)
		{
			option_ids_cont.append(std::to_string(option_ids.at(j)));
			option_ids_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * option_ids and not option_ids_cont in condition as in that case we would destroy the json array
		 */
		if(option_ids.size() > 0)
		{
			//finish json array
			option_ids_cont.pop_back();
			option_ids_cont.pop_back();
		}
		option_ids_cont.append("]");

		json.append("\"option_ids\": " + option_ids_cont);

		json.append("}");

		return json;
	}
}
