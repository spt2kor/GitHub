#include <iostream>
#include <memory>
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
using namespace std::chrono;

template<typename T>
void PrintTime(T timeVar)
{
	cout << endl << " PrintTime T timeVar  = " << typeid(timeVar).name() <<" = " <<timeVar.count()<< endl;//seconds s  = class std::chrono::duration<__int64,struct std::ratio<1,1> >
}

void TestTimeLibrary()
{
	TRACE("TestTimeLibrary()");
	auto timeVar = 20ms;
	cout << endl << " timeVar = " << typeid(timeVar).name() << endl;	//class std::chrono::duration<__int64,struct std::ratio<1,1000> >
	seconds s{};
	//LOG_VAR(s);	cout<<s  , not defined gives error
	cout << endl << " seconds s  = " << typeid(s).name() << endl;//seconds s  = class std::chrono::duration<__int64,struct std::ratio<1,1> >
	seconds sec20 = 20s;

	int x{};		//init with 0
	LOG_VAR(x);		//	TestTimeLibrary()() : [31] : x = 0
	int x1;			//garbage, not  init
	LOG_VAR(x1);	//TestTimeLibrary()() : [33] : x1 = -858993460
	
	//seconds sec2 = 20;	//Error	C2440	'initializing': cannot convert from 'int' to 'std::chrono::duration<__int64,std::ratio<1,1>>'	
	seconds sec4{ 20 };	//ok
	seconds sec3 = 20s;	//ok
	sec3 = 20min;	//up to down ok
	sec4 = 12h;		//up to down ok

	minutes m1{ 6100 };
	m1 = 21h;		//up to down ok
	cout << endl << " minutes m1  = " << typeid(m1).name() << endl;//minutes m1  = class std::chrono::duration<int,struct std::ratio<60,1> >
	
	hours h1{ 1 };
	//h1 = 10min;		//Error	C2679	binary '=': no operator found which takes a right - hand operand of type 'std::chrono::minutes' (or there is no acceptable conversion)
	h1 = 30h;		
	//h1 = m1;			//Error	C2679	binary '=': no operator found which takes a right - hand operand of type 'std::chrono::minutes' (or there is no acceptable conversion)
	m1 = h1;

	cout << endl << " hours h1  = " << typeid(h1).name() << endl;//hours h1  = class std::chrono::duration<int,struct std::ratio<3600,1> >

	milliseconds mill1{ 100000 };
	mill1 = 100000ms;
	mill1 = m1;
	mill1 = h1;
	cout << endl << " milliseconds mill1  = " << typeid(mill1).name() << endl;//milliseconds mill1 = class std::chrono::duration<__int64, struct std::ratio<1, 1000> >

	microseconds micro1{ 100000 };
	micro1 = 100000ms;
	micro1 = micro1 + m1;
	micro1 = mill1;
	cout << endl << " microseconds micro1  = " << typeid(micro1).name() << endl;//microseconds micro1 = class std::chrono::duration<__int64, struct std::ratio<1, 1000000> >

	nanoseconds nano1{ 100000 };
	nano1 = 100000ms;
	nano1 = m1;
	nano1 = nano1 + m1;
	nano1 = mill1 + h1;
	decltype(mill1 + h1) x111 = mill1 + h1;;		//conversion happens at compile time
	cout<<"\n decltype(mill1 + h1) = "<< typeid(x111).name() << endl;	//decltype(mill1 + h1) = class std::chrono::duration<__int64,struct std::ratio<1,1000> >
	cout << endl << " nanoseconds nano1  = " << typeid(nano1).name() << endl;//nanoseconds nano1 = class std::chrono::duration<__int64, struct std::ratio<1, 1000000000> >
	LOG("++++++++++++++++++++++++");
	PrintTime(nano1);	
	PrintTime(micro1);
	PrintTime(mill1);
	PrintTime(sec3);
	PrintTime(m1);
	PrintTime(h1);
	/*PrintTime T timeVar = class std::chrono::duration<__int64, struct std::ratio<1, 1000000000> > = 108000000000000
	PrintTime T timeVar = class std::chrono::duration<__int64, struct std::ratio<1, 1000000> > = 108000000000
	PrintTime T timeVar = class std::chrono::duration<__int64, struct std::ratio<1, 1000> > = 108000000
	PrintTime T timeVar = class std::chrono::duration<__int64, struct std::ratio<1, 1> > = 1200
	PrintTime T timeVar = class std::chrono::duration<int, struct std::ratio<60, 1> > = 1800
	PrintTime T timeVar = class std::chrono::duration<int, struct std::ratio<3600, 1> > = 30*/

	if (h1 < m1)			//ok		//conversion happens at compile time
		cout << "\n if(h1 < m1 )" << endl;
	else
		cout << "\n if(h1 > m1 )" << endl;//ok
	
	//string literals 
	LOG("++++++++++++++++++++++++");
	auto str1 = "AeroSpace";
	cout << endl << " auto str1 = \"AeroSpace\"  = " << typeid(str1).name() << endl;//auto str1 = "AeroSpace" = char const *
	auto str2 = "AeroSpace"s;	//suffix s with char array gives string, with int 10s makes seconds
	cout << endl << " auto str2 = \"AeroSpace\"s  = " << typeid(str2).name() << endl;//auto str2 = "AeroSpace"s = class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> >
	

		
		


	//Sleep(sec20);  // error needs DWORD ,not seconds
	this_thread::sleep_for(sec20);

	LOG("++++++++++++++++++++++++");
}