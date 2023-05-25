#include"header.h"

size_t choise_subject()
{
	size_t subject;
	std::cout << "Выберите предмет:\n0 - Математика,\n1 - Физика"
		<< "\n2 - Программирование\n3 - Информатика" << std::endl;
	std::cin >> subject;
	return subject;
}