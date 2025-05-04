#pragma once
#include "raquete.h"
#include "config.h"

class Bola {
    public:
        Bola();
        void update(Raquete raquete1, Raquete raquete2);
        void reset();
        void mudar_dir();
        void draw_bola(SDL_Renderer* renderer);

    private:
        bool colidiu_raquete(SDL_Rect raquete_rect);
        SDL_Rect rect = {TAMANHO_TELA[0]/2 - TAMANHO_BOLA[0]/2, TAMANHO_TELA[1]/2 - TAMANHO_BOLA[1]/2, TAMANHO_BOLA[0], TAMANHO_BOLA[1]};
        int x_dir = 0;
        int y_dir = 0;
        int vel = 6;
};