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
    sort(arr.begin(), arr.end());
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
