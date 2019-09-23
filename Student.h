#pragma once 
#include"Subject.h"

class Student : public IOInterface
{
protected:
	string m_name; //�л���
	int m_hakbun; //�й�
	int m_subnum; //������ ���� ��
	Subject* m_sub; //������ �����
	float m_aveGPA; //������ ������� ��� ����

public:
	Student(); //����Ʈ ������
	Student(string name, int hakbun, int subnum, Subject *sub); //�����ִ� ������
	Student(const Student& std); //���� ������
	~Student(); //�Ҹ���

	void InputData(); //������� �� �Է�
	void PrintData() const; //������� �� ���
	void CalcAveGPA(); //��� ���� ���
	void Modify(); //������� �� ���� 
	Subject* SubSearch(string subname) const; //���� Ž��

    //������ �Լ�
	string GetName() const;
	int GetHakbun() const;
	int GetSubNum() const;
	float GetAveGPA() const;
};