#include "Student.h"

Student::Student() //NULL �Ǵ� 0���� �ʱ�ȭ
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0;
	cout << "STD ����Ʈ ������ ȣ��!" << endl;
}

Student::Student(string name, int hakbun, int subnum, Subject *sub)
{//��������� ���� �Էµ� ���ڷ� �ʱ�ȭ(���� ����)
	m_name = name;
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_sub = new Subject[m_subnum]; //���� �Ҵ�
	for (int i = 0; i < m_subnum; i++)
		m_sub[i] = sub[i];
	CalcAveGPA(); //��� ���� ���
	cout << "STD ���� �ִ� ������ ȣ��!" << endl;
}

Student::Student(const Student& std)
{//�ٸ� StudentŬ������ ��������� ������ �ʱ�ȭ(���� ����)
	m_name = std.m_name;
	m_hakbun = std.m_hakbun;
	m_subnum = std.m_subnum;
	m_sub = new Subject[m_subnum]; //���� �Ҵ�
	for (int i = 0; i < m_subnum; i++)
		m_sub[i] = std.m_sub[i];
	CalcAveGPA(); //��� ���� ���
	cout << "STD ���� ������ ȣ��!" << endl;
}

Student::~Student() //���� �Ҵ� ���� �޸� ����
{
	delete[] m_sub;
	m_sub = NULL;
	cout << "STD �Ҹ��� ȣ��!" << endl;
	//�Ҹ��ڴ� ���α׷��� ������ �ڵ����� ������ �Ǵµ�, �̶� Student�� �Ҹ��ڰ� ���� ������ �˴ϴ�
	//�׷��� �Ҹ����� �������� m_sub�� �����Ͱ����� �������ǰ� �̿����� m_sub�� �Ҹ��ڸ� �����ų �� ���� �ǹǷ� ������ ���ϴ�
}

void Student::InputData()
{
	cout << "�̸� : ";
	InputUtil::InputValue(m_name); //�̸� �Է�
	cout << "�й� : ";
	InputUtil::InputValue(m_hakbun); //�й� �Է�
	cout << "\n������ ���� ���� �Է� : ";
	InputUtil::InputValue(m_subnum); //���� �� �Է�
	m_sub = new Subject[m_subnum]; //���� �Ҵ�
	for (int i = 0; i < m_subnum; i++)
		m_sub[i].InputData(); //���� ���� �Է�
	CalcAveGPA(); //��� ���� ���
}

void Student::PrintData() const
{
	cout << "====================================================" << endl;
	cout << setw(15) << "�̸� : " << m_name << "\t�й� : " << m_hakbun << "" << endl; //�̸��� �й� ���
	m_sub->PrintTitle();
	for (int i = 0; i < m_subnum; i++)
		m_sub[i].PrintData(); //���� ���� ���
	cout << "====================================================" << endl;
	cout.width(45);
	cout << right << "�������\t" << m_aveGPA << endl; //������� ���
}

void Student::CalcAveGPA()
{
	float sum = 0.0;

	for (int i = 0; i < m_subnum; i++) // i�� 0���� m_subnum�� �� ������
	{
		sum = sum + m_sub[i].GetGPA(); //sum���� m_sub[i]�� m_GPA�� ������
	}
	m_aveGPA = (sum / m_subnum); //m_aveGPA�� sum�� m_subnum���� ���� �� ����
}

Subject* Student::SubSearch(string subname) const
{
	int i;
	for (i = 0; i < m_subnum; i++) //����� ������ŭ
		if (m_sub[i].GetName() == subname) //�Է��� ���� �̸��� ���� ���� �߿� �ִٸ�
			return &m_sub[i]; //�Է��� �̸��� ���� ���� �ּ� ��ȯ
	if (i == m_subnum) //�Է��� ���� �̸��� ������
		return NULL; //NULL�� ��ȯ
}

void Student::Modify()
{
	string Type; //�л����� �Ǵ� �������� �Ǵ� ��� ���ڿ� ����� string
	cout << "����(�л�����/��������/���) : ";
	InputUtil::InputValue(Type); //�л����� �Ǵ� �������� �Ǵ� ��� �Է�
	cout << endl;

	if (Type == "�л�����") //�л������� �Է����� ��
	{
		cout << "<" << m_name << "," << m_hakbun << ">�� ������ �����ϼ���." << endl;
		cout << "�̸� : "; InputUtil::InputValue(m_name); //������ �̸� �Է�
		cout << "�й� : "; InputUtil::InputValue(m_hakbun); //������ �й� �Է�
		cout << endl << endl;
	}
	else if (Type == "��������") //���������� �Է����� ��
	{
		string subname; //���� �̸��� ���� ���� string
		cout << "�˻��� ���� �̸� : ";
		InputUtil::InputValue(subname);
		Subject* Sub = SubSearch(subname); //�Է��� ���� �̸��� ���� ������ ã�Ҵٸ� Subject�� Sub������ ����
		if (Sub != NULL) //Sub�� NULL�� �ƴ϶��
		{
			Sub->Modify(); //Sub ����
			CalcAveGPA(); //������� ����
		}
		else cout << "ã�� ������ �����ϴ�" << endl;

	}
	else if (Type == "���") //��θ� �Է����� ��
	{
		cout << "<" << m_name << "," << m_hakbun << ">�� ������ �����ϼ���." << endl;
		cout << "�̸� : "; InputUtil::InputValue(m_name); //������ �̸� �Է�
		cout << "�й� : "; InputUtil::InputValue(m_hakbun); //������ �й� �Է�
		for (int i = 0; i < m_subnum; i++) //����� ������ŭ
			m_sub[i].Modify(); //��� ������� ���� ���� ����
		CalcAveGPA(); //������� ����
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