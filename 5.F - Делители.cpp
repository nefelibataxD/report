#include <iostream>
#include <vector>
 
using namespace std;
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> cnt(8, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    
    if (cnt[5] > 0 || cnt[7] > 0) {
        cout << -1 << "\n";
        return 0;
    }
    
    int x = cnt[4];
    int z = cnt[3];
    int y = cnt[2] - x;
    
    if (y < 0 || cnt[1] != cnt[2] + cnt[3] || cnt[6] != y + z) {
        cout << -1 << "\n";
        return 0;
    }
    
    for (int i = 0; i < x; i++) cout << "1 2 4\n";
    for (int i = 0; i < y; i++) cout << "1 2 6\n";
    for (int i = 0; i < z; i++) cout << "1 3 6\n";
    
    return 0;
}
