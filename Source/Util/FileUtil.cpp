
#include "FileUtil.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <jpeglib.h>
#include <jerror.h>


std::string getFileContents(const std::string& filePath)
{
    std::ifstream inFile;
    inFile.open(filePath);

    if(!inFile.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    std::stringstream stream;

    stream << inFile.rdbuf();
    return stream.str();
}

