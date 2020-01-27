#include "tgbot/types/Animation.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	Animation::Animation() : file_id(), file_unique_id(), width(), height(), duration(), thumb(), file_name(), mime_type(), file_size()
	{}

	Animation::Animation(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("file_id"))
			{
				if(doc["file_id"].IsString())
					file_id = doc["file_id"].GetString();
				else
					std::cerr << "Error: Field \"file_id\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("file_unique_id"))
			{
				if(doc["file_unique_id"].IsString())
					file_unique_id = doc["file_unique_id"].GetString();
				else
					std::cerr << "Error: Field \"file_unique_id\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("width"))
			{
				if(doc["width"].IsInt())
					width = doc["width"].GetInt();
				else
					std::cerr << "Error: Field \"width\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("height"))
			{
				if(doc["height"].IsInt())
					height = doc["height"].GetInt();
				else
					std::cerr << "Error: Field \"height\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("duration"))
			{
				if(doc["duration"].IsInt())
					duration = doc["duration"].GetInt();
				else
					std::cerr << "Error: Field \"duration\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("thumb"))
			{
				if(doc["thumb"].IsObject())
					thumb = std::make_shared<PhotoSize>(tools::Tools::get_json_as_string(doc["thumb"]));
				else
					std::cerr << "Error: Field \"thumb\" does not contain a json object." << std::endl;
			}

			if(doc.HasMember("file_name"))
			{
				if(doc["file_name"].IsString())
					file_name = doc["file_name"].GetString();
				else
					std::cerr << "Error: Field \"file_name\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("mime_type"))
			{
				if(doc["mime_type"].IsString())
					mime_type = doc["mime_type"].GetString();
				else
					std::cerr << "Error: Field \"mime_type\" does not contain a string." << std::endl;
			}

			if(doc.HasMember("file_size"))
			{
				if(doc["file_size"].IsInt())
					file_size = doc["file_size"].GetInt();
				else
					std::cerr << "Error: Field \"file_size\" does not contain an int." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string Animation::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//field file_unique_id
		json.append("\"file_unique_id\": \"" + file_unique_id + "\"");
		json.append(", ");

		//field width
		json.append("\"width\": " + width);
		json.append(", ");

		//field height
		json.append("\"height\": " + height);
		json.append(", ");

		//field duration
		json.append("\"duration\": " + duration);
		json.append(", ");

		//field thumb
		json.append("\"thumb\": " + thumb->parse_to_json());
		json.append(", ");

		//field file_name
		json.append("\"file_name\": \"" + file_name + "\"");
		json.append(", ");

		//field mime_type
		json.append("\"mime_type\": \"" + mime_type + "\"");
		json.append(", ");

		//field file_size
		json.append("\"file_size\": \"" + std::to_string(file_size) + "\"");

		json.append("}");

		return json;
	}
}
