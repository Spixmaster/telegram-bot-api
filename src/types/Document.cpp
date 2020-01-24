#include "tgbot/types/Document.h"
#include "tools/Tools.h"
#include <iostream>

namespace tgbot
{
	Document::Document() : file_id(), thumb(), file_name(), mime_type(), file_size()
	{}

	Document::Document(const std::string &json)
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

			if(doc.HasMember("thumb"))
				if(doc["thumb"].IsObject())
					thumb = std::make_shared<PhotoSize>(tools::Tools::get_json_as_string(doc["thumb"]));
				else
					std::cerr << "Error: Field \"thumb\" does not contain a json object." << std::endl;
			else
				std::cerr << "Error: There is no field \"thumb\"." << std::endl;

			if(doc.HasMember("file_name"))
				if(doc["file_name"].IsString())
					file_name = doc["file_name"].GetString();
				else
					std::cerr << "Error: Field \"file_name\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"file_name\"." << std::endl;

			if(doc.HasMember("mime_type"))
				if(doc["mime_type"].IsString())
					mime_type = doc["mime_type"].GetString();
				else
					std::cerr << "Error: Field \"mime_type\" does not contain a string." << std::endl;
			else
				std::cerr << "Error: There is no field \"mime_type\"." << std::endl;

			if(doc.HasMember("file_size"))
				if(doc["file_size"].IsInt())
					file_size = doc["file_size"].GetInt();
				else
					std::cerr << "Error: Field \"file_size\" does not contain an int." << std::endl;
			else
				std::cerr << "Error: There is no field \"file_size\"." << std::endl;
		}
	}

	std::string Document::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
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
		json.append("\"file_size\": " + file_size);

		json.append("}");

		return json;
	}
}
