#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main() {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if(SDL_Init(SDL_INIT_VIDEO) > 0) {
        cout << "SDL init failed." << endl;
        return 1;
    }
    
    SDL_Window *window = SDL_CreateWindow("ParticleFireExplosion", 
     SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
     SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        SDL_Quit();
        return 2;
    }

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
     SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if(renderer == NULL) {
        cout << "Could not create renderer: " << SDL_GetError() << endl;
        SDL_Quit();
        SDL_DestroyWindow(window);
        return 3;
    }

    if(texture == NULL) {
        cout << "Could not create texture: " << SDL_GetError() << endl;
        SDL_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        return 4;
    }

    Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

    for(int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
        buffer[i] = 0x0080FFFF;
    }
 
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool quit = false;

    SDL_Event event;

    while(!quit) {
        // Update particals
        // Draw particals
        
        // Check for messages/events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    delete[] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}