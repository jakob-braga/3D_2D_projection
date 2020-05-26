# include "./../include/game.h"

Game::Game()
{
    Camera camera;
    World world;
}

void Game::init(char *title, int xpos, int ypos, int wid, int hei, bool fullscreen)
{
    // init sdl if fail say not running
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL initialized"<< std::endl;

        // get fullscreen flags
        int flags = 0;
        if (fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        // create the window
        window = SDL_CreateWindow(title, xpos, ypos, wid, hei, flags);
        if (window)
        {
            std::cout << "window created" << std::endl;
        }

        // create the renderer
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            std::cout << "renderer created" << std::endl;
        }

        // set the state of the init
        running = true;
    }
    else {
        running = false;
    }

    center_x = wid / 2;
    center_y = hei / 2;
    
    camera.init();

    SDL_ShowCursor(false);

    int temp_gs[] = {0, 50, 100, 150, 200, 250, 75};
    int temp_rs[] = {0, 50, 100, 150, 200, 250, 75};

}

void Game::handleEvents()
{
    // update mouse/view
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x != center_x)
    {   
        float rotate_angle = (float(x) - float(center_x)) / 1500.f;
        camera.rotate_h(rotate_angle);
    }
    if (y != center_y)
    {
        float rotate_angle = (float(y) - float(center_y)) / 1500.f;
        camera.rotate_v(rotate_angle);
    }
    SDL_WarpMouseInWindow(window, center_x, center_y);


    // event handlers
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            running = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {

                case SDLK_ESCAPE:
                    running = false;
                    break;
                
                default:
                    break;
            }

        default:
            break;
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_W])
    {
        camera.move_longitudinally(1);
    }
    else if (state[SDL_SCANCODE_S])
    {
        camera.move_longitudinally(-1);
    }
    if (state[SDL_SCANCODE_D])
    {
        camera.move_laterally(1);
    }
    else if (state[SDL_SCANCODE_A])
    {
        camera.move_laterally(-1);
    }
}

void Game::update()
{}

void Game::draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < world.structures.size(); i++)  // loop for structs
    {
        for (int j = 0; j < world.structures[i].faces.size(); j++)  // loop for faces in a struct
        {
            
            Sint16 x_arr[world.structures[i].faces[j].verts.size()];  // setting up array
            Sint16 y_arr[world.structures[i].faces[j].verts.size()];

            for (int k = 0; k < world.structures[i].faces[j].verts.size(); k++)  // loop for verts in a face
            {
                Vector3 draw_p = camera.convert_to_draw(world.structures[i].faces[j].verts[k]);
                x_arr[k] = draw_p.x + 500;
                y_arr[k] = -draw_p.z + 300;
            }

            // draw polygon
            polygonRGBA(renderer, x_arr, y_arr, world.structures[i].faces[j].verts.size(), temp_rs[j], temp_gs[j], 255, 255);
        }
    }
    SDL_RenderPresent(renderer);
}

bool Game::isRunning()
{
    return running;
}

void Game::finishExit()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "finished exiting" << std::endl;
}

