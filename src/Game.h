#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
class Game {

    private:
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        //...

    public:
        Game();
        ~Game();
        void Initialize();
        void Destroy();
        void Run();

        void ProcessInput();
        void Update();
        void Render();
 };

#endif