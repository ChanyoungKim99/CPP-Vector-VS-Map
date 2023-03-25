#include <iostream>
#include <vector>
#include "Student.h"

using Students = std::vector<Student>;

void AddStudent(Students& v)
{
	std::cout << "[번호] [이름] [점수] : ";
	Student newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)	// 이런 표기법도 가능!
	{
		for (auto& e : v)
		{
			if (e.mNumber == newStudent.mNumber)		// 번호는 중복되면 안되니까!
			{
				std::cout << "중복된 번호입니다." << std::endl;
				return;
			}
		}
		v.push_back(newStudent);
	}
	else
	{
		std::cout << "잘못된 입력입니다." << std::endl;
	}
}

void RemoveStudent(Students& v)
{
	std::cout << "삭제할 번호를 입력하세요 : ";
	int number{};
	if (std::cin >> number)
	{
		for (auto itr = v.begin(); itr != v.end(); itr++)
		{
			if (itr->mNumber == number)
			{
				// 벡터의 erase는 이터레이터만 들어감, 따라서 위와 같이 생성
				v.erase(itr);
				return;
			}
		}
		std::cout << "없는 번호입니다." << std::endl;
	}
	else
	{
		std::cout << "잘못된 번호입니다." << std::endl;
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

	std::cout << "총점 : " << total << ", 평균 : " << total / v.size() << std::endl;
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
		std::cout << "1. 학생 추가" << std::endl
			<< "2. 학생 제거" << std::endl
			<< "3. 전체 학생 출력" << std::endl
			<< "4. 평균 및 총점" << std::endl
			<< "5. 평균 이상 학생 목록" << std::endl
			<< "6. 종료" << std::endl;

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
				std::cout << "잘못된 명령어입니다!" << std::endl;
				break;
		}
	}
}