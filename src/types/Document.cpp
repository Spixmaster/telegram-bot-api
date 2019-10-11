#include "tgbot/types/Document.h"

namespace tgbot
{
	Document::Document() : file_id(), thumb(), file_name(), mime_type(), file_size()
	{}

	Document::Document(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		//assignments
		if(doc.HasMember("file_id"))
			file_id = doc["file_id"].GetString();

		if(doc.HasMember("thumb"))
			thumb = std::make_shared<PhotoSize>(special_tools::get_json_obj_as_string(doc["thumb"]));

		if(doc.HasMember("file_name"))
			file_name = doc["file_name"].GetString();

		if(doc.HasMember("mime_type"))
			mime_type = doc["mime_type"].GetString();

		if(doc.HasMember("file_size"))
			file_size = doc["file_size"].GetInt();
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
