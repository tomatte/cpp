#ifndef FT_H
# define FT_H
# include "AMateria.hpp"

namespace ft
{
	typedef struct s_lst
	{
		AMateria	*materia;
		s_lst		*next;
	}	t_lst;

	void	add_to_list(t_lst **list, AMateria *materia);
	void	clear_list(t_lst **lst);
	t_lst	*dup_list(t_lst *lst);
}


#endif