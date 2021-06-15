#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, 0);
    SDL_Surface* surface = IMG_Load("src/1.jpg");
    if(surface == NULL)
        printf("BANANE\n");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_RenderClear(renderer);

    SDL_Rect rect;
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);

    rect.x = (1000 - rect.w) / 2;
    rect.y = (1000 - rect.h) / 2;

    SDL_RenderCopy(renderer, tex, NULL, &rect);

    // SDL_SetRenderDrawColor(renderer, 255,0,0, SDL_ALPHA_OPAQUE);
    // SDL_RenderDrawLine(renderer, 0,500, 1000,500);
    // SDL_RenderDrawLine(renderer, 500,0, 500,1000);
    SDL_RenderPresent(renderer);

    int close = 0;
    int x, y;
    while (!close) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    close = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            close = 1;
                            break;
                        default :
                            break;
                    }
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&x, &y);
                    if (y >500)
                        if (x > 500)
                            printf("click bottom right\n");
                        else
                            printf("click bottom left\n");
                    else
                        if (x > 500)
                            printf("click top right\n");
                        else
                            printf("click top left\n");
                default:
                    break;
            }
        }
    }

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
