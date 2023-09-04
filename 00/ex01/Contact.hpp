#ifndef CONTACT_H
# define CONTACT_H
#include <string>

class Contact {
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _dark_secret;
	std::string	_phone_number;
	public:
		Contact(void);
		Contact(Contact const & rhs);
		~Contact(void);

		Contact &	operator=(Contact const & rhs);

		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_nickname(void) const;
		std::string	get_dark_secret(void) const;
		std::string	get_phone_number(void) const;
		void		set_first_name(std::string name);
		void		set_last_name(std::string name);
		void		set_nickname(std::string name);
		void		set_dark_secret(std::string secret);
		void		set_phone_number(std::string number);
		void		show(void) const;	

};

#endif