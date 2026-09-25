#include<iostream>
#include<vector>

using namespace std;

string addition(string x, string y);

int main()
{
    string a;
    string aOg;
    string b;
    string name;
    string sum = "";

    char operation;
    char presentation;

    cout << "----------------Welcome----------------" << endl;
    while(true)
    {
        cout << "-Operations available:" << endl;
        cout << "   -A: Addition." << endl;
        cout << "   -C: Conversion." << endl;

        cout << "-Enter the operation you want to perform: ";
        cin >> operation;

        if(operation == 'A' || operation == 'a')
        {
            cout << "-Enter the first binary number: ";
            cin >> a;

            aOg = a;

            cout << "-Enter the second binary number: ";
            cin >> b;
            
            cout << "-" << aOg << " + " << b << " = " << addition(a,b) << endl;
        }
        else if(operation == 'C' || operation == 'c')
        {
            cout << "-Please enter the binary number you want to convert: ";
            cin >> a;

            aOg = a;

            if(a.at(0) != '0')
            {
                for(int i = 1; i < a.length(); i++)
                {
                    if(a.at(i) == '0') a.at(i) = '1';
                    else if(a.at(i) == '1') a.at(i) = '0';
                }
            }

            cout << "-Presentations available:" << endl;
            cout << "   -1: Signed-1's compliment." << endl;
            cout << "   -2: Signed-2's compliment." << endl;

            cout << "-Enter the presentation you want to convert to: ";

            cin >> presentation;

            if(presentation == '1') cout << "-1's C(" << aOg << ") = " << a << endl;
            else if(presentation == '2') cout << "-2's C(" << aOg << ") = " << addition(a, "1") << endl;
        }

        cout << "---------------------------------------" << endl;
    }
}

string addition(string x, string y)
{
    string sum = "";

    if(x.length() > y.length()) y.insert(0, x.length() - y.length(), '0');
    else if(x.length() < y.length()) x.insert(0, y.length() - x.length(), '0');

    for(int i = y.length() - 1; i > 0; i--)
    {
        if((y.at(i) - '0') + (x.at(i) - '0') < 2) sum.insert(0, to_string((y.at(i) - '0') + (x.at(i) - '0')));
        else
        {
            sum.insert(0, to_string((y.at(i) - '0') + (x.at(i) - '0') - 2));
            x.at(i - 1) = char((x.at(i - 1) - '0' + 1) + '0');
        }
    }

    if((y.at(0) - '0') + (x.at(0) - '0') < 2) sum.insert(0, to_string((y.at(0) - '0') + (x.at(0) - '0')));
    else if ((y.at(0) - '0') + (x.at(0) - '0') == 2) sum.insert(0, "10");
    else sum.insert(0, "11");

    return sum;
}
