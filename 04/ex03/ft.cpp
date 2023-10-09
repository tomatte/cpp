/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:12:58 by dbrandao          #+#    #+#             */
/*   Updated: 2023/10/09 08:15:10 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"
#include "AMateria.hpp"

namespace ft {
	typedef struct s_lst
	{
		AMateria	*materia;
		t_lst		*next;
	}	t_lst;

	void	add_to_list(t_lst **list, AMateria *materia)
	{
		t_lst	*aux;
		t_lst	*node;
	
		if (materia == NULL)
			return ;
		node = new t_lst;
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
			delete aux;
			*lst = (*lst)->next;
		}
		*lst = NULL;
	}
}
