#include "tgbot/types/GameHighScore.h"

namespace tgbot
{
	GameHighScore::GameHighScore() : position(), user(), score()
	{}

	GameHighScore::GameHighScore(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("position"))
			position = doc["position"].GetInt();

		if(doc.HasMember("user"))
			user = std::make_shared<User>(SpecialTools::get_json_obj_as_string(doc["user"]));

		if(doc.HasMember("score"))
			score = doc["score"].GetInt();
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
