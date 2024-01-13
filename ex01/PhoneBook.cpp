#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = -1;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add_contact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "first name: ";
	std::getline(std::cin, first_name);
	if (this->check_input_error(first_name, FIRST_NAME) == -1)
		return ;
	std::cout << "last name: ";
	std::getline(std::cin, last_name);
	if (this->check_input_error(last_name, LAST_NAME) == -1)
		return ;
	std::cout << "nickname: ";
	std::getline(std::cin, nickname);
	if (this->check_input_error(nickname, NICKNAME) == -1)
		return ;
	std::cout << "phone number: ";
	std::getline(std::cin, phone_number);
	if (this->check_input_error(phone_number, PHONE_NUMBER) == -1)
		return ;
	std::cout << "darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (this->check_input_error(darkest_secret, DARKEST_SECRRET) == -1)
		return ;
	this->index++;
	if (this->index == 8)
		this->index = 0;
	this->contacts[this->index].set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

int	PhoneBook::check_input_error(std::string input, int type)
{
	size_t	i;

	if (std::cin.eof())
	{
		std::cout << "\nError: Ctrl+D detected. exit\n";
		return (-1);
	}
	if (input.empty() == true)
	{
		std::cout << "Error: The input was empty.\n";
		return (-1);
	}
	i = 0;
	while (i < input.size())
	{
		if ((type == FIRST_NAME || type == LAST_NAME) && (std::isalpha(input[i]) == 0))
		{
			std::cout << "Error: The input is invalid.\n";
			return (-1);
		}
		else if ((type == NICKNAME || type == DARKEST_SECRRET) && (std::isalnum(input[i]) == 0))
		{
			std::cout << "Error: The input is invalid.\n";
			return (-1);
		}
		else if ((type == PHONE_NUMBER) && (std::isdigit(input[i]) == 0))
		{
			std::cout << "Error: The input is invalid.\n";
			return (-1);
		}
		i++;
	}
	return (0);
}

void	PhoneBook::search_contact(void)
{
	std::string	idx;
	int					i;

	if (this->index == -1)
	{
		std::cout << "Error: There is not any contact.\n";
		return ;
	}
	i = 0;
	while (i < 8 && this->contacts[i].is_empty() == 0)
	{
		this->contacts[i].display_contact_list(i);
		i++;
	}
	std::cout << "Please select an index for more details.\n";
	std::cin >> idx;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (this->check_index_existence(idx) == -1)
	{
		std::cout << "Error: There is no matching information.\n";
		return ;
	}
	this->contacts[idx[0] - '0'].display_contact_info();
}

int	PhoneBook::check_index_existence(std::string idx)
{
	if (idx.empty() != 0)
		return (-1);
	if (idx.size() != 1)
		return (-1);
	if (idx[0] < '0' || idx[0] > '7')
		return (-1);
	if (this->contacts[idx[0] - '0'].is_empty() != 0)
		return (-1);
	return (0);
}
