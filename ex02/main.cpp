/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 11:09:48 by cdeville          #+#    #+#             */
/*   Updated: 2024-11-26 11:09:48 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main(void)
{
    std::cout << 
    "/**========================================================================\n" <<
    "*                           TESTING SHRUBBERY\n" <<
    "*========================================================================**/" << std::endl;
    {
        std::cout << "\nCREATING BUREAUCRAT\n\n";

        Bureaucrat	thiery = Bureaucrat("Thiery", 3);
        Bureaucrat	thiery_copy = thiery;
        Bureaucrat	sophie = Bureaucrat("Sophie", 150);

        std::cout << "\nCREATING FORMS\n\n";

        ShrubberyCreationForm		f1 = ShrubberyCreationForm("ADA");
	    ShrubberyCreationForm		f2 = ShrubberyCreationForm("Ferrari");
	    ShrubberyCreationForm		f3 = ShrubberyCreationForm("Leclerc");

        std::cout << "\nTESTING ERRORS\n\n";

        std::cout << "--> Create a ShrubberyCreationForm with no target: \n\n";
        try
        {
            ShrubberyCreationForm	f4 = ShrubberyCreationForm("");
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> EXECUTE UNSIGNED FORM: \n\n";
        try
        {
            thiery.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> EXECUTE FORM WITH GRADE TO LOW: \n\n";
        try
        {
            thiery.signForm(f1);
            sophie.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> EXECUTE FORM WITH NO NAME BUREAUCRAT: \n\n";
        try
        {
            ShrubberyCreationForm tmp = ShrubberyCreationForm("ADA");
            Bureaucrat empty;
            thiery.signForm(tmp);
            empty.executeForm(tmp);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> SIGN FORM 2 TIMES: \n\n";
        try
        {
            thiery.signForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO SIGN WITH GRADE REQUIRED + 1: \n\n";
        try
        {
            ShrubberyCreationForm tmp = ShrubberyCreationForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToSign() + 1);
            empty.signForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO EXEC WITH GRADE REQUIRED + 1: \n\n";
        try
        {
            ShrubberyCreationForm tmp = ShrubberyCreationForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToExec() + 1);
            empty.executeForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO SIGN UNAMED FORM: \n\n";
        try
        {
            ShrubberyCreationForm tmp = ShrubberyCreationForm();
            Bureaucrat empty("Default", tmp.getGradeToExec() - 1);
            empty.signForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO EXEC UNAMED FORM: \n\n";
        try
        {
            ShrubberyCreationForm tmp = ShrubberyCreationForm();
            Bureaucrat empty("Default", tmp.getGradeToExec() - 1);
            empty.executeForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout <<    "\n/**======================\n" <<
                        "**      TESTING THINGS\n" << 
                        "**      THAT SHOULD WORK\n" <<
                        "*========================**/" << std::endl;

        std::cout << "\n--> TRY TO SIGN WITH GRADE REQUIRED: \n\n";
        try
        {
            ShrubberyCreationForm tmp = ShrubberyCreationForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToExec());
            empty.signForm(tmp);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO EXEC WITH GRADE REQUIRED: \n\n";
        try
        {
            ShrubberyCreationForm tmp = ShrubberyCreationForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToExec());
            empty.signForm(tmp);
            empty.executeForm(tmp);
            std::cout << "\n\nCHECK IF FILE Default_shruberry EXIST" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\nDESTRUCTORS\n\n";
    }

    std::cout << 
    "/**========================================================================\n" <<
    "*                           TESTING ROBOTOMY\n" <<
    "*========================================================================**/" << std::endl;
    {
        std::cout << "\nCREATING BUREAUCRAT\n\n";

        Bureaucrat	thiery = Bureaucrat("Thiery", 3);
        Bureaucrat	thiery_copy = thiery;
        Bureaucrat	sophie = Bureaucrat("Sophie", 150);

        std::cout << "\nCREATING FORMS\n\n";

        RobotomyRequestForm		f1 = RobotomyRequestForm("ADA");
	    RobotomyRequestForm		f2 = RobotomyRequestForm("Ferrari");
	    RobotomyRequestForm		f3 = RobotomyRequestForm("Leclerc");

        std::cout << "\nTESTING ERRORS\n\n";

        std::cout << "--> Create a ShrubberyCreationForm with no target: \n\n";
        try
        {
            RobotomyRequestForm	f4 = RobotomyRequestForm("");
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> EXECUTE UNSIGNED FORM: \n\n";
        try
        {
            thiery.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> EXECUTE FORM WITH GRADE TO LOW: \n\n";
        try
        {
            thiery.signForm(f1);
            sophie.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> EXECUTE FORM WITH NO NAME BUREAUCRAT: \n\n";
        try
        {
            RobotomyRequestForm tmp = RobotomyRequestForm("ADA");
            Bureaucrat empty;
            thiery.signForm(tmp);
            empty.executeForm(tmp);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> SIGN FORM 2 TIMES: \n\n";
        try
        {
            thiery.signForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO SIGN WITH GRADE REQUIRED + 1: \n\n";
        try
        {
            RobotomyRequestForm tmp = RobotomyRequestForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToSign() + 1);
            empty.signForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO EXEC WITH GRADE REQUIRED + 1: \n\n";
        try
        {
            RobotomyRequestForm tmp = RobotomyRequestForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToExec() + 1);
            empty.executeForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO SIGN UNAMED FORM: \n\n";
        try
        {
            RobotomyRequestForm tmp = RobotomyRequestForm();
            Bureaucrat empty("Default", tmp.getGradeToExec() - 1);
            empty.signForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO EXEC UNAMED FORM: \n\n";
        try
        {
            RobotomyRequestForm tmp = RobotomyRequestForm();
            Bureaucrat empty("Default", tmp.getGradeToExec() - 1);
            empty.executeForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout <<    "\n/**======================\n" <<
                        "**      TESTING THINGS\n" << 
                        "**      THAT SHOULD WORK\n" <<
                        "*========================**/" << std::endl;

        std::cout << "\n--> TRY TO SIGN WITH GRADE REQUIRED: \n\n";
        try
        {
            RobotomyRequestForm tmp = RobotomyRequestForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToExec());
            empty.signForm(tmp);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO EXEC WITH GRADE REQUIRED: \n\n";
        try
        {
            RobotomyRequestForm tmp = RobotomyRequestForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToExec());
            empty.signForm(tmp);
            empty.executeForm(tmp);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\nDESTRUCTORS\n\n";
    }

    std::cout << 
    "/**========================================================================\n" <<
    "*                           TESTING Presidential Pardon\n" <<
    "*========================================================================**/" << std::endl;
    {
        std::cout << "\nCREATING BUREAUCRAT\n\n";

        Bureaucrat	thiery = Bureaucrat("Thiery", 3);
        Bureaucrat	thiery_copy = thiery;
        Bureaucrat	sophie = Bureaucrat("Sophie", 150);

        std::cout << "\nCREATING FORMS\n\n";

        PresidentialPardonForm		f1 = PresidentialPardonForm("ADA");
	    PresidentialPardonForm		f2 = PresidentialPardonForm("Ferrari");
	    PresidentialPardonForm		f3 = PresidentialPardonForm("Leclerc");

        std::cout << "\nTESTING ERRORS\n\n";

        std::cout << "--> Create a ShrubberyCreationForm with no target: \n\n";
        try
        {
            PresidentialPardonForm	f4 = PresidentialPardonForm("");
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> EXECUTE UNSIGNED FORM: \n\n";
        try
        {
            thiery.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> EXECUTE FORM WITH GRADE TO LOW: \n\n";
        try
        {
            thiery.signForm(f1);
            sophie.executeForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> EXECUTE FORM WITH NO NAME BUREAUCRAT: \n\n";
        try
        {
            PresidentialPardonForm tmp = PresidentialPardonForm("ADA");
            Bureaucrat empty;
            thiery.signForm(tmp);
            empty.executeForm(tmp);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> SIGN FORM 2 TIMES: \n\n";
        try
        {
            thiery.signForm(f1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO SIGN WITH GRADE REQUIRED + 1: \n\n";
        try
        {
            PresidentialPardonForm tmp = PresidentialPardonForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToSign() + 1);
            empty.signForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO EXEC WITH GRADE REQUIRED + 1: \n\n";
        try
        {
            PresidentialPardonForm tmp = PresidentialPardonForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToExec() + 1);
            empty.executeForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO SIGN UNAMED FORM: \n\n";
        try
        {
            PresidentialPardonForm tmp = PresidentialPardonForm();
            Bureaucrat empty("Default", tmp.getGradeToExec() - 1);
            empty.signForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO EXEC UNAMED FORM: \n\n";
        try
        {
            PresidentialPardonForm tmp = PresidentialPardonForm();
            Bureaucrat empty("Default", tmp.getGradeToExec() - 1);
            empty.executeForm(tmp);

        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout <<    "\n/**======================\n" <<
                        "**      TESTING THINGS\n" << 
                        "**      THAT SHOULD WORK\n" <<
                        "*========================**/" << std::endl;

        std::cout << "\n--> TRY TO SIGN WITH GRADE REQUIRED: \n\n";
        try
        {
            PresidentialPardonForm tmp = PresidentialPardonForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToExec());
            empty.signForm(tmp);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\n--> TRY TO EXEC WITH GRADE REQUIRED: \n\n";
        try
        {
            PresidentialPardonForm tmp = PresidentialPardonForm("ADA");
            Bureaucrat empty("Default", tmp.getGradeToExec());
            empty.signForm(tmp);
            empty.executeForm(tmp);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        std::cout << "\nDESTRUCTORS\n\n";
    }
    return (0);
}