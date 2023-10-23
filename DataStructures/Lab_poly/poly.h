#ifndef POLY_H
#define POLY_H

using namespace std;

class Polynomial; // 전방참조

class Term {
	friend class Polynomial;
	friend ostream& operator<<(ostream&, Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
private:
	float coef; // coefficient 계수
	int exp; // exponent 지수
};

class Polynomial {
public:
	Polynomial(); // construct a polynomial p(x) = 0.
	Polynomial operator+(Polynomial&); // 다항식의 합을 반환
	void NewTerm(const float, const int); // coef(계수)와 exp(지수)를 받아서 항 생성
	friend ostream& operator<<(ostream&, Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
private:
	Term* termArray;
	int capacity; // termArray의 크기, 1로 초기화
	int terms; // (0이 아닌 항의 수)저장된 항의 수, 0으로 초기화
};
#endif

