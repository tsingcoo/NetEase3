#include <iostream>
#include <cstring>

using namespace std;

const int M = 55;
int w[M];
int dp[M * 4096];

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
        w[i] /= 1024;
        sum += w[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
        for (int j = sum / 2; j >= w[i]; --j)
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
    printf("%d\n", 1024 * (sum - dp[sum / 2]));
    return 0;
}