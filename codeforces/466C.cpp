#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    vector<int> v(n);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    if (sum % 3 != 0)
    {
        cout << 0;
        return 0;
    }

    

    cout << count;

    return 0;
}