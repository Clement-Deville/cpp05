/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:59:45 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/18 15:00:38 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "string"
# include "iostream"
# include "Bureaucrat.hpp"

class EmptyNameException;
class Bureaucrat;

class AForm
{
protected:
	const std::string	_name;
	const int			_GradeToSign;
	const int			_GradeToExec;
	bool				_is_signed;
public:
	AForm();
	AForm(const AForm &Cpy);
	AForm(const std::string name,
		int newGradeToExec, int newGradeToSign, bool issigned);
	virtual ~AForm();

	AForm & operator=(const AForm &Cpy);

	int			getGradeToExec(void) const;
	int			getGradeToSign(void) const;
	std::string	getName(void) const;
	bool		getSigned(void) const;

	void			beSigned(const Bureaucrat &B);
	virtual	void	execute(Bureaucrat const & executor) const = 0;

	static std::out_of_range	GradeTooHighException;
	static std::out_of_range	GradeTooLowException;
	static EmptyNameException	NameEmptyException;
};

std::ostream & operator<<(std::ostream &out, const AForm &B);

#endif
