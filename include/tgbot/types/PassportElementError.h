#ifndef TGBOT_TYPES_PASSPORTELEMENTERROR_H
#define TGBOT_TYPES_PASSPORTELEMENTERROR_H

#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct PassportElementError
	{
		//pointer of itself
		typedef std::shared_ptr<PassportElementError> ptr;

		//destructors
		virtual ~PassportElementError();

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		virtual std::string parse_to_json() const;
	};
}

#endif
