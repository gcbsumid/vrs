#ifdef WIN32
#include <windows.h>
#endif

#include <memory>
#include <stdexcept>
#include <iostream>
#include <string>

#include "Engine.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    unique_ptr<VRS::Engine> engine(nullptr);
    engine = unique_ptr<VRS::Engine> (new VRS::Engine());

    try {
        if (engine) {
            engine->run();
        }
    } catch (exception& err) {
        cerr << "Runtime Error: " << err.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}