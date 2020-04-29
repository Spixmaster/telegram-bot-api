#ifndef TGBOT_TYPES_PASSPORTELEMENTERROR_H
#define TGBOT_TYPES_PASSPORTELEMENTERROR_H

#include <memory>

namespace tgbot
{
	/**
	 * @struct PassportElementError
	 * @brief The super class of all passport element errors.
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
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		virtual std::string parse_to_json() const noexcept;
	};
}

#endif
