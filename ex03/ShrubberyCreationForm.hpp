/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:03:31 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/25 16:21:53 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &Cpy);
	ShrubberyCreationForm(const std::string target);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm & operator=(const ShrubberyCreationForm &Cpy);

	virtual	void	execute(Bureaucrat const & executor) const;
};

void	printASCITree(std::ostream &out);

#endif


