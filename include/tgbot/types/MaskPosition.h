#ifndef TGBOT_TYPES_MARKPOSITION_H
#define TGBOT_TYPES_MARKPOSITION_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @struct MaskPosition
	 * @brief This object describes the position on faces where a mask should be placed by default.
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
		 * @var point
		 * @brief The part of the face relative to which the mask should be placed. One of “forehead”, “eyes”, “mouth”, or “chin”.
		 */
		std::string point;
		/**
		 * @var x_shift
		 * @brief Shift by X-axis measured in widths of the mask scaled to the face size, from left to right.
		 * @details For example, choosing -1.0 will place mask just to the left of the default mask position.
		 */
		float x_shift = -1;
		/**
		 * @var y_shift
		 * @brief Shift by Y-axis measured in heights of the mask scaled to the face size, from top to bottom.
		 * @details For example, 1.0 will place the mask just below the default mask position.
		 */
		float y_shift = -1;
		/**
		 * @var scale
		 * @brief Mask scaling coefficient.
		 * @details For example, 2.0 means double size.
		 */
		float scale = -1;

		//Constructors
		MaskPosition();

		/**
		 * @param[in] json The proper JSON object from which this struct is constructed.
		 */
		MaskPosition(const std::string &json);

		//Member functions
		/**
		 * @brief Converts itself into a JSON object.
		 * @return The JSON object.
		 */
		std::string parse_to_json() const noexcept;
	};
}

#endif
