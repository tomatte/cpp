#ifndef COLOROUT_H
# define COLOROUT_H
# define NONE "\033[0m"			/* None */
# define RED "\033[0;31m"		/* Red */
# define GREEN "\033[0;32m"		/* Green */
# define GREEN_B "\033[0;32;1m"		/* Green Bold */
# define YELLOW  "\033[33m"		/* Yellow */
# define BLUE "\033[0;34m"		/* Blue */
# define BLUE_B "\033[0;34;1m"		/* Blue Bold */
# define MAGENTA "\033[35m"		/* Magenta */
# define CYAN    "\033[36m"		/* Cyan */
# define WHITE   "\033[37m"		/* White */
# include <iostream>

class ColorOut
{
	private:
		ColorOut(void);
		ColorOut(ColorOut const & rhs);
		~ColorOut(void);
		ColorOut & operator=(ColorOut const & rhs);

	public:
		typedef struct s_color
		{
			const char color[10];
		}	t_color;

		static t_color	none;
		static t_color	red;
		static t_color	green;
		static t_color	green_b;
		static t_color	yellow;
		static t_color	blue;
		static t_color	blue_b;
		static t_color	magenta;
		static t_color	cyan;
		static t_color	white;

};
ColorOut::t_color operator<<(ColorOut::t_color c, std::ostream & (*f)(std::ostream & o));

template <typename T>
ColorOut::t_color operator<<(ColorOut::t_color c, T & content)
{
	std::cout << (const char *) c.color;
	std::cout << content;
	std::cout << (const char *) ColorOut::none.color;
	return (c);
}

#endif