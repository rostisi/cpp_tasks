#include <iostream>
#include "Random.h"
#include "pas_gen.h"

int passwordGeneratorBeginning() // will be executed only once, in the beginning of programm
{
	std::cout << "GM, choose the option:						   \n";
	std::cout << "1. Random password generator.					   \n";
	std::cout << "2. Random password generator with chosen lenght. \n";
	std::cout << "3. Exit.										   \n";

	int decision;
	std::cin >> decision;
	questionsBeginning(decision);

	return 0;
}



int questionsBeginning(int x)
{
	if (x == 1)
	{
		int number = Random::get(1, 100);

		generateNumber(number);

		std::cout << '\n';
		passwordGeneratorEdit();
	}
	if (x == 2)
	{
		std::cout << "Enter lenght of your future password: ";
		int number;
		std::cin >> number;

		generateNumber(number);


		std::cout << '\n';
		passwordGeneratorEdit();
	}
	if (x == 3)
	{
		std::cout << "3\n";
		exit;
	}
	return 0;
}



int passwordGeneratorEdit()     // will be executed as many times as user will want (to edit generated password mostly)
{
	std::cout << "What is going to be your next step: \n";
	std::cout << "1. Edit generated password.		  \n";
	std::cout << "2. Delete generated password.       \n";
	std::cout << "3. Exit.							  \n";

	int decision;
	std::cin >> decision;
	questionsEdit(decision);

	return 0;
}



int questionsEdit(int x)
{
	if (x == 1)
	{
		std::cout << "1. Remove special symbols. \n";
		std::cout << "2. Remove upper letters.   \n";
		std::cout << "3. Remove lower letters.   \n";

		int decision;
		std::cin >> decision;
		if (decision == 1)
		{
			int password_lenght = password.length();
			for (int i = 0; i <= password_lenght; i++)
			{
				char password_symbol = password[i];
				if (password_symbol <= 47 || password_symbol >= 58 && password_symbol <= 64 || password_symbol >= 91 && password_symbol <= 96 || password_symbol >= 123)
				{
					password_symbol = 0;
				}
				else
				{
					return password_symbol;
				}
			}
		}
		
	}
	if (x == 2)
	{
		password = "";
	}
	if (x == 3)
	{
		exit;
	}
	return 0;
}



int generateNumber(int x)
{
	for (int i = 0; i <= x; i++)
	{
		char symbol = Random::get(35, 122);
		password.push_back(symbol);
	}
	std::cout << password;
	return 0;
}

