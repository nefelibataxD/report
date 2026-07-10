#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (max_heap.empty() || x <= max_heap.top()) {
            max_heap.push(x);
        } else {
            min_heap.push(x);
        }
        
        int target_size = (i + 2) / 2;
        
        while ((int)max_heap.size() < target_size) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
        while ((int)max_heap.size() > target_size) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        
        cout << max_heap.top() << " ";
    }
    
    cout << "\n";
    
    return 0;
}
