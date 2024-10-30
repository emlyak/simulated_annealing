#ifndef DLLEXPORT_H
#define DLLEXPORT_H

#ifndef __linux__
    #if defined( ANNEALING_EXPORTS )
        #define DLL_ANNEALING_EXPORTS __declspec(dllexport)
    #else // !BUILDING_DLL
        #define DLL_ANNEALING_EXPORTS __declspec(dllimport)
    #endif // BUILDING_DLL
#else
    #define DLL_ANNEALING_EXPORTS
#endif // __linux__

#endif // DLLEXPORT_H