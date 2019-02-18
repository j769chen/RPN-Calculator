#include "button.h"
#include <iostream>


using namespace std;

//Button constructor
button::button(int xpos, int ypos, int w, int h, int buttonSize, ALLEGRO_COLOR c, apstring txt){
    x = xpos;
    y = ypos;
    width = w;
    height = h;
    Size = buttonSize;
    colour = c;
    text = txt;
    font = al_load_font("font.ttf", 36, 0);
    if (!font) {
        cout << "FAILED TO LOAD FONT" << endl;
    }
}

//Draw function
void button::draw() {
    al_draw_filled_rectangle(x * Size + 0.05 * Size, y * Size + 0.05 * Size,
                             x * Size + (width - 1) * Size + 0.95 * Size, y * Size + (height - 1) * Size + 0.95 * Size, colour);

    al_draw_text(font, al_map_rgb(0, 0, 0), x * Size + Size / 2 + (width - 1) * Size / 2,
                 y * Size + 20 + (height - 1) * Size / 2, ALLEGRO_ALIGN_CENTRE, text.c_str());
}

//Get private members
int button::getx(){
    return x;
}

int button::gety(){
    return y;
}

int button::getWidth(){
    return width;
}

int button::getHeight(){
    return height;
}

apstring button::getText(){
    return text;
}

ALLEGRO_FONT* button::getfont(){
    return font;
}

