#ifndef TGBOT_TYPES_INPUTMEDIA_H
#define TGBOT_TYPES_INPUTMEDIA_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct InputMedia
	 * @brief This object represents the content of a media message to be sent. It should be one of
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
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}


#endif
