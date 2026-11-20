#include "EventManager.h"
#include "Auth.h"

int main() {
    while (loginPrompt()) {
        mainMenu();
        if (isLoggedIn()) break;   // user chose Exit, not Logout
    }
    return 0;
}