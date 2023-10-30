#ifndef RPN_H
# define RPN_H
# include <stack>
class RPN 
{
	private:
		std::stack<int>	_stack;

	public:
		RPN(void);
		RPN(RPN const & rhs);
		~RPN(void);

		RPN & operator=(RPN const & rhs);
};

#endif