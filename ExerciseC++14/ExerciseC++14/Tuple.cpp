#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <chrono>
#include <thread>
#include "Trace.h"
#include "Complex.h"
#include "windows.h"

#include "onlyFuncHeader.h"

using namespace std;


void TestTuple()
{
	TRACE("TestTuple()");

	tuple<int, double, string, float, Complex> t2;//by default zero initialised
	cout << "\n get<int>(t2) = " << get<int>(t2) << endl;		//	zero initialised

	tuple<int, double, string, float, Complex> t1{ 100,12.21f,"C++14" , 12.124f, {100,200} };
	cout << endl << " auto t2 = { 1,100 }  = " << typeid(t2).name() << endl;//auto t2 = { 1,100 }  = class std::tuple<int,double,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,float,class Complex>
	
	get<int>(t1) = 200;	//can assign also - returning as reference

	cout<<"\n get<int>(t1) = "<< get<int>(t1)<<endl;
	cout << "\n get<double>(t1) = " << get<double>(t1) << endl;
	cout << "\n get<string>(t1) = " << get<string>(t1) << endl;
	cout << "\n get<float>(t1) = " << get<float>(t1) << endl;
	cout << "\n get<int>(Complex) = " << get<Complex>(t1) << endl;
	//set<0>(t1) = 
	
	auto t3 = { 1,100 };
	cout << endl << " auto t3 = { 1,100 }  = " << typeid(t3).name() << endl;//auto t3 = { 1,100 }  = class std::initializer_list<int>
	
	//auto t4 = { 1, 100.1f ,  "hello"};	//Error	C2440	'initializing': cannot convert from 'initializer list' to 'std::initializer_list<int>'	

	tuple<int,double,char*> t4 = { 1, 100.1f ,  "hello" };
	tuple<int, double, string> t5 = make_tuple<int, double, string>( 121, 1030.1f ,  "hello"s );	//https://en.cppreference.com/w/cpp/utility/tuple
	//cout << endl << " auto t3 = { 1,100 }  = " << typeid(t3).name() << endl;//auto t3 = { 1,100 }  = class std::initializer_list<int>
	LOG("++++++++++++++++++++++++");
	int x = 0;  double d = 0;  string str1;
	tie(x, d, str1) = t5;
	LOG_VAR(x);
	x = 40;
	LOG_VAR(x);
	cout << "\n get<int>(t5) = " << get<int>(t5) << endl;
	LOG("++++++++++++++++++++++++");
	//auto [x, d, str1] = t5;			C++17 support


	//https://en.cppreference.com/w/cpp/utility/tuple/tuple
	LOG("++++++++++++++++++++++++");
}