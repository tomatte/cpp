/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:02:08 by dbrandao          #+#    #+#             */
/*   Updated: 2023/09/07 08:18:16 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void) {
	Harl	harl;

	std::cout << "Default order: DEBUG -> INFO -> WARNING -> ERROR\n\n";
	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	harl.complain("");
	harl.complain("debug");
	harl.complain("warning");
	harl.complain("info");
	harl.complain("error");
	harl.complain("DEBUGG");
	harl.complain("WARNNING");
	harl.complain("INNFO");
	harl.complain("ERRROR");
	harl.complain("A");

	std::cout << "-----------------------------------------------------------\n";
	std::cout << "Reversed order: ERROR -> WARNING -> INFO -> DEBUG\n\n";
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	return (0);
}
