#include "Student.h"

Student::Student() //NULL 또는 0으로 초기화
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0;
	cout << "STD 디폴트 생성자 호출!" << endl;
}

Student::Student(string name, int hakbun, int subnum, Subject *sub)
{//멤버변수의 값을 입력된 인자로 초기화(깊은 복사)
	m_name = name;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = new Subject[m_subnum]; //동적 할당
	for (int i = 0; i < m_subnum; i++)
		m_sub[i] = sub[i];
	CalcAveGPA(); //평균 평점 계산
	cout << "STD 인자 있는 생성자 호출!" << endl;
}

Student::Student(const Student& std)
{//다른 Student클래스의 멤버변수의 값으로 초기화(깊은 복사)
	m_name = std.m_name;
	m_hakbun = std.m_hakbun;
	m_subnum = std.m_subnum;
	m_sub = new Subject[m_subnum]; //동적 할당
	for (int i = 0; i < m_subnum; i++)
		m_sub[i] = std.m_sub[i];
	CalcAveGPA(); //평균 평점 계산
	cout << "STD 복사 생성자 호출!" << endl;
}

Student::~Student() //동적 할당 받은 메모리 정리
{
	delete[] m_sub;
	m_sub = NULL;
	cout << "STD 소멸자 호출!" << endl;
	//소멸자는 프로그램이 끝날때 자동으로 실행이 되는데, 이때 Student의 소멸자가 먼저 실행이 됩니다
	//그러나 소멸자의 실행으로 m_sub의 데이터공간이 삭제가되고 이에따라 m_sub의 소멸자를 실행시킬 수 없게 되므로 오류가 납니다
}

void Student::InputData()
{
	cout << "이름 : ";
	InputUtil::InputValue(m_name); //이름 입력
	cout << "학번 : ";
	InputUtil::InputValue(m_hakbun); //학번 입력
	cout << "\n수강한 과목 수를 입력 : ";
	InputUtil::InputValue(m_subnum); //과목 수 입력
	m_sub = new Subject[m_subnum]; //동적 할당
	for (int i = 0; i < m_subnum; i++)
		m_sub[i].InputData(); //과목 정보 입력
	CalcAveGPA(); //평균 평점 계산
}

void Student::PrintData() const
{
	cout << "====================================================" << endl;
	cout << setw(15) << "이름 : " << m_name << "\t학번 : " << m_hakbun << "" << endl; //이름과 학번 출력
	m_sub->PrintTitle();
	for (int i = 0; i < m_subnum; i++)
		m_sub[i].PrintData(); //과목 정보 출력
	cout << "====================================================" << endl;
	cout.width(45);
	cout << right << "평균평점\t" << m_aveGPA << endl; //평균평점 출력
}

void Student::CalcAveGPA()
{
	float sum = 0.0;

	for (int i = 0; i < m_subnum; i++) // i가 0에서 m_subnum이 될 때까지
	{
		sum = sum + m_sub[i].GetGPA(); //sum에다 m_sub[i]의 m_GPA를 더해줌
	}
	m_aveGPA = (sum / m_subnum); //m_aveGPA에 sum을 m_subnum으로 나눈 값 저장
}

Subject* Student::SubSearch(string subname) const
{
	int i;
	for (i = 0; i < m_subnum; i++) //과목수 개수만큼
		if (m_sub[i].GetName() == subname) //입력한 과목 이름이 과목 정보 중에 있다면
			return &m_sub[i]; //입력한 이름의 과목 정보 주소 반환
	if (i == m_subnum) //입력한 과목 이름이 없으면
		return NULL; //NULL값 반환
}

void Student::Modify()
{
	string Type; //학생정보 또는 과목정보 또는 모두 문자열 저장용 string
	cout << "수정(학생정보/과목정보/모두) : ";
	InputUtil::InputValue(Type); //학생정보 또는 과목정보 또는 모두 입력
	cout << endl;

	if (Type == "학생정보") //학생정보를 입력했을 시
	{
		cout << "<" << m_name << "," << m_hakbun << ">의 정보를 수정하세요." << endl;
		cout << "이름 : "; InputUtil::InputValue(m_name); //변경할 이름 입력
		cout << "학번 : "; InputUtil::InputValue(m_hakbun); //변경할 학번 입력
		cout << endl << endl;
	}
	else if (Type == "과목정보") //과목정보를 입력했을 시
	{
		string subname; //과목 이름을 저장 받을 string
		cout << "검색할 과목 이름 : ";
		InputUtil::InputValue(subname);
		Subject* Sub = SubSearch(subname); //입력한 과목 이름의 과목 정보를 찾았다면 Subject형 Sub변수에 저장
		if (Sub != NULL) //Sub가 NULL이 아니라면
		{
			Sub->Modify(); //Sub 수정
			CalcAveGPA(); //평균평점 재계산
		}
		else cout << "찾는 과목이 없습니다" << endl;

	}
	else if (Type == "모두") //모두를 입력했을 시
	{
		cout << "<" << m_name << "," << m_hakbun << ">의 정보를 수정하세요." << endl;
		cout << "이름 : "; InputUtil::InputValue(m_name); //변경할 이름 입력
		cout << "학번 : "; InputUtil::InputValue(m_hakbun); //변경할 학번 입력
		for (int i = 0; i < m_subnum; i++) //과목수 개수만큼
			m_sub[i].Modify(); //모든 과목들의 과목 정보 수정
		CalcAveGPA(); //평균평점 재계산
	}
}

string Student::GetName() const
{
	return m_name;
}

int Student::GetHakbun() const
{
	return m_hakbun;
}

int Student::GetSubNum() const
{
	return m_subnum;
}

float Student::GetAveGPA() const
{
	return m_aveGPA;
}