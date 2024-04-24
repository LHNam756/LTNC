#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0, tmp = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    int x; cin >> x;
    int a, b; cin >> a >> b;
    arr.erase(arr.begin()+x-1);
    arr.erase(arr.begin()+a - 1, arr.begin()+b-1);
    cout << arr.size() << endl;
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

