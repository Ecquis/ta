// TA1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Enrolle.h"
#include "time.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int n = 1000000; // number of elements in array
float coef1, coef2, coef3;
Enrolle enr[n];

void ReadFromFile(string path) {
	ifstream finp(path);
	string line;
	int j = 0;
	while (getline(finp, line))
	{
		
		stringstream lineStream(line);
		string cell;
		int i = 0;
		while (getline(lineStream, cell, ','))
		{
			i++;
			switch (i) {
			case 1: {enr[j].name += cell + ' '; break; }
			case 2: {enr[j].name += cell; break; }
			case 3: {enr[j].ex1 = stoi(cell); break; }
			case 4: {enr[j].ex2 = stoi(cell); break; }
			case 5: {enr[j].ex3 = stoi(cell); break; }
			case 6: {enr[j].certMark = stoi(cell); break; }
			}

		}
		j++;
	}
}

float check() {
	float a;
	for (;;) {
		try
		{
			cin >> a;
			return a;
		}
		catch (const std::exception&)
		{
			cout << "Please enter float";
		}
	}
}


void CalculateRating() {
//<<<<<<< HEAD
//<<<<<<< Updated upstream
//=======
//<<<<<<< Updated upstream
	float start_time = clock();
	for (int i = 0; i < n; i ++) {
		enr[i].ratMark = enr[i].ex1*coef1 + enr[i].ex2*coef2 + enr[i].ex3*coef3 + 
						 (enr[i].certMark *8.33333f + 100)*(1 - (coef1 + coef2 + coef3));
//=======
//>>>>>>> master
	cout << "Enter coef for the first exam\n";
	coef1 = check();
	cout << "Enter coef for the second exam\n";
	coef2 = check();
	cout << "Enter coef for the third exam\n";
	coef3 = check();
//<<<<<<< HEAD
	if (coef1 + coef2 + coef3 <= 0.95f) {
//=======
	if (coef1 + coef2 + coef3 < 0.95f) {
//>>>>>>> master
		float start_time = clock();
		for (int i = 0; i < n; i++) {
			enr[i].ratMark = enr[i].ex1*coef1 + enr[i].ex2*coef2 + enr[i].ex3*coef3 +
				(enr[i].certMark / 12 * 100 + 100)*(1 - (coef1 + coef2 + coef3));
		}
		float finish_time = clock();
		cout << "Rating calculation time: " << finish_time - start_time << " ms\n";
//<<<<<<< HEAD
//>>>>>>> Stashed changes
//=======
//>>>>>>> Stashed changes
//>>>>>>> master
	}
	else
	{
		cout << "coef1 + coef2 + coef3 must be less than 0.95\n";
		CalculateRating();
	}
	
}


// insertion sort
/*
void SortEnrolles() {
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
*/
// used for debugging. Prints first 5 and last 5 elements in array.
	void PrintFiveFirstAndLast() {
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
	cout << "reading from file...\n";
	float start_time = clock();
	ReadFromFile("base.csv");
	float end_time = clock();
	cout << "reading from file completed.\n";
	cout << "Time reading " << end_time - start_time << "ms\n";
	cout << "-----------------------------\n";
	CalculateRating();
	cout << "-----------------------------\n";
	//cout << "Some of elements before processing:\n";
	//PrintFiveFirstAndLast();
	//cout << "------------------\n";
	//SortEnrolles();
	//cout << "------------------\n";
	cout << "Some of elements after processing:\n";
	PrintFiveFirstAndLast();
}
