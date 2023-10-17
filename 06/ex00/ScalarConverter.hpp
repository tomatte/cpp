#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H
# include <string>
# define OPERATIONS 6

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & rhs);
		~ScalarConverter(void);

		ScalarConverter & operator=(ScalarConverter const & rhs);

		static char		n_char;
		static int		n_int;
		static float	n_float;
		static double	n_double;

		static void		trim_zeros(std::string & literal);
		static void		print_char(void);
		static void		print_double(void);
		static void		print_float(void);
		static void		print_int(void);
		static void		print_everything(void);

		static bool		convert_to_char(std::string literal);
		static bool		convert_to_int(std::string literal);
		static bool		convert_to_float(std::string literal);
		static bool		convert_to_double(std::string literal);
		static bool		convert_double_specials(std::string literal);
		static bool		convert_float_specials(std::string literal);
		static bool		(*convertions[OPERATIONS])(std::string);

	public:
		static void	convert(std::string literal);
};

#endif