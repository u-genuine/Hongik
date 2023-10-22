#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

using namespace std;

class Rectangle {
public:
	Rectangle(int, int, int, int); // constructor
//	Rectangle(); //���� ������
	~Rectangle(); // destructor
	void Print();
	int Area();
	bool LessThan(Rectangle&); // ������ ������ true
	bool EqualSize(Rectangle&); // ������ �����ϸ� true
	bool Equal(Rectangle&); // ������ Equal (��� ����� �����ϸ� true)
	int GetHeight();
	int GetWidth();

	//operator overloading ����
	bool operator<(Rectangle&);
	bool operator==(Rectangle&);
	friend ostream& operator<<(ostream&, Rectangle&);

private:
	int xLow, yLow, height, width;
};
#endif