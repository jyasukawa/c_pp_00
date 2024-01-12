#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook		phonebook;
	std::string	input;

	while (1)
	{
		std::cout << "Please enter one of the commands: ADD, SEARCH, or EXIT.\n";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			break;
	}
	return (0);
}
