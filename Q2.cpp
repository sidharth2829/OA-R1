#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        int sum = 0;
        int max_val = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            max_val = max(max_val, arr[i]);
        }
        int customers = (sum + x - 1) / x;
        int ans = max(customers, max_val);
        cout << ans << endl;
    }
    return 0;
}
