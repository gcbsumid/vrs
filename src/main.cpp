#ifdef WIN32
#include <windows.h>
#endif

#include <memory>
#include <stdexcept>
#include <iostream>
#include <string>

#include "Engine.hpp"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

using namespace std;

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT) 
#else 
int main(int argc, char* argv[]) 
#endif
{
    unique_ptr<Engine> engine(nullptr);
    engine = unique_ptr<Engine> (new Engine());

    try {
        engine->initialize();
        if (engine) {
            engine->run();
        }
    } catch (exception& err) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, err.what(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            cerr << "Runtime Error: " << err.what() << endl;
#endif
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}