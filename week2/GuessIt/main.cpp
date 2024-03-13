#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

int generateRandomNum();
int guessInput();
void displayStatus(int guess, int secretNum, int guessCount);
void playAgame();
bool isOver();

int main(int argc,char** argv)
{
    srand(time(0));
    do
    {
        playAgame();
    }while(isOver());
    return 0;
}

int guessInput()
{
    int input;
    cout << "Guess a number (1..100) !\n";
    while (!(cin >> input))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input; please re-enter.\n";
    }
    return input;
}


void displayStatus(int guess, int secretNum, int guessCount)
{
    if(guess == secretNum)
        cout << "Correct!\n" << (100 - guessCount) << endl;
    else if (guess < secretNum)
        cout << "Too small!\n";
    else
        cout << "Too big!\n";
}

int generateRandomNum()
{
   int random = rand() % 100;
   return random + 1;
}

void playAgame()
{
    int secretNum = generateRandomNum();
    int guessCount = 0;
    bool correct;
    do{
        int guess = guessInput();
        correct = (guess == secretNum);
        guessCount++;
        displayStatus(guess, secretNum, guessCount);
    }while(!correct);
}

bool isOver()
{
    char isPlayMore;
    cout << "Do you want to play again? Input 'y' for continue or 'n' for over" << endl;
    cin >>  isPlayMore;
    if (isPlayMore == 'y') return true;
    else if (isPlayMore == 'n') return false;
}
