# telegram-bot-api
C++ library for the Telegram bot API.

Current state: Bot API 4.4 (up to date)

See the [Telegram documentation](https://core.telegram.org/bots/api).

## Usage
### Dependencies
You need to use a C++17 compiler.

The following packages need to be installed:
```sh
sudo apt install libpoco-dev
```
Moreover, [rapdijson](https://github.com/Tencent/rapidjson) needs to be installed.

For this, do the following steps:
1. git clone https://github.com/Tencent/rapidjson
2. cd rapidjson
3. cmake .
4. make -j4
5. sudo make install

#### Libraries that need to be linked (option -l)
* PocoFoundation
* PocoNetSSL
* PocoNet

### Example
```cpp
#include "tgbot/Bot.h"
#include <memory>

int main()
{
	tgbot::Bot::ptr bot = std::make_shared<tgbot::Bot>("your-bot-token");

	/*
	 * command /test
	 * just for testing purposes
	 */
	bot->get_event_handler()->on_cmd("test", [&bot](const tgbot::Message::ptr &msg)
	{
		bot->get_endpnts()->sendMessage(msg->chat->id, "Hey, <b>there</b>.", "HTML", false, 0);
	});

	//test listener
	bot->get_event_handler()->on_non_cmd_msg([&bot](const tgbot::Message::ptr &msg)
	{
		bot->get_endpnts()->sendMessage(msg->chat->id, "I hear you.");
	});

	while(true)
	{
		bot->get_event_handler()->long_poll();
	}

	return EXIT_SUCCESS;
}
```

## Known Errors
The function editMessageMedia() does not work properly although it should as the principle is the same as with other functions. The issue may be from Telegram's side.

## FAQ
* Q: Can I run a bot with this API which runs 24/7.
⋅⋅* A: Yes, you can. I can assure you that as I do it myself. There is not a single memory leak so you RAM will not bloat. Additionally, the http requests are completely safe.
Even if you do wrong action like trying to delete messages with a bot who does not have admin rights and if you send wrong requests to the Telegram server the proper messages will be output to the sterr.

* Q: What happens at night when the internal ip changes or my Internet connection is interrupted due to a blackout or similar?
⋅⋅* A: The Http client is completely safe. It will just connect again as soon as a connection can be established again.
