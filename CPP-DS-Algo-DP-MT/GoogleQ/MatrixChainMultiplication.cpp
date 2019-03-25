//
//  MatrixChainMultiplication.cpp
//  GoogleQ
//
//  Created by Shailendra Pratap Singh Rajput on 23/03/19.
//  Copyright © 2019 Shailendra Pratap Singh Rajput. All rights reserved.
//

#include <iostream>
using namespace std;


int main()
{
	cout<<"\n Program Started MAtrix Chain Multiplication DP"<<endl;
	//string str = "ABCD";
	//printParanthesis(str,0,str.size());
	
	cout<<"\n Program Ended "<<endl;
	return 0;
}


/*
 
 string  printParanthesis(string & str, int s, int e) // ( s , e ]
 {
 string result;
 if(s>=e)
 return result;
 
 if(s+1==e)
 {
 result += str[s];
 return result;
 }
 
 if( s+2 == e)
 {
 result.push_back('(');
 result.push_back(str[s]);
 result.push_back(str[s+1]);
 result.push_back(')');
 return result;
 }
 
 for(int i=s; i< e ; ++i)
 {
 result.clear();
 result += "(";
 result += printParanthesis(str, s, i+1 );
 result +=printParanthesis(str , i+1, e );
 
 result += ")";
 }
 if(s==0  && e== str.size())
 cout<<endl<< result<<endl;
 return result;
 //0,1   1,4				( A (BCD) )
 //=>	1,2  2,4			(B  (CD) )
 //=>	1,3  3,4			( (BC) D)
 
 //0,2   2,4		(AB) (CD)
 //1,3   3,4		(ABC) (D)
 }
 */
