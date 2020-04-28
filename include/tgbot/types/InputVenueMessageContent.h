#ifndef TGBOT_TYPES_INPUTVENUEMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTVENUEMESSAGECONTENT_H

#include <string>
#include "tgbot/types/InputMessageContent.h"
#include <rapidjson/document.h>
#include <memory>

namespace tgbot
{
	/**
	 * @struct InputVenueMessageContent
	 */
	struct InputVenueMessageContent : public InputMessageContent
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputVenueMessageContent> ptr;

		//Member variables
		/**
		 * @var
		 */
		float latitude = -1;
		/**
		 * @var
		 */
		float longitude = -1;
		/**
		 * @var
		 */
		std::string title;
		/**
		 * @var
		 */
		std::string address;
		/**
		 * @var
		 */
		std::string foursquare_id;
		/**
		 * @var
		 */
		std::string foursquare_type;

		//Constructors
		InputVenueMessageContent();

		//@param json: json object of InputVenueMessageContent
		InputVenueMessageContent(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
