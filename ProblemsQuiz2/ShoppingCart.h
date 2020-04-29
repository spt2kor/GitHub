#pragma once
#include "Item.h"


class ShoppingCart
{
	vector<Item> m_itemsToPurchase;
public:
	void AddItem(Item_Type itemType, const string &itemName, double pricePerItem, int itemQuantity = 1, Item_Import_Type importType = IIT_Local_Product);
	
	vector<Item>& GetAllItems();
};

//==========================================================================================
class ItemBillingMgr
{
	double m_basicTax;
	double m_ImportSalesTax;
	set<Item_Type> m_discountedItems;
	unordered_map<Item_Type, string> m_itemTypeToNameMap;

	string m_itemTypeStr;
public:
	ItemBillingMgr();
	bool AddDiscountedItemType(Item_Type itemType);

	bool SetImportSalesTax(double importTax);		//Percentage
	
	bool SetBasicSalesTax(double basicTax);			//Percentage
	
	void CalculateBillNPrintReceipt(ShoppingCart& aCart);

	string GetItemTypeString();
};