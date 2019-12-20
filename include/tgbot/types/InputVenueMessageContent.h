#ifndef TGBOT_TYPES_INPUTVENUEMESSAGECONTENT_H
#define TGBOT_TYPES_INPUTVENUEMESSAGECONTENT_H

#include <string>
#include "tgbot/types/InputMessageContent.h"
#include <rapidjson/document.h>
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct InputVenueMessageContent : public InputMessageContent
	{
		//pointer of itself
		typedef std::shared_ptr<InputVenueMessageContent> ptr;

		//member variables
		float latitude = -1;
		float longitude = -1;
		std::string title;
		std::string address;
		std::string foursquare_id;
		std::string foursquare_type;

		//constructors
		InputVenueMessageContent();

		//@param json: json object of InputVenueMessageContent
		InputVenueMessageContent(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
