#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <vector>

namespace tgbot
{
	namespace tools
	{
		std::vector<std::string> get_args(const std::string &str);
		std::vector<std::string> get_args_w_lns(const std::string &str);
		std::string get_file_cont(const std::string &file);
		std::string get_file_cont_wo_srch_ln(const std::string &file, const std::string &srch);
		size_t get_beg_pos_ln(const std::string &file, const std::string &srch);
		bool is_pos_int(const std::string &str);
		bool is_pos_int(const char &ch);
		std::string get_file_ln_w_srch(const std::string &file, const std::string &srch);
		char get_first_char(const std::string &str);
		bool starts_w(const std::string &str, const std::string &beg);
		bool ends_w(const std::string &str, const std::string &end);
		bool file_cont_str(const std::string &file, const std::string &str);
		std::string cut_off_first_char(const std::string &str);
		bool file_exists(const std::string &file);
		std::string get_first_lns_file(const std::string &file, const int &ln_nums);
		std::string get_last_lns_file(const std::string &file, const int &ln_nums);
		int64_t get_int_ln_end (const std::string &entry);
		std::string get_file_ln(const std::string &file, const int &ln_num);
		int get_amnt_file_lns(const std::string &file);
		std::string get_exe_path();
	}
}

#endif
