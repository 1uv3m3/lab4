#include"header.h"

size_t choise_subject()
{
	size_t subject;
	std::cout << "�������� �������:\n0 - ����������,\n1 - ������"
		<< "\n2 - ����������������\n3 - �����������" << std::endl;
	std::cin >> subject;
	return subject;
}