#ifndef TOPDOWN_WORLD_GENERATION_TILE_H
#define TOPDOWN_WORLD_GENERATION_TILE_H

#include <array>
#include <raylib.h>

enum TileKind {
    Water, Dirt, Grass, Sand
};


static constexpr std::array<Color, 4> COLORS = {BLUE, BROWN, GREEN, YELLOW};

struct Tile {
    Rectangle rect = {0, 0, 0, 0};
    TileKind kind = Water;
    Color color = COLORS[Water];

    static auto Create(const TileKind p_kind) -> Tile {
        Tile tile;
        tile.kind = p_kind;
        tile.color = COLORS[p_kind];
        return tile;
    }

    static auto ChangeKind(Tile& tile, const TileKind p_kind) -> void {
        tile.color = COLORS[p_kind];
        tile.kind = p_kind;
    }

    auto Render() const -> void {
        DrawRectangleRec(this->rect, this->color);
    }
};


#endif //TOPDOWN_WORLD_GENERATION_TILE_H
