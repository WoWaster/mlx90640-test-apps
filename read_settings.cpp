#include <cstdint>
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "MLX90640_API.h"

int main()
{
    int resolution = MLX90640_GetCurResolution(default_i2c_addr);
    std::cout << "Current resolution ";
    switch (resolution)
    {
    case 0:
        std::cout << "16 bit";
        break;
    case 1:
        std::cout << "17 bit";
        break;
    case 2:
        std::cout << "18 bit";
        break;
    case 3:
        std::cout << "19 bit";
        break;
    }
    std::cout << std::endl;

    paramsMLX90640 params = get_parameters(default_i2c_addr);

    std::cout << "Dumping all parameters:" << std::endl;

    std::cout << "kVdd " << params.kVdd << std::endl;
    std::cout << "vdd25 " << params.vdd25 << std::endl;
    std::cout << "KvPTAT " << params.KvPTAT << std::endl;
    std::cout << "KtPTAT " << params.KtPTAT << std::endl;
    std::cout << "kVvPTAT25dd " << params.vPTAT25 << std::endl;
    std::cout << "alphaPTAT " << params.alphaPTAT << std::endl;
    std::cout << "gainEE " << params.gainEE << std::endl;
    std::cout << "tgc " << params.tgc << std::endl;
    std::cout << "cpKv " << params.cpKv << std::endl;
    std::cout << "cpKta " << params.cpKta << std::endl;
    std::cout << "resolutionEE " << params.resolutionEE << std::endl;
    std::cout << "calibrationModeEE " << params.calibrationModeEE << std::endl;
    std::cout << "KsTa " << params.kVdd << std::endl;

    std::cout << "ksTo ";
    for (auto i : params.ksTo)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "ct ";
    for (auto i : params.ct)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "alpha ";
    for (auto i : params.alpha)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "alphaScale " << params.alphaScale << std::endl;

    std::cout << "offset ";
    for (auto i : params.offset)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "kta ";
    for (auto i : params.kta)
        std::cout << i << " ";
    std::cout << std::endl;

    // Prints something weird and breaks terminal
    // std::cout << "ktaScale " << params.ktaScale << std::endl;

    std::cout << "kv ";
    for (auto i : params.kv)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "kvScale " << params.kvScale << std::endl;

    std::cout << "cpAlpha ";
    for (auto i : params.cpAlpha)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "cpOffset ";
    for (auto i : params.cpOffset)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "ilChessC ";
    for (auto i : params.ilChessC)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "brokenPixels ";
    for (auto i : params.brokenPixels)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "outlierPixels ";
    for (auto i : params.outlierPixels)
        std::cout << i << " ";
    std::cout << std::endl;
}
