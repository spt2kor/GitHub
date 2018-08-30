
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <chrono>
#include <thread>
#include "Trace.h"
#include "Complex.h"
#include "windows.h"

#include "onlyFuncHeader.h"

using namespace std;


void TestUnorderedContainer()
{
	TRACE("TestUnorderedContainer()");
	unordered_map<int, string> unmap;
	unmap[12] = "Two";
	unmap[5] = "Five";
	/*unmap[80] = "Eight";
	unmap[3] = "Three";
	unmap[40] = "Four";
	unmap[122] = "Two";
	unmap[53] = "Five";
	unmap[830] = "Eight";
	unmap[33] = "Three";
	unmap[440] = "Four";
	unmap[142] = "Two";
	unmap[54] = "Five";
	unmap[850] = "Eight";
	unmap[35] = "Three";
	unmap[450] = "Four";*/
	for (auto x : unmap)
		cout << " -> " << x.first <<" , " <<x.second;

	cout << "\n unmap.bucket_count()  = " << unmap.bucket_count() << endl;			//	unmap.bucket_count()  = 8
	unmap[126] = "Two";
	unmap[56] = "Five";
	unmap[860] = "Eight";
	unmap[73] = "Three";
	unmap[7740] = "Four";
	unmap[172] = "Two";
	unmap[57] = "Five";
	unmap[880] = "Eight";
	unmap[38] = "Three";
	unmap[480] = "Four";
	cout << "\n unmap.bucket_count()  = " << unmap.bucket_count() << endl;			//	unmap.bucket_count()  = 64
	
	cout << "\n *******************************************" << endl;
	for (int i = 0; i < unmap.bucket_count(); ++i)
		if(unmap.bucket(i) > 0 )
		cout << "\n unmap.bucket_size(" << i << ")  = " << unmap.bucket_size(i) << endl;			//	unmap.bucket_count()  = 64
	cout << "\n *******************************************" << endl;
	for(int i = 0 ; i < unmap.bucket_count() ; ++i)
		cout << "\n unmap.bucket_size("<<i<<")  = " << unmap.bucket_size(i) << endl;			//	unmap.bucket_count()  = 64
}
