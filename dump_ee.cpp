#include <cstdint>
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "MLX90640_API.h"
constexpr std::vector<uint16_t>::size_type eeprom_size = 832;
int main()
{
    int status;

    std::vector<uint16_t> eeprom(eeprom_size);
    status = MLX90640_DumpEE(default_i2c_addr, eeprom.data());
    parse_status(status);
    for(auto c: eeprom) {
        std::cout << std::hex << c << std::endl;
    }
}
