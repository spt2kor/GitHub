template <int Size = 3>
class TicTacToeCore
{
public:
	enum EMove
	{
		eUnVisited = 0,
		eP1Move = 1,
		eP2Move = 2
	};

	enum EWinStatus
	{
		ePlayFurther	=	0,
		eTie	=	1,
		eP1Win	=	2,
		eP2Win	=	3
	};
		
	TicTacToeCore(void)
	{
		for(int i= 0 ; i< Size ; ++i)
			for(int j= 0 ; j< Size ; ++j)
				m_arr[i][j] = eUnVisited;
		
		m_moveCount = 0;

	}

	~TicTacToeCore(void)
	{

	}

	
	bool Move(EMove playerNo , int row, int col)
	{
		if(m_arr[row][col] == eUnVisited)
		{
			switch( playerNo )
			{
			case eP1Move :
				m_arr[row][col] = eP1Move;
				break;
			case eP2Move :
				m_arr[row][col] = eP2Move;
				break;
			}
			++m_moveCount;
			return true;
		}
		else
			return false;		
	}
	
	void Print()
	{
		for(int i= 0 ; i< Size ; ++i)
		{
			cout<<"\n";
			for(int j= 0 ; j< Size ; ++j)
			{
				cout<<"\t";

				switch( m_arr[i][j] )
				{
				case eUnVisited :
					cout<<"_";
					break;
				case eP1Move :
					cout<<"X";
					break;
				case eP2Move :
					cout<<"O";
					break;
				}
			}
		}
		cout<<"\n";
	}

	EWinStatus isWin(EMove playerNo , int row, int col)//return winning player no 1,2 or tie , Playfurther
	{
		int PlayerValue = eUnVisited;
		EWinStatus status = ePlayFurther;

		if(playerNo == eP1Move)	{ PlayerValue = eP1Move; status = eP1Win ;  }
		else if(playerNo == eP2Move)	{ PlayerValue = eP2Move;status = eP2Win ;  }
		
		//compare column
		int count = 0;
		for(int i= 0 ; i< Size ; ++i)	
			if(m_arr[i][col] == PlayerValue)
				count++;
		if(count == Size)
			return status;

		//compare row
		count = 0;
		for(int i= 0 ; i< Size ; ++i)	
			if(m_arr[col][i] == PlayerValue)
				count++;
		if(count == Size)
			return status;

		//compare diagnal backward
		count = 0;
		if(row == col)
		{
			for(int i= 0 ; i< Size ; ++i)	
				if(m_arr[i][i] == PlayerValue)
					count++;
			if(count == Size)
				return status;
		}

		//compare diagnal farward
		count = 0;
		if( (Size - row -1) == col)
		{
			for(int i= 0 ; i< Size ; ++i)	
				if(m_arr[Size-i-1][i] == PlayerValue)
					count++;
			if(count == Size)
				return status;
		}

		//check Tie , or further play
		if(m_moveCount == Size*Size)
			return status = eTie;
		else
			return status = ePlayFurther;
	}


private :
	int m_arr[Size][Size] ;
	int m_moveCount;


};

