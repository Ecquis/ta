#pragma once
#include <string>
using namespace std;

class Enrolle
{
	public:
		string name;
		int ex1;
		int ex2;
		int ex3;
		int certMark;
		float ratMark;

		Enrolle(string name, int ex1, int ex2, int ex3, int certMark)
		{
			this->name = name;
			this->ex1 = ex1;
			this->ex2 = ex2;
			this->ex3 = ex3;
			this->certMark = certMark;
		}

};

