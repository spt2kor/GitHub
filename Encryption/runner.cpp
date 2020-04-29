# include "Util.h"
# include "Encryption.h"
# include "EncryptionXOR.h"

void EncryptByADD(const string & inputFile , const string& outputFile)
{
	//encrypt the file
	EncryptFile(inputFile, outputFile, Encrypt_via_addition);

	//decrypt the file
	string decryptFile = "dec_lpopt_input.dat";
	EncryptFile(outputFile, decryptFile, Decrypt_via_addition);
}

void EncryptByXORMap(const string & inputFile, const string& outputFile)
{
	//encrypt the file
	EncryptionXOR encrytionHelper;
	encrytionHelper.EncryptFileXOR(inputFile, outputFile);

	//decrypt the file
	string decryptFile = "dec_lpopt_input.dat";
	encrytionHelper.EncryptFileXOR(outputFile, decryptFile);
}

void main(int argc , char* argv[])
{
	cout << "\n Program started" << endl;

	if (argc == 3 && argv[1])
	{
		cout << "\n input file to process : " << argv[1] << endl;
		string inputFile(argv[1]);
		string outputFile(argv[2]);

		//test File Type and chars
		//CheckCharTypes(inputFile);
		
		//Encryption by ADD
		//EncryptByADD(inputFile , outputFile);

		//Encryption by MAP XOR
		EncryptByXORMap(inputFile, outputFile);
	}
	else {
		cerr << "Error : need to pass input file & output file path: "<<argc << endl;
	}
	cout << "\n Program ended" << endl;
}