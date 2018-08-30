#include <iostream>
#include <tuple>
#include <typeinfo>
#include <string>
#include <algorithm>
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

bool compareStr(const string& l, const string& r)
{
	return l.size() < r.size();
}

int m1{ 22 };
double m2{ 33.33 };

void TestLambdas()
{
	TRACE("TestTuple()");
	vector<string>	vStr{"Complex"s , "set"s , "list"s , "string"s , "tuple"s };
	for (auto str : vStr)
		cout << "\n " << str;

	auto vStr1(vStr);
	LOG("++++++++++++++++++++++++");
	sort(vStr.begin(), vStr.end(), compareStr);
	for (auto str : vStr)
		cout << "\n " << str;
	LOG("++++++++++++++++++++++++");

	sort(vStr1.begin(), vStr1.end(), [](auto const& l, auto const& r) {return l.size() < r.size(); });
	for (auto str : vStr1)
		cout << "\n " << str;

	LOG("+++++++++++vector<unique_ptr<string>>+++++++++++++");
	vector<unique_ptr<string>> vUStr ;
	vUStr.push_back(make_unique<string>("Complex"));
	vUStr.push_back(make_unique<string>("set"));
	vUStr.push_back(make_unique<string>("list"));
	vUStr.push_back(make_unique<string>("string"));
	vUStr.push_back(make_unique<string>("tuple"));
	
	LOG("++++++++++for each ++++++++++++++");
	for_each(vUStr.begin(), vUStr.end(), [](auto &x) { cout << "\n " << *x;  });

	LOG("+++++++++range for+++++++++++++++");
	for(auto& x : vUStr)
		cout << "\n " << *x;

	LOG("++++++++++sort++++++++++++++");
	//generic lambdas / polymorphic lambdas - usign auto , instead of fully qualified name for templates
	sort(vUStr.begin(), vUStr.end(), [](unique_ptr<string> & l, unique_ptr<string> & r) {return l->size() < r->size();  });

	sort(vUStr.begin(), vUStr.end(), [](auto & l, auto & r) {return l->size() < r->size();  });////C++14 generic lambdas / polymorphic lambdas - labda with auto

	for (auto& x : vUStr)
		cout << "\n " << *x;

	LOG("++++++++++lambda ++++++++++++++");
	int x{ 10 };
	double y{ 20 };
	//https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c
	//throws away cv-qualifiers, references, and lvalue/rvalue-ness. For example:
	cout << "\n x=" << x << ", &x = " << &x << ", typeid(x).name() = " << typeid(x).raw_name() << "|| y=" << y << ", &y = " << &y << ", typeid(y).name() = " << typeid(y).name() << endl;
	//cout << "\n x=" << x << ", &x = " << &x << ", typeid(x).name() = " << type_name<decltype((x)>() << "|| y=" << y << ", &y = " << &y << ", typeid(y).name() = " << typeid(y).name() << endl;

	//[x, m2]() { //eror not allow o capture global/static variable, only auto var allowed
	[x, y]() {
		cout << "\n Lambda called" << endl; 
		cout << "\n x=" << x << ", &x = " << &x<<", typeid(x).name() = " << typeid(x).name() << "|| y=" << y << ", &y = " << &y << ", typeid(y).name() = " << typeid(y).name() << endl;
		//x = 300; y = 500;		//error unable to modify
	}();

	LOG("++++++++++lambda pass by reference ++++++++++++++");
	[x, &y]() {
		cout << "\n Lambda called" << endl;
		cout << "\n x=" << x << ", &x = " << &x << "|| y=" << y << ", &y = " << &y << endl;
		y = 10000;
	}();
	cout << "\n y = " << y << endl;

	LOG("++++++++++lambda init capture ++++++++++++++");
	[x, y{20000}, value = 100]() {
		cout << "\n Lambda called" << endl;
		cout << "\n x=" << x << ", &x = " << &x << "|| y=" << y << ", &y = " << &y << ", value = " << value << endl;
	}();
	LOG("++++++++++lambda init capture for unique_ptr++++++++++++++");
	unique_ptr<Complex> cuptr = make_unique<Complex>(3, 9);

	[&cuptr]() {
		cout << "\n Lambda called" << endl;
		cout << "\n *cuptr=" << *cuptr << endl;
	}();

	[uptr{move(cuptr)}]() {
		cout << "\n Lambda called" << endl;
		cout << "\n *uptr=" << *uptr << endl;
	}();
	LOG("++++++++++lambda init capture for shared_ptr++++++++++++++");
	shared_ptr<Complex> csptr = make_shared<Complex>(3, 9);

	//[csptr]() { //ok
	[csptr]() {	//ok
		cout << "\n Lambda called" << endl;
		cout << "\n *csptr=" << *csptr << endl;
	}();
	
	[sptr{move(csptr)}]() {	//ok
		cout << "\n Lambda called" << endl;
		cout << "\n sptr=" << *sptr << endl;
	}();


	LOG("++++++++++++++++++++++++");
}