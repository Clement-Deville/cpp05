/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:06:34 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/18 12:04:42 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <sstream>

#define YES	1
#define NO	0

bool	is_number(const std::string& s) {
	std::istringstream iss(s);
	int d;
	return iss >> d && iss.eof();
}

bool	compareStrings(int param, std::string &answer)
{
	std::string base;
	std::string little_base;

	if (param == YES)
	{
		base = "yes";
		little_base = "y";
	}
	else
	{
		base = "no";
		little_base = "n";
	}
	if (answer.length() != base.length() && answer.length() != little_base.length())
		return (false);
	for (int i = -1; answer[i] && base[i]; ++i)
	{
		if (tolower(answer[i]) != base[i])
			return (false);
	}
	if (tolower(answer[0]) != little_base[0])
		return (false);
	return (true);
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
			if (!is_number(tmp_nb))
			{
				std::cerr << "This is not a number" << std::endl;
				continue;
			}
			std::stringstream(tmp_nb) >> tmp;
			if (tmp > 0)
				test += tmp;
			else
				test -= -tmp;
			std::cout << test;
		}
		catch (const EmptyNameException& e)
		{
			std::cerr << e.what() << '\n';
			continue;
		}
		catch (const std::exception& e)
		{
			std::string	answer;
			bool		cont;
			std::cerr << e.what() << '\n';
			for (int i = 0; i < 5; i++)
			{
				std::cerr << "Continue? Y/N: ";
				std::getline(std::cin, answer);
				if (std::cin.eof() || compareStrings(NO, answer))
				{
					cont = false;
					break;
				}
				if (compareStrings(YES, answer))
				{
					cont = true;
					break;
				}
			}
			if (!cont)
				break ;
		}
	}
	std::cout << "Exit" << std::endl;
	return (0);
}
