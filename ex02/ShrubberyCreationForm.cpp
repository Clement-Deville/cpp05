/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:05:21 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/22 17:03:46 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("", "", 145, 137, false)
{
	std::cout << "\e[0;32mShrubberyCreationForm Default constructor called\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Cpy): AForm(Cpy)
{
	std::cout << "\e[0;32mShrubberyCreationForm Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target):
	AForm(name, target, 145, 137, false)
{
	std::cout << "\e[0;32mShrubberyCreationForm NewGrade constructor called\e[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mShrubberyCreationForm Destructor called\e[0m" << std::endl;
}

/**------------------------------------------------------------------------
 *                           Members functions
 *------------------------------------------------------------------------**/

/*	Executes the form with a Bureaucrat executor, if it is not signed or if
	the grade is not high enought, throws a corresponding exception */

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->_target.empty() || this->_name.empty())
		throw AForm::NameEmptyException;
	if (this->_GradeToExec < executor.getGrade())
		throw GradeTooLowException;
	std::ofstream file;
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	file.open((this->_target + "_shruberry").c_str());
	printASCITree(file);
}

/**------------------------------------------------------------------------
 *                           OPERATORS
 *------------------------------------------------------------------------**/

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Cpy)
{
	// a verifier
	std::cout << "\e[0;32mAForm assignement operator called\e[0m" << std::endl;
	AForm::operator=(Cpy);
	return (*this);
}