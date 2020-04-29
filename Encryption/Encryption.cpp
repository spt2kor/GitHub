#include "Encryption.h"



unsigned char Encrypt_via_addition(unsigned char data)
{
	return data + 127;
}
unsigned char Decrypt_via_addition(unsigned char data)
{
	return data - 127;
}


//===================================================
void EncryptFile(const string& inputFile, const string& outputFile, conversion_func cfunc)
{
	cout << endl << __FUNCTION__ << "() - started : input file : " << inputFile<<"\t, output file : "<<outputFile << endl;
	
	ifstream ifile(inputFile);
	ofstream ofile(outputFile);
	if (ifile.is_open() )
	{
		string iline;
		string oline;
		int lineCount = 0;
		int cCount = 0;
		size_t isize = 0;
		while (getline(ifile, iline))
		{
			oline.clear();
			//cout << iline << endl;
			++lineCount;

			isize = iline.size();
			oline.resize(isize + 1);
			for (int i = 0; i < isize; ++i)
			{
				++cCount;
				oline[i] = cfunc(iline[i]);
				//oline[i] = iline[i] + 127;
			}
			oline[isize] = '\n';
			ofile.write(oline.c_str(), isize+1);
		}
		ofile.close();

		cout << "\n ***************************************  " << endl;
		cout << "\n lineCount = " << lineCount << ",\t charCount = " << cCount << endl;
	}
	else
	{
		cerr << "\n ERROR : unable to open file : " << inputFile << endl;
	}

	cout << endl << __FUNCTION__ << "() - ended" << endl;
}


/*
Encryption::Encryption()
{
}


Encryption::~Encryption()
{
}
*/