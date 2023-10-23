#include <iostream>
#include "poly.h"
using namespace std;


istream& operator>> (istream& is, Polynomial& p) {
	// #terms and (coefficoent, exponent)의 pair들을 읽어들인다. 
	// 높은 차수의 항부터 입력되어 저장된다고 가정한다.
	int noofterms;
	float coef;
	int exp;
	is >> noofterms;
	for (int i = 0; i < noofterms; i++) {
		is >> coef >> exp; // 계수와 지수 pair를 읽어들인다.
		p.NewTerm(coef, exp);
	}
	return is;
}
ostream& operator<< (ostream& os, Polynomial& p)
{
	// 포맷에 맞게 출력하는 코드 입력
	for (int i = 0; i < p.terms; i++)
	{
		if (p.termArray[i].exp >= 2) //지수가 2차 이상 이면,
		{
			if (p.termArray[i].coef == 1) //계수가 1이면, "x^지수" 출력
				cout << "x^" << p.termArray[i].exp << " ";
			else if (p.termArray[i].coef == -1)
				cout << "-x^" << p.termArray[i].exp << " "; //계수가 -1이면, "-x^지수" 출력
			else
				cout << p.termArray[i].coef << "x^" << p.termArray[i].exp << " "; // 그외 계수인 경우, "계수x^지수" 출력
		}
		else if (p.termArray[i].exp == 1)  // 지수가 1차인 경우,
		{
			if (p.termArray[i].coef == 1)
				cout << "x ";	//계수가 1이면, "x" 출력
			else if (p.termArray[i].coef == -1)
				cout << "-x ";	//계수가 -1이면, "-x"
			else
				cout << p.termArray[i].coef << "x ";	// 그외 계수인 경우 "계수x"
		}
		else  // 상수항인 경우
			cout << p.termArray[i].coef; //계수만 출력


		if (i < p.terms - 1) // 마지막 항이 아니면
		{
			//다음i+1 계수 값이 0 이상이면 " +" 출력, 음수인 경우 "  " 출력
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
	// 새로운 항을 termArray 끝에 첨가
	if (terms == capacity) // termArray가 꽉 차있으면
	{	//termArray의 크기를 두 배로 확장
		capacity *= 2;
		Term* temp = new Term[capacity]; // 새로운 배열
		copy(termArray, termArray + terms, temp);
		delete[] termArray; // 이전 메모리를 반환
		termArray = temp;
	}

	termArray[terms].coef = theCoeff; // termArray에 추가된 새로운 항의 계수 설정
	termArray[terms++].exp = theExp; // termArray에 추가된 새로운 항의 지수 설정
}

Polynomial Polynomial::operator+(Polynomial& b)
{
	// return the sum of the polynomials *this and b.
	Polynomial c; // 합을 저장할 Polynomial 객체 c
	
	int aPos = 0, bPos = 0; // 각 배열의 항을 비교할 때 쓸 인덱스.
	while ((aPos < terms) && (bPos < b.terms)) 

		if (termArray[aPos].exp == b.termArray[bPos].exp) { //두 항의 차수 같은 경우
			float t = termArray[aPos].coef + b.termArray[bPos].coef; //두 항의 계수 더하기
			
			if (t) // 계수 더해서 0이 아니라면 c에 추가 
				c.NewTerm(t, termArray[aPos].exp);
			aPos++; 
			bPos++;
		}

		else if (termArray[aPos].exp < b.termArray[bPos].exp) { //b의 차수가 더 큰경우
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}

		else { //a의 차수가 더 큰 경우
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}

	// add in remaining terms of *this
	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	
	// add in remaining terms of b(x)
	for (; bPos < b.terms; bPos++) // 교재에는 b++로 잘못 적혀있음
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
	return c;

}

