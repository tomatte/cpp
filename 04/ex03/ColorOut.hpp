#ifndef COLOROUT_H
# define COLOROUT_H
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define NONE "\033[0m"
# define RED "\033[0;31m"
# include <iostream>

class ColorOut
{
	public:
		ColorOut(void);
		ColorOut(ColorOut const & rhs);
		~ColorOut(void);

		ColorOut & operator=(ColorOut const & rhs);

		typedef struct s_color
		{
			const char color[9];
		}	t_color;

		static t_color	red;
		static t_color	green;
		static t_color	blue;
		static t_color	none;
		static t_color	last;

};

ColorOut::t_color operator<<(ColorOut::t_color c, std::string & str);
ColorOut::t_color operator<<(ColorOut::t_color c, std::string str);
ColorOut::t_color operator<<(ColorOut::t_color c, const char *str);
ColorOut::t_color operator<<(ColorOut::t_color c, const char *str);
ColorOut::t_color operator<<(ColorOut::t_color c, std::ostream & (*f)(std::ostream & o));

#endif