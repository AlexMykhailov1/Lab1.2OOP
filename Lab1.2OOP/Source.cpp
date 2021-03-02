// Source.cpp
// ���������� �� ������ �����
// �������� ���������
// ������ 19*

#include <iostream>
#include <string>
#include <sstream>
#include "BigInt.h"

using namespace std;

BigInt MakeBigInt() {
	BigInt num;
	if (!num.Read()) {
		cout << " ERROR";
		exit(0);
	}
	return num;
}

int main() 
{
	BigInt bignum1, bignum2;

	bignum1 = MakeBigInt();
	bignum1.Display();

	bignum2 = MakeBigInt();
	bignum2.Display();

	int* arr1 = bignum1.GetArray(); // ����������� ���,
	int* arr2 = bignum2.GetArray(); // ������ ��� ����������
	int size1 = bignum1.GetSize();
	int size2 = bignum2.GetSize();

	bignum1.Compare(arr1, arr2, size1, size2); // ��������� �����

	delete[] arr1;
	delete[] arr2;
	return 0;
}