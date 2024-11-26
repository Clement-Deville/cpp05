/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:33:16 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/25 18:52:48 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat Jimmy("jimmy", 5);
	Bureaucrat *Louis = new Bureaucrat("Louis", 150);
	Bureaucrat Victor(*Louis);

	std::cout << std::endl;
	std::cout << "Shrubbery Tests" << std::endl;
	AForm *f1 = new ShrubberyCreationForm("toilets");
	std::cout << *f1 << std::endl;
	ShrubberyCreationForm f2("garden");
	std::cout << f2 << std::endl;

	try {
		Louis->signForm(*f1);
	}
	catch (std::exception &e) {
		std::cout <<"Can't sign Form because : ";
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->beSigned(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete f1;

	std::cout << std::endl;
	std::cout << "Robotomy Request Tests" << std::endl;
	f1 = new RobotomyRequestForm(Jimmy.getName());
	std::cout << *f1 << std::endl;
	RobotomyRequestForm f3("Juan");
	std::cout << f3 << std::endl;

	std::cout << Louis->getName() << std::endl;
	for (; Louis->getGrade() > 73; ) {
		++(*Louis);
	}
	std::cout << *Louis << std::endl;
	try {
		f1->beSigned(*Louis);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	++(*Louis);
	std::cout << *Louis << "" << *f1 << std::endl;
	try {
		f1->beSigned(*Louis);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Louis->executeForm(*f1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete f1;

	std::cout << std::endl;
	std::cout << "Presidential Pardon Tests" << std::endl;
	f1 = new PresidentialPardonForm(Jimmy.getName());
	std::cout << *f1 << std::endl;
	PresidentialPardonForm f4(*dynamic_cast<PresidentialPardonForm*>(f1));
	std::cout << f4 << std::endl;

	for (; Louis->getGrade() > 25; ) {
		++(*Louis);
	}
	try {
		Louis->signForm(*f1);
	}
	catch (std::exception &e) {
		std::cout <<"Can't sign Form because : ";
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	++(*Louis);
	try {
		f1->beSigned(*Louis);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Victor);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		f1->execute(Jimmy);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	delete Louis;
	delete f1;
	return (0);
}
