#include "GradeManager.h"

GradeManager::GradeManager() //디폴트 생성자
{
	m_std = NULL;
	m_stdnum = 0;
	cout << "GradeManager 디폴트 생성자 호출!" << endl;
}

GradeManager::GradeManager(int m_stdnum) //인자 있는 생성자
{ 
	m_std = new Student[m_stdnum];
	this->m_stdnum = m_stdnum;
	cout << "GradeManager 인자 있는 생성자 호출!" << endl;
}

GradeManager::~GradeManager() //소멸자
{
	delete[] m_std;
	cout << "GrandManager 소멸자 호출!" << endl;
}

void GradeManager::PrintMenu() //메뉴 출력
{
	cout << endl;
	cout << "===== 메뉴 =====" << endl;
	cout << "1. 학생 성적 입력" << endl;
	cout << "2. 전체 성적 보기" << endl;
	cout << "3. 학생 검색" << endl;
	cout << "4. 학생 목록 보기" << endl;
	cout << "5. 학생 정보 수정" << endl;
	cout << "6. 프로그램 종료" << endl;
	cout << endl;

	cout << "원하는 기능을 입력하세요(번호 입력) : ";
}

void GradeManager::Execute() //학생 성적 관리
{
	int choice=0;
	string stdname;
	Student *std;

	while (1)
	{
		PrintMenu();
		InputUtil::InputValue(choice);
		switch (choice)
		{
		case 1:
			for (int i = 0; i < m_stdnum; i++)
				m_std[i].InputData();
			break;
		case 2:
			for (int i = 0; i < m_stdnum; i++)
				m_std[i].PrintData();
			break;
		case 3:
			cout << "검색할 학생 이름 : ";
			InputUtil::InputValue(stdname);
			std = StdSearch(stdname);
			if (std == NULL)
			{
				cout << endl << "해당 학생이 존재하지 않습니다!" << endl;
				break;
			}
			else
			{
				std->PrintData();
				break;
			}
		case 4:
			PrintAllStdList();
			break;
		case 5:
			Modify();
			break;
		case 6:
			exit(1);
			break;
		}
	}
}

Student* GradeManager::StdSearch(string stdname) const //원하는 학생 검색
{
	Student* std = NULL;
	for (int i = 0; i < m_stdnum; i++)
	{
		if (m_std[i].GetName() == stdname)
			return std = (m_std + i);
	}
		return NULL;
}

void GradeManager::PrintAllStdList() const //전체 학생 목록 출력
{
	cout << "==================================" << endl;
	cout << right << setw(10) << "이름" << setw(20) << "학번" << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < m_stdnum; i++)
	{
		cout << right << setw(10) << m_std[i].GetName() << setw(20) << m_std[i].GetHakbun() << endl;
	}
	cout << "==================================" << endl;
}

void GradeManager::Modify() //원하는 학생의 정보 수정
{
	string stdname;
	cout << "검색할 학생 이름 : ";
	InputUtil::InputValue(stdname);
	Student* std = StdSearch(stdname);
	if (std == NULL)
		cout << "해당 학생이 존재하지 않습니다!" << endl;
	else
		std->Modify();
}