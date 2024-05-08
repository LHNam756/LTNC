#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

enum wordType {hoz, vez};

struct Task {
    int row;
    int col;
    wordType type;
};

vector<Task> getListTask(vector<string> crossword) {
    Task tmpTask;
    vector<Task> listTask;
    int vtSize = crossword.size();
    int strSize = crossword[0].size();
    for (int i = 0; i < vtSize; i++) {
        for (int j = 0; j < strSize; j++) {
            if(crossword[i][j] == '-') {
                tmpTask.row = i;
                tmpTask.col = j;
                if(i + 1 < vtSize && crossword[i+1][j] == '-') {
                    tmpTask.type = vez;
                    listTask.push_back(tmpTask);
                }
                if(j + 1 < strSize && crossword[i][j+1] == '-') {
                    tmpTask.type = hoz;
                    listTask.push_back(tmpTask);
                }
            }
        }
    }
    return listTask;
}

vector<string> extractWords(string words) {
    vector<string> wordList;
    stringstream ss(words);
    char temp;
    string str;

    while (ss >> temp) {
        str += temp;
        if (ss.peek() == ';') {
            wordList.push_back(str);
            str = "";
            ss.ignore();
        }
    }
    wordList.push_back(str);
    return wordList;
}

bool isValid(vector<string>& crossword, Task task, string word) {
    if (task.type == vez) {
        for (int i = 0; i < word.length(); i++) {
            if (crossword[task.row + i][task.col] != '-' && crossword[task.row + i][task.col] != word[i]) {
                return false;
            }
        }
    } else if (task.type == hoz) {
        for (int i = 0; i < word.length(); i++) {
            if (crossword[task.row][task.col + i] != '-' && crossword[task.row][task.col + i] != word[i]) {
                return false;
            }
        }
    }
    return true;
}

void placeWord(vector<string>& crossword, Task task, string word) {
    if (task.type == vez) {
        for (int i = 0; i < word.length(); i++) {
            crossword[task.row + i][task.col] = word[i];
        }
    } else if (task.type == hoz) {
        for (int i = 0; i < word.length(); i++) {
            crossword[task.row][task.col + i] = word[i];
        }
    }
}

void removeWord(vector<string>& crossword, Task task, string word) {
    if (task.type == vez) {
        for (int i = 0; i < word.length(); i++) {
            crossword[task.row + i][task.col] = '-';
        }
    } else if (task.type == hoz) {
        for (int i = 0; i < word.length(); i++) {
            crossword[task.row][task.col + i] = '-';
        }
    }
}

bool solve(vector<string>& crossword, vector<Task>& listTask, vector<string>& words, int taskIndex) {
    if (taskIndex == listTask.size()) {
        for (const string& row : crossword) {
            if (row.find('-') != string::npos) {
                return false;
            }
        }
        return true;
    }

    Task currentTask = listTask[taskIndex];
    for (string word : words) {
        if (isValid(crossword, currentTask, word)) {
            placeWord(crossword, currentTask, word);
            if (solve(crossword, listTask, words, taskIndex + 1)) {
                return true;
            }
            else{
                removeWord(crossword, currentTask, word);
            }
        }
    }
    return false;
}
vector<string> solvePuzzle(vector<string>& crossword, vector<string>& words) {
    vector<Task> listTask = getListTask(crossword);
    if (solve(crossword, listTask, words, 0)) {
        return crossword;
    }
    return vector<string>();
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> wordList = extractWords(words);
    return solvePuzzle(crossword, wordList);
}

int main() {
    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    if (result.empty()) {
        cout << "Failed to solve crossword puzzle." << endl;
    } else {
        for (const string& row : result) {
            cout << row << endl;
        }
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

