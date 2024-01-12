#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define FIRST_NAME 1
# define LAST_NAME 2
# define NICKNAME 3
# define PHONE_NUMBER 4
# define DARKEST_SECRRET 5

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		int		check_input_error(std::string input, int type);
		void	search_contact(void);
		int		check_index_existence(std::string idx);
	private:
		Contact	contacts[8];
		int			index;
};

#endif
