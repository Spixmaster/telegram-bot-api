#ifndef TGBOT_CONSTANTS_MESSAGES_H
#define TGBOT_CONSTANTS_MESSAGES_H

#include <string>
#include <memory>

/*
 * @brief class contains messages which are used throughout the programme
 * @brief it is a monostate
 */

namespace tgbot
{
	class Messages
	{
	public:
		//pointer of itself
		typedef std::shared_ptr<Messages> ptr;

		//member variables
		static const std::string constructor_not_get_json_object;
		static const std::string server_resp_not_json_object;

		//member functions
		/*
		 * @brief creates message that the field does not contain a string
		 * @param field: field which does not contain a string
		 * @return the message
		 */
		static std::string field_does_not_contain_string(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field does not contain an int
		 * @param field: field which does not contain an int
		 * @return the message
		 */
		static std::string field_does_not_contain_int(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field does not contain an int64
		 * @param field: field which does not contain an int64
		 * @return the message
		 */
		static std::string field_does_not_contain_int64(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field does not contain a json object
		 * @param field: field which does not contain a json object
		 * @return the message
		 */
		static std::string field_does_not_contain_json_obj(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field does not contain a json array
		 * @param field: field which does not contain a json array
		 * @return the message
		 */
		static std::string field_does_not_contain_json_arr(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field's elements does not contain a json array
		 * @param field: field whose element does not contain a json array
		 * @return the message
		 */
		static std::string field_element_does_not_contain_json_arr(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field's elements does not contain a json object
		 * @param field: field whose element does not contain a json object
		 * @return the message
		 */
		static std::string field_element_does_not_contain_json_obj(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field does not exist
		 * @param field: field that does not exist
		 * @return the message
		 */
		static std::string field_non_existent(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field does not contain a boot
		 * @param field: field which does not contain a bool
		 * @return the message
		 */
		static std::string field_does_not_contain_bool(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field does not contain a float
		 * @param field: field which does not contain a float
		 * @return the message
		 */
		static std::string field_does_not_contain_float(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field's element's element does not contain a json object
		 * @param field: field whose element's element does not contain a json object
		 * @return the message
		 */
		static std::string field_element_element_does_not_contain_json_obj(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field's elements does not contain a string
		 * @param field: field whose element does not contain a string
		 * @return the message
		 */
		static std::string field_element_does_not_contain_string(const std::string &field) noexcept;

		/*
		 * @brief creates message that the field's elements does not contain an int
		 * @param field: field whose element does not contain an int
		 * @return the message
		 */
		static std::string field_element_does_not_contain_int(const std::string &field) noexcept;
	};
}

#endif
