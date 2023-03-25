#include <iostream>
#include <map>
#include "Student.h"

/*
std::map
template<
	class Key,													// key
	class T,													// value
	class Comapre = std::less<Key>								// ���� ���(��������)
	class Allocator = std::allocator<std::pair<const Key, T> >  // �Ҵ� ���(���߿�..)
	>
*/

using Students = std::map<int, Student>;		// ��ȣ(int), ����(Student)

void AddStudent(Students& v)
{
	std::cout << "[��ȣ] [�̸�] [����] : ";
	Student newStudent;

	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		//  pair�� ����
		//	std::pair<int, Student> pair;		<key, value>
		//	pair.first;		// int
		//	pair.second;	// Student

			/*
			v.insert(std::pair<int, Student>(newStudent.mNumber, newStudent));
			*/
			// key, value�� ���� pair�� �;���

			// insert(����) �Լ����� ���Ұ� pair<int, Student> ����ü��.
			// ����ü�� ������ �ʱ�ȭ������ �����ϰ� �����ϴ�!
			// ������ �ʱ�ȭ���� ����Ѵٸ�,
			/*
			v.insert({ newStudent.mNumber, newStudent });
			*/

			// map�� key�� unique�ؾ� �ϹǷ�
			// �Ȱ��� key�� ������ �� �� ����.
			// �׷��� �ߺ��� key�� ���� ���� ���� �� �ִ�.
			// insert �Լ��� std::pair<iterator, bool> Ÿ������ ��ȯ�ϴ� �Լ���.
			// bool = ������ �߰�(insert) �Ǿ����� �ƴ��� 
			// iterator = ���Ե� ������ ��ġ, Ȥ�� �̹� ����ִ� ������ ��ġ

		std::pair<std::map<int, Student>::iterator, bool> result =
			v.insert({ newStudent.mNumber, newStudent });

		if (!result.second)
		{
			std::cout << "�ߺ��� ��ȣ�Դϴ�" << std::endl;
			return;
		}
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
	}
}

void RemoveStudent(Students& v)
{
	std::cout << "������ ��ȣ�� �Է��ϼ��� : " << std::endl;
	int number{};
	if (std::cin >> number)
	{
		// ������ erase�� ���ͷ����͸� ��
		// ���� erase�� �������� ���� ����
		if (v.erase(number) == 0)	// erase�� ���� �� 1 ��ȯ, �� ���� �� 0 ��ȯ
		{
			std::cout << "���� ��ȣ�Դϴ�." << std::endl;
		}
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
	}
}

void PrintStudents(Students& v)
{
	for (auto& e : v)
	{
		e.second.Print();
	}
}

void PrintScoreInfo(Students& v)
{
	int total{};

	for (auto& e : v)
	{
		total += e.second.mScore;
	}
	std::cout << "���� : " << total << ", ��� : " << total / v.size() << std::endl;
}

void PrintOverAverage(Students& v)
{
	int average{};
	for (auto& e : v)
	{
		average += e.second.mScore;
	}
	average /= v.size();

	for (auto& e : v)
	{
		if (e.second.mScore >= average)
		{
			e.second.Print();
		}
	}
}

int main()
{
	Students students
	{
		{ 1, {1, "Kim", 80}  },
		{ 2, {2, "Lee", 20}  },
		{ 3, {3, "Park", 50} },
		{ 4, {4, "Choi", 30} }
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