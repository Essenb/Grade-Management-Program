#include "Subject.h"

Subject::Subject()//NULL �Ǵ� 0���� �ʱ�ȭ
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0f;
	cout << "SUB ����Ʈ ������ ȣ��!" << endl;
}

Subject::Subject(string name, int hakjum, string grade)
{//��������� ���� �Էµ� ���ڷ� �ʱ�ȭ
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA(); //���� ���
	cout << "SUB ���� �ִ� ������ ȣ��!" << endl;
}

Subject::Subject(const Subject& sub)
{//�ٸ� SubjcetŬ������ ��������� ������ �ʱ�ȭ
	m_name = sub.m_name;
	m_hakjum = sub.m_hakjum;
	m_grade = sub.m_grade;
	m_GPA = sub.m_GPA;
	cout << "SUB ���� ������ ȣ��!" << endl;
}

Subject::~Subject() //�ƹ��ϵ� ���� ����
{
	cout << "SUB �Ҹ��� ȣ��!" << endl;
}

void Subject::InputData()
{
	cout << "\n������� : ";
	InputUtil::InputValue(m_name); //�����̸� �Է�
	cout << "�������� ��: ";
	InputUtil::InputValue(m_hakjum); //�������� �Է�
	cout << "������(A+ ~ F) : ";
	InputUtil::InputValue(m_grade);//������ �Է�
	CalcGPA();
}

void Subject::PrintTitle()
{
	cout << "\n====================================================" << endl;
	cout << "\t�������  ��������  ������  ��������" << endl;
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
	if ((m_grade == "A+") || (m_grade == "a+")) //m_grade�� ����Ǿ� �ִ� ���ڿ��� ""�ȿ� �ִ� ���ڿ��� ���ؼ� ��ġ�ϸ�
		m_GPA = 4.5f * m_hakjum; //m_GPA�� �� ������ ���ڷ� ��ȯ�� �� * m_hakjum ����

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
	cout << "\n< ������� : " << m_name << ", ���� : " << m_hakjum << ", ��� : " << m_grade << " >�� ������ �����ϼ���." << endl;
	cout << "������� : "; InputUtil::InputValue(m_name); //������ ������� �Է�
	cout << "�������� : "; InputUtil::InputValue(m_hakjum); //������ �������� �Է�
	cout << "������ : "; InputUtil::InputValue(m_grade); //������ ������ �Է�
	CalcGPA(); //����� ������ �̿��� �ٽ� ���� ���
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