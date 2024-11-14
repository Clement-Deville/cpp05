/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:04:13 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/14 17:40:44 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

Form::Form() : _name(""), _GradeToExec(1), _GradeToSign(1)
{
	std::cout << "\e[0;32mForm Default constructor called\e[0m" << std::endl;
}

Form::Form(const Form &Cpy) : _name(Cpy._name)
{
	std::cout << "\e[0;32mForm Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Form::Form(const std::string name, int newGradeToExec, int newGradeToSign):
	_name(name), _GradeToExec(newGradeToExec), _GradeToSign(newGradeToSign)
{
	std::cout << "\e[0;32mForm NewGrade constructor called\e[0m" << std::endl;
	if (newGradeToExec == 0 || newGradeToSign == 0)
		throw GradeTooHighException;
	if (newGradeToExec < 0 || newGradeToSign < 0)
		throw std::out_of_range("out of range");
	if (newGradeToExec > 150 || newGradeToSign > 150)
		throw GradeTooLowException;
	if (name.empty() || onlyWhiteSpace(name))
		throw NameEmptyException;
}

Form::~Form()
{
	std::cout << "\e[0;31mForm Destructor called\e[0m" << std::endl;
}

int	Form::getGradeToExec(void) const
{
	return (this->_GradeToExec);
}

int	Form::getGradeToSign(void) const
{
	return (this->_GradeToSign);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getSigned(void) const
{
	return (this->_is_signed);
}

void	Form::beSigned(const Bureaucrat &B)
{
	if (B.getName().empty())
		throw B.NameEmptyException;
	if (this->_is_signed)
		throw std::runtime_error("Is already signed");
	if (this->getGradeToSign() >= B.getGrade())
		_is_signed = true;
	else
		throw Bureaucrat::GradeTooLowException;
}


std::ostream & operator<<(std::ostream &out, const Form &B)
{
	out << B.getName() << ", Form grade " << B.getGrade() << std::endl;
	return (out);
}

Form & Form::operator=(const Form &Cpy)
{
	std::cout << "\e[0;32mForm assignement operator called\e[0m" << std::endl;
	this->_grade = Cpy._grade;
	return (*this);
};
