/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:25 by cdeville          #+#    #+#             */
/*   Updated: 2024/10/28 13:05:44 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class TooHighException: public std::exception
{
	public:
	virtual const char *what(void) const throw();
};

class TooLowException: public std::exception
{
	public:
	virtual const char *what(void) const throw();
};

class EmptyNameException: public std::exception
{
	public:
	virtual const char *what(void) const throw();
};

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &Cpy);
	Bureaucrat(const std::string name, int newGrade);
	virtual ~Bureaucrat();

	Bureaucrat & operator=(const Bureaucrat &Cpy);
	Bureaucrat &operator++(void);
	Bureaucrat operator++(int);
	Bureaucrat &operator+=(int value);
	Bureaucrat &operator--(void);
	Bureaucrat operator--(int);
	Bureaucrat &operator-=(int value);

	int getGrade(void) const;
	std::string getName(void) const;
	class GradeTooHighException: public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};

	class NameEmptyException: public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	// static TooHighException		GradeTooHighException;
	// static TooLowException		GradeTooLowException;
	// static EmptyNameException	NameEmptyException;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B);

#endif
