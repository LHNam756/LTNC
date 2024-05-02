#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
private:
    vector<int> scores;

public:
    void input() {
        scores.resize(5); // Resize the vector to hold 5 elements
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
        }
    }

    int calculateTotalScore() {
        int total = 0;
        for (int i = 0; i < 5; i++) {
            total += scores[i];
        }
        return total;
    }
};

int main() {
    int numStudents;
    cin >> numStudents;

    vector<Student> KrisClass(numStudents); // Create vector of students with size numStudents

    for (int i = 0; i < numStudents; i++) {
        KrisClass[i].input();
    }

    int KrisScore = KrisClass[0].calculateTotalScore();
    int cnt = 0;
    for (int i = 1; i < numStudents; i++) {
        if (KrisClass[i].calculateTotalScore() > KrisScore) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}

