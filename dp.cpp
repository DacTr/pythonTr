
// decompose les nombres allant de 1 à 2000 en somme minimale de cubes. 

#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2000];
int temp;
map<int, pair<int,int> > parent;
int index1, index2 = 0;
int counter, query;


int main()
{
    dp[0] = 1;
    for (int i = 1; i < 2000; i++)
    {
        dp[i] = i;
    }

    for (int i = 2; i < 2000; i++)
    {
        index1, index2 = 0;
        for (int j = 1; j < 2000; j++)
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
    cout << parent[query].second << "^3";
    counter = parent[query].first;
    while (counter>0)
    {
        cout << " + " << parent[counter].second << "^3";
        counter = parent[counter].first; 
    }
    return 0;
}
