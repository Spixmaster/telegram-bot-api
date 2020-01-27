#include "tgbot/types/PhotoSize.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	PhotoSize::PhotoSize() : file_id(), file_unique_id(), width(), height(), file_size()
	{}

	PhotoSize::PhotoSize(const std::string &json)
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
					width = doc["height"].GetInt();
				else
					std::cerr << "Error: Field \"height\" does not contain an int." << std::endl;
			}

			if(doc.HasMember("file_size"))
			{
				if(doc["file_size"].IsInt())
					width = doc["file_size"].GetInt();
				else
					std::cerr << "Error: Field \"file_size\" does not contain an int." << std::endl;
			}
		}
		else
			std::cerr << "Error: The to the constructor passed string is not a json object." << std::endl;
	}

	std::string PhotoSize::parse_to_json() const
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

		//field file_size
		json.append("\"file_size\": " + file_size);

		json.append("}");

		return json;
	}
}
