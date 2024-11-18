/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:04:13 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/18 15:01:56 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/**------------------------------------------------------------------------
 *                           Prototypes/statics
 *------------------------------------------------------------------------**/

std::out_of_range	Form::GradeTooHighException("Grade Too High");
std::out_of_range	Form::GradeTooLowException("Grade Too Low");
EmptyNameException	Form::NameEmptyException;

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

Form::Form() : _name(""), _GradeToSign(1), _GradeToExec(1), _is_signed(false)
{
	std::cout << "\e[0;32mForm Default constructor called\e[0m" << std::endl;
}

Form::Form(const Form &Cpy) :
	_name(Cpy._name), _GradeToSign(Cpy._GradeToSign),
	_GradeToExec(Cpy._GradeToExec)
{
	std::cout << "\e[0;32mForm Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

Form::Form(const std::string name, int newGradeToExec, int newGradeToSign, bool issigned):
	_name(name), _GradeToSign(newGradeToSign), _GradeToExec(newGradeToExec), _is_signed(issigned)
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
	out << B.getName() << ", Form grade to exec: " << B.getGradeToExec()
	<< ", Form grade to sign: " << B.getGradeToSign() << " signed: "
	<< (B.getSigned()? "true" : "false") << std::endl;
	return (out);
}

Form & Form::operator=(const Form &Cpy)
{
	std::cout << "\e[0;32mForm assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->_is_signed = Cpy._is_signed;
	return (*this);
};
