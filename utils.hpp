#include <cstdint>
#include <vector>
#include "MLX90640_API.h"

constexpr uint8_t default_i2c_addr = 0x33;
constexpr std::vector<uint16_t>::size_type frame_size = 834;
constexpr std::vector<uint16_t>::size_type image_size = 768;

paramsMLX90640 get_parameters(uint8_t addr);

void parse_status(int status);

void correct_bad_pixels(paramsMLX90640 *params, std::vector<float> pic, uint8_t addr);
