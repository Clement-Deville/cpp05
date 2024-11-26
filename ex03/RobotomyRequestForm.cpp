/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:05:21 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/25 12:59:12 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", "", 45, 72, false)
{
	std::cout << "\e[0;32mRobotomyRequestForm Default constructor called\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Cpy): AForm(Cpy)
{
	std::cout << "\e[0;32mRobotomyRequestForm Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm("RobotomyRequestForm", target, 45, 72, false)
{
	std::cout << "\e[0;32mRobotomyRequestForm NewGrade constructor called\e[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mRobotomyRequestForm Destructor called\e[0m" << std::endl;
}

/**------------------------------------------------------------------------
 *                           Members functions
 *------------------------------------------------------------------------**/

/*	Executes the form with a Bureaucrat executor, if it is not signed or if
	the grade is not high enought, throws a corresponding exception */

void robotomize(RobotomyRequestForm const & form)
{
	std::cout << "Makes some drilling noises... \n";
	std::srand(std::time(0));
	if (std::rand() % 2)
	{
		std::cout << "SUCESS, " << form.getTarget()
			<< " has been successfully robotomised!" << std::endl;
	}
	else
	{
		std::cout << "FAILURE, " << form.getTarget()
			<< " has not been robotomised!" << std::endl;
	}
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->_target.empty())
		throw AForm::NameEmptyException();
	if (this->_GradeToExec < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (this->_is_signed == false)
		throw AForm::NotSignedException();
	robotomize(*this);
}

/**------------------------------------------------------------------------
 *                           OPERATORS
 *------------------------------------------------------------------------**/

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &Cpy)
{
	// a verifier
	std::cout << "\e[0;32mAForm assignement operator called\e[0m" << std::endl;
	AForm::operator=(Cpy);
	return (*this);
}
