#include "SDL.h"
#include "bola.h"
#include "raquete.h"
#include "config.h"

Bola::Bola() {
    reset();
}

void Bola::update(Raquete raquete1, Raquete raquete2) {
    SDL_Rect raquete1_rect = raquete1.get_rect();
    SDL_Rect raquete2_rect = raquete2.get_rect();
    rect.x += x_dir*vel;
    if (rect.x+rect.w > TAMANHO_TELA[0]) {
        colidiu_parede = 2;
        rect.x = TAMANHO_TELA[0] - rect.w;
        x_dir = -x_dir;
    } else if (rect.x < 0) {
        colidiu_parede = 1;
        rect.x = 0;
        x_dir = -x_dir;
    }
    rect.y += y_dir*4;
    if (rect.y+rect.h > TAMANHO_TELA[1]) {
        rect.y = TAMANHO_TELA[1] - rect.h;
        y_dir = -y_dir;
    } else if (rect.y < 0) {
        rect.y = 0;
        y_dir = -y_dir;
    }

    if (colidiu_raquete(raquete1_rect)) {
        rect.x = raquete1_rect.x + raquete1_rect.w;
        x_dir = -x_dir;
        float angulo = (raquete1_rect.y+raquete1_rect.h/2) - (rect.y + rect.h/2);
        angulo = -angulo/(raquete1_rect.h/2);
        y_dir = 0;
        if (angulo < -0.2) {
            y_dir = -1;
        } else if (angulo  > 0.2) {
            y_dir = 1;
        }
    } else if (colidiu_raquete(raquete2_rect)) {
        rect.x = raquete2_rect.x - rect.w;
        x_dir = -x_dir;
        float angulo = (raquete2_rect.y+raquete2_rect.h/2) - (rect.y + rect.h/2);
        angulo = -angulo/(raquete2_rect.h/2);
        y_dir = 0;
        if (angulo < -0.4) {
            y_dir = -1;
        } else if (angulo  > 0.4) {
            y_dir = 1;
        }
    }
}

void Bola::reset() {
    colidiu_parede = 0;
    rect.x = TAMANHO_TELA[0]/2 - TAMANHO_BOLA[0]/2;
    rect.y = TAMANHO_TELA[1]/2 - TAMANHO_BOLA[1]/2;
    x_dir = rand() % 2 ? -1 : 1;
    y_dir = rand() % 2 ? -1 : 1;
}

void  Bola::draw_bola(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, COR_BOLA[0], COR_BOLA[1], COR_BOLA[2], 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, COR_FUNDO[0], COR_FUNDO[1], COR_FUNDO[2], 255);
}

bool Bola::colidiu_raquete(SDL_Rect raquete_rect) {
    SDL_Rect resultado;
    return SDL_IntersectRect(&rect, &raquete_rect, &resultado);
}

int Bola::get_colidiu_parede() {
    return colidiu_parede;
}