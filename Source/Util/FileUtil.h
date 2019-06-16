
#ifndef WAVEINTERFERENCE_FILEUTIL_H
#define WAVEINTERFERENCE_FILEUTIL_H

#include <string>
#include <GL/glew.h>

std::string getFileContents(const std::string& filePath);

GLuint LoadJPEG(char* FileName);

#endif //WAVEINTERFERENCE_FILEUTIL_H
