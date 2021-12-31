//                     o
//                    /|\
//                    < >
//                    / \
//               /\  /   \              /\
//              /  \/     \            /  \
//             /           \          /    \
//      /\    /             \  /\    /
//   /\/  \  /               \/  \  /
//  /      \/                     \/
// /

#include<vector>
#include <iostream>
using namespace std;

int main(){

    vector<int> a = {3,1,2,3,6,2,3,6,2,3,6,3};

    //sum of all elements
    int sum = 0;
    for(int i:a)
    {
        sum += i;
    }

    //two dimensional array of size N
    int N = sum*2;
    int **arr = new int*[N];
    for(int i=0; i<N; i++)
    {
        arr[i] = new int[N];
    }

    //initialize all elements to 0
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            arr[i][j] = 0;
        }
    }

    int i=sum-1, j=0;
    int direction = -1;
    for(int k:a)
    {
        for (int l = 0; l < k; l++)
        {
            arr[i][j] = direction;
            j++;
            i += direction;
        }
        direction *= -1;
        i += direction;
    }

    int peak_j = -1;

    //loop through the array and find the peak
    for(int i=0; i<N ; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(arr[i][j] != 0)
            {
                peak_j = j;
                arr[i-1][j] = 2;     // <
                arr[i-1][j+1] = 3;   // >
                arr[i-2][j] = -1;
                arr[i-2][j+1] = 4; //  |
                arr[i-2][j+2] = 1;
                arr[i-3][j+1] = 5; //  0
                break;
            }
        }
        if (peak_j != -1)
        {
            break;
        }
    }
    int extra_space = 0;
    //print the array
    for(int i=0; i<N; i++)
    {
        int skip = 1;
        for(int j=0; j<N; j++)
        {
            if (arr[i][j] != 0)
            {
                skip = 0;
            }
        }
        if(skip == 0)
        {
            for(int j=0; j<N; j++)
            {
                if ((extra_space == 1) && (j == (peak_j + 1)))
                {
                    cout << " ";
                }
                if (arr[i][j] == -1)
                {
                    cout << "/";
                }
                else if(arr[i][j] == 1)
                {
                    cout << "\\";
                }
                else if(arr[i][j] == 2)
                {
                    cout << "<";
                    extra_space = 1;
                }
                else if(arr[i][j] == 3)
                {
                    cout << ">";
                }
                else if(arr[i][j] == 4)
                {
                    cout << "|";
                }
                else if(arr[i][j] == 5)
                {
                    cout << "o";
                }
                else
                {
                    cout << " ";
                }
            }
            cout<<endl;
        }
    }

    // free the array
    for(int i=0; i<N; i++)
    {
        delete [] arr[i];
    }

    return 0;
}