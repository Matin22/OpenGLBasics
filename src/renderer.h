#pragma once

#include <GLAD/glad.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x)   \
    GLClearError(); \
    x; \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char *function, const char *file, int line);

void GLAPIENTRY debugCallback(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char *message, const void *userParam);

void initializeSimpleDebugCallback();