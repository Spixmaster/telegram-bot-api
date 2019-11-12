# telegram-bot-api
C++ library for the Telegram bot API.

## Usage
### Dependencies
You need to use a C++17 compiler.
The following packages need to be installed:
```sh
sudo apt install libpoco-dev
```
Moreover, [rapdijson](https://www.google.com "Google's Homepage") needs to be installed.

On Mac OSX, first insall macports from [MacPorts](https://www.macports.org/install.php) and in Terminal
```sh
sudo port install cmake json-c curl
```
To compile the library execute following commands:
```sh
cd [your repository]
mkdir -p Build && cd Build
cmake ../
make
```
This will create `echobot` executable under `Build/test` folder. This is a simple dummy bot which echoes back the messages sent to it. Head over to [Telegram Bots](https://core.telegram.org/bots) page to read about how to register your brand new echo bot with Telegram platform and see it in action.
