/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 14:38:42 by cdeville          #+#    #+#             */
/*   Updated: 2024-11-26 14:38:42 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string Intern::names[3][10] = {{"presidential pardon", "presidential", ""}, 
    {"robotomy request", "robotomy", ""}, 
    {"shrubbery creation", "shrubbery", ""}};

int Intern::find_index(const std::string input)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10 && !Intern::names[i][j].empty(); j++)
        {
            if (Intern::names[i][j] == input)
                return (i);
        }
    }
    return (-1);
}

AForm *Intern::makeForm(const std::string input, const std::string target) const
{
    switch (Intern::find_index(input))
    {
        case 0:
        {
            std::cout << "Intern creates PresidentialPardonForm" << std::endl;
            return (new PresidentialPardonForm(target));
        }
        case 1:
        {
            std::cout << "Intern creates RobotomyRequestForm" << std::endl;
            return (new RobotomyRequestForm(target));
        }
        case 2:
        {
            std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
            return (new ShrubberyCreationForm(target));
        }
        default:
        {
            std::cerr << "Intern failed to create corresponding form: " << input << std::endl;
            return (NULL);
        }
    }
}

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

Intern::Intern()
{
	std::cout << "\e[0;32mIntern Default constructor called\e[0m" << std::endl;
}

Intern::Intern(const Intern &Cpy)
{
	std::cout << "\e[0;32mIntern Copy constructor called\e[0m" << std::endl;
    (void)Cpy;
}

Intern::~Intern()
{
	std::cout << "\e[0;31mIntern Destructor called\e[0m" << std::endl;
}