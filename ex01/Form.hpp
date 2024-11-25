/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:59:45 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/25 12:43:45 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "string"
# include "iostream"
# include "Bureaucrat.hpp"

class EmptyNameException;
class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_GradeToSign;
	const int			_GradeToExec;
	bool				_is_signed;
public:
	Form();
	Form(const Form &Cpy);
	Form(const std::string name,
		int newGradeToExec, int newGradeToSign, bool issigned);
	virtual ~Form();

	Form & operator=(const Form &Cpy);

	int			getGradeToExec(void) const;
	int			getGradeToSign(void) const;
	std::string	getName(void) const;
	bool		getSigned(void) const;

	void		beSigned(const Bureaucrat &B);

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
};

std::ostream & operator<<(std::ostream &out, const Form &B);

#endif
