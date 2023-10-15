#ifndef INTERN_H
# define INTERN_H

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & rhs);
		~Intern(void);

		Intern & operator=(Intern const & rhs);
};

#endif