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
        
        // Check for messages/events
        if(!screen.processEvents()) {
            break;
        }
    }

    screen.close();

    return 0;
}