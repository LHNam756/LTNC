#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    int age;
    string firstName;
    string lastName;
    int standard;

    void print()
    {
        cout << age << " "
            <<  firstName << " "
            << lastName << " "
            << standard << endl;
        return;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    student student1;
    cin >> student1.age
        >> student1.firstName
        >> student1.lastName
        >> student1.standard;
    student1.print();
    return 0;
}

