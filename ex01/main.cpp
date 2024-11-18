/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:06:34 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/18 15:22:06 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <sstream>

int	main(void)
{
	Bureaucrat	thiery = Bureaucrat("Thiery", 3);
	Bureaucrat	thiery_copy = thiery;
	Bureaucrat	sophie = Bureaucrat("Sophie", 150);
	Bureaucrat	lou = Bureaucrat("Lou", 20);

	Form		f1 = Form("f1", 1, 75, false);
	Form		f2 = Form("f2", 1, 2, false);
	Form		f3 = Form("f3", 1, 20, false);


	std::cout << "--> Create a form with grade too high: \n";
	try
	{
		Form	f4 = Form("f4", 1, 184, false);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Create a form with grade too high: \n";
	try
	{
		Form	f4 = Form("f4", 1, 0, false);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> SignForm: Sophie sign F1: \n";
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

	std::cout << "--> SignForm: Lou sign F3: \n";
	try
	{
		lou.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--> Duplicate SignForm: Thierry sign F3: \n";
	try
	{
		thiery.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--> Duplicate SignForm: Thierry sign F3: \n";
	try
	{
		Form f4("f4", 1, 150, 0);
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
