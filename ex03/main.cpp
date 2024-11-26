/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 11:09:48 by cdeville          #+#    #+#             */
/*   Updated: 2024-11-26 11:09:48 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << 
    "/**========================================================================\n" <<
    "*                           TESTING INTERN\n" <<
    "*========================================================================**/" << std::endl;

    std::cout << "\n--> INTERN CONSTRUCTORS \n\n";

    Intern test = Intern();

    std::cout << "\n--> TRY TO ALLOCATE INCORRECT FORM: \n\n";
    try
    {
        AForm *newForm;
        newForm = test.makeForm("incorrect", "goal");
        if (newForm)
        {        
            std::cout << *newForm << std::endl;
            delete newForm;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--> TRY TO ALLOCATE CORRECT FORM WITH NO TARGET: \n\n";
    try
    {
        AForm *newForm;
        newForm = test.makeForm("presidential", "");
        if (newForm)
        {   
            std::cout << *newForm << std::endl;
            delete newForm;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--> TRY TO ALLOCATE EMPTY FORM NAME: \n\n";
    try
    {
        AForm *newForm;
        newForm = test.makeForm("", "");
        if (newForm)
        {   
            std::cout << *newForm << std::endl;
            delete newForm;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
   return (0);
}