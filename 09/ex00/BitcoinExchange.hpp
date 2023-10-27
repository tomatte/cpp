#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H
# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include <cctype>
# include <sstream>
# include <limits>
# include <stdexcept>
# include <algorithm>

typedef std::map<std::string, double> t_data;

class BitcoinExchange
{
	private:
		t_data	_database;

		static double		read_number(std::string & line, std::string & delim);
		static std::string	read_date(std::string & line, std::string & delim);
		static void			deep_copy(const t_data & src, t_data & dst);

		void	extract_data(std::string filename);
		void	print_convertion(std::string key, double value);

	public:
		static bool	is_valid_date(const char *str);

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & rhs);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		void			convert_values(std::string filename);
		void			init_database(std::string filename);
		t_data const	get_database(void) const;
};

#endif