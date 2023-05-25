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
		cout << "�������� ����� ����: " << endl;
		cout << scan_from_keyboard << " - ������ � ����������" << endl
			<< scan_from_file << " - ������ �� �����" << endl
			<< print_to_display << " - ����� �� �����" << endl
			<< print_to_file << " - ����� � ����" << endl
			<< debtors << " - ������ ��������� �� ��������" << endl
			<< grades << " -  ������ ��������� � ����������� ������� �� ��������" << endl
			<< gpa << " - ������ ��������� � �� ������� ������" << endl
			<< exit_programm << " - �����" << endl;
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
			cout << "������� �������� ����� ";
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
			cout << "������� �������� ����� ";
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
			cout << "������� ������ ";
			cin >> grade;
			InstSession::grades_for_subject(students, number_of_students, subject, grade);
		}
		case gpa:
		{
			cout << "�������� ������";
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