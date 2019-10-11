#ifndef TGBOT_TYPES_MARKPOSITION_H
#define TGBOT_TYPES_MARKPOSITION_H

#include <string>
#include <memory>

namespace tgbot
{
	struct MaskPosition
	{
		//pointer of itself
		typedef std::shared_ptr<MaskPosition> ptr;

		//member variables
		std::string point;
		float x_shift = -1;
		float y_shift = -1;
		float number = -1;

		//constructors
		MaskPosition();

		//@param json: json object of MaskPosition
		MaskPosition(const std::string &json);

		//member functions

		/*
		 * @brief converts a itself into a json object
		 * @return the json object as a string
		 */
		std::string parse_to_json() const;
	};
}

#endif
