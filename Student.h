#pragma once 
#include"Subject.h"

class Student : public IOInterface
{
protected:
	string m_name; //학생명
	int m_hakbun; //학번
	int m_subnum; //수강한 과목 수
	Subject* m_sub; //수강한 과목들
	float m_aveGPA; //수강한 과목들의 평균 평점

public:
	Student(); //디폴트 생성자
	Student(string name, int hakbun, int subnum, Subject *sub); //인자있는 생성자
	Student(const Student& std); //복사 생성자
	~Student(); //소멸자

	void InputData(); //멤버변수 값 입력
	void PrintData() const; //멤버변수 값 출력
	void CalcAveGPA(); //평균 평점 계산
	void Modify(); //멤버변수 값 수정 
	Subject* SubSearch(string subname) const; //과목 탐색

    //접근자 함수
	string GetName() const;
	int GetHakbun() const;
	int GetSubNum() const;
	float GetAveGPA() const;
};