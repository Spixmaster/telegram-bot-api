# telegram-bot-api
A C++ library for the Telegram bot API.\
Current state: Bot API 4.9\
See the [Telegram documentation](https://core.telegram.org/bots/api) for changelogs and documentation. I copied the documentation into the source code according to the Doxygen syntax but the website is the original source.

## Installation
### Compiler
You need to use a C++17 compiler for compilation.

### Dependencies
This software is built with the help of third party libraries. It is shown below how to install them.

#### Poco
```sh
sudo pacman -S poco
```

#### Rapidjson
```sh
sudo pacman -S rapidjson
```

#### Boost
```sh
sudo pacman -S boost
```

#### Submodules
```sh
git submodule init
git submodule update
```

#### Libraries that need to be linked (option -l)
* PocoFoundation
* PocoNet
* PocoNetSSL
* PocoCrypto
* boost_iostreams
* boost_filesystem
* boost_locale

### Submodule
```sh
cd to/your/project/
git submodule add *link-to-this-repo*
```

### Makefile
```sh
cd to/this/project/
cmake .
make -j 4
```

## Eclipse setup
These instructions show how to set up the project in eclipse.
1. Clone the project.
2. Create a new eclipse project.
3. Right click on the eclipse project > "Import" > "General" > "File System".
4. Select all content from the cloned project.

## Usage
This project is thought to be used in other software as a library.

### Documentation
The documentation is generated with the help of Doxygen. It is an HTML document and can be found in *./doc/html/index.html*. Open that file with your favourite browser.

### Example
Look in the examples folder.

## Changelog
The changelog can be seen on the documentation's main page.

## FAQ
* Q: Can I run a bot with this API which runs 24/7?
* A: Yes, you can. I can assure you that as I do it myself. There is not a single memory leak so your RAM will not bloat. Additionally, the HTTP requests are completely safe. If you send wrong requests to the Telegram servers like trying to delete messages with a bot which does not have admin rights the proper error messages will be written to the error log.
***
* Q: What happens at night when the internal IP changes or my Internet connection is interrupted due to a blackout or similar?
* A: The HTTP client is completely safe. It will just connect again as soon as a connection can be established.
