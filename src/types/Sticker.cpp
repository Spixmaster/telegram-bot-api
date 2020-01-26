#include "tgbot/types/Sticker.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	Sticker::Sticker() : file_id(), file_unique_id(), width(), height(), is_animated(), thumb(), emoji(), set_name(), mask_position(), file_size()
	{}

	Sticker::Sticker(const std::string &json)
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

			if(doc.HasMember("width"))
				if(doc["width"].IsInt())
					width = doc["width"].GetInt();
				else
					std::cerr << "Error: Field \"width\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"width\"." << std::endl;

			if(doc.HasMember("height"))
				if(doc["height"].IsInt())
					width = doc["height"].GetInt();
				else
					std::cerr << "Error: Field \"height\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"height\"." << std::endl;

			if(doc.HasMember("is_animated"))
				if(doc["is_animated"].IsBool())
					is_animated = doc["is_animated"].GetBool();
				else
					std::cerr << "Error: Field \"is_animated\" does not contain a bool." << std::endl;
			else
				std::cerr << "Error: There is no field \"is_animated\"." << std::endl;

			if(doc.HasMember("thumb"))
				if(doc["thumb"].IsObject())
					thumb = std::make_shared<PhotoSize>(tools::Tools::get_json_as_string(doc["thumb"]));
				else
					std::cerr << "Error: Field \"thumb\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"thumb\"." << std::endl;

			if(doc.HasMember("emoji"))
				if(doc["emoji"].IsString())
					emoji = doc["emoji"].GetString();
				else
					std::cerr << "Error: Field \"emoji\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"emoji\"." << std::endl;

			if(doc.HasMember("set_name"))
				if(doc["set_name"].IsString())
					file_id = doc["set_name"].GetString();
				else
					std::cerr << "Error: Field \"set_name\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"set_name\"." << std::endl;

			if(doc.HasMember("mask_position"))
				if(doc["mask_position"].IsObject())
					mask_position = std::make_shared<MaskPosition>(tools::Tools::get_json_as_string(doc["mask_position"]));
				else
					std::cerr << "Error: Field \"mask_position\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"mask_position\"." << std::endl;

			if(doc.HasMember("file_size"))
				if(doc["file_size"].IsInt())
					width = doc["file_size"].GetInt();
				else
					std::cerr << "Error: Field \"file_size\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"file_size\"." << std::endl;
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string Sticker::parse_to_json() const
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

		//field is_animated
		std::string is_animated_bool = is_animated ? "true" : "false";
		json.append("\"is_animated\": " + is_animated_bool);
		json.append(", ");

		//field thumb
		json.append("\"thumb\": " + thumb->parse_to_json());
		json.append(", ");

		//field emoji
		json.append("\"emoji\": \"" + emoji + "\"");
		json.append(", ");

		//field set_name
		json.append("\"set_name\": \"" + set_name + "\"");
		json.append(", ");

		//field mask_position
		json.append("\"mask_position\": " + mask_position->parse_to_json());
		json.append(", ");

		//field file_size
		json.append("\"file_size\": " + file_size);

		json.append("}");

		return json;
	}
}
