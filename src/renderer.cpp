#include "renderer.h"
#include <iostream>

void GLClearError(){
    while(glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char *function, const char *file, int line){
    while(GLenum error = glGetError()){
        std::cout << "[-] OPENGL ERROR: (" << error << ") " << function << " " << file << ":" << line << std::endl;
        return false;
    }

    return true;
}

void GLAPIENTRY debugCallback(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char *message, const void *userParam){

    // Print the debug message
    std::cout << "OpenGL Debug Message:" << std::endl;
    std::cout << "Source: " << source << ", Type: " << type << ", ID: " << id << ", Severity: " << severity << std::endl;
    std::cout << "Message: " << message << std::endl;

    if (type == GL_DEBUG_TYPE_ERROR) {
        std::cout << "Stopping due to OpenGL error!" << std::endl;
        __builtin_trap();
    }
}

void initializeSimpleDebugCallback(){
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(debugCallback, NULL);
}