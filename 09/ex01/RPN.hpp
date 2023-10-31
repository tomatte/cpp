#ifndef RPN_H
# define RPN_H
# include <stack>
# include <string>
# include <iostream>
# include <stdexcept>
# include <cstdlib>
# include <limits>
# include <sstream>

# define npos std::string::npos
# define OPERANDS "+-/*"

# define ft_stack std::stack<int>

class RPN 
{
	private:
		ft_stack	_stack1;
		ft_stack	_stack2;
		int			len;
		char		op;

	public:
		RPN(void);
		RPN(RPN const & rhs);
		~RPN(void);

		RPN & operator=(RPN const & rhs);

		void	operation(std::string str);
		void	verify_error(std::string & str) const;
		static int	func(int a, int b, char op);
		static char	find_operator(std::string const & str);
		int	get_operand(std::stringstream & ss);
		int	pop(ft_stack & s);

		void	numbers_to_stack1(std::stringstream & ss);
		void	from_stack1_to_stack2(void);
		int		convert_to_int(std::string & str);

};

#endif