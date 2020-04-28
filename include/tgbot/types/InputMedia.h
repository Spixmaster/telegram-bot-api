#ifndef TGBOT_TYPES_INPUTMEDIA_H
#define TGBOT_TYPES_INPUTMEDIA_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct InputMedia
	 */
	struct InputMedia
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<InputMedia> ptr;

		//Destructors
		virtual ~InputMedia();

		//Member functions
		/*
		 * @brief parses itself into json equivalent
		 * @return json object of the itself as a string
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}


#endif
