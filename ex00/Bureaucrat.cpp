/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:05:29 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/28 17:38:14 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "\e[0;32mBureaucrat Default constructor called\e[0m" << std::endl;
	this->_type = "Bureaucrat";
}

Bureaucrat::Bureaucrat(const Bureaucrat &Cpy)
{
	std::cout << "\e[0;32mBureaucrat Copy constructor called\e[0m" << std::endl;
	this->_type = "Bureaucrat";
	*this = Cpy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mBureaucrat Destructor called\e[0m" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &Cpy)
{
	std::cout << "\e[0;32mBureaucrat Copy assignement operator called\e[0m" << std::endl;
	if (this == &Cpy)
		return (*this);
	return (*this);
}
