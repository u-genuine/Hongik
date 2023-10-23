#include <iostream>
#include "poly.h"
using namespace std;


istream& operator>> (istream& is, Polynomial& p) {
	// #terms and (coefficoent, exponent)�� pair���� �о���δ�. 
	// ���� ������ �׺��� �ԷµǾ� ����ȴٰ� �����Ѵ�.
	int noofterms;
	float coef;
	int exp;
	is >> noofterms;
	for (int i = 0; i < noofterms; i++) {
		is >> coef >> exp; // ����� ���� pair�� �о���δ�.
		p.NewTerm(coef, exp);
	}
	return is;
}
ostream& operator<< (ostream& os, Polynomial& p)
{
	// ���˿� �°� ����ϴ� �ڵ� �Է�
	for (int i = 0; i < p.terms; i++)
	{
		if (p.termArray[i].exp >= 2) //������ 2�� �̻� �̸�,
		{
			if (p.termArray[i].coef == 1) //����� 1�̸�, "x^����" ���
				cout << "x^" << p.termArray[i].exp << " ";
			else if (p.termArray[i].coef == -1)
				cout << "-x^" << p.termArray[i].exp << " "; //����� -1�̸�, "-x^����" ���
			else
				cout << p.termArray[i].coef << "x^" << p.termArray[i].exp << " "; // �׿� ����� ���, "���x^����" ���
		}
		else if (p.termArray[i].exp == 1)  // ������ 1���� ���,
		{
			if (p.termArray[i].coef == 1)
				cout << "x ";	//����� 1�̸�, "x" ���
			else if (p.termArray[i].coef == -1)
				cout << "-x ";	//����� -1�̸�, "-x"
			else
				cout << p.termArray[i].coef << "x ";	// �׿� ����� ��� "���x"
		}
		else  // ������� ���
			cout << p.termArray[i].coef; //����� ���


		if (i < p.terms - 1) // ������ ���� �ƴϸ�
		{
			//����i+1 ��� ���� 0 �̻��̸� " +" ���, ������ ��� "  " ���
			if (p.termArray[i + 1].coef >= 0)
				cout << " +";
			else
				cout << " ";
		}
	}
	os << endl;
	return os;
}






Polynomial::Polynomial():capacity(1), terms(0)
{
	termArray = new Term[capacity];
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
	// ���ο� ���� termArray ���� ÷��
	if (terms == capacity) // termArray�� �� ��������
	{	//termArray�� ũ�⸦ �� ��� Ȯ��
		capacity *= 2;
		Term* temp = new Term[capacity]; // ���ο� �迭
		copy(termArray, termArray + terms, temp);
		delete[] termArray; // ���� �޸𸮸� ��ȯ
		termArray = temp;
	}

	termArray[terms].coef = theCoeff; // termArray�� �߰��� ���ο� ���� ��� ����
	termArray[terms++].exp = theExp; // termArray�� �߰��� ���ο� ���� ���� ����
}

Polynomial Polynomial::operator+(Polynomial& b)
{
	// return the sum of the polynomials *this and b.
	Polynomial c; // ���� ������ Polynomial ��ü c
	
	int aPos = 0, bPos = 0; // �� �迭�� ���� ���� �� �� �ε���.
	while ((aPos < terms) && (bPos < b.terms)) 

		if (termArray[aPos].exp == b.termArray[bPos].exp) { //�� ���� ���� ���� ���
			float t = termArray[aPos].coef + b.termArray[bPos].coef; //�� ���� ��� ���ϱ�
			
			if (t) // ��� ���ؼ� 0�� �ƴ϶�� c�� �߰� 
				c.NewTerm(t, termArray[aPos].exp);
			aPos++; 
			bPos++;
		}

		else if (termArray[aPos].exp < b.termArray[bPos].exp) { //b�� ������ �� ū���
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}

		else { //a�� ������ �� ū ���
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}

	// add in remaining terms of *this
	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	
	// add in remaining terms of b(x)
	for (; bPos < b.terms; bPos++) // ���翡�� b++�� �߸� ��������
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
	return c;

}

