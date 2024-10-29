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
class Bureaucrat
{
private:
	std::string	_name;
	unsigned short _grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &Cpy);
	virtual ~Bureaucrat();

	Bureaucrat & operator=(const Bureaucrat &Cpy);
	Bureaucrat operator++(void);
	Bureaucrat operator++(int);
	Bureaucrat operator--(void);
	Bureaucrat operator--(int);

};

#endif
