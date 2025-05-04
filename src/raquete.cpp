#include "SDL.h"
#include "raquete.h"
#include "config.h"

Raquete::Raquete(int x, int y) {
    rect.x = x;
    rect.y = y;
    rect.w = TAMANHO_RAQUETE[0];
    rect.h = TAMANHO_RAQUETE[1];
}

void Raquete::set_cima(int var) {
    cima =  var;
}

void Raquete::set_baixo(int var) {
    baixo = var;
}

SDL_Rect Raquete::get_rect() {
    return rect;
}

void Raquete::draw_raquete(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, COR_RAQUETE[0], COR_RAQUETE[1], COR_RAQUETE[2], 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, COR_FUNDO[0], COR_FUNDO[1], COR_FUNDO[2], 255);
}

void Raquete::update() {
    rect.y += (baixo - cima) * 6;
    if (rect.y+rect.h > TAMANHO_TELA[1]) {
        rect.y = TAMANHO_TELA[1] - rect.h;
    } else if (rect.y < 0) {
        rect.y = 0;
    }
}

void Raquete::reset() {
    rect.y = TAMANHO_TELA[1]/2 - rect.h/2;
}