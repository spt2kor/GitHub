#include "Tester.h"
#include "Util.h"
#include "Item.h"
#include "ShoppingCart.h"

void runStandardTestCase()
{
	cout << "\n ( TEST MODE ON )\n *****************" << endl;
	ItemBillingMgr billingMgr;
	billingMgr.SetBasicSalesTax(10.0);
	billingMgr.SetImportSalesTax(5.0);
	billingMgr.AddDiscountedItemType(IT_Food);
	billingMgr.AddDiscountedItemType(IT_Books);
	billingMgr.AddDiscountedItemType(IT_Medicine);

	//=====================================================
	cout << "\n adding items to Shopping cart 1 " << endl;
	ShoppingCart cart1;
	cart1.AddItem(IT_Books, "Book", 12.49, 1, IIT_Local_Product);
	cart1.AddItem(IT_Electronics, "music CD", 14.99, 1, IIT_Local_Product);
	cart1.AddItem(IT_Food, "chocolate bar", 0.85, 1, IIT_Local_Product);
	billingMgr.CalculateBillNPrintReceipt(cart1);

	cout << "\n adding items to Shopping cart 2 " << endl;
	ShoppingCart cart2;
	cart2.AddItem(IT_Food, "chocolates", 10.00, 1, IIT_Imported_Product);
	cart2.AddItem(IT_PersonalHygiene, "perfume", 47.50, 1, IIT_Imported_Product);
	billingMgr.CalculateBillNPrintReceipt(cart2);

	cout << "\n adding items to Shopping cart 3 " << endl;
	ShoppingCart cart3;
	cart3.AddItem(IT_PersonalHygiene, "perfume", 27.99, 1, IIT_Imported_Product);
	cart3.AddItem(IT_PersonalHygiene, "perfume", 18.99, 1, IIT_Local_Product);
	cart3.AddItem(IT_Medicine, "headache pills", 9.75, 1, IIT_Local_Product);
	cart3.AddItem(IT_Food, "chocolates", 11.25, 1, IIT_Imported_Product);
	billingMgr.CalculateBillNPrintReceipt(cart3);

	cout << "\n Thanks , visit again!!!" << endl;

}