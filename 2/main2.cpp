#include <iostream>
#include <map>
#include "Student.h"

/*
std::map
template<
	class Key,													// key
	class T,													// value
	class Comapre = std::less<Key>								// 정렬 방식(오름차순)
	class Allocator = std::allocator<std::pair<const Key, T> >  // 할당 방식(나중에..)
	>
*/

using Students = std::map<int, Student>;		// 번호(int), 정보(Student)

void AddStudent(Students& v)
{
	std::cout << "[번호] [이름] [점수] : ";
	Student newStudent;

	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		//  pair의 사용법
		//	std::pair<int, Student> pair;		<key, value>
		//	pair.first;		// int
		//	pair.second;	// Student

			/*
			v.insert(std::pair<int, Student>(newStudent.mNumber, newStudent));
			*/
			// key, value가 묶인 pair가 와야함

			// insert(원소) 함수에서 원소가 pair<int, Student> 구조체다.
			// 구조체는 유니폼 초기화식으로 간단하게 가능하다!
			// 유니폼 초기화식을 사용한다면,
			/*
			v.insert({ newStudent.mNumber, newStudent });
			*/

			// map은 key가 unique해야 하므로
			// 똑같은 key가 여러개 들어갈 수 없다.
			// 그래서 중복된 key가 들어가는 것을 막을 수 있다.
			// insert 함수는 std::pair<iterator, bool> 타입으로 반환하는 함수다.
			// bool = 실제로 추가(insert) 되었는지 아닌지 
			// iterator = 삽입된 원소의 위치, 혹은 이미 들어있는 원소의 위치

		std::pair<std::map<int, Student>::iterator, bool> result =
			v.insert({ newStudent.mNumber, newStudent });

		if (!result.second)
		{
			std::cout << "중복된 번호입니다" << std::endl;
			return;
		}
	}
	else
	{
		std::cout << "잘못된 입력입니다." << std::endl;
	}
}

void RemoveStudent(Students& v)
{
	std::cout << "삭제할 번호를 입력하세요 : " << std::endl;
	int number{};
	if (std::cin >> number)
	{
		// 벡터의 erase는 이터레이터만 들어감
		// 맵의 erase는 여러가지 형태 존재
		if (v.erase(number) == 0)	// erase가 지울 시 1 반환, 안 지울 시 0 반환
		{
			std::cout << "없는 번호입니다." << std::endl;
		}
	}
	else
	{
		std::cout << "잘못된 입력입니다." << std::endl;
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
	std::cout << "총점 : " << total << ", 평균 : " << total / v.size() << std::endl;
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