// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,r;
        cin>>n>>r;
        int ans = 0;
        vector<int> arr(n);
        for(int i = 0;i < n;i++)
        {
            cin>>arr[i];
        }
        int odd_rem = 0;
        int rows = r;
        for(int i = 0;i < n;i++)
        {
            if(arr[i] && !(arr[i]%2))
            {
                ans += arr[i];
                rows -= arr[i]/2;
            }
            else
            {
                ans += arr[i]-1;
                odd_rem++;
                rows -= arr[i]/2;
            }
        }
        if(rows*2 != odd_rem)
        {
            if(rows <= odd_rem)
            ans += (rows - (odd_rem%rows));
            else
            {
                ans += odd_rem%rows;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
