#include "tgbot/types/GameHighScore.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	GameHighScore::GameHighScore() : position(), user(), score()
	{}

	GameHighScore::GameHighScore(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("position"))
				if(doc["position"].IsInt())
					position = doc["position"].GetInt();
				else
					std::cerr << "Error: Field \"position\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"position\"." << std::endl;

			if(doc.HasMember("user"))
				if(doc["user"].IsObject())
					user = std::make_shared<User>(tools::Tools::get_json_as_string(doc["user"]));
				else
					std::cerr << "Error: Field \"user\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"user\"." << std::endl;

			if(doc.HasMember("score"))
				if(doc["score"].IsInt())
					score = doc["score"].GetInt();
				else
					std::cerr << "Error: Field \"score\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"score\"." << std::endl;
		}
	}

	std::string GameHighScore::parse_to_json() const
	{
		std::string json = "{";

		//field position
		json.append("\"position\": " + position);
		json.append(", ");

		//field user
		json.append("\"user\": " + user->parse_to_json());
		json.append(", ");

		//field score
		json.append("\"score\": " + score);
		json.append(", ");

		json.append("}");

		return json;
	}
}
