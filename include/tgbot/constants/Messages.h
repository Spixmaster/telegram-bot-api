#ifndef TGBOT_CONSTANTS_MESSAGES_H
#define TGBOT_CONSTANTS_MESSAGES_H

#include <string>
#include <memory>

namespace tgbot
{
	/**
	 * @class Messages
	 * @brief The class contains messages which are used throughout the programme.
	 * @details It is a monostate.
	 */
	class Messages
	{
	public:
		//Pointer of itself
		/**
		 * @var ptr
		 * @brief A pointer of itself.
		 */
		typedef std::shared_ptr<Messages> ptr;

		//Member variables
		/**
		 * @var constructor_not_get_json_object
		 * @brief A message that states that the constructor did not get a JSON object.
		 */
		static const std::string constructor_not_get_json_object;
		/**
		 * @var server_resp_not_json_object
		 * @brief A message that states that the server response is not a JSON object.
		 */
		static const std::string server_resp_not_json_object;

		//Member functions
		/**
		 * @brief Creates a message that the field does not contain a string.
		 * @param[in] field The field which does not contain a string.
		 * @return The message.
		 */
		static std::string field_does_not_contain_string(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field does not contain an integer.
		 * @param[in] field The field which does not contain an integer.
		 * @return The message.
		 */
		static std::string field_does_not_contain_int(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field does not contain a 64 bits integer.
		 * @param[in] field The field which does not contain a 64 bits integer.
		 * @return The message.
		 */
		static std::string field_does_not_contain_int64(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field does not contain a JSON object.
		 * @param[in] field The field which does not contain a JSON object.
		 * @return The message.
		 */
		static std::string field_does_not_contain_json_obj(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field does not contain a JSON array.
		 * @param[in] field The field which does not contain a JSON array.
		 * @return The message.
		 */
		static std::string field_does_not_contain_json_arr(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field's elements does not contain a JSON array.
		 * @param[in] field The field whose element does not contain a JSON array.
		 * @return The message.
		 */
		static std::string field_element_does_not_contain_json_arr(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field's elements does not contain a JSON object.
		 * @param[in] field The field whose element does not contain a JSON object.
		 * @return The message.
		 */
		static std::string field_element_does_not_contain_json_obj(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field does not exist.
		 * @param[in] field The field that does not exist.
		 * @return The message.
		 */
		static std::string field_non_existent(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field does not contain a boolean.
		 * @param[in] field The field which does not contain a boolean-
		 * @return The message.
		 */
		static std::string field_does_not_contain_bool(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field does not contain a float-
		 * @param[in] field The field which does not contain a float.
		 * @return The message.
		 */
		static std::string field_does_not_contain_float(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field's element's element does not contain a JSON object.
		 * @param[in] field The field whose element's element does not contain a JSON object.
		 * @return The message.
		 */
		static std::string field_element_element_does_not_contain_json_obj(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field's elements does not contain a string.
		 * @param[in] field The field whose element does not contain a string.
		 * @return The message.
		 */
		static std::string field_element_does_not_contain_string(const std::string &field) noexcept;

		/**
		 * @brief Creates a message that the field's elements does not contain an integer.
		 * @param[in] field The field whose element does not contain an integer.
		 * @return The message.
		 */
		static std::string field_element_does_not_contain_int(const std::string &field) noexcept;
	};
}

#endif
