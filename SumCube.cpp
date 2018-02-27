#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#define M_SIZE 100000

using namespace std;

int dp[M_SIZE];
int temp;
map<int, pair<int,int> > parent;
int index1, index2 = 0;
int counter, query;

void display(int query, map<int, pair<int, int> > parent)
{
    cout << parent[query].second << "^3";
    counter = parent[query].first;
    while (counter>0)
    {
        cout << " + " << parent[counter].second << "^3";
        counter = parent[counter].first; 
    }
}


int main()
{
    dp[0] = 1;
    parent[1].first = 0;
    parent[1].second = 1;
    for (int i = 1; i < M_SIZE; i++)
    {
        dp[i] = i;
    }

    for (int i = 2; i < M_SIZE; i++)
    {
        index1, index2 = 0;
        for (int j = 1; j < M_SIZE; j++)
        {
            temp = j*j*j;
            if( temp > i)
                break;
            if (dp[i] >= dp[i-temp] + 1)
            {
                dp[i] = dp[i-temp] + 1;
                index1 = i-temp;
                index2 = j;
            }
        }
        parent[i].first = index1;
        parent[i].second = index2;
        //cout << "number : " << i << " --> " << dp[i] << endl;
    }


    cin >> query;
    if (cin.good())
        display(query, parent);
    else
        cout << "Enter number" << endl;
    return 0;
}