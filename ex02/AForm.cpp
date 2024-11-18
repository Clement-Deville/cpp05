/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:04:13 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/18 15:01:56 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/**------------------------------------------------------------------------
 *                           Prototypes/statics
 *------------------------------------------------------------------------**/

std::out_of_range	AForm::GradeTooHighException("Grade Too High");
std::out_of_range	AForm::GradeTooLowException("Grade Too Low");
EmptyNameException	AForm::NameEmptyException;

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

AForm::AForm() : _name(""), _GradeToSign(1), _GradeToExec(1), _is_signed(false)
{
	std::cout << "\e[0;32mAForm Default constructor called\e[0m" << std::endl;
}

AForm::AForm(const AForm &Cpy) :
	_name(Cpy._name), _GradeToSign(Cpy._GradeToSign),
	_GradeToExec(Cpy._GradeToExec)
{
	std::cout << "\e[0;32mAForm Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

AForm::AForm(const std::string name, int newGradeToExec, int newGradeToSign, bool issigned):
	_name(name), _GradeToSign(newGradeToSign), _GradeToExec(newGradeToExec), _is_signed(issigned)
{
	std::cout << "\e[0;32mAForm NewGrade constructor called\e[0m" << std::endl;
	if (newGradeToExec == 0 || newGradeToSign == 0)
		throw GradeTooHighException;
	if (newGradeToExec < 0 || newGradeToSign < 0)
		throw std::out_of_range("out of range");
	if (newGradeToExec > 150 || newGradeToSign > 150)
		throw GradeTooLowException;
	if (name.empty() || onlyWhiteSpace(name))
		throw NameEmptyException;
}

AForm::~AForm()
{
	std::cout << "\e[0;31mAForm Destructor called\e[0m" << std::endl;
}

int	AForm::getGradeToExec(void) const
{
	return (this->_GradeToExec);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_GradeToSign);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getSigned(void) const
{
	return (this->_is_signed);
}

void	AForm::beSigned(const Bureaucrat &B)
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


std::ostream & operator<<(std::ostream &out, const AForm &B)
{
	out << B.getName() << ", AForm grade to exec: " << B.getGradeToExec()
	<< ", AForm grade to sign: " << B.getGradeToSign() << " signed: "
	<< (B.getSigned()? "true" : "false") << std::endl;
	return (out);
}

AForm & AForm::operator=(const AForm &Cpy)
{
	std::cout << "\e[0;32mAForm assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	this->_is_signed = Cpy._is_signed;
	return (*this);
};
