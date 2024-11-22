/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:06:34 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/22 16:54:00 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <sstream>

int	main(void)
{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	Bureaucrat	thiery_copy = thiery;
	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);

	ShrubberyCreationForm		f1 = ShrubberyCreationForm("f1", "ADA");
	ShrubberyCreationForm		f2 = ShrubberyCreationForm("f2", "Ferrari");
	ShrubberyCreationForm		f3 = ShrubberyCreationForm("f3", "Leclerc");


	std::cout << "--> Create a ShrubberyCreationForm with no target: \n";
	try
	{
		ShrubberyCreationForm	f4 = ShrubberyCreationForm("f4","");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Create a ShrubberyCreationForm with no name: \n";
	try
	{
		ShrubberyCreationForm	f4 = ShrubberyCreationForm("","ADA");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "--> SignAForm: Sophie sign F1: \n";
	try
	{
		sophie.signAForm(f1);
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

	std::cout << "--> SignAForm: Lou sign F3: \n";
	try
	{
		lou.signAForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--> Duplicate SignAForm: Thierry sign F3: \n";
	try
	{
		thiery.signAForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Duplicate SignAForm: Thierry sign F3: \n";
	try
	{
		ShrubberyCreationForm f4("f4", "EDF");
		Bureaucrat("Low bureaucrat", 150).signAForm(f4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> << OVERLOAD OPERATOR TEST: \n";
	std::cout << f3 << f1 << f2;
	return 0;
}
