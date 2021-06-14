#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);

    int close = 0;
    int y;
    while (!close) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    close = 1;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(NULL, &y);
                    if (y >500)
                        printf("click bottom\n");
                    else
                        printf("click top\n");
            }
        }
    }

    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
