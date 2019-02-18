/*****************************************************************************
 *	Name: James Chen
 *	Course: ICS4U
 *	Date: 4/11/2018
 *
 *	Purpose: Calculator that takes its input in Reverse Polish Notation
 *
 *	Usage: User input is done through on screen buttons, must enter two values then operation(RPN)
 *
 *	Revision History: v 5.3
 *
 *	Known Issues: Cannot enter numbers greater than max value of a float (1.2E-38 to 3.4E+38)
 *
 *****************************************************************************/

#include <iostream>
#include <apstring.h>
#include <apstring.cpp>
#include <cstdio>

#include "linkedlist.h"
#include "RPNcalc.h"
#include "button.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define buttonSize 100

using namespace std;

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *event_queue;

static ALLEGRO_COLOR WHITE;
static ALLEGRO_COLOR GRAY;
static ALLEGRO_COLOR SILVER;
static ALLEGRO_COLOR CRIMSON;
static ALLEGRO_COLOR BLACK;

int main(){

    //Allegro Initialization
    if (!al_init()) {
        cout << "Allegro initialization unsuccessful."  << endl;
        return -1;
    }

    if (!al_init_primitives_addon())  {
        cout << "Primitives initialization unsuccessful."  << endl;
        return -1;
    }

    if (!al_init_font_addon())  {
        cout << "Font addon initialization unsuccessful."  << endl;
        return -1;
    }

    if (!al_init_ttf_addon())  {
        cout << "Ttf addon initialization unsuccessful."  << endl;
        return -1;
    }

    if (!al_install_keyboard()) {
        cout << "Keyboard initialization unsuccessful."  << endl;
        return -1;
    }

    if(!al_install_mouse()) {
        cout << "Mouse initialization unsuccessful." << endl;
        return -1;
    }

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(600, 800);
    event_queue = al_create_event_queue();
    ALLEGRO_EVENT userInput;
    al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

    //Colours
    WHITE = al_map_rgb(255,255,255);
    GRAY = al_map_rgb(128,128,128);
    SILVER = al_map_rgb(192,192,192);
    CRIMSON = al_map_rgb(220,20,60);
    BLACK = al_map_rgb(0,0,0);

    RPNcalc calc;
    float input;
    apstring num = "";
    char num2[100];

    //Buttons
    button *buttons[28];

    //*1-9
    buttons[0] = new button(0, 7, 1, 1, buttonSize, WHITE, "0");
    buttons[1] = new button(0, 6, 1, 1, buttonSize, WHITE, "1");
    buttons[2] = new button(1, 6, 1, 1, buttonSize, WHITE, "2");
    buttons[3] = new button(2, 6, 1, 1, buttonSize, WHITE, "3");
    buttons[4] = new button(0, 5, 1, 1, buttonSize, WHITE, "4");
    buttons[5] = new button(1, 5, 1, 1, buttonSize, WHITE, "5");
    buttons[6] = new button(2, 5, 1, 1, buttonSize, WHITE, "6");
    buttons[7] = new button(0, 4, 1, 1, buttonSize, WHITE, "7");
    buttons[8] = new button(1, 4, 1, 1, buttonSize, WHITE, "8");
    buttons[9] = new button(2, 4, 1 ,1, buttonSize, WHITE, "9");

    //Basic Operators
    buttons[10] = new button(3, 4, 1, 1, buttonSize, GRAY, "+"); //add
    buttons[11] = new button(3, 5, 1, 1, buttonSize, GRAY, "-"); //subtract
    buttons[12] = new button(3, 6, 1, 1, buttonSize, GRAY, "x"); //multiply
    buttons[13] = new button(3, 7, 1, 1, buttonSize, GRAY, "/"); //division
    buttons[14] = new button(2, 7, 1, 1, buttonSize, WHITE, "+/-"); //Sign
    buttons[15] = new button(1, 7, 1, 1, buttonSize, WHITE, "."); //Decimal Place

    //Trig
    buttons[16] = new button(0, 2, 1, 1, buttonSize, GRAY, "sin"); //sine
	buttons[17] = new button(1, 2, 1, 1, buttonSize, GRAY, "cos"); //cosine
	buttons[18] = new button(2, 2, 1, 1, buttonSize, GRAY, "tan"); //tangent
	buttons[19] = new button(3, 2, 1, 1, buttonSize, GRAY, "PI"); //pi


    //Exponents/misc
	buttons[20] = new button(3, 3, 1, 1, buttonSize, CRIMSON, "1/x"); //reciprocal
	buttons[21] = new button(0, 3, 1, 1, buttonSize, CRIMSON, "SQRT"); //root
	buttons[22] = new button(1, 3, 1, 1, buttonSize, CRIMSON, "EXP"); //exponent
	buttons[23] = new button(2, 3, 1, 1, buttonSize, CRIMSON, "LOG"); //Logarithm

	//Calculator functions
	buttons[24] = new button(4, 6, 2, 2, buttonSize, SILVER, "ENT"); //enter
	buttons[25] = new button(4, 3, 2, 2, buttonSize, SILVER, "C"); //clear
	buttons[26] = new button(4, 5, 2, 1, buttonSize, SILVER, "AC"); //all clear
    buttons[27] = new button(4, 2, 2, 1, buttonSize, SILVER, "EXIT"); //exit

    while(true){

        input = atof(num.c_str());

        for (int i = 0; i <= 27; i++) {
            buttons[i]->draw();
        }

        //Display boxes
        al_draw_filled_rectangle(5, 5, 595, 95, WHITE);
        al_draw_filled_rectangle(5, 105, 595, 195, WHITE);

        if (calc.isEmpty()){
            sprintf(num2, "%f", 0.0);
        }
        else {
            sprintf(num2, "%f", calc.getval());
        }

        //Display values
        al_draw_text(buttons[0]->getfont(), BLACK, 590, 145, ALLEGRO_ALIGN_RIGHT, num.c_str());
		al_draw_text(buttons[0]->getfont(), BLACK, 590, 45, ALLEGRO_ALIGN_RIGHT, num2);

        al_flip_display();

        al_wait_for_event(event_queue, &userInput);

        //If user presses ESC then exit program
        if (userInput.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (userInput.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                break;
            }
        }
        //If user clicks "X" in top right then exit program
        else if (userInput.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
        }
        //Checks for button press
        else if (userInput.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            if (userInput.mouse.button == 1){

                for(int i = 0; i <= 27; i++){

                    //If mouse is over a button
                    if (userInput.mouse.x >= buttons[i]->getx() * 100
                        && userInput.mouse.x <= buttons[i]->getx() * 100 + buttons[i]->getWidth() * 100
                        && userInput.mouse.y >= buttons[i]->gety() * 100
                        && userInput.mouse.y <= buttons[i]->gety() * 100 + buttons[i]->getHeight() * 100){

                        if (i >= 0 && i <= 9){ //Numpad
                            num = num + buttons[i]->getText();
                        }

                        else if (i >= 10 && i <= 13){ //+,-,x,/

                            calc.push(input);
                            input = 0;
                            num = "";
                            calc.operate(buttons[i]->getText()[0]);

                        }

                        else if (i == 14){ //Change sign
                            if (num[0] == '-'){
                                int j = 0;

                                for(j = 0; j < num.length() - 1; j++){
                                    num[j] = num[j+1];
                                }

                                num[j] = '\0';
                            }

                            else {
                                num = "-" + num;
                            }
                        }

                        else if (i == 15){ //Decimal
                            num += ".";
                        }

                        else if (i == 16){ //Sine
                            calc.push(input);
                            input = 0;
                            num = "";
                            calc.operate('s');
                        }

                        else if (i == 17){ //Cosine
                            calc.push(input);
                            input = 0;
                            num = "";
                            calc.operate('c');
                        }

                        else if (i == 18){ //Tangent
                            calc.push(input);
                            input = 0;
                            num = "";
                            calc.operate('t');
                        }

                        else if (i == 19){ //Pi
                            calc.push(input);
                            input = 0;
                            num = "";
                            calc.operate('p');
                        }

                        else if (i == 20){ //Reciprocal
                            calc.push(input);
                            input = 0;
                            num = "";
                            calc.operate('1');
                        }


                        else if (i == 21){ //Square root
                            calc.push(input);
                            input = 0;
                            num = "";
                            calc.operate('2');
                        }

                        else if (i == 22){ //Power
                            calc.push(input);
                            input = 0;
                            num = "";
                            calc.operate('^');
                        }

                        else if (i == 23){ //Logarithm (base 10)
                            calc.push(input);
                            input = 0;
                            num = "";
                            calc.operate('l');
                        }

                        else if (i == 24){ //Enter
                            calc.push(input);
                            input = 0;
                            num = "";
                        }

                        else if (i == 25){ //Clear
                            input = 0;
                            num = "";
                        }

                        else if (i == 26){ //All clear
                            input = 0;
                            num = "";
                            calc.clearcalc();
                        }

                        else if (i == 27){ //Exit
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
