#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include "Trace.h"
#include "Complex.h"

#include "onlyFuncHeader.h"
//http://thispointer.com/c11-unique_ptr-tutorial-and-examples/
using namespace std;

class Shape
{
public:
	Shape() = default;
	~Shape() = default;
	Shape(const Shape&) = default;
	Shape& operator = (const Shape&) = delete;
//	Shape& operator = (const Shape&) = default;
	
};


template <typename T>
void gen_deleter(T* ptr)
{
	TRACE("gen_deleter");
	if (ptr)
		delete ptr;
	ptr = nullptr;
}


void Complex_Deleter(Complex* ptr)
{
	TRACE("Complex_Deleter");
	if (ptr)
		delete ptr;
	ptr = nullptr;
}

//====================================
void TestUniquePtr()
{
	TRACE("TestUniquePtr");
	LOG("++++++++++++++++++++++++");
	
	{
		unique_ptr<Complex> cbp = make_unique<ComplexD>(44, 55, 66);//calls non virtual DTOR of Complex class only
		cbp->Show();
	}



	LOG("++++++++++++++++++++************ +++++++++++++++++++++++++++++++++++++++");

	unique_ptr<Complex[]> complexArray{ new Complex[5]{Complex(1,2),Complex(3,4),Complex(5,6),Complex(7,8),Complex(9,10) } };
	cout << complexArray[0] <<endl;

	vector<unique_ptr<Complex>> vComp;
	vComp.push_back(make_unique<Complex>(10, 20));
	vComp.push_back(make_unique<Complex>(30, 40));
	vComp.push_back(make_unique<Complex>(50, 60));
	for (auto& itr : vComp)
		cout << "value : " << *itr;

	list<unique_ptr<Complex>> listComp;
	listComp.push_back(make_unique<Complex>(10, 20));

	set<unique_ptr<Complex>> setComp;
	setComp.insert(make_unique<Complex>(10, 20));

	map<unique_ptr<Complex>, string> mapComp;
	mapComp.insert(make_pair( make_unique<Complex>(10, 20), "complex" ) );
	auto itrMap = mapComp.find(make_unique<Complex>(10, 20));
	if(itrMap != mapComp.end())
		cout << "\n itrMap = "<<* (itrMap->first) << ", " << itrMap->second << endl;

	itrMap = mapComp.find(make_unique<Complex>(30, 40));
	if (itrMap != mapComp.end())
		cout << "\n itrMap 2nd = " << *(itrMap->first) << ", " << itrMap->second << endl;

	LOG("++++++++++++++++++++++++");

	Shape s1;
	Shape s2(s1);
	//	s1 = s2;		// error calling deleted functions
	LOG("++++++++++++++++++++++++");

	int * p = new int{ 100 };
	LOG_VAR(p);
	LOG_VAR(*p);

	unique_ptr<int> pp{ p };
	LOG_VAR(*pp);

	LOG("+++++++++++pComp1 , pComp2+++++++++++++");
	unique_ptr<Complex> pComp1{new Complex(100,200)};
	pComp1->Show();
	//unique_ptr<Complex> pComp2{pComp1};			// eror calling deleted funcion.

	unique_ptr<Complex> pComp2{ make_unique<Complex>(10,20) };
	if(pComp2)
		pComp2->Show();

	LOG("++++++++++++pComp3++++++++++++");
	unique_ptr<Complex> pComp3;
	//pComp3 = pComp2;		//error calling deleted function, 
	pComp3 = move(pComp1);		
	if (pComp3)
		pComp3->Show();
	if (pComp1)
		pComp1->Show();

	LOG("++++++++++pComp4++++++++++++++");
	unique_ptr<Complex> pComp4 = move(pComp3);
	if (pComp4)
		pComp4->Show();

	LOG("++++++++++pComp5++++++++++++++");

	//unique_ptr< Complex, decltype(&Complex_Deleter) > pComp5{ make_unique<Complex>(111,222) , &Complex_Deleter };
	//unique_ptr< Complex, decltype(&Complex_Deleter) > pComp5 =  make_unique<Complex, &Complex_Deleter >(111,222) ;
	unique_ptr< Complex, decltype(&Complex_Deleter) > pComp5{ new Complex(111,222) , &Complex_Deleter };
	if (pComp5)
		pComp5->Show();

	LOG("++++++++++pComp6++++++++++++++");

	//unique_ptr< Complex, decltype(&Complex_Deleter) > pComp5{ make_unique<Complex>(111,222) , &Complex_Deleter };
	//unique_ptr< Complex, decltype(&Complex_Deleter) > pComp5 =  make_unique<Complex, &Complex_Deleter >(111,222) ;
	unique_ptr< Complex, decltype(&gen_deleter<Complex>) > pComp6{ new Complex(111,222) , &gen_deleter<Complex> };
	if (pComp6)
		pComp6->Show();

	LOG("++++++++++++++++++++++++");

	unique_ptr<int[]> p_arr{ new int[10]{101,20,30,40,50} };
	cout << p_arr[1] << endl;
	LOG_VAR( (p_arr[3] ) );
	p_arr[3] = 3000;
	LOG_VAR((p_arr[3]));
	//LOG_VAR((p_arr[30])); // no boundry check ,call success
	//for (auto &x : p_arr)	//should have begin() inside unique_ptr - error
//		cout << "\n value = " << x << ;

	int arrT2[20] = {0};
	for (auto &x : arrT2)	//should have begin() inside unique_ptr - error
		cout << "\n value = " << x << endl;
	LOG("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
}