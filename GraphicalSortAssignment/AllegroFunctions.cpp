#include "AllegroHeader.h"
#include "MyListClassHeader.h"

//initialize global allegro variables/pointers
ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_FONT *arial = nullptr;

//initializes allegro
void InitializeAllegro() {
    //initializes allegro
    al_init();

    // Initialize keyboard routines
    if (!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    }

    //Initialize image add on
    if (!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error",
                                   "Failed to initialize al_init_image_addon!",nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    }

    al_init_font_addon();
    al_init_ttf_addon();
    arial = al_load_ttf_font("C:/Windows/Fonts/arial.ttf", 30, 0);
    al_init_primitives_addon();

    // set up event queue and puts up a message box and destroys the display if it fails
    event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
    }
}

void DisplayTitle(int Screen_H,int Screen_W) {
    // initialize display
    display = al_create_display(Screen_W, Screen_H);
    if (!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    }
    al_set_window_title(display, "Sorts (Graphcally)"); //Sets title of window to "StarFall - TitleScreen"

    // set up event queue and puts up a message box and destroys the display if it fails

    // need to register events for our event queue
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

}

void DrawText(string text){
    //draws any text that is input to the screen
    al_draw_text(arial, WHITE, 2, 2, ALLEGRO_ALIGN_LEFT, text.c_str());
}


