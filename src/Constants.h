#ifndef TOPDOWN_WORLD_GENERATION_CONSTANTS_H
#define TOPDOWN_WORLD_GENERATION_CONSTANTS_H

#include <cstdint>

namespace Constants {
    constexpr uint16_t SCREEN_W = 720;
    constexpr uint16_t SCREEN_H = 480;
    constexpr uint32_t TOTAL_PIXELS = SCREEN_W * SCREEN_H;
    constexpr uint8_t TILE_SIZE = 16;
}

#endif //TOPDOWN_WORLD_GENERATION_CONSTANTS_H