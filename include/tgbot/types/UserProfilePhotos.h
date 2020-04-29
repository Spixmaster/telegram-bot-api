#ifndef TGBOT_TYPES_USERPROFILEPHOTOS_H
#define TGBOT_TYPES_USERPROFILEPHOTOS_H

#include "tgbot/types/PhotoSize.h"
#include <vector>
#include <memory>

namespace tgbot
{
	/**
	 * @struct UserProfilePhotos
	 * @brief This object represent a user's profile pictures.
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
		/**
		 * @var total_count
		 * @brief Total number of profile pictures the target user has
		 */
		int total_count;
		/**
		 * @var photos
		 * @brief Requested profile pictures (in up to 4 sizes each)
		 */
		std::vector<PhotoSize::ptr> photos;

		//Constructors
		UserProfilePhotos();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		UserProfilePhotos(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
