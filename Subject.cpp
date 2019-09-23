#include "Subject.h"

Subject::Subject()//NULL 또는 0으로 초기화
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0f;
	cout << "SUB 디폴트 생성자 호출!" << endl;
}

Subject::Subject(string name, int hakjum, string grade)
{//멤버변수의 값을 입력된 인자로 초기화
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA(); //평점 계산
	cout << "SUB 인자 있는 생성자 호출!" << endl;
}

Subject::Subject(const Subject& sub)
{//다른 Subjcet클래스의 멤버변수의 값으로 초기화
	m_name = sub.m_name;
	m_hakjum = sub.m_hakjum;
	m_grade = sub.m_grade;
	m_GPA = sub.m_GPA;
	cout << "SUB 복사 생성자 호출!" << endl;
}

Subject::~Subject() //아무일도 하지 않음
{
	cout << "SUB 소멸자 호출!" << endl;
}

void Subject::InputData()
{
	cout << "\n교과목명 : ";
	InputUtil::InputValue(m_name); //과목이름 입력
	cout << "과목학점 수: ";
	InputUtil::InputValue(m_hakjum); //과목학점 입력
	cout << "과목등급(A+ ~ F) : ";
	InputUtil::InputValue(m_grade);//과목등급 입력
	CalcGPA();
}

void Subject::PrintTitle()
{
	cout << "\n====================================================" << endl;
	cout << "\t교과목명  과목학점  과목등급  과목평점" << endl;
	cout << "\n====================================================" << endl;
}

void Subject::PrintData() const
{
	cout.width(15);
	cout << right << m_name;
	cout.width(10);
	cout << right << m_hakjum;
	cout.width(10);
	cout << right << m_grade;
	cout.width(10);
	cout << right << m_GPA << endl;
}

void Subject::CalcGPA()
{
	if ((m_grade == "A+") || (m_grade == "a+")) //m_grade에 저장되어 있는 문자열과 ""안에 있는 문자열을 비교해서 일치하면
		m_GPA = 4.5f * m_hakjum; //m_GPA에 각 학점을 숫자로 변환한 값 * m_hakjum 저장

	else if ((m_grade == "A") || (m_grade == "a"))
		m_GPA = 4.0f * m_hakjum;

	else if ((m_grade == "B+") || (m_grade == "b+"))
		m_GPA = 3.5f * m_hakjum;

	else if ((m_grade == "B") || (m_grade == "b"))
		m_GPA = 3.0f * m_hakjum;

	else if ((m_grade == "C+") || (m_grade == "c+"))
		m_GPA = 2.5f * m_hakjum;

	else if ((m_grade == "C") || (m_grade == "c"))
		m_GPA = 2.0f * m_hakjum;

	else if ((m_grade == "D+") || (m_grade == "d+"))
		m_GPA = 1.5f * m_hakjum;

	else if ((m_grade == "D") || (m_grade == "d"))
		m_GPA = 1.0f * m_hakjum;

	else if ((m_grade == "F") || (m_grade == "f"))
		m_GPA = 0.0f * m_hakjum;

	else
		m_GPA = 0.0f * m_hakjum;
}

void Subject::Modify()
{
	cout << "\n< 교과목명 : " << m_name << ", 학점 : " << m_hakjum << ", 등급 : " << m_grade << " >의 정보를 수정하세요." << endl;
	cout << "교과목명 : "; InputUtil::InputValue(m_name); //변경할 교과목명 입력
	cout << "과목학점 : "; InputUtil::InputValue(m_hakjum); //변경할 과목학점 입력
	cout << "과목등급 : "; InputUtil::InputValue(m_grade); //변경할 과목등급 입력
	CalcGPA(); //변경된 학점을 이용해 다시 평점 계산
}

string Subject::GetName() const
{
	return m_name;
}

int Subject::GetHakjum() const
{
	return m_hakjum;
}

string Subject::GetGrade() const
{
	return m_grade;
}

float Subject::GetGPA() const
{
	return m_GPA;
}