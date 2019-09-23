#include "Student.h"

class GradeManager
{
protected:
	Student *m_std; //��ü �л� ������ ��� �ִ� ��ü
	int m_stdnum; //�����ϰ� �ִ� ��ü �л� ��

	static void PrintMenu(); //�޴� ���
	Student* StdSearch(string stdname) const; //���ϴ� �л� �˻�
	void PrintAllStdList() const; //��ü �л� ��� ���
	void Modify(); //���ϴ� �л��� ���� ����

public:
	GradeManager(); //����Ʈ ������
	GradeManager(int m_stdnum); //���� �ִ� ������
	~GradeManager(); //�Ҹ���
	void Execute(); //�л� ������ �����ϴ� �Լ�
};