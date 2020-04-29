#include "TicTacToeCore.h"
#include <iostream>
using namespace std;


void main()
{
	cout<<"\n Program started "<<__FILE__<<endl;

	TicTacToeCore<> game;
	
	int row1,col1;
	int row2,col2;
	TicTacToeCore<>::EWinStatus status;
	bool ToStop = true;
	while(ToStop)
	{
		row1 = -1, col1 = -1;
		row2 = -1, col2 = -1;
		game.Print();


		while (	1 ) 
		{
			cout<<"\n\n Enter Player One Move :";
			cin>>row1>>col1;
			if(	game.Move(TicTacToeCore<>::EMove::eP1Move , row1 ,col1) )
			{
				status = game.isWin(TicTacToeCore<>::EMove::eP1Move , row1 ,col1);
				if( status  == TicTacToeCore<>::EWinStatus::eP1Win) {
					cout<<"\n Player One Win !!!!"<<endl; ToStop = false;	}
				else if( status  == TicTacToeCore<>::EWinStatus::eTie) {
					cout<<"\n Match Tie Ending!!!!"<<endl; ToStop = false;	}

				break;
			}
			else
			{
				cout<<"\n place is booked try again!!!!"<<endl; continue;
			}
		}

		game.Print();
		while (ToStop)
		{
			cout<<"\n\n Enter Player Two Move :";
			cin>>row2>>col2;
			if ( game.Move(TicTacToeCore<>::EMove::eP2Move , row2 ,col2) )
			{
				status = game.isWin(TicTacToeCore<>::EMove::eP2Move , row2 ,col2);
				if( status  == TicTacToeCore<>::EWinStatus::eP2Win) {
					cout<<"\n Player Two Win !!!!"<<endl; ToStop = false;	}
				else if( status  == TicTacToeCore<>::EWinStatus::eTie) {
					cout<<"\n Match Tie Ending!!!!"<<endl; ToStop = false;	}

				break;

			}
			else
			{
				cout<<"\n place is booked try again!!!!"<<endl; continue;
			}
		}
	}

	
	cout<<"\n Program Ended"<<endl;
}