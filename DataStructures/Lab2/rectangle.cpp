#include "rectangle.h"

Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w = 0)
	: xLow(x), yLow(y), height(h), width(w) { }

/*
Rectangle::Rectangle() {
	xLow = 1;
	yLow = 1;
	height = 2;
	width = 5;	
}
*/


Rectangle::~Rectangle() { }

void Rectangle::Print()
{ // 위에 제시된 출력창의 포맷에 맞게 출력할 수 있도록 구성
	cout << "xLow: " << xLow << ", yLow: " << yLow << ", height: " << height << ", width: " << width << endl;
}

int Rectangle::Area()
{ // 면적 값을 산출하여 반환하기
	return GetWidth() * GetHeight();
}

bool Rectangle::LessThan(Rectangle& s)
{ // 사각형의 면적(Area())이 작은 경우 작은 사각형으로 결정
	return Area() < s.Area();
}

bool Rectangle::EqualSize(Rectangle& s)
{// 사각형의 면적(Area())이 같은 경우 true 반환
	return (Area() == s.Area());
}

bool Rectangle::Equal(Rectangle& s)
{ // 교재 내용: 위치, 넓이, 높이 모두 같아야 동일한 사각형으로 결정
	//동일 객체인 경우
	if (this == &s) 
		return true;

	//다른 객체지만 위치, 넓이, 높이 모두 같은 경우
	else if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width))
		return true;
	
	else
		return false;

}
int Rectangle::GetHeight() { return height; }
int Rectangle::GetWidth() { return width; }


ostream& operator<<(ostream& os, Rectangle& s) // 연산자 <<는 클래스 Ractangle의 private 멤버에 접근 -> friend로 선언되어야 함
{
	os << "xLow: " << s.xLow << ", yLow: " << s.yLow;
	os << ",Height: " << s.height << ", Width : " << s.width << endl;
	return os;
}
bool Rectangle::operator<(Rectangle& s)
{
	return (Area() < s.Area());
}

bool Rectangle::operator==(Rectangle& s)
{
	if (this == &s)
		return true;

	//다른 객체지만 위치, 넓이, 높이 모두 같은 경우
	else if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width))
		return true;

	else
		return false;
}