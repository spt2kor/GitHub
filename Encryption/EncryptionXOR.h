#pragma once
#include <iostream>
#include <string>
using namespace std;

class EncryptionXOR
{
public:
	EncryptionXOR();
	size_t EncryptXOR(string& ioline);
	~EncryptionXOR();
	void EncryptFileXOR(const string& inputFile, const string& outputFile);

};

