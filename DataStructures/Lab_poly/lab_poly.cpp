// C119173 ������
#include <iostream>
using namespace std;
#include "poly.h"

int main() {
	Polynomial p1, p2;
	cin >> p1 >> p2; // 2���� ���׽��� �о� ���δ�.
	Polynomial p3 = p1 + p2;
	cout << p1 << p2 << p3;
}