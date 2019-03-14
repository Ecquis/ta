// TA1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Enrolle.h"
#include "time.h"

using namespace std;

const int n = 1000000; // number of elements in array
int coef1, coef2, coef3;

void ReadFromFile(Enrolle enr[]) {

}

void CalculateRating(Enrolle enr[]) {
	float start_time = clock();
	for (int i = 0; i < n; i ++) {
		enr[i].ratMark = enr[i].ex1*coef1 + enr[i].ex2*coef2 + enr[i].ex3*coef3 + 
						 enr[i].certMark * (1 - (coef1 + coef2 + coef3));
	}
	float finish_time = clock();
	cout << "Rating calculation time: " << finish_time - start_time << " ms\n";
}

// insertion sort
void SortEnrolles(Enrolle enr[]) {
	Enrolle key;
	int index;
	float start_time = clock();
	for (int i = 1; i < n; i++) {
		key = enr[i];
		index = i - 1;
		while (index >= 0 && enr[index].ratMark < key.ratMark) {
			enr[index + 1] = enr[index];
			index--;
		}
		enr[index + 1] = key;
	}
	float finish_time = clock();
	cout << "Sorting time: " << finish_time - start_time << " ms\n";
}

// used for debugging. Prints first 5 and last 5 elements in array.
void PrintFiveFirstAndLast(Enrolle enr[]) {
	for (int i = 0; i < 5; i++) {
		cout << enr[i].name << ": ex1=" << enr[i].ex1 << ", ex2=" << enr[i].ex2
			<< ", ex3=" << enr[i].ex3 << ", certMark=" << enr[i].certMark
			<< "; rating=" << enr[i].ratMark << '\n';
	}
	cout << "...\n";
	for (int i = n - 5; i < n; i++) {
		cout << enr[i].name << ": ex1=" << enr[i].ex1 << ", ex2=" << enr[i].ex2
			<< ", ex3=" << enr[i].ex3 << ", certMark=" << enr[i].certMark
			<< "; rating=" << enr[i].ratMark << '\n';
	}
	cout << '\n';
}

int main()
{
	Enrolle enr[n];
	ReadFromFile(enr);
	cout << "-----------------------------\n";
	CalculateRating(enr);
	cout << "-----------------------------\n";
	cout << "Some of elements before processing:\n";
	PrintFiveFirstAndLast(enr);
	cout << "------------------\n";
	SortEnrolles(enr);
	cout << "------------------\n";
	cout << "Some of elements after processing:\n";
	PrintFiveFirstAndLast(enr);
}
