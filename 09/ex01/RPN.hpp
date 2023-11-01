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
		ft_stack	_stack;
		char		_op;

	public:
		RPN(void);
		RPN(RPN const & rhs);
		~RPN(void);

		RPN & operator=(RPN const & rhs);

		void	operation(std::string str);
		void	verify_error(std::string & str) const;
		static int	func(int a, int b, char op);
		int			pop(void);

		void	numbers_to_stack1(std::stringstream & ss);
		int		convert_to_int(std::string & str);
		void	execute_operation(void);

};

#endif