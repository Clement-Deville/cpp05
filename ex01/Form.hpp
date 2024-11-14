/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:59:45 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/14 17:40:35 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "string"
# include "iostream"
# include "Bureaucrat.hpp"

class Form
{
private:
	const		std::string _name;
	bool		_is_signed;
	const int	_GradeToSign;
	const int	_GradeToExec;
public:
	Form();
	Form(const Form &Cpy);
	Form(const std::string name, int newGradeToExec, int newGradeToSign);
	virtual ~Form();

	Form & operator=(const Form &Cpy);

	int			getGradeToExec(void) const;
	int			getGradeToSign(void) const;
	std::string	getName(void) const;
	bool		getSigned(void) const;

	void		beSigned(const Bureaucrat &B);

	static std::out_of_range	GradeTooHighException;
	static std::out_of_range		GradeTooLowException;
	static EmptyNameException	NameEmptyException;
};

#endif
