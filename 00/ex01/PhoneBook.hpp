#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include "Contact.hpp"
#include <string>

class PhoneBook {
	Contact	contacts[8];
	int		index;
	int			has_empty_field(Contact & c);
	static void print_with_pipe(std::string str);
	static void print_with_pipe(int index);
	static void	print_multiple_char(char c, int n);
	public:
		PhoneBook(void);
		PhoneBook(PhoneBook const & rhs);
		~PhoneBook(void);
	
		PhoneBook &		operator=(PhoneBook const & rhs);

		Contact const &	get_contact(int i) const;
		void			add_contact(Contact & contact);
		void			show_contacts(void) const;
};

#endif