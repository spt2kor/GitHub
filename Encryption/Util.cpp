# include "Util.h"
#include <iomanip>  

void CheckCharTypes(const string &fileName)
{
	cout << endl << __FUNCTION__ << "() - started : input file to process : " << fileName << endl;
	ifstream file(fileName);
	if (file.is_open())
	{
		string line;
		//line = "abc";
		//cout << "\n size = " << line.size() << ", len = " << line.length() << endl;
		//return;
		int charCount[256] = { 0 };
		int lineCount = 0;
		int cCount = 0;
		while (getline(file, line))
		{
			cout << line << endl;
			++lineCount;
			for (int i = 0; i < line.size(); ++i)
			{
				++cCount;
				++charCount[line[i]];
			}
		}

		cout << "\n ***************************************  " << endl;
		cout << "\n lineCount = " << lineCount << ",\t cCount = " << cCount << endl;

		int VChar = 0;
		for (int i = 0; i < 256; ++i)
		{
			cout << "\t" << std::dec << i << "\t[  " << char(i) << "  ]\t=\t" << charCount[i] << endl;
			cout<< "0x"<< std::setfill('0') << std::setw(2)<< std::hex << i;

			if (charCount[i] > 0)
				++VChar;
		}
		cout << "\n valid chars : " << VChar << endl;
		cout << endl << __FUNCTION__ << "() - Ended " << endl;
	}
	else
	{
		cerr << "\n ERROR : unable to open file : " << fileName << endl;
	}
}

