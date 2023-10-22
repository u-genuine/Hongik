#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

using namespace std;

class Rectangle {
public:
	Rectangle(int, int, int, int); // constructor
//	Rectangle(); //기정 생성자
	~Rectangle(); // destructor
	void Print();
	int Area();
	bool LessThan(Rectangle&); // 면적이 작으면 true
	bool EqualSize(Rectangle&); // 면적이 동일하면 true
	bool Equal(Rectangle&); // 교재의 Equal (모든 멤버가 동일하면 true)
	int GetHeight();
	int GetWidth();

	//operator overloading 버전
	bool operator<(Rectangle&);
	bool operator==(Rectangle&);
	friend ostream& operator<<(ostream&, Rectangle&);

private:
	int xLow, yLow, height, width;
};
#endif