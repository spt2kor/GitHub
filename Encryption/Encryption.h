#pragma once
#include "Util.h"

typedef unsigned char(*conversion_func) (unsigned char) ;


unsigned char Encrypt_via_addition(unsigned char data);
unsigned char Decrypt_via_addition(unsigned char data);

void EncryptFile(const string& inputFile, const string& outputFile, conversion_func cfunc);

/*
class Encryption
{
public:
	Encryption();
	~Encryption();
};
*/
