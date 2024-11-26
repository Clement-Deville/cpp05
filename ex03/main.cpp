/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:06:34 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/25 17:34:03 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sstream>

int	main(void)
{
	std::cout <<
	 	"/**========================================================================\n"
	 	"*                           TESTING ShrubberyCreationForm					\n"
	 	"*========================================================================**//" << std::endl;

	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	Bureaucrat	thiery_copy = thiery;
	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);

	ShrubberyCreationForm		f1 = ShrubberyCreationForm("ADA");
	ShrubberyCreationForm		f2 = ShrubberyCreationForm("Ferrari");
	ShrubberyCreationForm		f3 = ShrubberyCreationForm("Leclerc");


	std::cout << "--> Create a ShrubberyCreationForm with no target: \n";
	try
	{
		ShrubberyCreationForm	f4 = ShrubberyCreationForm("");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Create a ShrubberyCreationForm with no name: \n";
	try
	{
		ShrubberyCreationForm	f4 = ShrubberyCreationForm("ADA");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> signForm: Sophie sign F1: \n";
	try
	{
		sophie.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> BeSigned: Thiery sign F2: \n";
	try
	{
		f2.beSigned(thiery);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> BeSigned: Thierry_copy sign F2: \n";
	try
	{
		f2.beSigned(thiery_copy);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> signForm: Lou sign F3: \n";
	try
	{
		lou.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--> Duplicate signForm: Thierry sign F3: \n";
	try
	{
		thiery.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Duplicate signForm: Thierry sign F3: \n";
	try
	{
		ShrubberyCreationForm f4("EDF");
		Bureaucrat("Low bureaucrat", 150).signForm(f4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Duplicate signForm: Thierry execute F3: \n";
	try
	{
		ShrubberyCreationForm f4("EDF");
		Bureaucrat("Low bureaucrat", 50).signForm(f4);
		Bureaucrat("Low bureaucrat", 50).executeForm(f4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> << OVERLOAD OPERATOR TEST: \n";
	std::cout << f3 << f1 << f2;
	/**========================================================================
	 *                           TESTING PRESIDENTIAL
	 *========================================================================**/

	std::cout <<
	 	"/**========================================================================\n"
	 "*                           TESTING PRESIDENTIAL								\n"
	 "*========================================================================**//" << std::endl;
	{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	Bureaucrat	thiery_copy = thiery;
	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);

	PresidentialPardonForm f1 = PresidentialPardonForm("ADA");
	PresidentialPardonForm		f2 = PresidentialPardonForm("Ferrari");
	PresidentialPardonForm		f3 = PresidentialPardonForm("Leclerc");


	std::cout << "--> Create a ShrubberyCreationForm with no target: \n";
	try
	{
		PresidentialPardonForm	f4 = PresidentialPardonForm("");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Create a ShrubberyCreationForm with no name: \n";
	try
	{
		PresidentialPardonForm	f4 = PresidentialPardonForm("ADA");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "--> signForm: Sophie sign F1: \n";
	try
	{
		sophie.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> BeSigned: Thiery sign F2: \n";
	try
	{
		f2.beSigned(thiery);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> BeSigned: Thierry_copy sign F2: \n";
	try
	{
		f2.beSigned(thiery_copy);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> signForm: Lou sign F3: \n";
	try
	{
		lou.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--> Duplicate signForm: Thierry sign F3: \n";
	try
	{
		thiery.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Duplicate signForm: Thierry sign F3: \n";
	try
	{
		PresidentialPardonForm f4("EDF");
		Bureaucrat("Low bureaucrat", 150).signForm(f4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> << OVERLOAD OPERATOR TEST: \n";
	std::cout << f3 << f1 << f2;
	}

	/**========================================================================
	 *                           ROBOTOMY TESTING
	 *========================================================================**/

	std::cout <<
	 	"/**========================================================================\n"
	 	"*                           TESTING RobotomyRequestForm					\n"
	 	"*========================================================================**//" << std::endl;

	{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	Bureaucrat	thiery_copy = thiery;
	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);

	RobotomyRequestForm		f1 = RobotomyRequestForm("ADA");
	RobotomyRequestForm		f2 = RobotomyRequestForm("Ferrari");
	RobotomyRequestForm		f3 = RobotomyRequestForm("Leclerc");


	std::cout << "--> Create a ShrubberyCreationForm with no target: \n";
	try
	{
		RobotomyRequestForm	f4 = RobotomyRequestForm("");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Create a ShrubberyCreationForm with no name: \n";
	try
	{
		RobotomyRequestForm	f4 = RobotomyRequestForm("ADA");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "--> signForm: Sophie sign F1: \n";
	try
	{
		sophie.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> BeSigned: Thiery sign F2: \n";
	try
	{
		f2.beSigned(thiery);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> BeSigned: Thierry_copy sign F2: \n";
	try
	{
		f2.beSigned(thiery_copy);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> signForm: Lou sign F3: \n";
	try
	{
		lou.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--> Duplicate signForm: Thierry sign F3: \n";
	try
	{
		thiery.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Duplicate signForm: Thierry sign F3: \n";
	try
	{
		RobotomyRequestForm f4("EDF");
		Bureaucrat("Low bureaucrat", 150).signForm(f4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> << OVERLOAD OPERATOR TEST: \n";
	std::cout << f3 << f1 << f2;
	return 0;
	}
}
