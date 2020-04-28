#ifndef TGBOT_TYPES_USERPROFILEPHOTOS_H
#define TGBOT_TYPES_USERPROFILEPHOTOS_H

#include "tgbot/types/PhotoSize.h"
#include <vector>
#include <memory>

namespace tgbot
{
	/**
	 * @struct UserProfilePhotos
	 */
	struct UserProfilePhotos
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<UserProfilePhotos> ptr;

		//Member variables
		int total_count = -1;
		std::vector<PhotoSize::ptr> photos;

		//Constructors
		UserProfilePhotos();

		//@param json: json object of UserProfilePhotos
		UserProfilePhotos(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
