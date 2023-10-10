#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ft.hpp"

namespace ft {
	void	add_to_list(t_lst **list, AMateria *materia)
	{
		t_lst	*aux;
		t_lst	*node;
	
		if (materia == NULL)
			return ;
		node = new t_lst;
		node->next = NULL;
		node->materia = materia;
		if (*list == NULL)
		{
			*list = node;
			return ;
		}
		aux = *list;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = node;
	}

	void	clear_list(t_lst **lst)
	{
		t_lst	*aux;
	
		while (1)
		{
			aux = *lst;
			if (aux == NULL)
				break ;
			delete aux->materia;
			*lst = (*lst)->next;
			delete aux;
		}
		*lst = NULL;
	}

	t_lst	*dup_list(t_lst *lst)
	{
		t_lst		*dup = NULL;
		AMateria	*m;

		while (lst)
		{
			if (lst->materia->getType() == "ice")
				m = new Ice(*lst->materia);
			else
				m = new Cure(*lst->materia);
			add_to_list(&dup, m);
			lst = lst->next;
		}
		return dup;
	}
}
