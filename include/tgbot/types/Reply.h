#ifndef TYPES_REPLY_H
#define TYPES_REPLY_H

#include <memory>

namespace tgbot
{
	struct Reply
	{
		//pointer of itself
		typedef std::shared_ptr<Reply> ptr;

		//destructor
		virtual ~Reply();

		//member functions
		virtual std::string parse_to_json();
	};
}

#endif
