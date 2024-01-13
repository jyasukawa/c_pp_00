#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void	set_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string	darkest_secret);
		int		is_empty(void);
		void	display_contact_list(int index);
		void	display_contact_info(void);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		void	adjust_to_right_align(std::string str);
};

#endif
