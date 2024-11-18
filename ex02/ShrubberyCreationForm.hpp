/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:03:31 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/18 18:54:26 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &Cpy);
	ShrubberyCreationForm(const std::string name);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm & operator=(const ShrubberyCreationForm &Cpy);

	virtual	void	execute(Bureaucrat const & executor) const;
};

#endif


