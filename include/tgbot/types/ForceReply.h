#ifndef TGBOT_TYPES_FORCEREPLY_H
#define TGBOT_TYPES_FORCEREPLY_H

#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	/**
	 * @struct ForceReply
	 */
	struct ForceReply : public Reply
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<ForceReply> ptr;

		//Member variables
		/**
		 * @var
		 */
		bool force_reply = true;
		/**
		 * @var
		 */
		bool selective = false;

		//Constructors
		ForceReply();

		//@param json: json object of ForceReply
		ForceReply(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
