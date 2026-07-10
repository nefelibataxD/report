#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> mins, maxs;
    int gMinPos = 0, gMaxPos = 0;  
    for (int i = 0; i < n; ++i) {
        bool hasL = (i > 0);
        bool hasR = (i < n - 1);
        bool isMin = (!hasL || a[i - 1] > a[i]) && (!hasR || a[i + 1] > a[i]);
        bool isMax = (!hasL || a[i - 1] < a[i]) && (!hasR || a[i + 1] < a[i]);
        if (isMin) mins.push_back(i + 1);   
        if (isMax) maxs.push_back(i + 1);
        if (a[i] < a[gMinPos]) gMinPos = i;
        if (a[i] > a[gMaxPos]) gMaxPos = i;
    }
    cout << mins.size();
    for (int p : mins) cout << ' ' << p;
    cout << '\n';
    cout << maxs.size();
    for (int p : maxs) cout << ' ' << p;
    cout << '\n';
    cout << (gMinPos + 1) << ' ' << (gMaxPos + 1) << '\n';
    return 0;
