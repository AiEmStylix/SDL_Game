#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;
const int WIDTH = 800, HEIGHT = 600;
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = NULL;


    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
        if (window == NULL)
        {
            std::cout << "Could not create window: " << SDL_GetError() << std::endl;
            return 1;
        }
    }

    SDL_Event windowEvent;
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}