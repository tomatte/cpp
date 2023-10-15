#include "ColorOut.hpp"

ColorOut::ColorOut(void)
{
}

ColorOut::ColorOut(ColorOut const & rhs)
{
	(void) rhs;
}

ColorOut::~ColorOut(void)
{
}

ColorOut & ColorOut::operator=(ColorOut const & rhs)
{
	(void) rhs;
	return (*this);
}

ColorOut::t_color	ColorOut::red = {RED};
ColorOut::t_color	ColorOut::green = {GREEN};
ColorOut::t_color	ColorOut::green_b = {GREEN_B};
ColorOut::t_color	ColorOut::blue = {BLUE};
ColorOut::t_color	ColorOut::blue_b = {BLUE_B};
ColorOut::t_color	ColorOut::none = {NONE};
ColorOut::t_color	ColorOut::yellow = {YELLOW};
ColorOut::t_color	ColorOut::magenta = {MAGENTA};
ColorOut::t_color	ColorOut::cyan = {CYAN};
ColorOut::t_color	ColorOut::white = {WHITE};

ColorOut::t_color operator<<(ColorOut::t_color c, std::string & str)
{
	std::cout << (const char *) c.color;
	std::cout << str;
	std::cout << (const char *) ColorOut::none.color;
	return (c);
}

ColorOut::t_color operator<<(ColorOut::t_color c, const std::string & str)
{
	std::cout << (const char *) c.color;
	std::cout << str;
	std::cout << (const char *) ColorOut::none.color;
	return (c);
}

ColorOut::t_color operator<<(ColorOut::t_color c, const char *str)
{
	std::cout << (const char *) c.color;
	std::cout << str;
	std::cout << (const char *) ColorOut::none.color;
	return (c);
}

/* This overload passes operators like std::endl to std::cout */
ColorOut::t_color operator<<(ColorOut::t_color c, std::ostream & (*f)(std::ostream & o))
{
	std::cout << f;
	return (c);
}
