#include <tgbot/SpecialTools.h>
#include "tgbot/types/Sticker.h"
#include "tgbot/Tools.h"

namespace tgbot
{
	Sticker::Sticker() : file_id(), width(), height(), is_animated(), thumb(), emoji(), set_name(), mask_position(), file_size()
	{}

	Sticker::Sticker(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//assignments
			if(doc.HasMember("file_id"))
				file_id = doc["file_id"].GetString();

			if(doc.HasMember("width"))
				width = doc["width"].GetInt();

			if(doc.HasMember("height"))
				height = doc["height"].GetInt();

			if(doc.HasMember("is_animated"))
				is_animated = doc["is_animated"].GetBool();

			if(doc.HasMember("thumb"))
				thumb = std::make_shared<PhotoSize>(SpecialTools::get_json_as_string(doc["thumb"]));

			if(doc.HasMember("emoji"))
				emoji = doc["emoji"].GetString();

			if(doc.HasMember("set_name"))
				set_name = doc["set_name"].GetString();

			if(doc.HasMember("mask_position"))
				mask_position = std::make_shared<MaskPosition>(SpecialTools::get_json_as_string(doc["mask_position"]));

			if(doc.HasMember("file_size"))
				file_size = doc["file_size"].GetInt();
		}
	}

	std::string Sticker::parse_to_json() const
	{
		std::string json = "{";

		//field file_id
		json.append("\"file_id\": \"" + file_id + "\"");
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
