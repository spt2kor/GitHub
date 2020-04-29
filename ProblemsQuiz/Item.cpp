#include "Item.h"

Item::Item(Item_Type itemType, const string &itemName, double pricePerItem, int itemQuantity, Item_Import_Type importType) :
	m_ItemType(itemType), m_itemName(itemName), m_pricePerItem(pricePerItem),
	m_iitType(importType), m_itemQuantity(itemQuantity)
{}

Item::~Item()
{
}
//==========================================================
