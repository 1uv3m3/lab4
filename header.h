#pragma once

#include <iostream>
#include <string>

const size_t number_of_subjects = 4;

struct subject_grade
{
	std::string subject;
	size_t grade;
};

class InstSession
{
	std::string student;
	std::string group;
	subject_grade* grades = new subject_grade[number_of_subjects];

public:
	//конструкторы
	InstSession()
	{
		student = group = "0";
		for (size_t i = 0; i < number_of_subjects; i++) grades[i].grade = 0;
		grades[0].subject = "Математика";
		grades[1].subject = "Физика";
		grades[2].subject = "Программирование";
		grades[3].subject = "Информатика";
	}

	InstSession(std::string surname, std::string gr, size_t * grade)
	{
		student = surname;
		group = gr;
		for (size_t i = 0; i < number_of_subjects; i++) grades[i].grade = grade[i];
	}

	InstSession (const InstSession& t)
	{
		student = t.student;
		group = t.group;
		for (size_t i = 0; i < number_of_subjects; i++) grades[i].grade = t.grades[i].grade;
	}


	//методы
	void scan(std::istream& in)
	{
		if (&in == &std::cin)
			std::cout << "Введите фамилию студента, его группу и оценки по предметам: " <<
				"Математика, Физика, Программирование и Информатика. ";
		in >> student >> group;
		for (size_t i = 0; i < number_of_subjects; i++) in >> grades[i].grade;
	}

	static InstSession* array_input(std::istream& in, size_t &number_of_students)
	{
		if (&in == &std::cin)
			std::cout << "Введите количество студентов: ";
		in >> number_of_students;
		InstSession* students = new InstSession[number_of_students];
		for (size_t i = 0; i < number_of_students; i++)
		{
			students[i].scan(in);
		}
		return students;
	}

	void print(std::ostream& out) const
	{
		out << student << " " << group << std::endl;
		for (size_t i = 0; i < number_of_subjects; i++)
		{
			out << grades[i].subject << " " << grades[i].grade << std::endl;
		}
	}

	static void array_output(InstSession* students, size_t number_of_students, std::ostream& out)
	{
		for (size_t i = 0; i < number_of_students; i++)
		{
			students[i].print(out);
		}
	}


	//проверки
	bool is_debt(size_t subject) const
	{
		return (grades[subject].grade == 2);
	}

	bool had_grade(size_t subject, size_t grade) const
	{
		return (grades[subject].grade == grade);
	}

	double gpa() const
	{
		double summary = 0;
		for (size_t i = 0; i < number_of_subjects; i++)
			summary += grades[i].grade;
		return summary /= (double)number_of_subjects;
	}


	//выборки
	static void debtors(InstSession* students, size_t number_of_students,
		size_t subject)
	{
		for (size_t i = 0; i < number_of_students; i++)
			if (students[i].is_debt(subject))
				std::cout << students[i].student << std::endl;
	}

	static void grades_for_subject(InstSession* students, size_t number_of_students,
		size_t subject, size_t grade)
	{
		for (size_t i = 0; i < number_of_students; i++)
		{
			if (students[i].had_grade(subject, grade))
				std::cout << students[i].student << std::endl;
		}
	}

	static void gpa_in_group(InstSession* students, size_t number_of_students,
		std::string group)
	{
		for (size_t i = 0; i < number_of_students; i++)
		{
			if (group == students[i].group)
			{
				std::cout << students[i].student << " " << students[i].gpa() << std::endl;
			}
		}
	}
};


//функции
size_t choise_subject();