#ifndef TGBOT_TYPES_USERPROFILEPHOTOS_H
#define TGBOT_TYPES_USERPROFILEPHOTOS_H

#include "tgbot/types/PhotoSize.h"
#include <vector>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct UserProfilePhotos
	{
		//pointer of itself
		typedef std::shared_ptr<UserProfilePhotos> ptr;

		//member variables
		int total_count = -1;
		std::vector<PhotoSize::ptr> photos;

		//constructors
		UserProfilePhotos();

		//@param json: json object of UserProfilePhotos
		UserProfilePhotos(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
