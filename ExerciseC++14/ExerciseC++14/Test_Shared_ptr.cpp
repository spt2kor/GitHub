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
using namespace std;
//http://en.cppreference.com/w/cpp/memory/shared_ptr
//https://en.cppreference.com/w/cpp/memory/enable_shared_from_this

/*class Node
{
	int value;
public:
	std::shared_ptr<Node> leftPtr;
	std::shared_ptr<Node> rightPtr;
	std::shared_ptr<Node> parentPtr;
	Node(int val) : value(val) {
		std::cout << "Contructor" << std::endl;
	}
	~Node() {
		std::cout << "Destructor" << std::endl;
	}
};*/

class Node
{
	int value;
public:
	std::shared_ptr<Node> leftPtr;
	std::shared_ptr<Node> rightPtr;
	// Just Changed the shared_ptr to weak_ptr
	std::weak_ptr<Node> parentPtr;
	Node(int val) : value(val) {
		std::cout << "Contructor" << std::endl;
	}
	~Node() {
		std::cout << "Destructor" << std::endl;
	}
};/*
int main()
{
	std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
	ptr->leftPtr = std::make_shared<Node>(2);
	ptr->leftPtr->parentPtr = ptr;
	ptr->rightPtr = std::make_shared<Node>(5);
	ptr->rightPtr->parentPtr = ptr;
	std::cout << "ptr reference count = " << ptr.use_count() << std::endl;
	std::cout << "ptr->leftPtr reference count = " << ptr->leftPtr.use_count() << std::endl;
	std::cout << "ptr->rightPtr reference count = " << ptr->rightPtr.use_count() << std::endl;
	std::cout << "ptr->rightPtr->parentPtr reference count = " << ptr->rightPtr->parentPtr.lock().use_count() << std::endl;
	std::cout << "ptr->leftPtr->parentPtr reference count = " << ptr->leftPtr->parentPtr.lock().use_count() << std::endl;
	return 0;
}*/
template <typename T>
void print(shared_ptr<T>& x)
{
	cout << "\n print(shared_ptr x) use_count= " << x.use_count() << endl;
	if (!x)
		cout << "\n print(shared_ptr x) is empty " << endl;
	else
		cout << "\n print(shared_ptr x) = " << *x << endl;
}
template <typename T>
void print(weak_ptr<T>& x)		//http://en.cppreference.com/w/cpp/memory/weak_ptr
{
	cout << "\n print(weak_ptr x) use_count= " << x.use_count() << endl;
	if (x.expired())
		cout << "\n print(weak_ptr x) is empty " << endl;
	else
		cout << "\n print(weak_ptr x) = " << *x.lock() << endl;

	//cout << "\n print(weak_ptr x) use count= " << x.lock().use_count() << endl; //creates temporary shared_ptr and increases the use_count by 1
}
//============================================================
struct Cyclic_A;
struct Cyclic_B
{
	shared_ptr<Cyclic_A> aPtr;
	Cyclic_B()
	{
		cout << "\n Cyclic_B()" << endl;
	}
	~Cyclic_B()
	{
		cout << "\n ~Cyclic_B()" << endl;
		
		cout << "\n ~Cyclic_B() aPtr.use_count() = " << aPtr.use_count() << endl;
	}
};
struct Cyclic_A
{
	shared_ptr<Cyclic_B> bPtr;
	Cyclic_A()
	{
		cout << "\n Cyclic_A()" << endl;
	}
	~Cyclic_A()
	{
		cout << "\n ~Cyclic_A()" << endl;
		cout << "\n ~Cyclic_A() bPtr.use_count() = " << bPtr.use_count() << endl;
	}
};
//============================================================

//http://www.acodersjourney.com/2016/05/top-10-dumb-mistakes-avoid-c-11-smart-pointers/

void TestSharedPtr()
{
	TRACE("TestSharedPtr");
	{
		//http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3974.pdf
		LOG("++++++++++++++++++++++++");
		shared_ptr<Complex> cbp = make_shared<ComplexD>(23, 24, 25);		//calls non virtual DTOR of ComplexD and Complex class in proper order ??? how?? 
		cbp->Show();		
		//shared_ptr<ComplexD> cdp(dynamic_cast<Complex*>(cbp.release() ) ) );// not compiling - no release function
		/*
		shared_ptr<ComplexD> cdp;
		//swap(cbp, cdp);	down cast not working 
		if(cdp )
			cdp->Show();
			*/
		LOG("++++++++++++++++++++++++");
		shared_ptr<ComplexD> cdp1 = dynamic_pointer_cast<ComplexD>(cbp);//https://en.cppreference.com/w/cpp/memory/shared_ptr/pointer_cast			-	VIMP 
		//https://www.lonecpluspluscoder.com/2014/11/19/polymorphism-and-boost-shared_ptr/
		//https://www.reddit.com/r/cpp_questions/comments/4mb5dp/is_it_okay_to_use_stdshared_ptr_with_polymorphic/
		cdp1->Show();
		cout << "\n count = " << cdp1.use_count() << endl; // count is 2.
	}
	LOG("++++++++++++************* ++++++++++++");

	{		//cyclic dependency
		shared_ptr<Cyclic_A> aCycPtr;
		shared_ptr<Cyclic_B> bCycPtr;
		aCycPtr = make_shared<Cyclic_A>();
		cout << "\n aCycPtr.use_count() = " << aCycPtr.use_count() << endl;
		bCycPtr = make_shared<Cyclic_B>();
		cout << "\n bCycPtr.use_count() = " << bCycPtr.use_count() << endl;
		aCycPtr->bPtr = bCycPtr;
		cout << "\n **** aCycPtr.use_count() = " << aCycPtr.use_count() << endl;
		cout << "\n **** bCycPtr.use_count() = " << bCycPtr.use_count() << endl;
		bCycPtr->aPtr = aCycPtr;
		cout << "\n ##### aCycPtr.use_count() = " << aCycPtr.use_count() << endl;
		cout << "\n ##### bCycPtr.use_count() = " << bCycPtr.use_count() << endl;

	}


	LOG("++++++++++++++++++++++++");
	shared_ptr <Complex> s_comp = make_shared<Complex>(1, 2);
	print(s_comp);
	
	weak_ptr<Complex> w_comp =  s_comp ;//http://www.learncpp.com/cpp-tutorial/15-7-circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/
	print(w_comp);

	auto s_comp1 = s_comp;
	auto s_comp2 = s_comp1;
	cout << "\n s_comp2 use count= " << s_comp2.use_count() << endl;
	s_comp = s_comp2;
	cout << "\ns_comp use count= " << s_comp.use_count() << endl;
	LOG("++++++++++++++++++++++++");

	shared_ptr<int> s_null;
	if (!s_null)
		cout << "\n s_null is empty " << endl;
	s_null = make_shared<int>(100);
	if (!s_null)
		cout << "\n s_null is empty " << endl;
	else
		cout << "\n *s_null = " << *s_null << endl;
	LOG("++++++++++++++++++++++++");

	unique_ptr<int> u_i = make_unique<int>(100);
	//cout << "\n u_i = " << u_i << endl;		no auto dereference
	cout << "\n *u_i = " << *u_i << endl;

	shared_ptr<int> s_i_u ( move(u_i) );
	cout << "\n *s_i_u = " << *s_i_u << endl;		//owner ship is gone
	if(u_i)
		cout << "\n *u_i = " << *u_i << endl;		
	LOG("++++++++++++++++++++++++");
	std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
	ptr->leftPtr = std::make_shared<Node>(2);
	ptr->leftPtr->parentPtr = ptr;
	ptr->rightPtr = std::make_shared<Node>(5);
	ptr->rightPtr->parentPtr = ptr;
	std::cout << "ptr reference count = " << ptr.use_count() << std::endl;
	std::cout << "ptr->leftPtr reference count = " << ptr->leftPtr.use_count() << std::endl;
	std::cout << "ptr->rightPtr reference count = " << ptr->rightPtr.use_count() << std::endl;
	std::cout << "ptr->rightPtr->parentPtr reference count = " << ptr->rightPtr->parentPtr.lock().use_count() << std::endl;
	std::cout << "ptr->leftPtr->parentPtr reference count = " << ptr->leftPtr->parentPtr.lock().use_count() << std::endl;
	LOG("++++++++++++++++++++++++");
	shared_ptr<int> p_i{ make_shared<int>( 100 ) };
	LOG_VAR(p_i);		//prints pointer
	LOG_VAR(*p_i);		//prints value

	int * p_i1 = new int{ 2000 };
	shared_ptr<int> p_i2 (p_i1);
	LOG_VAR(p_i2);		//prints pointer
	LOG_VAR(*p_i2);		//prints value

	cout << "\n count = " << p_i2.use_count() << endl;
	shared_ptr<int> p_i2_2(p_i2);

	cout << "\np_i2_2  count = " << p_i2_2.use_count() << endl;
	p_i = p_i2_2;
	cout << "\n p_i2_2 count = " << p_i2_2.use_count() << endl;
	p_i.reset<int>(new int(200));
	cout << "\n p_i2_2 count = " << p_i2_2.use_count() << endl;
	p_i2_2 = nullptr;
	cout << "\n p_i2_2 count = " << p_i2_2.use_count() << endl;
	cout << "\n  p_i2 count = " << p_i2.use_count() << endl;

	shared_ptr<int> p_iArr( new int[5]{10,20,30,40,50} );
	//int x = * p_iArr[0];					//aray indexing not supported in shared_ptr	[], supported in C++17
	//cout<<"value = "<< p_iArr[0] <<endl;		
	


}