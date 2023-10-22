#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & rhs);
		~BitcoinExchange(void);

		BitcoinExchange & operator=(BitcoinExchange const & rhs);
};

#endif;