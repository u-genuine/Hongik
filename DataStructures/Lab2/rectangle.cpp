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
{ // ���� ���õ� ���â�� ���˿� �°� ����� �� �ֵ��� ����
	cout << "xLow: " << xLow << ", yLow: " << yLow << ", height: " << height << ", width: " << width << endl;
}

int Rectangle::Area()
{ // ���� ���� �����Ͽ� ��ȯ�ϱ�
	return GetWidth() * GetHeight();
}

bool Rectangle::LessThan(Rectangle& s)
{ // �簢���� ����(Area())�� ���� ��� ���� �簢������ ����
	return Area() < s.Area();
}

bool Rectangle::EqualSize(Rectangle& s)
{// �簢���� ����(Area())�� ���� ��� true ��ȯ
	return (Area() == s.Area());
}

bool Rectangle::Equal(Rectangle& s)
{ // ���� ����: ��ġ, ����, ���� ��� ���ƾ� ������ �簢������ ����
	//���� ��ü�� ���
	if (this == &s) 
		return true;

	//�ٸ� ��ü���� ��ġ, ����, ���� ��� ���� ���
	else if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width))
		return true;
	
	else
		return false;

}
int Rectangle::GetHeight() { return height; }
int Rectangle::GetWidth() { return width; }


ostream& operator<<(ostream& os, Rectangle& s) // ������ <<�� Ŭ���� Ractangle�� private ����� ���� -> friend�� ����Ǿ�� ��
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

	//�ٸ� ��ü���� ��ġ, ����, ���� ��� ���� ���
	else if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width))
		return true;

	else
		return false;
}