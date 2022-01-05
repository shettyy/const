#include <iostream>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
#endif
    // read a number from input
    int n;
    cin >> n;

    while (n--)
    {
        string i;
        cin >> i;
        // get length of string
        int len = i.length();
        // get the last character of string
        char last = i[len - 1];
        // get the first character of string
        char first = i[0];

        if (len > 10)
        {
            cout << first << len - 2 << last << endl;
        }
        else
        {
            cout << i << endl;
        }
    }

    return 0;
}