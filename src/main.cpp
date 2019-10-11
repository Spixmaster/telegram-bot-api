#include "tgbot/Bot.h"
#include "tgbot/EventHandler.h"
#include "tgbot/types/Message.h"
#include "tgbot/types/ReplyKeyboardRemove.h"
#include "tgbot/types/Update.h"
#include "tgbot/types/User.h"
#include "tgbot/types/UserProfilePhotos.h"
#include <iostream>
#include <fstream>

//	InputFile::ptr file0 = std::make_shared<InputFile>("/home/matheus/Bilder/Hintergrundbilder/4k-wallpaper-bay-beach-2521619.jpg");
//	InputFile::ptr file1 = std::make_shared<InputFile>("/media/matheus/TOSHIBA EXT/Geld (Ordner)/Telegram/Geile Profilfotos/@voevoda22/photo_2019-08-04_11-59-57.jpg");

//chat id dx50: -1001329833740
//my tg usr id: 360617853

int main()
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("some_tg_bot_api_key");

	//can only be executed in a group
	bot->get_event_handler()->on_cmd("chatid", [&bot](tgbot::Message::ptr msg)
	{
		bot->get_endpnts()->sendMessage(-1001329833740, "hi");
	});

	while(true)
	{
		bot->get_event_handler()->long_poll();
	}

	return EXIT_SUCCESS;
}
