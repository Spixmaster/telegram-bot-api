#ifndef TGBOT_TYPES_DOCUMENT_H
#define TGBOT_TYPES_DOCUMENT_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <memory>

//@brief represents on object in the Telegram bot api

namespace tgbot
{
	struct Document
	{
		//pointer of itself
		typedef std::shared_ptr<Document> ptr;

		//member variables
		std::string file_id;
		PhotoSize::ptr thumb;
		std::string file_name;
		std::string mime_type;
		int file_size = -1;

		//constructors
		Document();

		//@param json: json object of Document
		Document(const std::string &json);

		//member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
