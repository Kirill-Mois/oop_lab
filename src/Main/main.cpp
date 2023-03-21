#include "../GameManager/gameManager.h"

int main() {
    GameManager* gameManager = new GameManager;
    gameManager->OpenMenu();
    if (gameManager)
        delete gameManager;
    return 0;
}
