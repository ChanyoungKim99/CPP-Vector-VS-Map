#include <iostream>
#include <vector>
#include "Student.h"

using Students = std::vector<Student>;

void AddStudent(Students& v)
{
	std::cout << "[��ȣ] [�̸�] [����] : ";
	Student newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)	// �̷� ǥ����� ����!
	{
		for (auto& e : v)
		{
			if (e.mNumber == newStudent.mNumber)		// ��ȣ�� �ߺ��Ǹ� �ȵǴϱ�!
			{
				std::cout << "�ߺ��� ��ȣ�Դϴ�." << std::endl;
				return;
			}
		}
		v.push_back(newStudent);
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
	}
}

void RemoveStudent(Students& v)
{
	std::cout << "������ ��ȣ�� �Է��ϼ��� : ";
	int number{};
	if (std::cin >> number)
	{
		for (auto itr = v.begin(); itr != v.end(); itr++)
		{
			if (itr->mNumber == number)
			{
				// ������ erase�� ���ͷ����͸� ��, ���� ���� ���� ����
				v.erase(itr);
				return;
			}
		}
		std::cout << "���� ��ȣ�Դϴ�." << std::endl;
	}
	else
	{
		std::cout << "�߸��� ��ȣ�Դϴ�." << std::endl;
	}

}

void PrintStudents(Students& v)
{
	for (auto& e : v)
	{
		e.Print();
	}
}

void PrintScoreInfo(Students& v)
{
	int total{};
	for (auto& e : v)
	{
		total += e.mScore;
	}

	std::cout << "���� : " << total << ", ��� : " << total / v.size() << std::endl;
}

void PrintOverAverage(Students& v)
{
	int average{};
	for (auto& e : v)
	{
		average += e.mScore;
	}
	average /= v.size();

	for (auto& e : v)
	{
		if (e.mScore >= average)
		{
			e.Print();
		}
	}
}

int main()
{
	std::vector<Student> students
	{
		{1, "Kim", 80},
		{2, "Lee", 20},
		{3, "Park", 50},
		{4, "Choi", 30}
	};

	bool isExit{ false };
	while (!isExit)
	{
		std::cout << "1. �л� �߰�" << std::endl
			<< "2. �л� ����" << std::endl
			<< "3. ��ü �л� ���" << std::endl
			<< "4. ��� �� ����" << std::endl
			<< "5. ��� �̻� �л� ���" << std::endl
			<< "6. ����" << std::endl;

		int command{};
		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case 1:
				AddStudent(students);
				break;

			case 2:
				RemoveStudent(students);
				break;

			case 3:
				PrintStudents(students);
				break;

			case 4:
				PrintScoreInfo(students);
				break;

			case 5:
				PrintOverAverage(students);
				break;

			case 6:
				isExit = true;
				break;

			default:
				std::cout << "�߸��� ��ɾ��Դϴ�!" << std::endl;
				break;
		}
	}
}