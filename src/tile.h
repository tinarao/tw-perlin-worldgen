#ifndef TOPDOWN_WORLD_GENERATION_TILE_H
#define TOPDOWN_WORLD_GENERATION_TILE_H

#include <array>
#include <raylib.h>

enum TileKind {
    Water, Dirt, Grass
};


static constexpr std::array<Color, 3> COLORS = {BLUE, BROWN, GREEN};

struct Tile {
    Rectangle rect = { 0,0,0,0};
    TileKind kind = Water;
    Color color = COLORS[Water];

    static auto Create(const TileKind p_kind) -> Tile {
        Tile tile;
        tile.kind = p_kind;
        return tile;
    }

    auto Render() const -> void {
        DrawRectangleRec(this->rect, this->color);
    }
};

// class Tile {
// private:
//     Rectangle rect = {0, 0, 0, 0};
//     TileKind kind = Water;
//     Color color = WHITE;
//
// public:
//     explicit Tile(Rectangle p_rect, const TileKind p_kind)
//         : rect(p_rect), kind(p_kind), color(COLORS[p_kind]) {
//     }
//
//     auto Render() const -> void {
//         DrawRectangleRec(rect, color);
//     }
// };


#endif //TOPDOWN_WORLD_GENERATION_TILE_H
