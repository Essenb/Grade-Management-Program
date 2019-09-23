#pragma once
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

class InputUtil //데이터 입력
{
public:
	inline static void InputValue(int &data);
	inline static void InputValue(string &data);
	inline static void InputValue(char *data);
	inline static void InputValue(float &data);
	inline static void InputValue(double &data);
};

inline void InputUtil::InputValue(int &data)
{
	cin >> data;
	cin.ignore();
}

inline void InputUtil::InputValue(string &data)
{
	getline(cin, data);
}

inline void InputUtil::InputValue(char *data)
{
	cin >> data;
	cin.ignore();
}

inline void InputUtil::InputValue(float &data)
{
	cin >> data;
	cin.ignore();
}

inline void InputUtil::InputValue(double &data)
{
	cin >> data;
	cin.ignore();
}