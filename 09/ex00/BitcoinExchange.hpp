#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H
# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <ctime>

typedef std::map<std::string, double> t_data;

class BitcoinExchange
{
	private:
		static void	extract_data(t_data & storage, std::string filename);

	public:
		static bool	is_valid_date(const char *str);

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & rhs);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		t_data	prices;
		t_data	ammounts;
};

#endif