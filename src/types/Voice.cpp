#include <rapidjson/document.h>
#include "tgbot/types/Voice.h"

namespace tgbot
{
	Voice::Voice() : file_id(), duration(), mime_type(), file_size()
	{}

	Voice::Voice(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("file_id"))
			file_id = doc["file_id"].GetString();

		if(doc.HasMember("duration"))
			duration = doc["duration"].GetInt();

		if(doc.HasMember("mime_type"))
			mime_type = doc["mime_type"].GetString();

		if(doc.HasMember("file_size"))
			file_size = doc["file_size"].GetInt();
	}

	std::string Voice::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//field duration
		json.append("\"duration\": " + duration);
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
