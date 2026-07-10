#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<long long> dt(n);
    for (int i = 0; i < n; ++i) cin >> dt[i];
    sort(dt.begin(), dt.end());
    long long count = 0;
    for (int k = 2; k < n; ++k) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (dt[i] + dt[j] > dt[k]) {
                count += (j - i);
                j--;
            }
            else {
                i++;
            }
        }
    }
    cout << count << '\n';
    return 0;
}
