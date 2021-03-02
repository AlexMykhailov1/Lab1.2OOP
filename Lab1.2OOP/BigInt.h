// BigInt.h

#pragma once

class BigInt
{
private:
	int* p;
	unsigned int size;
public:
	void SetSize(int value) { size = value; };
	int GetSize() const { return size; };
	int* GetArray() { return p; };

	bool Read();
	void Display() const;
	void Init(unsigned int);
	void Dispose();

	void Compare(int*, int*, int, int);
};