#ifndef RPN_H
# define RPN_H
# include <stack>
# include <string>
# include <iostream>
# include <stdexcept>

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
		static int	func(int a, int b, char operand);
};

#endif