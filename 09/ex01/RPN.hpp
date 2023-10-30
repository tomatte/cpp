#ifndef RPN_H
# define RPN_H
# include <stack>
# include <string>
# include <iostream>
# include <stdexcept>
# include <cstdlib>
# include <limits>

# define npos std::string::npos
# define OPERANDS "+-/*"

class RPN 
{
	private:
		std::stack<int>	_stack;

	public:
		RPN(void);
		RPN(RPN const & rhs);
		~RPN(void);

		RPN & operator=(RPN const & rhs);

		void	operation(std::string str);
		void	verify_error(std::string & str) const;
		static int	func(int a, int b, char op);
		static char	find_operator(std::string & str);
		static int	get_operand(std::string & str);
};

#endif