#include <iostream>
#include <string>
using namespace std;

int main() {
    // Complete the program
    string  s1, s2;
    cin >> s1 >> s2;
    cout << s1.size() << " " <<s2.size() << endl;
    cout << s1 + s2 << endl;
    {
        cout << s2[0];
        for (int i = 1, n = s1.size(); i < n; i++)
        {
            cout << s1[i];
        }
        cout <<  " ";
    }
    {
        cout << s1[0];
        for (int i = 1, n = s2.size(); i < n; i++)
        {
            cout << s2[i];
        }
        cout << endl;
    }



    return 0;
}

