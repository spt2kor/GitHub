/*
//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/tutorial/


//https://www.youtube.com/watch?v=OQ5jsbhAv_M

//https://www.programiz.com/cpp-programming/examples/fibonacci-series

//https://www.sciencedirect.com/science/article/pii/S0019995885800462?via%3Dihub

*/

#include <iostream>
using namespace std;


//=====================================================================================================
//=====================================================================================================
int count_Fabonaci_Recursion = 0;
int fab_rec_actual_cal = 0;
int *count_Fab_Recu_no = NULL;

int Fabonaci_Recursion(int Tn)
{
	++count_Fabonaci_Recursion;
	if ( Tn == 1 )
	{
		++count_Fab_Recu_no[Tn];
		//cout<<"\n Fabonaci_Recursion("<<Tn<<") :"<<0<<endl;
		return 0;
	}
	else if ( Tn == 2 )
	{
		++count_Fab_Recu_no[Tn];
		//cout<<"\n Fabonaci_Recursion("<<Tn<<") :"<<1<<endl;
		return 1;
	}
	else if( Tn > 2)
	{
		++fab_rec_actual_cal;
		++count_Fab_Recu_no[Tn];
		int sum = Fabonaci_Recursion ( Tn - 1 ) + Fabonaci_Recursion ( Tn - 2);
		//cout<<"\n Fabonaci_Recursion("<<Tn<<") :"<<sum<<endl;
		return sum;
	}
	else 
		return -1;
}

int Fabonaci_Recursion_Helper(int Tn)
{
	if( Tn == 1 )
		return 0;
	if( Tn == 2 )
		return 1;

	count_Fab_Recu_no = new int[Tn+1];
	fab_rec_actual_cal = 0;
	count_Fabonaci_Recursion = 0;

	for(int i = 0 ; i< (Tn+1) ; ++i)
		count_Fab_Recu_no[i] = 0;

	int sum = Fabonaci_Recursion(Tn);
	cout<<"\n ********* \n : count_Fabonaci_Recursion = "<<count_Fabonaci_Recursion<<"\n   fab_rec_actual_cal = "<<fab_rec_actual_cal<<endl;

	for(int i = 0 ; i< (Tn+1) ; ++i)
	{
		cout<<"\n count_Fab_Recu_no["<<i<<"] = "<<count_Fab_Recu_no[i];
	}
	cout<<"\n*********"<<endl;

	delete[] count_Fab_Recu_no;
	count_Fab_Recu_no = NULL;
	return sum;
}

//=====================================================================================================
int Fabonaci_Loop(int pos)
{
	if(pos == 1)
		return 0;
	else if(pos == 2)
		return 1;
	else if(pos < 0)
		return -1;
	else		//pos > 2
	{
		int p1 = 0 , p2 = 1; //last = 0 , sec_last = 1;
		int curr = 0;
		for( int i = 3 ; i <= pos; ++i)
		{
			curr = p2 + p1;
			p1 = p2;
			p2 = curr;
		}
		return curr;
	}
}
//=====================================================================================================
int * fab_rec_DP = NULL;
int fab_rec_DP_actual_cal = 0; 
int count_Fab_Rec_DP = 0; 
int Fabonaci_Recursion_DP(int Tn)
{
	if( (Tn == 1) || (Tn == 2) )
	{
		++count_Fab_Rec_DP;
		return fab_rec_DP[Tn];
	}
	else if(fab_rec_DP[Tn] == 0)  //for Tn > 2
	{
		++fab_rec_DP_actual_cal;
		++count_Fab_Rec_DP;
		return ( fab_rec_DP[Tn] = Fabonaci_Recursion_DP(Tn-1) + Fabonaci_Recursion_DP(Tn-2) ); 		
	}
	else
	{
		return fab_rec_DP[Tn];
	}
}

int Fabonaci_Recursion_DP_Helper(int Tn)
{
	if(Tn == 1)
		return 0;
	else if(Tn == 2)
		return 1;

	fab_rec_DP_actual_cal = 0; 
	count_Fab_Rec_DP = 0; 

	fab_rec_DP = new int[Tn+1];		//keep 0th location unused
	for(int i=0; i< Tn+1 ; ++i)
		fab_rec_DP[i] = 0;
	fab_rec_DP[1] = 0;
	fab_rec_DP[2] = 1;

	Fabonaci_Recursion_DP(Tn);
	cout<<"\n****************"<<endl;
	for(int i = 0; i < Tn+1 ; ++i)
		cout<<"\n fab_rec_DP["<<i<<"] = "<< fab_rec_DP[i];
	cout<<"\n****************\n  count_Fab_Rec_DP = "<<count_Fab_Rec_DP<<"\n   fab_rec_DP_actual_cal = "<<fab_rec_DP_actual_cal<<endl;

	Tn = fab_rec_DP[Tn];
	delete[] fab_rec_DP;
	fab_rec_DP = NULL;

	return Tn;


}
//=====================================================================================================
void main()
{
	cout<<"\n Program Started "<<__FILE__<<endl;
	
	//--------------------------------------------------------------------------------------
	cout<<"\n Fabonaci_Recursion_Helper(10) :"<<Fabonaci_Recursion_Helper(10)<<endl;
	cout<<"\n ================================================= "<<endl;
	//--------------------------------------------------------------------------------------
	cout<<"\n Fabonaci_Loop(10) :"<<Fabonaci_Loop(10)<<endl;
	cout<<"\n ================================================= "<<endl;
	//--------------------------------------------------------------------------------------
	cout<<"\n Fabonaci_Recursion_DP_Helper(10) :"<<Fabonaci_Recursion_DP_Helper(10)<<endl;
	cout<<"\n ================================================= "<<endl;
	//--------------------------------------------------------------------------------------


	//--------------------------------------------------------------------------------------
	cout<<"\n Program Ended"<<endl;
}
/*

 
 Program Started Dynamic-Programming\Fabonacci-DP.cpp

 *********
 : count_Fabonaci_Recursion = 109
   fab_rec_actual_cal = 54

 count_Fab_Recu_no[0] = 0
 count_Fab_Recu_no[1] = 21
 count_Fab_Recu_no[2] = 34
 count_Fab_Recu_no[3] = 21
 count_Fab_Recu_no[4] = 13
 count_Fab_Recu_no[5] = 8
 count_Fab_Recu_no[6] = 5
 count_Fab_Recu_no[7] = 3
 count_Fab_Recu_no[8] = 2
 count_Fab_Recu_no[9] = 1
 count_Fab_Recu_no[10] = 1
*********

 Fabonaci_Recursion_Helper(10) :34

 =================================================

 Fabonaci_Loop(10) :34

 =================================================

****************

 fab_rec_DP[0] = 0
 fab_rec_DP[1] = 0
 fab_rec_DP[2] = 1
 fab_rec_DP[3] = 1
 fab_rec_DP[4] = 2
 fab_rec_DP[5] = 3
 fab_rec_DP[6] = 5
 fab_rec_DP[7] = 8
 fab_rec_DP[8] = 13
 fab_rec_DP[9] = 21
 fab_rec_DP[10] = 34
****************
  count_Fab_Rec_DP = 11
   fab_rec_DP_actual_cal = 8

 Fabonaci_Recursion_DP_Helper(10) :34

 =================================================

 Program Ended
Press any key to continue . . .







*/