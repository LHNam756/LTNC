#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

const int SCREEN_WIDTH = 861;
const int SCREEN_HEIGHT = 517;
const char* WINDOW_TITLE = "SDL_GuessIt";


SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Texture* gameScreen = nullptr;
SDL_Texture* startMsg = nullptr; SDL_Texture* biggerMsg = nullptr; SDL_Texture* smallerMsg = nullptr;
SDL_Texture* humanMsg = nullptr; SDL_Texture* computerMsg = nullptr; SDL_Texture* correctMsg = nullptr;
SDL_Texture* numMsg[101];


int generateRandomNum();
int guessInput();
void displayStatus(int guess, int secretNum, int guessCount);
void playAgame();

void logErrorAndExit(const char* msg, const char* error);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void loadImages();
void quitSDL();
void waitUntilKeyPressed();
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
void displayGameScreen();
void displayHumanMsg();
void displayComputerMsg();
void displayStartMsg();
void displayNumMsg(SDL_Texture* tex);
void unloadTexture();

int computeNumber(int x, int y);

SDL_Texture* loadTexture(const string& path);

int main(int argc,char** argv)
{

    initSDL(window, renderer);
    loadImages();
    SDL_RenderClear(renderer);


    srand(time(0));
    playAgame();
    unloadTexture();
    quitSDL();
    return 0;
}
int computeNumber(int x, int y)
{
    int tableX0 = 29, tableY0=285, tableX1=829, tableY1= 493;
    if (x<tableX0 || x>tableX1 || y<tableY0 || y>tableY1) return -1;
    int col = (x-tableX0)*20/(tableX1-tableX0), row=(y-tableY0)*5/(tableY1-tableY0);
    return (row*20 + col + 1);
}


int guessInput()
{
    int number;
    SDL_Event e;
    while (number<0 || number>100) {
        SDL_Delay(10);
        if ( SDL_WaitEvent(&e) == 0) continue;
        if ((e.type == SDL_QUIT) || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
            unloadTexture();
            exit(1);
        }

        if (e.type == SDL_MOUSEBUTTONDOWN) {
            number = computeNumber(e.button.x, e.button.y);
        }
    }

    return number;
}


void displayStatus(int guess, int secretNum, int guessCount)
{
    if(guess == secretNum)
    {
        displayGameScreen();
        renderTexture(correctMsg, renderer, 555, 132);
        SDL_RenderPresent(renderer);
        displayNumMsg(numMsg[guess]);
        SDL_Delay(1500);
    }
    else if (guess < secretNum)
    {
        displayGameScreen();
        renderTexture(smallerMsg, renderer, 555, 132);
        SDL_RenderPresent(renderer);
        displayNumMsg(numMsg[guess]);
        SDL_Delay(1500);
    }
    else
    {
        displayGameScreen();
        renderTexture(biggerMsg, renderer, 555, 132);
        SDL_RenderPresent(renderer);
        displayNumMsg(numMsg[guess]);
        SDL_Delay(1500);
    }

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
    displayGameScreen();
    displayStartMsg();
    SDL_Delay(1500);
    displayGameScreen();
    bool correct;
    do{
        int guess = guessInput();
        correct = (guess == secretNum);
        guessCount++;
        displayStatus(guess, secretNum, guessCount);
    }while(!correct);
}

void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());
    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    //   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr)logErrorAndExit("CreateWindow", SDL_GetError());


    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}


void quitSDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}


SDL_Texture* loadTexture(const string& path)
{
    SDL_Texture *texture = nullptr;
    SDL_Surface* texSurface = SDL_LoadBMP(path.c_str());
    if (texSurface != nullptr){
		texture = SDL_CreateTextureFromSurface(renderer, texSurface);
		SDL_FreeSurface(texSurface);
		if (texture == nullptr){
			logErrorAndExit("CreateTextureFromSurface", SDL_GetError());
		}
	}
	else {
		logErrorAndExit("LoadBMP", SDL_GetError());
	}
	return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}


void displayGameScreen()
{


    renderTexture(gameScreen, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_RenderPresent(renderer);
}

void displayStartMsg()
{
    renderTexture(startMsg, renderer, 555, 132);
    SDL_RenderPresent(renderer);
}


void displayHumanMsg()
{
    renderTexture(humanMsg, renderer, 296, 107);
    SDL_RenderPresent(renderer);
}

void displayComputerMsg()
{
    renderTexture(computerMsg, renderer, 555, 132);
    SDL_RenderPresent(renderer);
}

void displayNumMsg(SDL_Texture* tex)
{
    renderTexture(tex, renderer, 296, 107);
    SDL_RenderPresent(renderer);
}


void loadImages()
{
    gameScreen = loadTexture("images/game.bmp");
    startMsg = loadTexture("images/start.bmp");
    biggerMsg = loadTexture("images/big.bmp");
    smallerMsg = loadTexture("images/small.bmp");
    humanMsg = loadTexture("images/human.bmp");
    computerMsg = loadTexture("images/computer.bmp");
    correctMsg = loadTexture("images/same.bmp");
    for (int i = 0; i < 101; i++)
    {
        numMsg[i] = loadTexture("images/" + to_string(i) + ".bmp");
    }
}


void unloadTexture()
{
    SDL_DestroyTexture(gameScreen);
    SDL_DestroyTexture(startMsg);
    SDL_DestroyTexture(biggerMsg);
    SDL_DestroyTexture(smallerMsg);
    SDL_DestroyTexture(humanMsg);
    SDL_DestroyTexture(computerMsg);
    SDL_DestroyTexture(correctMsg);
    for(int i = 0; i < 101; i++)
    {
        SDL_DestroyTexture(numMsg[i]);
    }

}


