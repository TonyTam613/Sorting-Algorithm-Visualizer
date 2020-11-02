#ifndef ALLEGROHEADER_H_INCLUDED
#define ALLEGROHEADER_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <string>


using namespace std;

#define PINK        al_map_rgb(255, 0, 255)
#define BLACK       al_map_rgb(0, 0, 0)
#define GREEN       al_map_rgb(0, 255, 0)
#define BLUE        al_map_rgb(0, 0, 255)
#define WHITE       al_map_rgb(255, 255, 255)
#define SLATEGREY   al_map_rgb(112,128,144)
#define FOREGROUND al_map_rgb(0x3C, 0x64, 0x78)

const int Screen_H = 900;
const int Screen_W = 1600;

void DisplayTitle(int Screen_H,int Screen_W);
void InitializeAllegro();
void DrawText(string text);

#endif // ALLEGROHEADER_H_INCLUDED
