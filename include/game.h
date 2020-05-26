# include "camera.h"
# include "../libs/SDL2_gfx/SDL2_gfxPrimitives.h"
# include <SDL2/SDL.h>
# include <iostream>


class Game
{
    public:

    Game();

    void init(char* title, int xpos, int ypos, int wid, int hei, bool fullscreen);

    void handleEvents();
    void update();
    void draw();

    void finishExit();
    bool isRunning();


    private:

    int temp_rs[10];
    int temp_gs[10];

    bool running;
    int center_x;
    int center_y;

    Camera camera;
    World world;

    SDL_Window *window;
    SDL_Renderer *renderer;
    
};