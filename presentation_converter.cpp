#include<iostream>
#include<vector>

using namespace std;

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
            sum = "";

            cout << "-Enter the first binary number: ";
            cin >> a;

            aOg = a;

            cout << "-Enter the second binary number: ";
            cin >> b;
        
            if(a.length() > b.length()) b.insert(0, a.length() - b.length(), '0');
            else if(a.length() < b.length()) a.insert(0, b.length() - a.length(), '0');

            for(int i = b.length() - 1; i > 0; i--)
            {
                if((b.at(i) - '0') + (a.at(i) - '0') < 2) sum.insert(0, to_string((b.at(i) - '0') + (a.at(i) - '0')));
                else
                {
                    sum.insert(0, to_string((b.at(i) - '0') + (a.at(i) - '0') - 2));
                    a.at(i - 1) = char((a.at(i - 1) - '0' + 1) + '0');
                }
            }

            if((b.at(0) - '0') + (a.at(0) - '0') < 2) sum.insert(0, to_string((b.at(0) - '0') + (a.at(0) - '0')));
            else if ((b.at(0) - '0') + (a.at(0) - '0') == 2) sum.insert(0, "10");
            else sum.insert(0, "11");

            cout << "-" << aOg << " + " << b << " = " << sum << endl;
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
            else if(presentation == '2')
            {
                sum = "";
                b = "1";
            
                b.insert(0, a.length() - b.length(), '0');

                for(int i = b.length() - 1; i > 0; i--)
                {
                    if((b.at(i) - '0') + (a.at(i) - '0') < 2) sum.insert(0, to_string((b.at(i) - '0') + (a.at(i) - '0')));
                    else
                    {
                        sum.insert(0, to_string((b.at(i) - '0') + (a.at(i) - '0') - 2));
                        a.at(i - 1) = char((a.at(i - 1) - '0' + 1) + '0');
                    }
                }

                if((b.at(0) - '0') + (a.at(0) - '0') < 2) sum.insert(0, to_string((b.at(0) - '0') + (a.at(0) - '0')));
                else if ((b.at(0) - '0') + (a.at(0) - '0') == 2) sum.insert(0, "10");
                else sum.insert(0, "11");

                cout << "-2's C(" << aOg << ") = " << sum << endl;
            }
        }

        cout << "---------------------------------------" << endl;
    }
}