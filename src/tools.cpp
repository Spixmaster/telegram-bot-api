#include <iostream>
#include <fstream>
#include <cmath>
#include <linux/limits.h>
#include "tgbot/Constants.h"
#include "tgbot/tools.h"
#include <unistd.h>

/*
 * content: all functions for general C++ user or generally necessary for this project
 */

namespace tgbot
{
	namespace tools
	{
		//lists down all words in a vector
		//one vector location --> one word
		//args.at(0) is /*command*
		//can handle new lines and several spaces
		//gets only words
		//be aware when writing the arguments down --> you need to put spaces in between
		std::vector<std::string> get_args(const std::string &str)
		{
			std::vector<std::string> args;
			std::string word;

			for (size_t j = 0; j < str.length(); ++j)
			{
				try
				{
					//deal with last char/word
					//add last char to word
					//at end no ' ' --> otherwise, last word would not be added to vector
					if(j == (str.length() - 1) && str.at(j) != ' ')
					{
						word += str.at(j);
						args.push_back(word);
						word = "";
						break;	//otherwise, next condition would be true
					}

					//add characters
					if(str.at(j) != ' ' && str.at(j) != '\n')
						word += str.at(j);

					//detect words
					//&& word != "" --> so that e. g. several spaces would not add an empty slot in args
					if((str.at(j) == ' ' || str.at(j) == '\n') && word != "")
					{
						args.push_back(word);
						word = "";
					}
				}
				catch(std::exception &e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			return args;
		}

		//lists down all words in a vector
		//one vector location --> one word
		//args.at(0) is /*command*
		//can handle new lines and several spaces
		//additionally gets new lines
			//example:
			//at(0) --> hello\nhow
			//are
			//you?
		//be aware when writing the arguments down --> you need to put spaces in between
		std::vector<std::string> get_args_w_lns(const std::string &str)
		{
			std::vector<std::string> args;
			std::string word;

			for (size_t j = 0; j < str.length(); ++j)
			{
				try
				{
					//deal with last char/word
					//add last char to word
					//at end no ' ' --> otherwise, last word would not be added to vector
					if(j == (str.length() - 1) && str.at(j) != ' ')
					{
						word += str.at(j);
						args.push_back(word);
						word = "";
						break;	//otherwise, next condition would be true
					}

					//add characters
					if(str.at(j) != ' ')
						word += str.at(j);
					//detect words
					else
					{
						args.push_back(word);
						word = "";
					}
				}
				catch(std::exception &e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			return args;
		}

		//returns everything from file
		//neglects empty lines
		//new line included at end
		std::string get_file_cont(const std::string &file)
		{
			if(tools::file_exists(file))
			{
				std::ifstream inf(file);
				std::string cont;

				if(inf.is_open())
				{
					while (!inf.eof())
					{
						std::string cur_ln;
						std::getline(inf, cur_ln);
						if(cur_ln != "")
							cont.append(cur_ln + "\n");
					}
				}
				return cont;
			}
			else
			{
				Constants::file_non_existent(file);
				return "";
			}
		}

		//returns everything but the line which contains the search string
		//neglects empty lines
		//new line at end included
		std::string get_file_cont_wo_srch_ln(const std::string &file, const std::string &srch)
		{
			if(tools::file_exists(file))
			{
				std::ifstream inf(file);
				std::string cont;
				size_t found;

				if(inf.is_open())
				{
					while (!inf.eof())
					{
						std::string cur_ln;
						std::getline(inf, cur_ln);

						//srch in line
						if((found = cur_ln.find(srch)) != std::string::npos)
							continue;
						else if(cur_ln != "")
							cont.append(cur_ln + "\n");
					}
				}
				return cont;
			}
			else
			{
				Constants::file_non_existent(file);
				return "";
			}
		}

		//returns position of beginning of line which contains "srch" for file pointer
		//with that postion one can overwrite the beginning of the line
		//gets beginning line of first fitting string it mets
		//by default, returns 0
		size_t get_beg_pos_ln(const std::string &file, const std::string &srch)
		{
			if(tools::file_exists(file))
			{
				std::ifstream inf(file);
				std::string cur_ln;
				size_t found;
				size_t chars_to_srch = 0;

				if(inf.is_open())
				{
					while (!inf.eof())
					{
						std::getline(inf, cur_ln);

						//srch found
						if((found = cur_ln.find(srch)) != std::string::npos)
							break;

						//due to "\n"
						chars_to_srch += cur_ln.length();
						chars_to_srch += 2;
					}
				}
				return chars_to_srch;
			}
			else
			{
				Constants::file_non_existent(file);
				return 0;
			}
		}

		//returns true when string only consists of number --> therefore, postive integer
		//in case of negative number returns false
		//',' and '.' in string return false too
		bool is_pos_int(const std::string &str)
		{
			for (size_t j = 0; j < str.length(); ++j)
				if(!isdigit(str[j]))
					return false;
			return true;
		}

		//returns true when char is number --> 0 - 9
		//in case of negative number returns false
		//',' and '.' return false too
		bool is_pos_int(const char &ch)
		{
			if(!isdigit(ch))
				return false;
			return true;
		}

		//returns line which contains the string srch
		//when only part of string appears it does not count
		//gets line of first fitting string it mets
		//by default, returns nothing
		std::string get_file_ln_w_srch(const std::string &file, const std::string &srch)
		{
			if(tools::file_exists(file))
			{
				std::ifstream inf(file);
				std::string cur_ln;
				size_t found;

				if(inf.is_open())
				{
					while (!inf.eof())
					{
						std::getline(inf, cur_ln);

						//srch found
						if((found = cur_ln.find(srch)) != std::string::npos)
							return cur_ln;
					}
					//otherwise, if nothing found he would send the last line
					cur_ln = "";
				}
				return cur_ln;
			}
			else
			{
				Constants::file_non_existent(file);
				return "";
			}
		}

		//returns first char of string
		//by default, return nothing
		char get_first_char(const std::string &str)
		{
			if(str != "")
			{
				try
				{
					return str.at(0);
				}
				catch(std::exception &e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			const char *c = "";
			return *c;
		}

		//states whether str begins with beg
		//by default, returns nothing
		bool starts_w(const std::string &str, const std::string &beg)
		{
			//otherwise beginning could not even be beginning
			if(str.length() > beg.length())
			{
				try
				{
					for (size_t j = 0; j < beg.length(); ++j)
						if(!(beg.at(j) == str.at(j)))
							return false;
					return true;
				}
				catch(std::exception &e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			return false;
		}

		//states whether str ends with end
		bool ends_w(const std::string &str, const std::string &end)
		{
			//otherwise end could not even be end
			if(str.length() > end.length())
			{
				try
				{
					for (size_t j = 0; j < end.length(); ++j)
						if(!(end.at(end.length() - 1 - j) == str.at(str.length() - 1 - j)))
							return false;
					return true;
				}
				catch(std::exception &e)
				{
					std::cerr << e.what() << std::endl;
				}

			}
			return false;
		}

		//states whether string is in file
		//if only part of string appears it does not count
		bool file_cont_str(const std::string &file, const std::string &str)
		{
			if(tools::file_exists(file))
			{
				std::ifstream inf(file);
				std::string cur_ln;
				size_t found;

				if(inf.is_open())
				{
					while (!inf.eof())
					{
						std::getline(inf, cur_ln);

						if((found = cur_ln.find(str)) != std::string::npos)
							return true;
					}
				}
				return false;
			}
			else
			{
				Constants::file_non_existent(file);
				return false;
			}
		}

		//gets rid of first char
		std::string cut_off_first_char(const std::string &str)
		{
			std::string res;
			//j = 1 --> omit .at(0)
			for (size_t j = 1; j < str.length(); ++j)
			{
				try
				{
					res.push_back(str.at(j));
				}
				catch(std::exception &e)
				{
					std::cerr << e.what() << std::endl;
				}
			}

			//as with .length() = 1 for loop is not executed
			if(str.length() == 1)
				res = "";
			return res;
		}

		//checks whether the file exists
		bool file_exists(const std::string &file)
		{
			std::ifstream inf(file);
			return inf.good();
		}

		//gets first "ln_nums" lines of the file "file"
		//it does not matter whether "file" does not have "ln_nums" lines --> then, all are got
		//e.g. get first 5 lines of file
		//neglects empty lines
		//new line included at end
		std::string get_first_lns_file(const std::string &file, const int &ln_nums)
		{
			if(tools::file_exists(file))
			{
				if(ln_nums >= 0)
				{
					std::ifstream inf(file);
					std::string str;
					int count = 0;

					if(inf.is_open())
					{
						while (!inf.eof())
						{
							if(count == ln_nums)
								break;
							std::string cache;
							std::getline(inf, cache);
							if(cache != "")
								str.append(cache + "\n");
							++count;
						}
					}
					return str;
				}
				else
				{
					std::cerr << "You need to enter a positive value to read in" << " \"" + file << "\"." << std::endl;
					return "";
				}
			}
			else
			{
				Constants::file_non_existent(file);
				return "";
			}
		}

		//skips first "ln_nums" lines of the file "file"
		//it does not matter whether "file" does not have "ln_nums" lines --> then, all are got
		//e.g. first 2 lines are skipped
		//neglects empty lines
		//new line included at end
		std::string get_last_lns_file(const std::string &file, const int &ln_nums)
		{
			if(tools::file_exists(file))
			{
				if(ln_nums >= 0)
				{
					std::ifstream inf(file);
					std::string str;
					int count = 0;

					if(inf.is_open())
					{
						while (!inf.eof())
						{
							if(count < ln_nums)
							{
								std::string cache;
								std::getline(inf, cache);
								++count;
							}
							else
							{
								std::string cache;
								std::getline(inf, cache);
								if(cache != "")
									str.append(cache + "\n");

								++count;
							}
						}
					}
					return str;
				}
				else
				{
					std::cerr << "You need to enter a positive value to read in" << " \"" + file << "\"." << std::endl;
					return "";
				}
			}
			else
			{
				Constants::file_non_existent(file);
				return "";
			}
		}

		//returns the positive/negative integer at the end of a file
		//does not work properly when number contains: '.', ','
		//when no numerals at end or empty entry --> returns 0
		int64_t get_int_ln_end (const std::string &entry)
		{
			if(entry != "")
			{
				int64_t number = 0;
				bool is_neg = false;

				//get amount of numerals at the end
				int pos = 1; //begin with last char else end sequence
				int digits = 0;

				//no numerals at end --> digits = 0
				while (true)
				{
					try
					{
						if(tools::is_pos_int(entry.at(entry.length() - pos)) || entry.at(entry.length() - pos) == '-')
						{
							if(entry.at(entry.length() - pos) != '-')
							{
								++digits;
							}
							else
							{
								//so that '-' cannot occur in the middle of a number
								is_neg = true;
								break;
							}
							++pos;
						}
						else
							break;
					}
					catch(std::exception &e)
					{
						std::cerr << e.what() << std::endl;
					}
				}

				//if digits = 0 --> 0 is returned
				if(digits == 0)
				{
					std::cout << "There are no numerals at the end of the string: \"" << entry << "\"" << std::endl;
					return 0;
				}

				//get number according to digits
				for (int j = 0; j < digits; ++j)
				{
					try
					{
						//+ 1 --> else first iteration would end sequence
						char numeral = entry.at(entry.length() - (j + 1));
						//first iteration: j = 0 --> pow(10, 0) = 1
						number += static_cast<int64_t>(pow(10, j) * static_cast<int64_t>(numeral - 48));
					}
					catch(std::exception &e)
					{
						std::cerr << e.what() << std::endl;
					}
				}

				//consider sign
				if(is_neg)
					return -number;
				else
					return number;
			}
			else
			{
				std::cerr << "The given string is empty." << std::endl;
				return 0;
			}
		}

		//gets line "ln_num" of the file "file"
		//it does not matter whether "file" does not have "ln_num" line --> then, nothing is got
		//e.g. gets line 5 of file
		//"ln_num" needs to be greater than 0
		//NO new line ("\n") included at end
		std::string get_file_ln(const std::string &file, const int &ln_num)
		{
			if(tools::file_exists(file))
			{
				if(ln_num >= 1)
				{
					std::ifstream inf(file);
					std::string str;
					int count = 1;

					if(inf.is_open())
					{
						while (!inf.eof())
						{

							std::string cache;
							std::getline(inf, cache);

							if(count == ln_num)
								return cache;
							++count;
						}
					}
					return str;
				}
				else
				{
					std::cerr << "You need to enter a positive value and greater than 0 to read in" << " \"" + file << "\"." << std::endl;
					return "";
				}
			}
			else
			{
				Constants::file_non_existent(file);
				return "";
			}
		}

		//returns the amount of written lines in a file
		//empty lines do not count
		//by default, returns 0
		int get_amnt_file_lns(const std::string &file)
		{
			if(tools::file_exists(file))
			{
				std::ifstream inf(file);

				if(inf.is_open())
				{
					int x = 0;
					while (!inf.eof())
					{
						std::string cache;
						std::getline(inf, cache);

						if(cache != "")
							++x;
					}
					return x;
				}
			}
			else
				Constants::file_non_existent(file);
			return 0;
		}

		//Linux only: returns the path in which the program is in with appended executable name
		std::string get_exe_path()
		{
		  char result[ PATH_MAX ];
		  ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
		  return std::string( result, (count > 0) ? count : 0 );
		}
	}
}
