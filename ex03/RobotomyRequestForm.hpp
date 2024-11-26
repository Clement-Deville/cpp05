/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:03:31 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/25 16:21:46 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &Cpy);
	RobotomyRequestForm(const std::string target);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm & operator=(const RobotomyRequestForm &Cpy);

	virtual	void	execute(Bureaucrat const & executor) const;
};

void	printASCITree(std::ostream &out);

#endif


