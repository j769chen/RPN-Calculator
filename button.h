#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <iostream>
#include <apstring.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>


class button {
    private:
        int x;
        int y;
        int width;
        int height;
        int Size;
        ALLEGRO_COLOR colour;
        ALLEGRO_FONT *font;
        apstring text;
    public:
        button(int xpos, int ypos, int w, int h, int buttonSize, ALLEGRO_COLOR c, apstring txt);
        void draw();
        int getx();
        int gety();
        int getWidth();
        int getHeight();
        apstring getText();
        ALLEGRO_FONT *getfont();
        ~button();
};


#endif // BUTTON_H_INCLUDED

