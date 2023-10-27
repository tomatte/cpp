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

typedef std::map<std::string, double> t_data;

class BitcoinExchange
{
	private:
		void	extract_data(std::string filename);

	public:
		static bool	is_valid_date(const char *str);
		static bool	is_valid_number(const char *str);

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & rhs);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		void	convert_values(std::string filename);
		void	init_prices(std::string filename);
		t_data	prices;
};

#endif