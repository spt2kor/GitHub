#include "Util.h"

double PrecisionCorrection(double no)
{
	double res = no;
	int temp = (no * 1000);
	temp = (temp % 10 >= 5) ? (temp / 10 + 1) : temp / 10;
	res = (temp*1.0) / 100;
	//cout << ">>>>PrecisionCorrection : " << no << ",  " << res<<endl;
	return res;
}
double RoundUp(double no)
{
	double res = no;
	int temp = (no * 100);
	if ((temp % 10 == 0) || (temp % 10 == 5))
		res = no;
	else //((temp % 10 < 5) && (temp % 10 != 0))
	{
		if ((temp % 10 < 5))
			temp = (temp / 10) * 10 + 5;
		else
			temp = (temp / 10) * 10 + 10;
		res = (temp*1.0) / 100;
	}

	//cout << ">>>>RoundUp : " << no << ",  " << res<<endl;
	return res;
}
