#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int INT;
    long LONG;
    char CHAR;
    double D1, D2;
    cin >> INT >> LONG >> CHAR >> D1 >> D2;
    cout << INT << endl << LONG << endl
        << CHAR << endl << setprecision(3) << fixed << D1 << endl
        << setprecision(9) << fixed << D2 << endl;
    return 0;
}

