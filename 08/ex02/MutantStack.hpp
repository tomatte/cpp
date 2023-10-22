#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	typedef typename Container::iterator ft_iterator;

	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(MutantStack const & rhs) : std::stack<T>(rhs) {}
		~MutantStack(void) {}

		MutantStack & operator=(MutantStack const & rhs) {
			std::stack<T>::operator=(rhs);
		}

		ft_iterator	begin(void) {
			return (this->c.begin());
		}

		ft_iterator	end(void) {
			return (this->c.end());
		}
};

#endif