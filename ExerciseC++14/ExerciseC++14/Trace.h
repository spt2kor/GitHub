#pragma once

#include <iostream>
#include <string>
using namespace std;

class Trace
{
	const string& m_funcName;
public:
	Trace(const string& funcName, int lineNo) :m_funcName(funcName)
	{
		cout << "\n " << m_funcName << "():" << lineNo << ":" << "Started" << endl;
	}
	~Trace()
	{
		cout << "\n " << m_funcName << "():Ended" << endl;
	}
	void Log(const string& msgStr,int lineNo)
	{
		cout << "\n " << m_funcName << "():"<<lineNo<<":" << msgStr << endl;
	}

	template <typename T>
	void Log_Var(const string& varName, const T& var, int lineNo)
	{
		cout << "\n " << m_funcName << "():[" << lineNo << "]:" << varName <<"="<<var<< endl;
	}


};

#define TRACE(funName)		\
					static const string tr_FunctionName = funName;	\
					Trace tr(tr_FunctionName,__LINE__);						

#define LOG(strMsg)		tr.Log(strMsg,__LINE__);

#define LOG_VAR(var)		tr.Log_Var(#var, var,__LINE__);
