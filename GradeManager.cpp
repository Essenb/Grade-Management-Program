#include "GradeManager.h"

GradeManager::GradeManager() //����Ʈ ������
{
	m_std = NULL;
	m_stdnum = 0;
	cout << "GradeManager ����Ʈ ������ ȣ��!" << endl;
}

GradeManager::GradeManager(int m_stdnum) //���� �ִ� ������
{ 
	m_std = new Student[m_stdnum];
	this->m_stdnum = m_stdnum;
	cout << "GradeManager ���� �ִ� ������ ȣ��!" << endl;
}

GradeManager::~GradeManager() //�Ҹ���
{
	delete[] m_std;
	cout << "GrandManager �Ҹ��� ȣ��!" << endl;
}

void GradeManager::PrintMenu() //�޴� ���
{
	cout << endl;
	cout << "===== �޴� =====" << endl;
	cout << "1. �л� ���� �Է�" << endl;
	cout << "2. ��ü ���� ����" << endl;
	cout << "3. �л� �˻�" << endl;
	cout << "4. �л� ��� ����" << endl;
	cout << "5. �л� ���� ����" << endl;
	cout << "6. ���α׷� ����" << endl;
	cout << endl;

	cout << "���ϴ� ����� �Է��ϼ���(��ȣ �Է�) : ";
}

void GradeManager::Execute() //�л� ���� ����
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
			cout << "�˻��� �л� �̸� : ";
			InputUtil::InputValue(stdname);
			std = StdSearch(stdname);
			if (std == NULL)
			{
				cout << endl << "�ش� �л��� �������� �ʽ��ϴ�!" << endl;
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

Student* GradeManager::StdSearch(string stdname) const //���ϴ� �л� �˻�
{
	Student* std = NULL;
	for (int i = 0; i < m_stdnum; i++)
	{
		if (m_std[i].GetName() == stdname)
			return std = (m_std + i);
	}
		return NULL;
}

void GradeManager::PrintAllStdList() const //��ü �л� ��� ���
{
	cout << "==================================" << endl;
	cout << right << setw(10) << "�̸�" << setw(20) << "�й�" << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < m_stdnum; i++)
	{
		cout << right << setw(10) << m_std[i].GetName() << setw(20) << m_std[i].GetHakbun() << endl;
	}
	cout << "==================================" << endl;
}

void GradeManager::Modify() //���ϴ� �л��� ���� ����
{
	string stdname;
	cout << "�˻��� �л� �̸� : ";
	InputUtil::InputValue(stdname);
	Student* std = StdSearch(stdname);
	if (std == NULL)
		cout << "�ش� �л��� �������� �ʽ��ϴ�!" << endl;
	else
		std->Modify();
}