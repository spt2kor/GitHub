#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

enum Item_Import_Type
{
	IIT_Local_Product,
	IIT_Imported_Product,
	IIT_Total_Products
};


enum Item_Type
{
	IT_UnknowType,
	IT_Food,
	IT_Medicine,
	IT_Books,
	IT_Electronics,
	IT_PersonalHygiene,
	IT_Others,
	IT_TotalItemTypes
};

struct Item
{
	Item_Type m_ItemType;
	string m_itemName;
	double m_pricePerItem;
	Item_Import_Type m_iitType;
	int m_itemQuantity;

	Item(Item_Type itemType, const string &itemName, double pricePerItem, int itemQuantity = 1, Item_Import_Type importType = IIT_Local_Product);
	
	~Item();
};
