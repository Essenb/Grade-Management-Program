#pragma once
#include "IOInterface.h"

class Subject : public IOInterface
{
protected:
	string m_name; //�����
	int m_hakjum; //����
	string m_grade; //���
	float m_GPA; //����
public:
	Subject(); //����Ʈ ������
	Subject(string name, int hakjum, string grade); //�����ִ� ������
	Subject(const Subject& sub); //���������
	~Subject(); //�Ҹ���

	void InputData(); //������� �� �Է�
	static void PrintTitle(); //��������� ���� title Text ���
	void PrintData() const; //������� �� ���
	void CalcGPA(); //���� ���
	void Modify(); //������� �� ����

	//������ �Լ�
	string GetName() const;
	int GetHakjum() const;
	string GetGrade() const;
	float GetGPA() const;
};