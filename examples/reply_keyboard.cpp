#include "tgbot/Bot.h"
#include "tgbot/types/Message.h"
#include <memory>

int main()
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("put your own token in here");

	//################make reply keyboard###################
	std::vector<tgbot::KeyboardButton::ptr> row0;
	std::vector<tgbot::KeyboardButton::ptr> row1;

	tgbot::KeyboardButton::ptr button0 = std::make_shared<tgbot::KeyboardButton>();
	button0->text = "Click me!";

	tgbot::KeyboardButton::ptr button1 = std::make_shared<tgbot::KeyboardButton>();
	button1->text = "Click me even harder!";

	tgbot::KeyboardButton::ptr button2 = std::make_shared<tgbot::KeyboardButton>();
	button2->text = "I know what you want ;)";


	row0.push_back(button0);
	row0.push_back(button1);
	row1.push_back(button2);

	std::vector<std::vector<tgbot::KeyboardButton::ptr>> keyboard;
	keyboard.push_back(row0);
	keyboard.push_back(row1);

	tgbot::ReplyKeyboardMarkup::ptr keyboard_ptr = std::make_shared<tgbot::ReplyKeyboardMarkup>(keyboard);
	keyboard_ptr->resize_keyboard = true;
	keyboard_ptr->one_time_keyboard = true;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	tgbot::Message::ptr msg = bot->get_endpnts().sendMessage(proper-chat-id,"<b>What's up!</b>", keyboard_ptr);

	return EXIT_SUCCESS;
}
