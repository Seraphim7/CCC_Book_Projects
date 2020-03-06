#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	string myString;

	fin.open("Inputfile.txt");
	fout.open("OutputFile.txt");

	if (fin.is_open())
	{
		getline(fin, myString);

		fout << myString << endl;

		fin.close();
		fout.close();
	}
	else
	{
		cout << "error" << endl;
	}
}