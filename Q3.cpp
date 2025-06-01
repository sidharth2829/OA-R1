#include <iostream>
#include <vector>
#include <string>
using namespace std;

int check(const string &str1, const string &str2, int r1, int c1, int r2, int c2, int r3, int c3) {
    int count = 0;
    if ((r1 == 0 ? str1[c1] : str2[c1]) == 'A') count++;
    if ((r2 == 0 ? str1[c2] : str2[c2]) == 'A') count++;
    if ((r3 == 0 ? str1[c3] : str2[c3]) == 'A') count++;
    return count >= 2;
}

int solve(int i, int j, int n, const string &str1, const string &str2, vector<vector<int>> &dp) {
    if (i == n && j == n) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int option1 = 0, option2 = 0, option3 = 0;

    if (i + 2 < n && j + 2 < n) {
        int score1 = check(str1, str2, 0, i, 0, i + 1, 0, i + 2);
        int score2 = check(str1, str2, 1, j, 1, j + 1, 1, j + 2);
        option1 = score1 + score2 + solve(i + 3, j + 3, n, str1, str2, dp);
    }

    if (i + 1 < n && j < n) {
        option2 = check(str1, str2, 0, i, 1, j, 0, i + 1) + solve(i + 2, j + 1, n, str1, str2, dp);
    }

    if (i < n && j + 1 < n) {
        option3 = check(str1, str2, 0, i, 1, j, 1, j + 1) + solve(i + 1, j + 2, n, str1, str2, dp);
    }

    return dp[i][j] = max(option1, max(option2, option3));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string str1, str2;
        cin >> str1 >> str2;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        cout << solve(0, 0, n, str1, str2, dp) << "\n";
    }

    return 0;
}
