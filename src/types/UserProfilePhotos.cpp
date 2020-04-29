#include "tgbot/types/UserProfilePhotos.h"
#include <iostream>
#include "tools/Tools.h"
#include "tgbot/constants/Messages.h"

namespace tgbot
{
	UserProfilePhotos::UserProfilePhotos() : total_count(), photos()
	{}

	UserProfilePhotos::UserProfilePhotos(const std::string &json)
	{
		rapidjson::Document doc;
		doc.Parse(json.c_str());

		if(doc.IsObject())
		{
			//Assignments
			if(doc.HasMember("total_count"))
			{
				if(doc["total_count"].IsInt())
					total_count = doc["total_count"].GetInt();
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_int("total_count"));
			}

			if(doc.HasMember("photos"))
			{
				/*
				 * photos are stored in an array a with multiple arrays b
				 * each array b represent one photo json object as the photo exists in several sizes
				 */
				if(doc["photos"].IsArray())
				{
					const rapidjson::Value &json_photo_array = doc["photos"].GetArray();

					//iterate through all photos
					for(std::size_t j = 0; j < json_photo_array.Size(); ++j)
					{
						if(json_photo_array[j].IsArray())
						{
							//iterate through all PhotoSizes of one photo
							for(std::size_t k = 0; k < json_photo_array[j].GetArray().Size(); ++k)
							{
								if(doc["photos"][j][k].IsObject())
									photos.push_back(std::make_shared<PhotoSize>(tools::Tools::get_json_as_string(json_photo_array[j][k])));
								else
									tools::Tools::write_err_log(Messages::field_element_element_does_not_contain_json_obj("photos"));
							}
						}
						else
							tools::Tools::write_err_log(Messages::Messages::field_element_does_not_contain_json_arr("photos"));
					}
				}
				else
					tools::Tools::write_err_log(Messages::field_does_not_contain_json_arr("photos"));
			}
		}
		else
			tools::Tools::write_err_log(Messages::constructor_not_get_json_object);
	}

	std::string UserProfilePhotos::parse_to_json() const noexcept
	{
		std::string json = "{";

		//Field total_count
		json.append("\"total_count\": " + total_count);
		json.append(", ");

		//Field photos
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
