#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H
# include "IMateriaSource.hpp"
# define MAX_MATERIAS 4


class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_materias[MAX_MATERIAS];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & rhs);
		~MateriaSource(void);

		MateriaSource & operator=(MateriaSource const & rhs);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif