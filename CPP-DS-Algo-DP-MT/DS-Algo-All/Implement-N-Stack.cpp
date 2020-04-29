#include <iostream>
#include <algorithm>
using namespace std;
# pragma warning(disable:4290)

struct EXCPTION_STACK_FULL : public exception
{
	EXCPTION_STACK_FULL(const char* const errorStr) : exception(errorStr)
	{	}
};
struct EXCPTION_STACK_EMPTY : public exception
{
	EXCPTION_STACK_EMPTY(const char* const errorStr) : exception(errorStr)
	{	}
};
//=====================================================================
struct MultiStack {
	const size_t capacity = 20;
	size_t size = 0; 
	size_t nextFreePos = 0; // next available marker;
	int *st;
	int *top;
	int *nextNprev;
	size_t nStack;


	MultiStack(int noOfStacks) {
		st			= new int[capacity];
		nextNprev	= new int[capacity];
		top			= new int[noOfStacks];
		nStack		= noOfStacks;
		for (int i = 0; i < capacity; ++i) {
			nextNprev[i] = i + 1;
		}
		for (int i = 0; i < noOfStacks; ++i) {
			top[i] = -1;
		}
	}
	void PrintStatus()
	{
		cout << "\n***********	\n size = " << size << "\t nextFreePos = " << nextFreePos << endl;
		cout << "top = \t";
		for_each(top, top + nStack, [this](int topValue) {
			cout << "\t "<< topValue;
		});
		cout << "\n nextNprev = \t";
		for_each(nextNprev, nextNprev + capacity, [this](int NextPrevValue) {
			cout << "\t " << NextPrevValue;
		});
		cout << "\n stack = \t";
		for_each(st, st + capacity, [this](int Stackvalue) {
			cout << "\t " << Stackvalue;
		});
	}
	void PrintAll() {
		for_each(top, top + nStack, [this](int stNo) { 
			cout << "\n Stack[" << stNo << "] Content = ";
			while (stNo != -1) {
				cout << " \t " << st[stNo];
				stNo = nextNprev[stNo];
			}
		});
	}

	void push(int stackNo, int data) throw(EXCPTION_STACK_FULL) {

		if (size == capacity)
			throw EXCPTION_STACK_FULL("Stack is FULL, unable to Push Element Now!!!");
		++size;
		st[nextFreePos] = data; //copy data to free slot
		int newNextPos = nextNprev[nextFreePos]; // find after push, next free pos.
		nextNprev[nextFreePos] = top[stackNo]; //put prev location pos
		top[stackNo] = nextFreePos; //mark curent location as top of stack.
		nextFreePos = newNextPos; //mark next free location.
		
		PrintStatus();
	}

	int pop(int stackNo) throw(EXCPTION_STACK_EMPTY) {
		if(size == 0 || (top[stackNo] == -1))
			throw EXCPTION_STACK_EMPTY("Stack is Empty, unable to POP Element Now!!!");
		int data = INT_MIN;
		int pos = top[stackNo];
		data = st[pos];
		top[stackNo] = nextNprev[pos];
		nextNprev[pos] = nextFreePos;
		nextFreePos = pos;
		--size;

		PrintStatus();
		
		return data;
	}
};
//=====================================================================
int main()
{
	try {


		cout << "\n Program started" << endl;

		MultiStack ms(5);

		ms.push(0, 10);
		ms.push(0, 20);
		ms.push(4, 30);
		ms.push(3, 40);
		ms.push(2, 50);
		ms.push(1, 60);
		ms.push(3, 70);

		cout << "\n Print All Stack" << endl;
		ms.PrintAll();

		for (auto i : { 0,1,2,3,4 })
			cout << "\n ms.pop(" << i << ") = " << ms.pop(i) << endl;

		cout << "\n Print All Stack" << endl;
		ms.PrintAll();

		ms.push(0, 80);
		ms.push(0, 90);
		ms.push(4, 100);
		ms.push(3, 110);
		ms.push(2, 120);
		ms.push(1, 130);
		ms.push(3, 140);

		cout << "\n Print All Stack" << endl;
		ms.PrintAll();

		cout << "\n Program Ended" << endl;
	}
	catch (exception &e) {
		cout << "\n @@@@@@ Exception Caught type = " << e.what() << endl;
	}
	return 0;
}
//=====================================================================