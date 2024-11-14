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

TooHighException	Bureaucrat::GradeTooHighException;
TooLowException		Bureaucrat::GradeTooLowException;
EmptyNameException	Bureaucrat::NameEmptyException;

bool onlyWhiteSpace(const std::string name)
{
	for (int i = 0; name[i]; i++)
	{
		if (std::isspace(name[i]) == false)
			return (false);
	}
	return (true);
}

const char *TooLowException::what () const throw(){
	return ("Too Low Exception");
}

const char *TooHighException::what () const throw(){
	return ("Too high Exception");
}

const char *EmptyNameException::what () const throw(){
	return ("Empty Name Exception");
}

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
	std::cout << "\e[0;32mBureaucrat Default constructor called\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &Cpy) : _name(Cpy._name)
{
	std::cout << "\e[0;32mBureaucrat Copy constructor called\e[0m" << std::endl;
	this->_grade = Cpy._grade;
}

Bureaucrat::Bureaucrat(const std::string name, int newGrade): _name(name)
{
	std::cout << "\e[0;32mBureaucrat NewGrade constructor called\e[0m" << std::endl;
	if (newGrade == 0)
		throw GradeTooHighException;
	if (newGrade < 0)
		throw std::out_of_range("out of range");
	if (newGrade > 150)
		throw GradeTooLowException;
	if (name.empty() || onlyWhiteSpace(name))
		throw NameEmptyException;
	this->_grade = newGrade;
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

std::ostream & operator<<(std::ostream &out, const Bureaucrat &B)
{
	out << B.getName() << ", bureaucrat grade " << B.getGrade() << std::endl;
	return (out);
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &Cpy)
{
	std::cout << "\e[0;32mBureaucrat assignement operator called\e[0m" << std::endl;
	this->_grade = Cpy._grade;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(void)
{
	if (this->_grade == 1)
		throw GradeTooHighException;
	this->_grade++;
	return (*this);
}

Bureaucrat &Bureaucrat::operator+=(int value)
{
	if (this->_grade - value < 1)
		throw GradeTooHighException;
	this->_grade -= value;
	return (*this);
}

Bureaucrat Bureaucrat::operator--(void)
{
	if (this->_grade == 150)
		throw GradeTooLowException;
	this->_grade--;
	return (*this);
}

Bureaucrat &Bureaucrat::operator-=(int value)
{
	if (this->_grade + value < 0)
		throw std::out_of_range("out of range");
	if (this->_grade + value > 150)
		throw Bureaucrat::GradeTooLowException;
	this->_grade += value;
	return (*this);
}
