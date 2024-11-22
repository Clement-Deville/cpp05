/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:39:17 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/22 17:43:56 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception"
#include "string"
#include "iostream"

class test
{
private:
	/* data */
public:
	test();
	~test();

	void calling_exce(void) {
		throw custom();
	};
	class custom : public std::exception
	{
		public:
		virtual const char *what(void) const throw()
		{
			return ("Execption catched");
		};
		// CONSTRUCTOR
		custom(): std::exception()
		{
			std::cout << "Custom constructor called" << std::endl;
		}
	};
};

test::test()
{
	std::cout << "Constructor Test" << std::endl;
}

test::~test()
{
	std::cout << "Destructor Test" << std::endl;
}


int	main(void)
{
	test yo;

	std::cout << "Throwing execption\n";
	try
	{
		yo.calling_exce();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
