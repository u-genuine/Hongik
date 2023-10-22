// C119173 박유진
#include "rectangle.h"

using namespace std;

int main() {
	Rectangle r(2, 3, 4, 6), s(1, 2, 6, 6);
	//Rectangle t; // (0, 0, 0, 0)? (1, 1, 2, 5)?

	cout << "<rectangle r> "; r.Print();
	cout << "<rectangle s> "; s.Print();


	if (r.LessThan(s))
		cout << "s is bigger";
	else if (r.EqualSize(s))
		cout << "Same Size";
	else 
		cout << "r is bigger";
	cout << endl << endl;
	

	//operator overloading 버전
	cout << "<rectangle r> " << r;
	cout << "<rectangle s> " << s;

	if (r < s)
		cout << "s is bigger";
	else if (r == s)
		cout << "Same Size";
	else 
		cout << "r is bigger";
	
	cout << endl << endl;
}