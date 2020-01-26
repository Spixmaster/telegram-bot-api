#include "tgbot/types/File.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	File::File() : file_id(), file_unique_id(), file_size(), file_path()
	{}

	File::File(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("file_id"))
				if(doc["file_id"].IsString())
					file_id = doc["file_id"].GetString();
				else
					std::cerr << "Error: Field \"file_id\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"file_id\"." << std::endl;

			if(doc.HasMember("file_unique_id"))
				if(doc["file_unique_id"].IsString())
					file_unique_id = doc["file_unique_id"].GetString();
				else
					std::cerr << "Error: Field \"file_unique_id\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"file_unique_id\"." << std::endl;

			if(doc.HasMember("file_size"))
				if(doc["file_size"].IsInt())
					file_size = doc["file_size"].GetInt();
				else
					std::cerr << "Error: Field \"file_size\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"file_size\"." << std::endl;

			if(doc.HasMember("file_path"))
				if(doc["file_path"].IsString())
					file_path = doc["file_path"].GetString();
				else
					std::cerr << "Error: Field \"file_path\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"file_path\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string File::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//field file_unique_id
		json.append("\"file_unique_id\": \"" + file_unique_id + "\"");
		json.append(", ");

		//field file_size
		json.append("\"file_size\": " + file_size);
		json.append(", ");

		//field file_path
		json.append("\"file_path\": \"" + file_path + "\"");

		json.append("}");

		return json;
	}
}
