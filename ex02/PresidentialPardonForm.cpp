/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:05:21 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/25 12:59:12 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", "", 5, 25, false)
{
	std::cout << "\e[0;32mPresidentialPardonForm Default constructor called\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &Cpy): AForm(Cpy)
{
	std::cout << "\e[0;32mPresidentialPardonForm Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm("PresidentialPardonForm", target, 5, 25, false)
{
	std::cout << "\e[0;32mPresidentialPardonForm NewGrade constructor called\e[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mPresidentialPardonForm Destructor called\e[0m" << std::endl;
}

/**------------------------------------------------------------------------
 *                           Members functions
 *------------------------------------------------------------------------**/

/*	Executes the form with a Bureaucrat executor, if it is not signed or if
	the grade is not high enought, throws a corresponding exception */

void pardon(PresidentialPardonForm const & form)
{
	std::cout << form.getTarget()
		<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->_target.empty())
		throw AForm::NameEmptyException();
	if (this->_GradeToExec < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (this->_is_signed == false)
		throw AForm::NotSignedException();
	pardon(*this);
}

/**------------------------------------------------------------------------
 *                           OPERATORS
 *------------------------------------------------------------------------**/

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &Cpy)
{
	// a verifier
	std::cout << "\e[0;32mAForm assignement operator called\e[0m" << std::endl;
	AForm::operator=(Cpy);
	return (*this);
}
