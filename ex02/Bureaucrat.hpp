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
# include "AForm.hpp"

class EmptyNameException: public std::exception
{
	public:
	virtual const char *what(void) const throw();
};

class AForm;

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

	void	signAForm(AForm &F);
	void	executeForm(AForm const & form);

	static	EmptyNameException	NameEmptyException;
	static	std::out_of_range GradeTooHighException;
	static	std::out_of_range GradeTooLowException;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B);
bool onlyWhiteSpace(const std::string name);

#endif
