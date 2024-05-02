#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student{
private:
    int age;
    string firstName;
    string lastName;
    int standard;
public:
    void set_age(int _age){
        age = _age;
    }
    int get_age(){
        return age;
    }
    string get_first_name(){
        return firstName;
    }
    void set_first_name(string _firstName){
        firstName = _firstName;
    }
    string get_last_name(){
        return lastName;
    }
    void set_last_name(string _lastName){
        lastName = _lastName;
    }
    int get_standard(){
        return standard;
    }
    void set_standard(int _standard){
        standard = _standard;
    }
    string to_string()
    {
        string tmp = std::__cxx11::to_string(age) + ','
                    + firstName + ','
                    + lastName + ','
                    + std::__cxx11::to_string(standard);
        return tmp;
    }

};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Student st1;
    int l1, l4; string l2, l3;
    cin >> l1 >> l2 >> l3 >> l4;
    st1.set_age(l1);
    st1.set_first_name(l2);
    st1.set_last_name(l3);
    st1.set_standard(l4);

    cout << l1 << endl << l3 + ", " + l2 << endl << l4 << endl;
    cout << endl;

    string tmp = st1.to_string();
    cout << tmp << endl;

    return 0;
}
