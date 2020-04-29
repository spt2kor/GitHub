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


string Trim(string str)
{
	if (str.empty())	return str;
	int size = str.size();
	int s = 0;
	int e = size - 1;
	while (s <= e)
	{
		if (str[s] == ' ')	++s;
		else break;
	}
	while (s <= e)
	{
		if (str[e] == ' ')	--e;
		else break;
	}
	string res(str, s, e - s + 1);
	//if((s!=0) || (e != (size-1)))
	//cout << "\n Trim input= [" << str << "] = out [" << res << "]" << endl;
	return res;
}
tuple<string, double> GetItemDetails(string itemName)
{
	double price = 0.0;
	itemName = Trim(itemName);
	size_t pos = itemName.find_last_of(' ');
	stringstream priceStr(itemName.substr(pos + 1));
	priceStr >> price;

	//cout << "\n price read : " << price;
	itemName.erase(pos);
	itemName = Trim(itemName);
	//cout << "\n name : " << itemName;
	pos = itemName.find_last_of("at");
	itemName.erase(pos - 1);
	itemName = Trim(itemName);
	//return tuple<string, double>(itemName , price);
	return{ itemName, price };
}

Item_Type GetItemType(string itemName)
{
	if (string::npos != itemName.find("book"))
		return IT_Books;
	if (string::npos != itemName.find("chocolate bar"))
		return IT_Food;
	if (string::npos != itemName.find("chocolates"))
		return IT_Food;
	if (string::npos != itemName.find("headache pills"))
		return IT_Medicine;

	return IT_Others;
}
