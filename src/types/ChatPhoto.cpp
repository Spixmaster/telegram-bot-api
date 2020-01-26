#include "tgbot/types/ChatPhoto.h"
#include "tools/Tools.h"
#include <iostream>

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
				if(doc["small_file_id"].IsString())
					small_file_id = doc["small_file_id"].GetString();
				else
					std::cerr << "Error: Field \"small_file_id\" does not contain a string." << std::endl;

			if(doc.HasMember("small_file_unique_id"))
				if(doc["small_file_unique_id"].IsString())
					small_file_unique_id = doc["small_file_unique_id"].GetString();
				else
					std::cerr << "Error: Field \"small_file_unique_id\" does not contain a string." << std::endl;

			if(doc.HasMember("big_file_id"))
				if(doc["big_file_id"].IsString())
					big_file_id = doc["big_file_id"].GetString();
				else
					std::cerr << "Error: Field \"big_file_id\" does not contain a string." << std::endl;

			if(doc.HasMember("big_file_unique_id"))
				if(doc["big_file_unique_id"].IsString())
					big_file_id = doc["big_file_unique_id"].GetString();
				else
					std::cerr << "Error: Field \"big_file_unique_id\" does not contain a string." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string ChatPhoto::parse_to_json() const
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
