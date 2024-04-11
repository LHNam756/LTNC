#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int H, W; cin >> W >> H;

    vector<vector<char>> world(H, vector<char>(W));
    vector<vector<bool>> route(H, vector<bool>(W));

    int youPosX, youPosY;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> world[i][j];
            if (world[i][j] == 'Y')
            {
                route[i][j] = true;
            }
            else route[i][j] = false;
        }
    }
    for (int i = 1; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            if(world[i][j] != 'R')
            {
                if (j == 0)
                {
                    if  (route[i - 1][j] == true ||
                        (world[i - 1][j] != 'R' && route[i - 1][j + 1] == true))

                        route[i][j] = true;
                }
                else if (j == W - 1)
                {
                    if  (route[i - 1][j] == true ||
                        (world[i - 1][j] != 'R' && route[i - 1][j - 1] == true))

                        route[i][j] = true;
                }
                else
                {
                    if (route[i - 1][j] == true ||
                        (world[i - 1][j] != 'R' && route[i - 1][j - 1] == true) ||
                        (world[i - 1][j] != 'R' && route[i - 1][j + 1] == true))

                        route[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < W; i++)
    {
        if (route[H - 1][i] == true)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}

