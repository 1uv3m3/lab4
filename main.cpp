#include<iostream>
#include<string>
#include<fstream>

#include"header.h"

using namespace std;

enum Menu
{
	scan_from_keyboard,
	scan_from_file,
	print_to_display,
	print_to_file,
	debtors,
	grades,
	gpa,
	exit_programm
};

int main()
{
	system("chcp 1251");
	size_t ans;
	InstSession* students = nullptr;
	size_t number_of_students = 0;

	do
	{
		cout << "Выберите пункт меню: " << endl;
		cout << scan_from_keyboard << " - чтение с клавиатуры" << endl
			<< scan_from_file << " - чтение из файла" << endl
			<< print_to_display << " - вывод на экран" << endl
			<< print_to_file << " - вывод в файл" << endl
			<< debtors << " - список должников по предмету" << endl
			<< grades << " -  список студентов с определённой оценкой по предмету" << endl
			<< gpa << " - список студентов и их средних баллов" << endl
			<< exit_programm << " - выход" << endl;
		cin >> ans;

		switch (ans)
		{
		case scan_from_keyboard:
		{
			students = InstSession::array_input(cin, number_of_students);
			break;
		}
		case scan_from_file:
		{
			string file;
			cout << "Введите название файла ";
			cin >> file;
			ifstream fin(file + ".txt");
			students = InstSession::array_input(fin, number_of_students);
			break;
		}
		case print_to_display:
		{
			InstSession::array_output(students, number_of_students, cout);
		}
		case print_to_file:
		{
			string file;
			cout << "Введите название файла ";
			cin >> file;
			ofstream fout(file + ".txt");
			InstSession::array_output(students, number_of_students, fout);
		}
		case debtors:
		{
			size_t subject = choise_subject();
			InstSession::debtors(students, number_of_students, subject);
		}
		case grades:
		{
			size_t grade;
			size_t subject = choise_subject();
			cout << "Введите оценку ";
			cin >> grade;
			InstSession::grades_for_subject(students, number_of_students, subject, grade);
		}
		case gpa:
		{
			cout << "Выберите группу";
			string group;
			cin >> group;
			InstSession::gpa_in_group(students, number_of_students, group);
		}
		case exit_programm:
			break;
		}
	}
	while (ans != exit_programm);
}