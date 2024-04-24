#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

void function(int *a, int *b)
{
    (*a) = (*a) + (*b);
    (*b) = abs((2*(*b) - (*a)));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b;
    cin >> a >> b;
    function(&a, &b);
    printf("%d\n%d", a, b);
    return 0;
}

