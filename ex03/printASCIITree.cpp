/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printASCIITree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:01:21 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/25 13:02:45 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <dirent.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>


void	printASCITree(std::ostream &out)
{
	std::srand(std::time(0));
	switch (std::rand() % 3)
	{
	case 0:
	{
		out <<
		"                                             .         ;" << "\n" <<
		"                .              .              ;%     ;;" << "\n" <<
		"                  ,           ,                :;%  %;" << "\n" <<
		"                   :         ;                   :;%;\'     .," << "\n" <<
		"          ,.        %;     %;            ;        %;\'    ,;" << "\n" <<
		"            ;       ;%;  %%;        ,     %;    ;%;    ,%\'" << "\n" <<
		"             %;       %;%;      ,  ;       %;  ;%;   ,%;\'" << "\n" <<
		"              ;%;      %;        ;%;        % ;%;  ,%;\'" << "\n" <<
		"               `%;.     ;%;     %;\'         `;%%;.%;\'" << "\n" <<
		"                `:;%.    ;%%. %@;        %; ;@%;%\'" << "\n" <<
		"                   `:%;.  :;bd%;          %;@%;\'" << "\n" <<
		"                     `@%:.  :;%.         ;@@%;\'" << "\n" <<
		"                       `@%.  `;@%.      ;@@%;" << "\n" <<
		"                         `@%%. `@%%    ;@@%;" << "\n" <<
		"                           ;@%. :@%%  %@@%;" << "\n" <<
		"                             %@bd%%%bd%%:;" << "\n" <<
		"                               #@%%%%%:;;" << "\n" <<
		"                               %@@%%%::;" << "\n" <<
		"                               %@@@%(o);  .  " << "\n" <<
		"                               %@@@o%;:(.," << "\n" <<
		"                           `.. %@@@o%::;" << "\n" <<
		"                              `)@@@o%::;" << "\n" <<
		"                               %@@(o)::;" << "\n" <<
		"                              .%@@@@%::;" << "\n" <<
		"                              ;%@@@@%::;." << "\n" <<
		"                             ;%@@@@%%:;;;." << "\n" <<
		"                         ...;%@@@@@%%:;;;;,.." << std::endl;
	}
	break;
	case 1:
	{
		out <<
		"            .        +          .      .          ." << "\n" <<
		"     .            _        .                    ." << "\n" <<
		"  ,              /;-._,-.____        ,-----.__" << "\n" <<
		" ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << "\n" <<
		"  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << "\n" <<
		"                      ,    `./  \\:. `.   )==-\'  ." << "\n" <<
		"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << "\n" <<
		".           \\/:/`-\' , ,\\ \'` ` `   ): , /_  -o" << "\n" <<
		"       .    /:+- - + +- : :- + + -:\'  /(o-) \\)     ." << "\n" <<
		"  .      ,=\':  \\    ` `/` \' , , ,:\' `\'--\".--\"---._/`7" << "\n" <<
		"   `.   (    \\: \\,-._` ` + \'\\, ,\"   _,--._,---\":.__/" << "\n" <<
		"              \\:  `  X` _| _,\\/\'   .-\'" << "\n" <<
		".               \":._:`\\____  /:\'  /      .           ." << "\n" <<
		"                    \\::.  :\\/:\'  /              +" << "\n" <<
		"   .                 `.:.  /:\'  }      ." << "\n" <<
		"           .           ):_(:;   \\           ." << "\n" <<
		"                      /:. _/ ,  |" << "\n" <<
		"                   . (|::.     ,`                  ." << "\n" <<
		"     .                |::.    {" << "\n" <<
		"                      |::.\\  \\ `." << "\n" <<
		"                      |:::(\\    |" << "\n" <<
		"              O       |:::/{ }  |                  (o" << "\n" <<
		"               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << "\n" <<
		"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << "\n" <<
		"      ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~" << "\n" << std::endl;
	}
	break;
	case 2:
	{
		out <<
		"     ccee88oo" << "\n" <<
		"  C8O8O8Q8PoOb o8oo" << "\n" <<
		" dOB69QO8PdUOpugoO9bD" << "\n" <<
		"CgggbU8OU qOp qOdoUOdcb" << "\n" <<
		"    6OuU  /p u gcoUodpP" << "\n" <<
		"      \\\\\\//  /douUP" << "\n" <<
		"        \\\\\\////" << "\n" <<
		"         |||/\\" << "\n" <<
		"         |||\\/" << "\n" <<
		"         |||||" << "\n" <<
		"   .....//||||\\...." << std::endl;
	}
	break;
}
}
