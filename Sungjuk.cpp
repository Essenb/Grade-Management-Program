#include "GradeManager.h"

void main()
{
	
	Student std;
	std.InputData();

	IOInterface* IO[2] = { new Subject("������", 3, "A+"), &std };

	for (int i = 0; i < 2; i++)
	{
		cout << "\n *" << i + 1 << "��° ������ : " << "\n";
		IO[i]->PrintData(); //�Ļ�Ŭ������ ����Լ��� ȣ��Ǿ�� ��
	}
	

	
	/*int stdnum;
	cout << "�Է��� �л� ���� �Է� : ";
	InputUtil::InputValue(stdnum);
	cout << endl;

	GradeManager GradeMgr(stdnum);
	GradeMgr.Execute();	*/
}