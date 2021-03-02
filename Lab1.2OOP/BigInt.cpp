// BigInt.cpp

#include "BigInt.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool BigInt::Read() {
	unsigned int s;
	cout << " Enter size: "; cin >> s;
	Init(s);

	string t;
	cout << " Enter number: "; cin >> t;
	
	if (t.length() > size) {
		Dispose();
		Init(t.length());
	}

	// Перевірка, що t це зображення числа
	bool flag = true;
	for (int i = 0; i < size; i++) {
		if (t[i] < 48 || t[i] > 57) {
			flag = false;
			break;
		}
	}

	if (flag) {
		int k = t.length() - 1;
		for (int i = 0; i < t.length(); i++, k--) {
			p[k] = (unsigned)t[i] - (unsigned)'0';
		}
	}

	return flag;
}

void BigInt::Display()const {
	for (int i = size - 1; i >= 0; i--) {
		cout << setw(4) << p[i];
	}
	cout << endl;
}

void BigInt::Init(unsigned int value) {
	size = value;
	p = new int[size];

	for (int i = 0; i < size; i++) {
		p[i] = 0;
	}
}

void BigInt::Dispose() {
	delete[] p;
}

void BigInt::Compare(int* num1, int* num2, int s1, int s2) {
	bool num1Bigger = false, equal = false;

	cout << endl;
	if (s1 != s2) { // Якщо розмір не однаковий
		if (s1 > s2) // Розмір 1 більше розміру 2
			cout << " First number is bigger than the second one!" << endl;
		else // Розмір 2 більше розміру 1
			cout << " Second number is bigger than the first one!" << endl;
	}
	else { // Розмір однаковий
		for (int i = s1 - 1; i >= 0; i--) {
			if (num1[i] != num2[i]) { // Цифри не рівні
				equal = false;
				if (num1[i] > num2[i]) { // Цифра 1 більша за цифру 2
					num1Bigger = true;
					break;
				}
			}
			else { // Якщо цифри рівні
				equal = true;
			}
		}

		if (!equal) { // Якщо числа не рівні
			if (!num1Bigger)
				cout << " Second number is bigger than the first one!" << endl;
			else
				cout << " First number is bigger than the second one!" << endl;
		}
		else
			cout << " Numbers are equal!" << endl;
	}
}