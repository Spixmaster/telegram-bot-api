#include "tgbot/types/Audio.h"

namespace tgbot
{
	Audio::Audio(): file_id(), duration(), performer(), title(), mime_type(), file_size(), thumb()
	{}

	Audio::Audio(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("file_id"))
			file_id = doc["file_id"].GetString();

		if(doc.HasMember("duration"))
			duration = doc["duration"].GetInt();

		if(doc.HasMember("performer"))
			performer = doc["performer"].GetString();

		if(doc.HasMember("title"))
			title = doc["title"].GetString();

		if(doc.HasMember("mime_type"))
			mime_type = doc["mime_type"].GetString();

		if(doc.HasMember("file_size"))
			file_size = doc["file_size"].GetInt();

		if(doc.HasMember("thumb"))
			thumb = std::make_shared<PhotoSize>(special_tools::get_json_obj_as_string(doc["thumb"]));
	}

	std::string Audio::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
		json.append(", ");

		//field duration
		json.append("\"duration\": " + duration);
		json.append(", ");

		//field performer
		json.append("\"performer\": \"" + performer + "\"");
		json.append(", ");

		//field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//field mime_type
		json.append("\"mime_type\": \"" + mime_type + "\"");
		json.append(", ");

		//field file_size
		json.append("\"file_size\": " + file_size);
		json.append(", ");

		//field thumb
		json.append("\"thumb\": " + thumb->parse_to_json());

		json.append("}");

		return json;
	}
}
