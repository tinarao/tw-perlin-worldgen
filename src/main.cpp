#include "tile.h"
#include "World.h"


int main() {
    InitWindow(Constants::SCREEN_W, Constants::SCREEN_H, "testings");
    SetTargetFPS(60);

    const auto world = std::make_unique<World>(1488);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        world->Render();

        EndDrawing();
    }

    CloseWindow();
}
