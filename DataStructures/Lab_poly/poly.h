#ifndef POLY_H
#define POLY_H

using namespace std;

class Polynomial; // ��������

class Term {
	friend class Polynomial;
	friend ostream& operator<<(ostream&, Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
private:
	float coef; // coefficient ���
	int exp; // exponent ����
};

class Polynomial {
public:
	Polynomial(); // construct a polynomial p(x) = 0.
	Polynomial operator+(Polynomial&); // ���׽��� ���� ��ȯ
	void NewTerm(const float, const int); // coef(���)�� exp(����)�� �޾Ƽ� �� ����
	friend ostream& operator<<(ostream&, Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
private:
	Term* termArray;
	int capacity; // termArray�� ũ��, 1�� �ʱ�ȭ
	int terms; // (0�� �ƴ� ���� ��)����� ���� ��, 0���� �ʱ�ȭ
};
#endif

