/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:06:34 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/13 19:29:43 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

bool is_number(const std::string& s) {
	std::istringstream iss(s);
	int d;
	return iss >> d && iss.eof();
}

int	main(void)
{
	std::string	name;
	std::string	tmp_nb;
	int			tmp;
	while (1)
	{
		try
		{
			std::cout << "Pick name: ";
			std::getline(std::cin, name);
			if (std::cin.eof())
				break;
			std::cout << "Pick grade: ";
			std::getline(std::cin, tmp_nb);
			if (std::cin.eof())
				break;
			if(!is_number(tmp_nb))
			{
				std::cerr << "This is not a number" << std::endl;
				continue;
			}
			std::stringstream(tmp_nb) >> tmp;
			Bureaucrat test(name, tmp);
			std::cout << test;
			std::cout << "Pick a grade increment/decrement: ";
			std::getline(std::cin, tmp_nb);
			if (std::cin.eof())
				break;
			if(!is_number(tmp_nb))
			{
				std::cerr << "This is not a number" << std::endl;
				continue;
			}
			std::stringstream(tmp_nb) >> tmp;
			if (tmp > 0)
				test -= tmp;
			else
				test += tmp;
			std::cout << test;
		}
		catch(const EmptyNameException& e)
		{
			std::cerr << e.what() << '\n';
			continue;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			continue;
		}
	}
	std::cout << "\nExit" << std::endl;
	return (0);
}
