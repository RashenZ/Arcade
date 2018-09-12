//
// EPITECH PROJECT, 2018
// arcade
// File description:
// main.cpp
//

#include "Arcade.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (84);	
	try {
		Arcade	*arcade = new Arcade(av[1]);

		arcade->loadDirLibs("./lib", arcade->LGRAPHICALS);
		arcade->loadDirLibs("./games", arcade->LGAMES);
		arcade->start();
	} catch (const std::exception &e) {
		std::cout << "Problem occured with the given library" << std::endl;
		return (84);
	}
	return 0;
}
