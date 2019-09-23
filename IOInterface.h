#pragma once
#include "InputUtil.h"

class IOInterface
{
public:
	virtual ~IOInterface() //�Ҹ���
	{
		cout << "IOInterface �Ҹ��� ȣ��!" << endl;
	}

	virtual void InputData()=0; //��������� �� �Է�
	virtual void PrintData() const=0; //��������� �� ���
	virtual void Modify()=0; //��������� �� ����
};