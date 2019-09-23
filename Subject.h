#pragma once
#include "IOInterface.h"

class Subject : public IOInterface
{
protected:
	string m_name; //과목명
	int m_hakjum; //학점
	string m_grade; //등급
	float m_GPA; //평점
public:
	Subject(); //디폴트 생성자
	Subject(string name, int hakjum, string grade); //인자있는 생성자
	Subject(const Subject& sub); //복사생성자
	~Subject(); //소멸자

	void InputData(); //멤버변수 값 입력
	static void PrintTitle(); //멤버변수에 대한 title Text 출력
	void PrintData() const; //멤버변수 값 출력
	void CalcGPA(); //평점 계산
	void Modify(); //멤버변수 값 수정

	//접근자 함수
	string GetName() const;
	int GetHakjum() const;
	string GetGrade() const;
	float GetGPA() const;
};