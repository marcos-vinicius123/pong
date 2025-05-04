#include "SDL.h"
#include "config.h"
#include "raquete.h"
#include "bola.h"
#include <iostream>

int main(int, char**){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("erro inicializando SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("PONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            TAMANHO_TELA[0], TAMANHO_TELA[1], 0);
    SDL_Renderer* renderer  = SDL_CreateRenderer(win, -1,
                            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event evento;
    bool rodando = true;

    Raquete raquete1 = {10, TAMANHO_TELA[1]/2-TAMANHO_RAQUETE[1]/2};
    Raquete raquete2 = {TAMANHO_TELA[0]-TAMANHO_RAQUETE[0]-10,
                        TAMANHO_TELA[1]/2-TAMANHO_RAQUETE[1]/2};
    
    int score[2] = { 0 };
    Bola bola;

    while (rodando) {
        SDL_SetRenderDrawColor(renderer, COR_FUNDO[0], COR_FUNDO[1], COR_FUNDO[2], 255);
        SDL_RenderClear(renderer);
        while (SDL_PollEvent(&evento) != 0) {
            switch (evento.type) {
                case SDL_QUIT:
                    rodando = false;
                    SDL_Quit();
                    break;

                case SDL_KEYDOWN:
                    if (evento.key.repeat) {
                        break;
                    }
                    switch (evento.key.keysym.sym) {
                        case SDLK_w:
                            raquete1.set_cima(1);
                            break;
                        
                        case SDLK_s:
                            raquete1.set_baixo(1);
                            break;
                        
                        case SDLK_UP:
                            raquete2.set_cima(1);
                            break;
                        
                        case SDLK_DOWN:
                            raquete2.set_baixo(1);
                            break;
                        
                        default:
                            break;
                    }
                    break;

                case SDL_KEYUP:
                    if (evento.key.repeat) {
                        break;
                    }
                    switch (evento.key.keysym.sym) {

                        case SDLK_a:
                            bola.reset();
                            break;

                        case SDLK_w:
                            raquete1.set_cima(0);
                            break;
                        
                        case SDLK_s:
                            raquete1.set_baixo(0);
                            break;
                        
                        case SDLK_UP:
                            raquete2.set_cima(0);
                            break;
                        
                        case SDLK_DOWN:
                            raquete2.set_baixo(0);
                            break;
                        
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        raquete1.update();
        raquete2.update();
        bola.update(raquete1, raquete2);

        if (bola.get_colidiu_parede()) {
            score[!(bola.get_colidiu_parede()-1)] += 1;
            bola.reset();
            raquete1.reset();
            raquete2.reset();
            std::cout << score[0] << " " << score[1] << std::endl;
        }

        raquete1.draw_raquete(renderer);
        raquete2.draw_raquete(renderer);
        bola.draw_bola(renderer);

        SDL_RenderPresent(renderer);
    }
    return 0;
}
