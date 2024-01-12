#include <iostream>

int	main(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			std::cout << (char)std::toupper(argv[i][j]);//(char)で明示的にキャストしないと返り値intになる
			j++;
		}
		i++;
	}
	std::cout << std::endl;//"\n"としないことでバッファーを処理する
	return (0);
}
