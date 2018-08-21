#include <iostream>
using namespace std;
//https://stackoverflow.com/questions/227897/how-to-allocate-aligned-memory-only-using-the-standard-library
/*

{
    void *mem = malloc(1024+15);
    void *ptr = ((uintptr_t)mem+15) & ~ (uintptr_t)0x0F;
    memset_16aligned(ptr, 0, 1024);
    free(mem);
}

*/
//https://wr.informatik.uni-hamburg.de/_media/teaching/wintersemester_2013_2014/epc-14-haase-svenhendrik-alignmentinc-paper.pdf

//https://embeddedartistry.com/blog/2017/2/20/implementing-aligned-malloc
//https://sites.google.com/site/ruslancray/lab/bookshelf/interview/ci/low-level/write-an-aligned-malloc-free-function

//https://msdn.microsoft.com/en-us/library/8z34s9c6.aspx
/*
void * _aligned_malloc(  
    size_t size,   
    size_t alignment  
);  
*/

void PrintBinary(int no)
{
	int totalBits = sizeof(no) * 8;
	cout<<"\n *******  PrintBinary ("<<no<<") = ";
	for(int i = totalBits-1 ; i >= 0 ; --i)
	{
		cout<<( (no & 1<<i)? "1":"0" );
	}
	cout<<endl<<endl;
}

void main()
{
	cout<<"\n Program Started"<<endl;
	
	int bytesNeeded = 15;
	cout<<"\n bytesNeeded = "<<bytesNeeded;
	PrintBinary(bytesNeeded);

	int allignmentNeeded = 16; //32
	cout<<"\n allignmentNeeded = "<<allignmentNeeded;
	PrintBinary(allignmentNeeded);
	
	int memoryAddressOrig = 100;
	cout<<"\n memoryAddressOrig = "<<memoryAddressOrig;
	PrintBinary(memoryAddressOrig);

	int allignedAddress = (memoryAddressOrig + allignmentNeeded-1)		;
	cout<<"\n bytesNeeded = "<<allignedAddress;
	PrintBinary(allignedAddress);

	int masking = ~(allignmentNeeded-1);
	cout<<"\n masking = "<<masking;
	PrintBinary(masking);

	allignedAddress = allignedAddress & masking;
	cout<<"\n allignedAddress = "<<allignedAddress;
	PrintBinary(allignedAddress);




	cout<<"\n Program Ended"<<endl;
}