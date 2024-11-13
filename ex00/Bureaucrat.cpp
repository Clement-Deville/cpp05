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

const char *TooLowException::what () const throw(){
	return ("Too Low Exception");
}

const char *TooHighException::what () const throw(){
	return ("Too high Exception");
}

TooHighException	Bureaucrat::GradeTooHighException;
TooLowException		Bureaucrat::GradeTooLowException;

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
	std::cout << "\e[0;32mBureaucrat Default constructor called\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &Cpy) : _name(Cpy._name)
{
	std::cout << "\e[0;32mBureaucrat Copy constructor called\e[0m" << std::endl;
	this->_grade = Cpy._grade;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned short newGrade): _name(name)
{
	std::cout << "\e[0;32mBureaucrat NewGrade constructor called\e[0m" << std::endl;
	if (newGrade == 0)
		throw GradeTooHighException;
	if (newGrade >= 150)
		throw GradeTooLowException;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mBureaucrat Destructor called\e[0m" << std::endl;
}

unsigned short	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}


std::ostream & operator<<(std::ostream &out, const Bureaucrat B)
{
	out << "My name is: " << B.getName() << " and my grade is: " << B.getGrade() << std::endl;
	return (out);
}

