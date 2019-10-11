#include <iostream>
#include "tgbot/types/Update.h"
#include "tgbot/types/User.h"
#include <cpr/cpr.h"
#include "Bot.h"
#include "tgbot/types/Message.h"

int main()
{
	Bot bot("put your own token in here");

	//########make inline keyboard##########################

	std::vector<KeyboardButton::ptr> row0;
	std::vector<KeyboardButton::ptr> row1;

	KeyboardButton::ptr button0 = std::make_shared<KeyboardButton>();
	button0->text = "Click me!";

	KeyboardButton::ptr button1 = std::make_shared<KeyboardButton>();
	button1->text = "Click me even harder!";

	KeyboardButton::ptr button2 = std::make_shared<KeyboardButton>();
	button2->text = "I know what you want ;)";


	row0.push_back(button0);
	row0.push_back(button1);
	row1.push_back(button2);

	std::vector<std::vector<KeyboardButton::ptr>> keyboard;
	keyboard.push_back(row0);
	keyboard.push_back(row1);

	ReplyKeyboardMarkup::ptr keyboard_ptr = std::make_shared<ReplyKeyboardMarkup>(keyboard);
	keyboard_ptr->resize_keyboard = true;
	keyboard_ptr->one_time_keyboard = true;

	//######################################################

	Message::ptr msg = bot.endpnts.sendMessage(proper-chat-id,"<b>What's up!</b>", keyboard_ptr);

	return EXIT_SUCCESS;
}
