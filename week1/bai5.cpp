#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tmp; int max(-99999);
    for (int i = 0; i < 4; i++)
    {
        cin >> tmp;
        if (tmp > max) max = tmp;
    }
    cout << max << endl;
    return 0;
}

