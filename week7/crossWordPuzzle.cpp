#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

enum wordType { HORIZONTAL, VERTICAL };

struct Task {
    int row;
    int col;
    wordType type;
};

vector<Task> getListTask(vector<string> crossword) {
    Task tmpTask;
    vector<Task> listTask;
    int rows = crossword.size();
    int cols = crossword[0].size();


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            if (crossword[i][j] == '-' && crossword[i][j + 1] == '-' && (j == 0 || crossword[i][j - 1] == '+')) {
                tmpTask.col = j;
                tmpTask.row = i;
                tmpTask.type = HORIZONTAL;
                listTask.push_back(tmpTask);
            }
        }
    }


    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows - 1; i++) {
            if (crossword[i][j] == '-' && crossword[i + 1][j] == '-' && (i == 0 || crossword[i - 1][j] == '+')) {
                tmpTask.col = j;
                tmpTask.row = i;
                tmpTask.type = VERTICAL;
                listTask.push_back(tmpTask);
            }
        }
    }

    return listTask;
}

vector<string> extractWords(string words) {
    vector<string> wordList;
    stringstream ss(words);
    string word;

    while (getline(ss, word, ';')) {
        wordList.push_back(word);
    }
    return wordList;
}

bool isValid(vector<string>& crossword, Task task, string word) {
    int len = word.length();
    if (task.type == VERTICAL) {
        if (task.row + len > crossword.size())
            return false;
        for (int i = 0; i < len; i++) {
            if (crossword[task.row + i][task.col] != '-' && crossword[task.row + i][task.col] != word[i]) {
                return false;
            }
        }
    } else if (task.type == HORIZONTAL) {
        if (task.col + len > crossword[0].size())
            return false;
        for (int i = 0; i < len; i++) {
            if (crossword[task.row][task.col + i] != '-' && crossword[task.row][task.col + i] != word[i]) {
                return false;
            }
        }
    }
    return true;
}

void placeWord(vector<string>& crossword, Task task, string word) {
    if (task.type == VERTICAL) {
        for (int i = 0; i < word.length(); i++) {
            crossword[task.row + i][task.col] = word[i];
        }
    } else if (task.type == HORIZONTAL) {
        for (int i = 0; i < word.length(); i++) {
            crossword[task.row][task.col + i] = word[i];
        }
    }
}

void removeWord(vector<string>& crossword, Task task, string word) {
    if (task.type == VERTICAL) {
        for (int i = 0; i < word.length(); i++) {
            crossword[task.row + i][task.col] = '-';
        }
    } else if (task.type == HORIZONTAL) {
        for (int i = 0; i < word.length(); i++) {
            crossword[task.row][task.col + i] = '-';
        }
    }
}

bool solve(vector<string>& crossword, vector<Task>& listTask, vector<string>& words, vector<bool>& used, int taskIndex) {
    if (taskIndex == listTask.size()) {
        return true;
    }

    Task currentTask = listTask[taskIndex];

    for (int i = 0; i < words.size(); i++) {
        if (!used[i] && isValid(crossword, currentTask, words[i])) {
            placeWord(crossword, currentTask, words[i]);
            used[i] = true;
            if (solve(crossword, listTask, words, used, taskIndex + 1)) {
                return true;
            }
            removeWord(crossword, currentTask, words[i]);
            used[i] = false;
        }
    }
    return false;
}

vector<string> solvePuzzle(vector<string>& crossword, vector<string>& words) {
    vector<Task> listTask = getListTask(crossword);
    vector<bool> used(words.size(), false);
    if (solve(crossword, listTask, words, used, 0)) {
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
