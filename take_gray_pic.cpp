#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "MLX90640_API.h"
#include "utils.hpp"

constexpr uint8_t refresh_rate = 0x03; // 4 Hz (FPS)

int main()
{
    int status;

    status = MLX90640_SetRefreshRate(default_i2c_addr, refresh_rate);
    parse_status(status);

    status = MLX90640_SetChessMode(default_i2c_addr);
    parse_status(status);

    paramsMLX90640 params = get_parameters(default_i2c_addr);

    std::vector<uint16_t> frame(frame_size);
    status = MLX90640_GetFrameData(default_i2c_addr, frame.data());

    std::transform(frame.cbegin(), frame.cend(), frame.begin(), [](uint16_t x)
                   { return ((x & 0xff) << 8) | ((x & 0xff00) >> 8); });

    std::ofstream file("frame_app", std::ios::binary);
    file.write(reinterpret_cast<char *>(frame.data()), image_size * sizeof(uint16_t));
}
