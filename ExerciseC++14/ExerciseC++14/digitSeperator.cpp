#include <iostream>
#include <string>
#include <windows.h>
#include "Trace.h"
#include "onlyFuncHeader.h"

using namespace std;


void main()
{
	TRACE("Main");
	TestUnorderedContainer();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//TestLambdas();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//TestTuple();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//TestTimeLibrary();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//TestSharedPtr();

	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//DigitSeperatorAndBinaryLiteral();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//VariableTemplate();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//TestStructDefaultValue();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//AutoReturnType();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//ConstExprFunc();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//UsingKeyword();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//DepricatedKeyword();	//C++ 14
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//TestUniquePtr();
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//TestFinalKeyword();		//C++11
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	//TestOverrideKeyword();		//C++11
	//LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

	LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
}
//==============================================================================

//https://en.cppreference.com/w/cpp/language/final   C++11

class A_over
{
public:
	//A_over(const A_over& o) { TRACE("A_over::A_over(A_over&)"); }
	virtual void printMe() { TRACE("A_over::printMe"); }
	void printMeNV() { TRACE("A_over::printMeNV"); }
	virtual A_over* Clone() { TRACE("A_over::Clone"); return new A_over(*this); }
	virtual int Do_Double() { TRACE("A_over::Do_Double"); return 100; }
};

class B_over : public A_over
{
public:
	//void printMe() const override { TRACE("B_over::printMe"); }	//no base class virtual function with same signaure
	void printMe() override { TRACE("B_over::printMe"); }
	void printMeNV() { TRACE("B_over::printMeNV"); }
	virtual B_over* Clone() override { TRACE("B_over::Clone"); return this; }		// return type not in picture of function sinature

	//https://stackoverflow.com/questions/11651892/overriding-virtual-function-return-type-differs-and-is-not-covariant/11651997
	//long Do_Double() { TRACE("B_over::Do_Double"); return 100L; }			//return only covariant type-means only derived class pointer
};



void TestOverrideKeyword()
{
	TRACE("TestOverrideKeyword");
	A_over obj;
	obj.printMe();
	obj.printMeNV();
	obj.Clone();
	obj.Do_Double();
	LOG("************************");
	A_over* pB = new B_over();
	pB->printMe();
	pB->printMeNV();
	pB->Clone();
	pB->Do_Double();
}
//==============================================================================
//https://en.cppreference.com/w/cpp/language/final   C++11
//class A final		//B cannot inherit from final class A
class A
{
public: 
	//virtual void printMe() final { TRACE("A::printMe");  }  ///gives compiler error in Derived class
	virtual void printMe() { TRACE("A::printMe"); }
	void printMeNV() { TRACE("A::printMeNV"); }
	//void printMeNV() final { TRACE("A::printMeNV"); }		//final used with only virtual function.
};

//class B final: public A			//class C cannot inherit from final class B
class B : public A			//class C cannot inherit from final class B
{
public:
	void printMe() { TRACE("B::printMe"); }
	void printMeNV() { TRACE("B::printMeNV"); }
};

class C : public B
{
public:
	void printMe() { TRACE("C::printMe"); }
	void printMeNV() { TRACE("C::printMeNV"); }
};


void TestFinalKeyword()
{
	TRACE("TestFinalKeyword");
	A obj;
	obj.printMe();
	obj.printMeNV();
	LOG("************************");
	A* pB = new B();
	pB->printMe();
	pB->printMeNV();

	LOG("************************");
	A* pC = new C();
	pC->printMe();
	pC->printMeNV();

}

//==============================================================================
int version_dep = 10;
int version_dep1 = 11;

[[deprecated ("You are using wrong version of library")]] 
void PrintMsg()
{
	TRACE("PrintMsg");
	LOG_VAR(version_dep);
}

//https://en.cppreference.com/w/cpp/language/attributes
//void PrintMsg()
//{
//	TRACE("PrintMsg");
//	LOG_VAR(version_dep1);
//}
void DepricatedKeyword()
{
	TRACE("DepricatedKeyword");
	PrintMsg();
}

//==============================================================================
typedef struct {
	int x;
	int y;
}TestTypeDef;

/*using TestUsing = struct {
	int x;
	int y;
	TestUsing() { cout << x; }			//	error
};*/

using TestUsing = struct {	int x;	int y;};

using TestUsing1 = struct Node
					{	
						int x;	
						int y; 
						Node() { cout << "\nCTOR" << endl; }
						~Node() { cout << "\nDTOR" << endl; }
					};

void UsingKeyword()
{
	TRACE("UsingKeyword");
	TestTypeDef X{ 10,20 };
	LOG_VAR(X.x);

	TestUsing Y{ 20,30 };
	LOG_VAR(Y.x);

	TestUsing1 Z;
}

//==============================================================================
template <int x>
void printVar()
{
	cout << "\n pritVar(): x=" << x << endl;
}

constexpr int Factorial(int x)
{
	if (x <= 1)
		return 1;
	else
		return x * Factorial(x - 1);
}
//https://en.cppreference.com/w/cpp/language/constexpr

