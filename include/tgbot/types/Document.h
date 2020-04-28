#ifndef TGBOT_TYPES_DOCUMENT_H
#define TGBOT_TYPES_DOCUMENT_H

#include <string>
#include "tgbot/types/PhotoSize.h"
#include <memory>

namespace tgbot
{
	/**
	 * @struct Document
	 */
	struct Document
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Document> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string file_id;
		/**
		 * @var
		 */
		std::string file_unique_id;
		/**
		 * @var
		 */
		PhotoSize::ptr thumb;
		/**
		 * @var
		 */
		std::string file_name;
		/**
		 * @var
		 */
		std::string mime_type;
		/**
		 * @var
		 */
		int file_size = -1;

		//Constructors
		Document();

		//@param json: json object of Document
		Document(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
