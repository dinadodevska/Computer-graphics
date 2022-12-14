#pragma once
unsigned int CreateShader(const char* vertexSource, const char* fragmentSource);

struct Texture
{
    unsigned int ID;
    int width, height, channels;
    int index;
    static int NUM_TEXTURES_LOADED;
};
Texture LoadTextureFromFile(const char* path);