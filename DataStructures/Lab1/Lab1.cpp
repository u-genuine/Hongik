// C119173 박유진
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
	cout << "정렬 전 myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;
	cout << endl << endl;


	sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71)26 80 53 33
	// print out content:
	cout << "앞부분 4개 정렬 후 myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;
	cout << endl << endl;


	// using function as comp
	sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
	cout << "뒷부분 4개 정렬 후 myvector contains:";
	// print out content:
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;
	cout << endl << endl;

	// using object as comp
	sort(myvector.begin(), myvector.end(), myobject); //(12 26 32 33 45 53 71 80)
	// print out content:
	cout << "모두 정렬 후 myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;
	cout << endl << endl;

	return 0;
}
