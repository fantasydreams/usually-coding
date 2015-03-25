#include<iostream>

using namespace std;

class Operator
{
	int integer;
public:
	Operator(int a) :integer(a)
	{
		cout << "Class instructor" << endl;
	}
	int operator+(const Operator & recieve);
	Operator operator+(const int num);
	Operator operator+=(const Operator & recieve);
	Operator operator+=(const int num);
	Operator operator*(const Operator & recieve);
	Operator operator*(const int num);
	Operator operator-(const Operator & recieve);
	Operator operator-(const int num);
	int Getvalue(){ return integer; }
};


Operator Operator::operator*(const Operator & recieve)
{
	cout << "object A and B operator*:";
	return Operator(integer*recieve.integer);
}

Operator Operator::operator-(const Operator & recieve)
{
	cout << "object A and B operator-:";
	return Operator(integer-recieve.integer);
}

Operator Operator::operator+=(const Operator & recieve)
{
	cout << "object A and B operator += :";
	return Operator(integer+=recieve.integer);
}



int Operator::operator+(const Operator & recieve)
{
	cout << "object A and B operator+:";
	return Operator(integer + recieve.integer).Getvalue();
}

Operator Operator::operator*(const int num)
{
	cout << "object A and a number operator*";
	return Operator(integer*num);
}

Operator Operator::operator+(const int num)
{
	cout << "object A and a number operator+";
	return Operator(integer+num);
}

Operator Operator::operator-(const int num)
{
	cout << "object A and a number operator-";
	return Operator(integer - num);
}

Operator Operator::operator+=(const int num)
{
	cout << "object A and a number operator += ";
	return Operator(integer += num);
}


void main()
{
	system("color F4");
	Operator A(5), B(6);
	cout << A + B << endl;
	A + 5;
	cout << A.Getvalue() << endl;
	A += 5;
	cout << A.Getvalue() << endl;
	A += B;
	cout << A.Getvalue() << endl;
	A*B;
	cout << A.Getvalue() << endl;
	A * 5;
	cout << A.Getvalue() << endl;
	A - B;
	cout << A.Getvalue() << endl;
	A - 5;
	cout << A.Getvalue() << endl;
	system("pause");
}