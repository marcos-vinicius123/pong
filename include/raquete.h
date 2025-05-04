#pragma once

class Raquete {
    public:
        Raquete(int x, int y);
        void set_cima(int var);
        void set_baixo(int var);
        SDL_Rect get_rect();
        void draw_raquete(SDL_Renderer* renderer);
        void update();
        void reset();

    private:
        int cima = 0;
        int baixo = 0;
        SDL_Rect rect;
};