#include <iostream>
#include <set>
#include <vector>
#include <string>

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
	cout << "\n Welcome to the Store\n ****************************" << endl;
	cout << "want to run in Test Mode (y/n)? : ";
	char choice=0;
	cin >> choice;
	if (choice == 'y' )
	{
		runStandardTestCase();
	}
	else
	{
		cout << "\n*****************************************************\n ************  INITIALIZING ************  \n";
		ItemBillingMgr billingMgr;
		billingMgr.SetBasicSalesTax(10.0);
		billingMgr.SetImportSalesTax(5.0);			cout << endl;
		billingMgr.AddDiscountedItemType(IT_Food);
		billingMgr.AddDiscountedItemType(IT_Books);
		billingMgr.AddDiscountedItemType(IT_Medicine);
		string allItemTypes = billingMgr.GetItemTypeString();
		//=====================================================
		cout << "\n*****************************************************\n\n Add items to Shopping cart " ;
		ShoppingCart cart1;
		

		while (1)
		{
			cout << "\n*******************************************" << endl;
			string itemName;
			cout << "Enter Valid Item name (ex.. cd/book/soap) [A-Z,a-z, no space] \t: ";
			cin >> itemName; 
			
			int itemType;
			cout << "Enter Item Type [" << allItemTypes << "] \t: ";
			cin >> itemType;
			
			double costPerItem = 0.0;
			cout << "Enter 1 item cost $ (0-9, '.') \t: ";
			cin >> costPerItem;

			double itemQuantity = 0.0;
			cout << "Enter Item Quantity [0-9] \t: ";
			cin >> itemQuantity;

			char isImported = 'n';
			cout << "is it Imported Product (y/n) \t: ";
			cin >> isImported;

			cout << "*******************************************" << endl;
			cart1.AddItem(Item_Type(itemType), itemName, costPerItem, itemQuantity, (isImported == 'y') ?  IIT_Imported_Product : IIT_Local_Product);
			
			choice = 'n';
			cout << "\n Do you want to add more Items to Cart (y/n): ";
			cin >> choice;
			if (choice == 'n')
				break;
		}
		billingMgr.CalculateBillNPrintReceipt(cart1);
		cout << "\n Thanks , visit again!!!" << endl;
	}
}