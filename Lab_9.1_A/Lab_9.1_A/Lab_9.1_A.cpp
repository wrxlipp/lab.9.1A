#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
#include <stdarg.h>
#include <conio.h>
#include <string>

using namespace std;

enum Spec { Ð², ÊÍ, ÏÌ };
const char* strSpec[] = { "Ð²", "ÊÍ", "ÏÌ" };
const char* Convert(Spec c) {
	return strSpec[c];
}

struct Student {
	string prizv;
	int kurs;
	Spec spec;
	unsigned fis;
	unsigned math;
	unsigned infor;
};

void Create(Student* s, const int n) {
	int p;

	for (int i = 0; i < n; i++) {
		cout << "Student # " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << "Surname: "; getline(cin, s[i].prizv);
		cout << "Course: "; cin >> s[i].kurs;
		cout << "Spec (0 - RI, 1 - KN, 2 - PM): ";
		cin >> p;
		s[i].spec = (Spec)p;
		cout << "Scores" << endl;
		cout << endl;
		cout << "Physics: "; cin >> s[i].fis;
		cout << "Math: "; cin >> s[i].math;
		cout << "Informatics: "; cin >> s[i].infor;
	}
}

void Table(Student* s, const int n)
{
	cout << fixed;
	cout << "|" << setw(30) << "Student" << setw(28) << "   |" << endl;
	cout << "-----------------------------------------------------------" << endl;

	cout << "|" << setw(10) << "Surname" << "  |  "
		<< setw(3) << "Course" << "  |  "
		<< setw(3) << "Spec" << "  |"
		<< setw(3) << "Phys" << "  |  "
		<< setw(3) << "Meth" << "  |  "
		<< setw(3) << "Infor" << "  |" << endl;

	cout << "-----------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		cout << "|  " << setw(2); cout << s[i].prizv << "  |  " << setw(5);
		cout << s[i].kurs << "  |" << setw(5);
		cout << Convert(s[i].spec) << "  |  " << setw(5);
		cout << s[i].fis << "  |" << setw(6);
		cout << s[i].math << "  |" << setw(6);
		cout << s[i].infor << "  |" << setw(6) << endl;
		cout << "-----------------------------------------------------------" << endl;
	}
}

int Count1(Student* s, const int n) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (s[i].fis > 3 && s[i].math > 3 && s[i].infor > 3)
			c++;
	}
	return c;
}

void Count2(Student* s, const int n) {
	double e = 0, proc;
	for (int i = 0; i < n; i++) {
		if ((s[i].fis + s[i].math + s[i].infor) / 3 < 4)
			e++;
	}
	proc = (e / n) * 100;
	cout << "% srudent with awerage score 4: " << setprecision(2) << proc << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, c;
	cout << "N: "; cin >> n;

	Student* s = new Student[n];

	Create(s, n);
	Table(s, n);
	c = Count1(s, n);
	cout << "Students without 3: " << c << endl;
	Count2(s, n);

	delete[] s;
	system("pause");
	return 0;
}