#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<ll> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());
 
    bool is_good = true;
    for (int i = 1; i < n; i++) {
        if (cards[i] - cards[i - 1] != 1) {
            is_good = false;
            break;
        }
    }
    if (is_good) {
        cout << "Deck looks good" << '\n';
    }
    else {
        cout << "Scammed" << '\n';
    }
    return 0;
}
