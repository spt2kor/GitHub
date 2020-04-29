#pragma once
#include <string>
#include <sstream>
#include <tuple>
#include "item.h"
using namespace std;
double PrecisionCorrection(double no);

double RoundUp(double no);

Item_Type GetItemType(string itemName);

string Trim(string str);
tuple<string, double> GetItemDetails(string itemName);