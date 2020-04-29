#include "tgbot/types/StickerSet.h"
#include "tools/Tools.h"
#include <iostream>
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	StickerSet::StickerSet() : name(), title(), is_animated(), contains_masks(), sticker(), thumb()
	{}

	StickerSet::StickerSet(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("name"))
			{
				if(doc["name"].IsString())
					name = doc["name"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("name"));
			}

			if(doc.HasMember("title"))
			{
				if(doc["title"].IsString())
					title = doc["title"].GetString();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_string("title"));
			}

			if(doc.HasMember("is_animated"))
			{
				if(doc["is_animated"].IsBool())
					is_animated = doc["is_animated"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("is_animated"));
			}

			if(doc.HasMember("contains_masks"))
			{
				if(doc["contains_masks"].IsBool())
					contains_masks = doc["contains_masks"].GetBool();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_bool("contains_masks"));
			}

			if(doc.HasMember("sticker"))
			{
				if(doc["sticker"].IsArray())
				{
					sticker.resize(doc["sticker"].GetArray().Size());

					for(std::size_t j = 0; j < doc["sticker"].GetArray().Size(); ++j)
					{
						if(doc["sticker"][j].IsObject())
							sticker.at(j) = std::make_shared<Sticker>(tools::Tools::get_json_as_string(doc["sticker"][j]));
						else
							tools::Tools::write_err_log(Messages::field_element_does_not_contain_json_obj("sticker"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("sticker"));
			}

			if(doc.HasMember("thumb"))
			{
				if(doc["thumb"].IsObject())
					thumb = std::make_shared<PhotoSize>(tools::Tools::get_json_as_string(doc["thumb"]));
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_obj("thumb"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string StickerSet::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field name
		json.append("\"name\": \"" + name + "\"");
		json.append(", ");

		//Field title
		json.append("\"title\": \"" + title + "\"");
		json.append(", ");

		//Field is_animated
		std::string is_animated_bool = is_animated ? "true" : "false";
		json.append("\"is_animated\": " + is_animated_bool);
		json.append(", ");

		//Field contains_masks
		std::string contains_masks_bool = contains_masks ? "true" : "false";
		json.append("\"contains_masks\": " + contains_masks_bool);
		json.append(", ");

		//Field sticker
		std::string sticker_cont = "[";

		for(std::size_t j = 0; j < sticker.size(); ++j)
		{
			sticker_cont.append(sticker.at(j)->parse_to_json());

			if(j != sticker.size() - 1)
				sticker_cont.append(", ");
		}

		sticker_cont.append("]");

		json.append("\"sticker\": \"" + sticker_cont + "\"");
		json.append(", ");

		//Field thumb
		json.append("\"thumb\": " + thumb->parse_to_json());

		json.append("}");
		return json;
	}
}
