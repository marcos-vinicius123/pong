#pragma once
#include "raquete.h"
#include "config.h"

class Bola {
    public:
        Bola();
        void update(Raquete raquete1, Raquete raquete2);
        void reset();
        void draw_bola(SDL_Renderer* renderer); //desenha a bola na tela
        int get_colidiu_parede();
    private:
        bool colidiu_raquete(SDL_Rect raquete_rect); //detecta se a bola colidiu com uma raquete
        SDL_Rect rect = {TAMANHO_TELA[0]/2 - TAMANHO_BOLA[0]/2, TAMANHO_TELA[1]/2 - TAMANHO_BOLA[1]/2, TAMANHO_BOLA[0], TAMANHO_BOLA[1]};
        int x_dir = 0; //direcao horizontal da bola
        int y_dir = 0; //direcao vertical da bola
        int vel = 6; //velocidade da bola
        int colidiu_parede; // 0=nao colidiu 1=colidiu parede esquerda 2=colidiu parede direita
};