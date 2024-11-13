/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:06:34 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/13 14:58:26 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::string	name;
	unsigned short tmp;
	while (std::cin.eof() == false)
	{
		try
		{
			std::cout << "Pick name: ";
			std::cin >> name;
			std::cout << "Pick grade: ";
			std::cin >> (unsigned short)tmp;
			Bureaucrat test(name, tmp);
			std::cout << test;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			break;
		}

	}
	return (0);
}
