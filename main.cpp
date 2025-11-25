#include <cstdint>
#include <vector>
#include "tile.h"

constexpr uint16_t screen_w = 720;
constexpr uint16_t screen_h = 480;
constexpr uint32_t total_pixels = screen_w * screen_h;

int main() {
    std::vector<Tile> tiles;
    tiles.reserve(total_pixels + 1);

    for (int y = 0; y < screen_w; y++) {
        for (int x = 0; x < screen_w; x++) {
            Rectangle rect = { static_cast<float>(x), static_cast<float>(y), 1, 1 };
            auto t = Tile(rect, TileKind::Dirt);
            tiles.push_back(t);
        }
    }

    //

    InitWindow(screen_w, screen_h, "testings");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        for (const auto& tile : tiles) {
            tile.Render();
        }

        EndDrawing();
    }

    CloseWindow();
}
