#ifndef CONTACT_H
# define CONTACT_H
#include <string>

class Contact {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string dark_secret;
	std::string	phone_number;
	public:
		Contact(void);
		~Contact(void);
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_nickname(void) const;
		std::string	get_dark_secret(void) const;
		std::string	get_phone_number(void) const;
		void		 set_first_name(std::string name);
		void		 set_last_name(std::string name);
		void		 set_nickname(std::string name);
		void		 set_dark_secret(std::string name);
		void		 set_phone_number(std::string number);

};

#endif

//irst name, last name, nickname, phone number, and darkest secret