#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
 
int main() {
    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
 
    ll ax1 = min(x1, x2), ax2 = max(x1, x2);
    ll ay1 = min(y1, y2), ay2 = max(y1, y2);
    ll bx1 = min(x3, x4), bx2 = max(x3, x4);
    ll by1 = min(y3, y4), by2 = max(y3, y4);
 
    ll s1 = (ax2 - ax1) * (ay2 - ay1);
    ll s2 = (bx2 - bx1) * (by2 - by1);
 
    ll dx = min(ax2, bx2) - max(ax1, bx1);
    ll dy = min(ay2, by2) - max(ay1, by1);
    ll inter = 0;
    if (dx > 0 && dy > 0) {
        inter = dx * dy;
    }
    cout << s1 + s2 - inter << '\n';
    return 0;
}
