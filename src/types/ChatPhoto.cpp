#include "tgbot/types/ChatPhoto.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	ChatPhoto::ChatPhoto() : small_file_id(), small_file_unique_id(), big_file_id(), big_file_unique_id()
	{}

	ChatPhoto::ChatPhoto(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("small_file_id"))
			{
				if(doc["small_file_id"].IsString())
					small_file_id = doc["small_file_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("small_file_id") << std::endl;
			}

			if(doc.HasMember("small_file_unique_id"))
			{
				if(doc["small_file_unique_id"].IsString())
					small_file_unique_id = doc["small_file_unique_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("small_file_unique_id") << std::endl;
			}

			if(doc.HasMember("big_file_id"))
			{
				if(doc["big_file_id"].IsString())
					big_file_id = doc["big_file_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("big_file_id") << std::endl;
			}

			if(doc.HasMember("big_file_unique_id"))
			{
				if(doc["big_file_unique_id"].IsString())
					big_file_id = doc["big_file_unique_id"].GetString();
				else
					std::cerr << Messages::field_does_not_contain_string("big_file_unique_id") << std::endl;
			}
		}
		else
			std::cerr << Messages::constructor_not_get_json_object << std::endl;
	}

	std::string ChatPhoto::parse_to_json() const noexcept
	{
		std::string json = "{";

		//field small_file_id
		json.append("\"small_file_id\": \"" + small_file_id + "\"");
		json.append(", ");

		//field small_file_unique_id
		json.append("\"small_file_unique_id\": \"" + small_file_unique_id + "\"");
		json.append(", ");

		//field big_file_id
		json.append("\"big_file_id\": \"" + big_file_id + "\"");
		json.append(", ");

		//field big_file_unique_id
		json.append("\"big_file_unique_id\": \"" + big_file_unique_id + "\"");

		json.append("}");

		return json;
	}
}
