/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:31:57 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 09:31:58 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string	brain("HI THIS IS BRAIN");
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "brain address: " << &brain << "\n";
	std::cout << "stringPTR: " << stringPTR << "\n";
	std::cout << "stringREF: " << &stringREF << "\n";
	
	std::cout << "brain value: " << brain << "\n";
	std::cout << "stringPTR pointed to: " << *stringPTR << "\n";
	std::cout << "stringREF pointed to: " << stringREF << "\n";
	return (0);
}
