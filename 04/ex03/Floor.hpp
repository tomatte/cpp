#ifndef FLOOR_H
# define FLOOR_H
# include "AMateria.hpp"

class Floor
{
	private:
		//AMateria linked list

	public:
		Floor(void);
		Floor(Floor const & rhs);
		~Floor(void);
		Floor & operator=(Floor const & rhs);

		void	add_materia(AMateria *materia);
		void	clear_floor(void);
};

#endif