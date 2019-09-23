#include "GradeManager.h"

void main()
{
	
	Student std;
	std.InputData();

	IOInterface* IO[2] = { new Subject("사진학", 3, "A+"), &std };

	for (int i = 0; i < 2; i++)
	{
		cout << "\n *" << i + 1 << "번째 데이터 : " << "\n";
		IO[i]->PrintData(); //파생클래스의 멤버함수가 호출되어야 함
	}
	

	
	/*int stdnum;
	cout << "입력할 학생 수를 입력 : ";
	InputUtil::InputValue(stdnum);
	cout << endl;

	GradeManager GradeMgr(stdnum);
	GradeMgr.Execute();	*/
}