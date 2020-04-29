#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;
//==========================================================================================
//==========================================================================================
//==========================================================================================
string Trim(string str)
{
	if (str.empty())	return str;
	int size = str.size();
	int s = 0;
	int e = size-1;
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
	string res(str , s , e-s+1);
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
	return {itemName, price};
}
void main()
{
	cout << "\n start\n ****************************" << endl;
	int quantity = 0;
	char itemStr[100];
	double price = 0.0;

	cout << "\nEnter Item details \t:";
	cin >> quantity;
	cin.getline(itemStr, 99);
	cout << endl << "item details read\t:" << quantity << " : [" << itemStr << "]" << endl;

	//while()
	string itemName(itemStr);
	tie(itemName, price)= GetItemDetails(itemName);
	cout << endl << "item details are\t:" << quantity << " [" << itemName << "] : " << price << endl;


	cout << "\n ****************************\n End" << endl;

}
/*
void main()
{
	cout << "\n start\n ****************************" << endl;
	int quantity = 0;
	char itemStr[100];
	double price = 0.0;

	cout << "\nEnter Item details \t:";
	cin >> quantity;
	cin.getline(itemStr,99);
	cout << endl << "item details read\t:" << quantity << " : [" << itemStr << "]"<<endl;
	
	//while()
	string itemName(itemStr);
	itemName = Trim(itemName);
	size_t pos = itemName.find_last_of(' ');
	stringstream priceStr(itemName.substr(pos+1));
	priceStr >> price;
	cout << "\n price read : " << price;
	itemName.erase(pos);
	itemName = Trim(itemName);
	cout << "\n name : " << itemName;
	pos = itemName.find_last_of("at");
	itemName.erase(pos-1);
	itemName = Trim(itemName);
	//cout << endl << "item details are:" << quantity << " " << itemName << " : " << price<<endl;
	//cout << endl << "item details are\t:" << quantity << " " << itemStr << " : " << price << endl;
	cout << endl << "item details are\t:" << quantity << " [" << itemName << "] : " << price << endl;


	cout << "\n ****************************\n End" << endl;

}

*/