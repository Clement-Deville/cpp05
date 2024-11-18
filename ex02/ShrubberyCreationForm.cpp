/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:05:21 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/18 18:48:11 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("", 145, 137, false)
{
	std::cout << "\e[0;32mShrubberyCreationForm Default constructor called\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Cpy): AForm(Cpy)
{
	std::cout << "\e[0;32mShrubberyCreationForm Copy constructor called\e[0m" << std::endl;
	*this = Cpy;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name):
	AForm(name, 145, 137, false)
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	//some code
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
