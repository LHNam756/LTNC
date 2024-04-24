#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;
    map<string, int> mp;
    for (int i = 0; i < Q; i++) {
        int type, y;
        string x;
        cin >> type;
        if (type == 1) {
            cin >> x >> y;
            if(mp.find(x) != mp.end()) {
                mp[x] += y;
            } else {
                mp.insert(make_pair(x, y));
            }
        }
        else if (type == 2) {
            cin >> x;
            mp.erase(x);
        }
        else if (type == 3) {
            cin >> x;
            map<string, int>::iterator itr = mp.find(x);
            if (itr != mp.end())
                cout << mp[x] << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}

