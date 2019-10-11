#ifndef TYPES_FORCEREPLY_H
#define TYPES_FORCEREPLY_H

#include <rapidjson/document.h>
#include <memory>
#include "tgbot/types/Reply.h"

namespace tgbot
{
	struct ForceReply : public Reply
	{
		//pointer of itself
		typedef std::shared_ptr<ForceReply> ptr;

		//member variables
		bool force_reply = true;
		bool selective = false;

		//constructors
		ForceReply();

		//@param json: json object of ForceReply
		ForceReply(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
