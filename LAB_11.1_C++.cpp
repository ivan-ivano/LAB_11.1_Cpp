#include <iostream>
#include <fstream>
using namespace std;

void CreateBIN(char* fname)
{
    ofstream fout(fname, ios::binary);
    char ch;
    float num;
    do
    {
        cin.get();
        cin.sync();
        cout << "enter number: "; cin >> num;
        fout.write((char*)&num, sizeof(num));
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'n');
    cout << endl;
}

void PrintBIN(char* fname)
{
    ifstream fin(fname, ios::binary);
    float num;
    while (fin.read((char*)&num, sizeof(num)))
    {
        cout << num << endl;
    }
    cout << endl;
}

void ProcessBIN1(char* fname, char* gname) // копіюємо в 2 файл всі числа з файлу 1, які не можуть бути значеннями функції sin x
{
    ifstream f(fname, ios::binary);
    ofstream g(gname, ios::binary);
    float num;
    while (f.read((char*)&num, sizeof(num)))
    {
        if (num >= 1 || num <= -1)
            g.write((char*)&num, sizeof(num));
    }
}

int main()
{
    char fname[100];
    cout << "enter file name 1: "; cin >> fname;
    CreateBIN(fname);
    PrintBIN(fname);

    char gname[100];
    cout << "enter file name 2: "; cin >> gname;
    ProcessBIN1(fname, gname);
    cout << "file 2: " << endl;
    PrintBIN(gname);
    cout << "file 1: " << endl;
    PrintBIN(fname);

    return 0;
}
