#include "ShoppingCart.h"
#include "Util.h"
#include "sstream"

void ShoppingCart::AddItem(Item_Type itemType, const string &itemName, double pricePerItem, int itemQuantity, Item_Import_Type importType)
{
	Item aItem(itemType, itemName, pricePerItem, itemQuantity, importType);
	m_itemsToPurchase.push_back(aItem);
	//cout << "\n*** Item Added to the Shopping Cart:   " << aItem.m_itemQuantity << " "										\
		<< ((aItem.m_iitType == IIT_Imported_Product) ? " imported " : " ")			\
		<< aItem.m_itemName << " : price - " << aItem.m_pricePerItem <<" $"<< endl;
}

	
vector<Item>& ShoppingCart::GetAllItems() 
{	
	return m_itemsToPurchase; 
}


//==========================================================================================
//==========================================================================================
//==========================================================================================

ItemBillingMgr::ItemBillingMgr()
{
	m_itemTypeToNameMap[IT_Food]			= "Food";	
  	m_itemTypeToNameMap[IT_Medicine]		= "Medicine";
	m_itemTypeToNameMap[IT_Books]			= "Books";
	m_itemTypeToNameMap[IT_Electronics]		= "Electronics";
	m_itemTypeToNameMap[IT_PersonalHygiene] = "Personal Hygiene";
	m_itemTypeToNameMap[IT_Others]			= "Others";

	stringstream stream;
	stream << IT_Food << ":Food / " << IT_Medicine << ":Medicine / " << IT_Books << ":Books / " << IT_Electronics << ":Electronics / " \
		<< IT_PersonalHygiene << ":Personal Hygiene / " << IT_Others << ":Others";

	m_itemTypeStr = stream.str();
}

string ItemBillingMgr::GetItemTypeString()
{
	return m_itemTypeStr;
}

bool ItemBillingMgr::AddDiscountedItemType(Item_Type itemType)
{
	if (IT_UnknowType < itemType && itemType < IT_TotalItemTypes)
	{
		//cout << "\n Item Type :" << m_itemTypeToNameMap[itemType] << ", is added as Discounted Item";
		m_discountedItems.insert(itemType);
		return true;
	}
	cout << "\n ERROR: Wrong Item Type entered :" << itemType << endl;
	return false;
}


bool ItemBillingMgr::SetImportSalesTax(double importTax)		//Percentage
{
	if (0 <= importTax && importTax <= 100)
	{
		m_ImportSalesTax = importTax;
		cout << "\n Setting Imported Item's Sales Tax = " << importTax <<" % ";
		return true;
	}
	cout << "\n ERROR: Wrong Imported Sales Tax value entered :" <<importTax << endl;
	return false;
}


bool ItemBillingMgr::SetBasicSalesTax(double basicTax)			//Percentage
{
	if (0 <= basicTax && basicTax <= 100)
	{
		m_basicTax = basicTax;
		cout << "\n Setting Basic Sales Tax = " << basicTax << " % ";
		return true;
	}
	cout << "\n ERROR: Wrong Basic Sales Tax value entered :" << basicTax << endl;
	return false;
}
//==========================================================================================

void ItemBillingMgr::CalculateBillNPrintReceipt(ShoppingCart& aCart)
{
	vector<Item>& itemsList = aCart.GetAllItems();
	double totalSalesTax = 0.0;
	double totalPrice = 0.0;
	double itemSalesTax = 0.0;
	double itemPrice = 0.0;
	cout << "\n******************************************\n FINAL BILL  \n******************************************";
	cout<<"\n Total Bill For this Cart, having Total Items : " << itemsList.size() << endl;
	for (vector<Item>::iterator ItemItr = itemsList.begin(); ItemItr != itemsList.end(); ++ItemItr)
	{
		itemSalesTax = 0.0;
		itemPrice = 0.0;

		set<Item_Type>::iterator itemTypeItr = m_discountedItems.find(ItemItr->m_ItemType);
		if (itemTypeItr == m_discountedItems.end()) //its not a discounted item
			itemSalesTax = m_basicTax;

		if (ItemItr->m_iitType == IIT_Imported_Product) // add import tax
			itemSalesTax += m_ImportSalesTax;

		itemSalesTax = RoundUp(PrecisionCorrection((ItemItr->m_pricePerItem * itemSalesTax) / 100));
		itemPrice = (ItemItr->m_pricePerItem + itemSalesTax);

		//cout << "-- " << ItemItr->m_itemQuantity << " "										\
			<< ((ItemItr->m_iitType == IIT_Imported_Product) ? " imported " : " ")			\
			<< ItemItr->m_itemName << " : " << (itemPrice) <<" $"<< endl;
		cout << "-- " << ItemItr->m_itemQuantity << " "										\
			<< ItemItr->m_itemName << " : " << (itemPrice) << " $" << endl;

		totalSalesTax += itemSalesTax;
		totalPrice += itemPrice;
	}
	cout << " Sales Tax : " << (totalSalesTax) << " $ \n Total Price : " << (totalPrice) << " $ \n******************************************" << endl;
}
