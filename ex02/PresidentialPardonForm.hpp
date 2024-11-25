/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:03:31 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/25 15:25:59 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &Cpy);
	PresidentialPardonForm(const std::string target);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm & operator=(const PresidentialPardonForm &Cpy);

	virtual	void	execute(Bureaucrat const & executor) const;
};

void	printASCITree(std::ostream &out);

#endif


