#ifndef TYPES_INPUTMEDIA_H
#define TYPES_INPUTMEDIA_H

#include <memory>

namespace tgbot
{
	struct InputMedia
	{
		//pointer of itself
		typedef std::shared_ptr<InputMedia> ptr;

		//destructors
		virtual ~InputMedia();

		//member functions

		/*
		 * @brief parses itself into json equivalent
		 * @return json object of the itself as a string
		 */
		virtual std::string parse_to_json() const;
	};
}


#endif
