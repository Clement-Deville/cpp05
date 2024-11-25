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

/**------------------------------------------------------------------------
 *                           Custom exception functions
 *------------------------------------------------------------------------**/

const char *Bureaucrat::GradeTooLowException::what () const throw(){
	return ("Bureaucrat: Too Low Exception");
}

const char *Bureaucrat::GradeTooHighException::what () const throw(){
	return ("Bureaucrat: Too high Exception");
}

const char *Bureaucrat::NameEmptyException::what () const throw(){
	return ("Bureaucrat: Empty Name Exception");
}

/**------------------------------------------------------------------------
 *                           Constructors/Destructors
 *------------------------------------------------------------------------**/

Bureaucrat::Bureaucrat() : _name(""), _grade(1)
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
		throw Bureaucrat::GradeTooHighException();
	if (newGrade < 0)
		throw std::out_of_range("out of range");
	if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (name.empty() || onlyWhiteSpace(name))
		throw Bureaucrat::NameEmptyException();
	this->_grade = newGrade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mBureaucrat Destructor called\e[0m" << std::endl;
}

int	Bureaucrat::getGrade(void) const
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
};

/**--------------------------------------------
 *               Aritmetics operators
 *---------------------------------------------**/

Bureaucrat	&Bureaucrat::operator++(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat tmp(*this);

	++(*this);
	return (tmp);
}

Bureaucrat &Bureaucrat::operator+=(int value)
{
	if (this->_grade - value < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= value;
	return (*this);
}

Bureaucrat	&Bureaucrat::operator--(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat tmp(*this);

	--(*this);
	return (tmp);
}

Bureaucrat &Bureaucrat::operator-=(int value)
{
	if (this->_grade + value < 0)
		throw std::out_of_range("out of range");
	if (this->_grade + value > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += value;
	return (*this);
}

/**--------------------------------------------
 *               Utils
 *---------------------------------------------**/

bool onlyWhiteSpace(const std::string name)
{
	for (int i = 0; name[i]; i++)
	{
		if (std::isspace(name[i]) == false)
			return (false);
	}
	return (true);
}

void	Bureaucrat::signForm(AForm &F)
{
	try
	{
		F.beSigned(*this);
		std::cout << this->_name << " sign "
			<< F.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name <<
			" couldn't sign " << F.getName() <<
			" cause " << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " exec "
			<< form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name <<
			" couldn't exec " << form.getName() <<
			" cause " << e.what() << '\n';
	}
}
