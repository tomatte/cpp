#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(MutantStack const & rhs) : std::stack<T>(rhs) {}
		~MutantStack(void) {}

		typedef typename Container::iterator iterator;
		
		MutantStack & operator=(MutantStack const & rhs) {
			std::stack<T>::operator=(rhs);
		}

		iterator	begin(void) {
			return (this->c.begin());
		}

		iterator	end(void) {
			return (this->c.end());
		}
};

#endif