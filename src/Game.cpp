#include <SDL2/SDL.h>
#include <iostream>

#include "Game.h"
Game::Game() 
{
    std::cout<< "Game constructor called!" << std::endl;
}

Game::~Game() 
{
    std::cout << "Game destructor called" << std::endl;
}

void Game::Initialize() 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error Initializing SDL" << std::endl; 
        return;
    } 

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    
     this->window = SDL_CreateWindow("Jomen",
     SDL_WINDOWPOS_CENTERED,
     SDL_WINDOWPOS_CENTERED,
     displayMode.w,
     displayMode.h,
     SDL_WINDOW_RESIZABLE | SDL_WINDOW_MINIMIZED |
     SDL_WINDOW_MAXIMIZED | SDL_WINDOW_BORDERLESS);

    if (this->window == NULL) {
        std::cerr << "Erreur lors de la creation de la fênetre SDL" << std::endl;
    }

    //SDL_DestroyWindow(window);
    this->renderer = SDL_CreateRenderer(window, -1, 0);
    if (this->renderer == NULL) {
        std::cerr <<"Erreur lors de la creation de le moteur de rendu (Renderer)" << std::endl;
    }    
    std::cout<<"Window has been created"<<std::endl;
    this->isRunning = true;

    SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN);
    return;
}

void Game::Destroy() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
    this->isRunning = false;
}

void Game::Run() {
    std::cout<<"Run"<<std::endl;
    while(this->isRunning) {
        this->ProcessInput();
        this->Update();
        this->Render();
    }
}

void Game::ProcessInput() {
    SDL_Event sdlEvent;
    while(SDL_PollEvent(&sdlEvent)) {
        switch(sdlEvent.type) {
            case SDL_QUIT: 
                this->isRunning = true;
                break;
            case SDL_KEYDOWN:
                switch(sdlEvent.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        isRunning = false;
                        break; 
                    case SDLK_k:
                        std::cout<<"YEAH BROO \n"<<std::endl;
                        break;
                }
                break;
        }
    }
}

void Game::Update() {


}

void Game::Render()
{
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
    SDL_Rect rect;
    rect.h = 100.0;
    rect.w = 120.0;

    rect.x = 100;
    rect.y = 80;
    SDL_RenderClear(this->renderer);
    SDL_RenderDrawRect(this->renderer, &rect);
    SDL_RenderFillRect(this->renderer, &rect);
    SDL_RenderPresent(this->renderer);
}