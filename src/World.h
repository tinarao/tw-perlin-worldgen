#ifndef TOPDOWN_WORLD_GENERATION_WORLD_H
#define TOPDOWN_WORLD_GENERATION_WORLD_H

#include <memory>
#include "Constants.h"
#include "tile.h"
#include "../lib/FastNoiseLite.h"

namespace IslandsNoiseConstants {
    constexpr float FREQ = 0.007;
    constexpr float FRACTAL_LACUNARITY = 3.330;
    constexpr float FRACTAL_GAIN = 1.5;
    constexpr float FRACTAL_WEIGHTED_STRENGTH = 1.180;
    constexpr int FRACTAL_OCTAVES = 3;
}


class World {
    FastNoiseLite islands_noise;
    Tile tiles[Constants::SCREEN_H][Constants::SCREEN_W];

private:
    auto generate_islands_noise(const int seed) -> void {
        using namespace IslandsNoiseConstants;

        islands_noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
        islands_noise.SetSeed(seed);
        islands_noise.SetFrequency(FREQ);

        islands_noise.SetFractalType(FastNoiseLite::FractalType_FBm);
        islands_noise.SetFractalOctaves(FRACTAL_OCTAVES);
        islands_noise.SetFractalGain(FRACTAL_GAIN);
        islands_noise.SetFractalWeightedStrength(FRACTAL_WEIGHTED_STRENGTH);
    }

public:
    explicit World(const int seed) {
        using namespace Constants;
        generate_islands_noise(seed);

        for (size_t y = 0; y < SCREEN_H; y++) {
            for (size_t x = 0; x < SCREEN_W; x++) {
                const auto fl_x = static_cast<float>(x);
                const auto fl_y = static_cast<float>(y);

                const auto noise_amount = islands_noise.GetNoise(
                    fl_x, fl_y
                );

                Tile tile;
                tile.rect = {fl_x, fl_y, TILE_SIZE, TILE_SIZE};

                if (noise_amount < 0) {
                    Tile::ChangeKind(tile, Water);
                } else if (noise_amount > 0.3) {
                    Tile::ChangeKind(tile, Grass);
                } else if (noise_amount > 0.2) {
                    Tile::ChangeKind(tile, Dirt);
                } else {
                    Tile::ChangeKind(tile, Sand);
                }

                tiles[y][x] = tile;
            }
        }
    }

    auto Render() const -> void {
        for (size_t y = 0; y < Constants::SCREEN_H; y++) {
            for (size_t x = 0; x < Constants::SCREEN_W; x++) {
                tiles[y][x].Render();
            }
        }
    }
};


#endif // TOPDOWN_WORLD_GENERATION_WORLD_H