class conststr {
	const char* p;
	size_t s;
public:
	template <size_t N>
	constexpr conststr(const char(&arr)[N]) : p(arr), s(N - 1)
	{}
	constexpr auto size() { return s; }
	constexpr char operator[](size_t in) { return p[in]; }
	constexpr const char* begin() { return p; }
	constexpr const char* end() { return &p[s+1]; }
};
constexpr int CountLower(conststr s)
{
	auto strlen = s.size();
	int count  = 0;
	for(auto a : s)				//https://en.cppreference.com/w/cpp/language/range-for
	{
		if (('a' <= a ) && (a <= 'z'))		
			++count;
	}
	return count;
}

void ConstExprFunc()
{
	TRACE("ConstExprFunc");
	LOG("++++++++++++++++++++++++++++++++++++++++");
	conststr str("hello world");			//error
	//conststr str = "hello world";
	cout << "\n type of str:" << typeid(str).name() << endl;
	auto strlen = str.size();
	LOG_VAR(strlen);
	auto chStr = str[3];
	LOG_VAR(chStr);

	auto lowers = CountLower("Hello World");
	LOG_VAR(lowers);
	//============================================
	LOG("++++++++++++++++++++++++++++++++++++++++");
	//int no = 5;			//error
	constexpr int no = 5;
	
	constexpr int fac = Factorial(no);
	LOG_VAR(fac);
	static_assert(Factorial(4) == 24, "Not Executed at compile time no");

	int no1 = 4;
	//static_assert(Factorial(no1) == 24, "Not Executed at compile time no1");		//error
	//============================================
	LOG("++++++++++++++++++++++++++++++++++++++++");
	printVar<Factorial(4)>();
	//printVar<no1>();			error
	printVar<no>();			

	int fac1 = Factorial(no1);		//	ok
	LOG_VAR(fac1);

	int fac2 = Factorial(6);		//	ok
	LOG_VAR(fac2);
	//============================================
}

//==============================================================================

template <typename T, typename U>
auto Addition(T a, U b)// -> decltype(a+b)
{
	decltype(a + b) temp;
	return a + b;
}

void AutoReturnType()
{
	TRACE("AutoReturnType");
	int a = 20;
	int b = 40;
	auto c = sum(a,b);
	LOG_VAR(c);

	double d = 40.1;
	auto c1 = Addition(a, d);
	LOG_VAR(c1);
}

auto sum(int a, int b) -> decltype(a+b)
{
	return a + b;
}
//==============================================================================
//C++11/14: Non-static member initialization
//http://www.learncpp.com/cpp-tutorial/47-structs/

	struct Math
	{
		int x = 100;
		int y = 200;
		friend ostream& operator<<(ostream& out, const Math& m)
		{
			out <<"Math object: x= " << m.x << ", y = " << m.y << endl;
			return out;
		}
	};
	void TestStructDefaultValue()
	{
		TRACE("TestStructDefaultValue");
		Math m1;
		LOG_VAR(m1);

		Math m2{ 10};
		LOG_VAR(m2);

	}
//=============================================================================
// C++14, a variable template
//	You access pi as you would an ordinary template: pi<double>, pi <long double>, or pi<T>.A C++14 function template that calculates a circular area can use pi like this :
	template<typename T>
	constexpr T pi = T(3.1415926535897932385);

	template <> 
	constexpr int pi<int> = 3;

	//=================================================
	//C++14, a variable template in use
	template<typename T>
	T circular_area(T r) {
		return pi<T> * r * r;
	}
	//=================================================

	void VariableTemplate()
	{
		TRACE("VariableTemplate");
		
		//variable templates
		//template<typename T>
		//constexpr T pi = T(3.1415926535897932385);

		double varTempD = pi<double>;
		LOG_VAR(varTempD);

		double varTempLong = pi<long>;
		LOG_VAR(varTempLong);

		int varTemInt = pi<int>;
		LOG_VAR(varTemInt);
		//=================================================
		//C++14, a variable template in use
		//template<typename T>
		//T circular_area(T r) {
		//		return pi<T> * r * r;
		//	}
		double doubleArea = circular_area(5.5);//uses pi<double>
		LOG_VAR(doubleArea);
		float floatArea = circular_area(5.5f);//uses pi<float>
		LOG_VAR(floatArea);
		//IMP == Template variables aren't confined to built-in types. They can be user-defined types as well, such as matrix<T>, complex<T>, and so on.

	}
//==============================================================================
	void DigitSeperatorAndBinaryLiteral()
	{
		TRACE("DigitSeperatorAndBinaryLiteral");
		
		//1'000'000
		long d = 10'00'0'0'00;			//	digit seperator
		LOG_VAR(d);

		float f = 123'23.4982f;			//	digit seperator
		LOG_VAR(f);
		//=======================================================================
		int binLit1 = 0b00010;			//binary literals with digit seperaor		//	http://www.informit.com/articles/article.aspx?p=2209021
		LOG_VAR(binLit1);

		int binLit4 = 0B100010;
		LOG_VAR(binLit4);


		int binLit2 = 0b0000'1001;
		LOG_VAR(binLit2);

		int binLit3 = 0b0000100100000001;
		LOG_VAR(binLit3);

		int binLit5 = 0B0000'0100'1000'1000;
		LOG_VAR(binLit5);
	}
