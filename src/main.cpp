#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
using namespace std;
using namespace particalfire;

int main() {

    Screen screen;

    if(!screen.init()) {
        cout << "Error initializing SDL." << endl;
        return 1;
    }

    while(true) {

        // Update particals

        // Draw particals
        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++){
            for (int x =0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }

        // screen.setPixel(400, 300, 255, 255, 255);

        // Update screen
        screen.update();
        
        // Check for messages/events
        if(!screen.processEvents()) {
            break;
        }
    }

    screen.close();

    return 0;
}