#include <iostream>
#include <vector>

using namespace std;

void makeString(const vector<char>& characters, int stringLen, string currentString){
    if (stringLen == 0){
        cout << currentString << endl;
        return;
    }

    for(auto c : characters){
        makeString(characters, stringLen - 1, currentString + c);
    }
}

int main()
{
    vector<char> characters = {'a', 'b', 'c', 'd'};
    int stringLen = 3;
    makeString(characters, stringLen, "");
    return 0;
}
