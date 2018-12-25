#include <iostream>
#include <fstream>
#include "string"
using namespace std;

int main()
{
    string line;
    string strFileName = "matrix.txt";
    fstream  myFile;
    myFile.open("example.txt", ios::in);
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            cout << line << '\n';
        }
        myFile.close();
    }
    return 0;
}