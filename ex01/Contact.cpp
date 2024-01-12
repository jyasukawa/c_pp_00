#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::set_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string	darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

int	Contact::is_empty(void)
{
	return (this->first_name.empty());
}

void	Contact::display_contact_list(int index)
{
	std::cout << "|" << std::setw(10) << index << "|";
	this->adjust_to_right_align(this->first_name);
	std::cout << "|";
	this->adjust_to_right_align(this->last_name);
	std::cout << "|";
	this->adjust_to_right_align(this->nickname);
	std::cout << "|" << std::endl;
}

void	Contact::adjust_to_right_align(std::string str)
{
	if (str.size() >= 11)
	{
		str.resize(10);
		str[9] = '.';
		std::cout << str;
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}

void	Contact::display_contact_info(void)
{
	std::cout << "first name     : " << this->first_name << std::endl;
	std::cout << "last name      : " << this->last_name << std::endl;
	std::cout << "nickname       : " << this->nickname << std::endl;
	std::cout << "phone number   : " << this->phone_number << std::endl;
	std::cout << "darkest secret : " << this->darkest_secret << std::endl;
}
