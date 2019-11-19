#include "tgbot/types/UserProfilePhotos.h"
#include <iostream>
#include "tgbot/Tools.h"

namespace tgbot
{
	UserProfilePhotos::UserProfilePhotos() : total_count(), photos()
	{}

	UserProfilePhotos::UserProfilePhotos(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(Tools::is_json(json))
		{
			//assignments
			if(doc.HasMember("total_count"))
				total_count = doc["total_count"].GetInt();

			if(doc.HasMember("photos"))
			{
				/*
				 * photos are stored in an array a with multiple arrays b
				 * each array b represent one photo json object as the photo exists in several sizes
				 */
				const rapidjson::Value &json_photo_array = doc["photos"].GetArray();

				//iterate through all photos
				for(std::size_t j = 0; j < json_photo_array.Size(); ++j)
					//iterate through all PhotoSizes of one photo
					for(std::size_t k = 0; k < json_photo_array[j].GetArray().Size(); ++k)
						photos.push_back(std::make_shared<PhotoSize>(SpecialTools::get_json_as_string(json_photo_array[j][k])));
			}
		}
	}

	std::string UserProfilePhotos::parse_to_json() const
	{
		std::string json = "{";

		//field total_count
		json.append("\"total_count\": " + total_count);
		json.append(", ");

		//field photos
		std::string photos_cont = "[";
		for(std::size_t j = 0; j < photos.size(); ++j)
		{
			photos_cont.append(photos.at(j)->parse_to_json());
			photos_cont.append(", ");
		}

		/*
		 * if size() == 0 pop_back() would crash the programme
		 * photos and not photos_cont in condition as in that case we would destroy the json array
		 */
		if(photos.size() > 0)
		{
			//finish json array
			photos_cont.pop_back();
			photos_cont.pop_back();
		}
		photos_cont.append("]");

		json.append("\"photos\": \"" + photos_cont + "\"");

		json.append("}");

		return json;
	}
}
