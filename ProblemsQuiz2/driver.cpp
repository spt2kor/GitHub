#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <unordered_map>

#include "Util.h"
#include "Item.h"
#include "ShoppingCart.h"
#include "Tester.h"
using namespace std;
//==========================================================================================
//==========================================================================================
//==========================================================================================
void main()
{
	cout << "\tWelcome to the Store" << endl;

	cout << "************  INITIALIZING ************";
	ItemBillingMgr billingMgr;
	billingMgr.SetBasicSalesTax(10.0);
	billingMgr.SetImportSalesTax(5.0);			//cout << endl;
	billingMgr.AddDiscountedItemType(IT_Food);
	billingMgr.AddDiscountedItemType(IT_Books);
	billingMgr.AddDiscountedItemType(IT_Medicine);
	string allItemTypes = billingMgr.GetItemTypeString();
	//=====================================================
	cout << "\n*****************************************************\n Add items to Shopping cart "<<endl ;
	ShoppingCart cart1;
	//books, food,and medical products that are exempt

	char choice = 'y';

	while (1)
	{
		cout << "*******************************************" << endl;
		double costPerItem = 0.0;
		int itemQuantity = 0;
		int itemType;
		char isImported = 'n';
		char itemStr[100];

		cout << "Enter Item details \t:\t";
		cin >> itemQuantity;
		cin.getline(itemStr, 99);
		//cout << endl << "item details read\t:" << itemQuantity << " : [" << itemStr << "]" << endl;

		string itemName(itemStr);
		tie(itemName, costPerItem) = GetItemDetails(itemName);
		//cout << endl << "item details are\t:" << itemQuantity << " [" << itemName << "] : " << costPerItem << endl;
			
		itemType = GetItemType(itemName);	
		isImported = (itemName.find("imported") != string::npos)? 'y' : 'n';

		cout << "*******************************************" << endl;
		cart1.AddItem(Item_Type(itemType), itemName, costPerItem, itemQuantity, (isImported == 'y') ?  IIT_Imported_Product : IIT_Local_Product);
			
		choice = 'n';
		cout << "Do you want to add more Items to Cart (y/n): ";
		cin >> choice;
		if (choice == 'n')
			break;
	}
	billingMgr.CalculateBillNPrintReceipt(cart1);
	cout << "\n Thanks , visit again!!!" << endl;

}