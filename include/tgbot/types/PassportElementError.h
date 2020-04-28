#ifndef TGBOT_TYPES_PASSPORTELEMENTERROR_H
#define TGBOT_TYPES_PASSPORTELEMENTERROR_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementError
	 */
	struct PassportElementError
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<PassportElementError> ptr;

		//Destructors
		virtual ~PassportElementError();

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}

#endif
