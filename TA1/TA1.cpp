// TA1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Enrolle.h"

using namespace std;

int main()
{
	Enrolle enr[1000000];
	ReadFromFile(enr);
	CalculateRating(enr);
	SortEnrolles(enr);
}

void ReadFromFile(Enrolle enr[]) {
	std::cout << "Lexa - cross";
}

void CalculateRating(Enrolle enr[]) {
	cout << "Lexa";
}

void SortEnrolles(Enrolle enr[]) {

}