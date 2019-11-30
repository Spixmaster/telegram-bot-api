#include "tgbot/types/ChatPhoto.h"
#include "tools/Tools.h"

namespace tgbot
{
	ChatPhoto::ChatPhoto() : small_file_id(), big_file_id()
	{}

	ChatPhoto::ChatPhoto(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("small_file_id"))
				small_file_id = doc["small_file_id"].GetString();

			if(doc.HasMember("big_file_id"))
				big_file_id = doc["big_file_id"].GetString();
		}
	}

	std::string ChatPhoto::parse_to_json() const
	{
		std::string json = "{";

		//field small_file_id
		json.append("\"small_file_id\": \"" + small_file_id + "\"");
		json.append(", ");

		//field big_file_id
		json.append("\"big_file_id\": \"" + big_file_id + "\"");

		json.append("}");

		return json;
	}
}
