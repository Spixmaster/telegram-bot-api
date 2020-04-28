#ifndef TGBOT_TYPES_MARKPOSITION_H
#define TGBOT_TYPES_MARKPOSITION_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct MaskPosition
	 */
	struct MaskPosition
	{
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<MaskPosition> ptr;

		//Member variables
		/**
		 * @var
		 */
		std::string point;
		/**
		 * @var
		 */
		float x_shift = -1;
		/**
		 * @var
		 */
		float y_shift = -1;
		/**
		 * @var
		 */
		float scale = -1;

		//Constructors
		MaskPosition();

		//@param json: json object of MaskPosition
		MaskPosition(const std::string &json);

		//Member functions
		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
