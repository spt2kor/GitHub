#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    char    abc[27];
    char    *ptr = abc;
    strcpy(abc, "abcdefgxyz");
     /*
     * What are the types and values of expressions:
     *
  
     * 1. abc
     * 2. *abc
     * 3. abc[2]
     * 4. &abc[3] //&abc[3] = abc + 3*sizeof(char)
     * 5. abc+4
     * 6. *(abc+5) + 20000  //h  long long x = int * 1LL * int
     * 7. abc[10] //'\0'
     * 8. abc[12] //memset ()
     * 9. &ptr //char**
     */
	cout<<"\n &abc = "<<&abc<<endl;
	cout<<"\n abc = "<<abc<<endl;
     
		 cout<<"\n *abc = "<<*abc<<endl;
     
	 cout<<"\n abc[2] = "<<abc[2]<<endl;
     
	 cout<<"\n &abc[3] = "<<&abc[3]<<endl;
     
		 cout<<"\n abc+4 = "<<abc+4<<endl;
     
		 cout<<"\n *(abc+5) + 20000 = "<<*(abc+5) + 20000<<endl;
     
	 cout<<"\n abc[10] = "<<abc[10]<<endl;
     
	 cout<<"\n abc[12] = "<<abc[12]<<endl;
     
		 cout<<"\n &ptr = "<<&ptr<<endl;
     return 0;
}