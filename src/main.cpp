# include "./../include/game.h"

int main(int argc, char *argv[])
{
    // initalize the game object
    Game game;

    // start the game with the init call
    game.init("t", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 600, false);

    // game loop
    while (game.isRunning())
    {
        SDL_Delay(20);

        game.handleEvents();
        game.update();
        game.draw();
    }

    game.finishExit();

    return 0;
}