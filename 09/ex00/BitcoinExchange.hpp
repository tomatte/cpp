#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H
# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>

typedef std::map<std::string, double> t_data;

class BitcoinExchange
{
	private:
		void	extract_data(std::string data_file);

	public:

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & rhs);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		t_data	btc_data;
};

#endif;