// https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

bool is_palindrome(const string &sub)
{
    int len = sub.size();
    bool no = true;
    if (len == 1)
        return false;
    //cout<<m[sub]<<endl;
    if (m[sub] == 1)
    {
        cout<<"yay"<<endl;
    }

    for (int i = 0; i < len / 2; i++)
    {
        if (sub[i] != sub[len - i - 1])
        {
            no = false;
            break;
        }
    }
    m[sub] = no?1:-1;
    return no;
}

bool check_string(const string &substr, string &sol)
{
    int len = substr.size();
    int l2 = sol.size();
    for (auto i = 0; i < len; i++)
    {
        if (l2 >= (len - i))
            return false;
        string sub2 = substr.substr(0, len - i);
        cout << "sub2: " << sub2 << endl;

        if (is_palindrome(sub2))
        {
            //cout << sub2 << endl;
            if (sol.size() < len)
            {
                sol = sub2;
            }

            return true;
        }
    }
    return false;
}

string longestPalindrome(string s)
{
    string sol;
    sol = s.substr(0, 1);
    for (auto i = 0; i < s.size(); i++)
    {
        // get substring from i to the end
        string sub = s.substr(i, s.size() - i);
        check_string(sub, sol);
    }
    cout << endl
         << sol << endl;
    return sol;
}

int main()
{
    string s = "aaaaaaaaaaaaaba";
    longestPalindrome(s);
    return 0;
}