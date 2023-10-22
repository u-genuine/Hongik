// C119173 ������
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool myfunction(int i, int j) { return (i < j); }

struct myclass {
	bool operator() (int i, int j) { return (i < j); }
} myobject;

int main() {
	int myints[] = { 32,71,12,45,26,80,53,33 };
	vector<int> myvector(myints, myints + 8); // 32 71 12 45 26 80 53 33
	vector<int>::iterator it; // using default comparison (operator <):

	// print out content:
	cout << "���� �� myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;
	cout << endl << endl;


	sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71)26 80 53 33
	// print out content:
	cout << "�պκ� 4�� ���� �� myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;
	cout << endl << endl;


	// using function as comp
	sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
	cout << "�޺κ� 4�� ���� �� myvector contains:";
	// print out content:
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;
	cout << endl << endl;

	// using object as comp
	sort(myvector.begin(), myvector.end(), myobject); //(12 26 32 33 45 53 71 80)
	// print out content:
	cout << "��� ���� �� myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;
	cout << endl << endl;

	return 0;
}
