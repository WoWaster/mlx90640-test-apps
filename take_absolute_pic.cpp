#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "MLX90640_API.h"
#include "utils.hpp"

constexpr uint8_t refresh_rate = 0x03; // 4 Hz (FPS)
constexpr float emissivity = 1;
constexpr float ta_shift = 8;

int main()
{
    int status;

    status = MLX90640_SetRefreshRate(default_i2c_addr, refresh_rate);
    parse_status(status);

    status = MLX90640_SetChessMode(default_i2c_addr);
    parse_status(status);

    paramsMLX90640 params = get_parameters(default_i2c_addr);

    std::vector<uint16_t> frame(frame_size);
    std::vector<float> image(image_size);
    float Ta;

    status = MLX90640_GetFrameData(default_i2c_addr, frame.data());
    MLX90640_GetTa(frame.data(), &params) - ta_shift;
    MLX90640_CalculateTo(frame.data(), &params, emissivity, Ta, image.data());

    status = MLX90640_GetFrameData(default_i2c_addr, frame.data());
    Ta = MLX90640_GetTa(frame.data(), &params) - ta_shift;
    MLX90640_CalculateTo(frame.data(), &params, emissivity, Ta, image.data());

    std::cout << "[";
    for (size_t i = 0; i < 32; i++)
    {
        std::cout << "[";
        for (size_t j = 0; j < 24; j++)
        {
            std::cout << image[32 * j + i] << ", ";
        }
        std::cout << "]," << std::endl;
    }
    std::cout << "]" << std::endl;
}
