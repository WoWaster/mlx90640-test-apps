#include <stdexcept>
#include "utils.hpp"

constexpr std::vector<uint16_t>::size_type eeprom_size = 832;

paramsMLX90640 get_parameters(uint8_t addr)
{
    int status;

    std::vector<uint16_t> eeprom(eeprom_size);
    status = MLX90640_DumpEE(default_i2c_addr, eeprom.data());
    parse_status(status);

    paramsMLX90640 params;
    status = MLX90640_ExtractParameters(eeprom.data(), &params);
    parse_status(status);

    return params;
}

void parse_status(int status)
{
    switch (status)
    {
    case -1:
        throw std::runtime_error("NACK");
        break;
    case -2:
        throw std::runtime_error("Wrote incorrect value.");
        break;
    case -7:
        throw std::runtime_error("Invalid EEPROM.");
        break;
    case -8:
        throw std::runtime_error("Cannot get data in time.");
        break;
    default:
        break;
    }
}

void correct_bad_pixels(paramsMLX90640 *params, std::vector<float> pic, uint8_t addr)
{
    int mode = MLX90640_GetCurMode(addr);
    MLX90640_BadPixelsCorrection(params->brokenPixels, pic.data(), mode, params);
    MLX90640_BadPixelsCorrection(params->outlierPixels, pic.data(), mode, params);
}
