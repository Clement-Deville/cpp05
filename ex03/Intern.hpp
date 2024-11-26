/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 14:17:47 by cdeville          #+#    #+#             */
/*   Updated: 2024-11-26 14:17:47 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    static std::string names[3][10];
    static int find_index(const std::string input);
public:
    Intern(void);
    Intern(const Intern &Cpy);
    ~Intern();
    AForm *makeForm(const std::string input, const std::string target) const;
};

#endif