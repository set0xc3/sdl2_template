#include "base_def.h"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

struct app_context
{
    b8 quit;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

int 
main(int argc, char **argv)
{
    local_variable app_context app;
    ZERO_STRUCT(&app);
    
    SDL_Init(SDL_INIT_VIDEO);
    app.window = SDL_CreateWindow("SDL2 Starter Project",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                          640, 480, 
                                          0);
    app.renderer = SDL_CreateRenderer(app.window, -1, 0);
    
    while (!app.quit)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        
        switch (event.type)
        {
            case SDL_QUIT:
            {
                app.quit = true;
                break;
            }
            
            
            case SDL_MOUSEBUTTONDOWN:
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    printf("Mouse\n");
                }
                break;
            }
        }
        
        SDL_SetRenderDrawColor(app.renderer, 242, 242, 242, 255);
        SDL_RenderClear(app.renderer);
        
        SDL_RenderPresent(app.renderer);
        
        SDL_Delay(1);
    }
    
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
    
    return 0;
}