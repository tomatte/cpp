#include "Form.hpp"

Form::Form(void) : _name("Default"), _signed(false),
_sign_grade(1), _execution_grade(1)
{
}

Form::Form(Form const & rhs) : _name(rhs._name), _signed(rhs._signed),
_sign_grade(rhs._sign_grade), _execution_grade(rhs._execution_grade)
{
}

Form::~Form(void)
{
}

Form & Form::operator=(Form const & rhs)
{
	this->_name = rhs._name;
	this->_signed = rhs._signed;
	return (*this);
}
