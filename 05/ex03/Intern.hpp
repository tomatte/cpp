#ifndef INTERN_H
# define INTERN_H
# include <string>

class AForm;

class Intern
{
	private:
		static AForm		*createShrubberyRequest(std::string target);
		static AForm		*createPresidentialPardon(std::string target);
		static AForm		*createRobotomyRequest(std::string target);
		static AForm 		*(*createFormFunctions[3])(std::string);
		static std::string	formNames[3];

	public:
		Intern(void);
		Intern(Intern const & rhs);
		~Intern(void);

		Intern & operator=(Intern const & rhs);

		AForm	*makeForm(std::string form, std::string target);
};

#endif