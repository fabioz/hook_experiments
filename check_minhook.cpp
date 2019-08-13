#include <iostream>
#include <MinHook.h>

extern "C" {

#include "check_minhook.h"

typedef enum { PyGILState_LOCKED, PyGILState_UNLOCKED } PyGILState_STATE;

typedef PyGILState_STATE PyGILState_EnsureFunc(void);

PyGILState_EnsureFunc *pPyGILState_Ensure = NULL;
PyGILState_STATE Detour_PyGILState_Ensure()
{
    std::cout << "Detour_PyGILState_Ensure called." << std::endl << std::flush;
    PyGILState_STATE state = pPyGILState_Ensure();
    return state;
}

DECLDIR int PatchPyGILState_Ensure(bool showDebugInfo) {
    std::cout << "PatchPyGILState_Ensure called" << std::endl;
    MH_STATUS status = MH_Initialize();
    
    if (status != MH_OK) {
        if (showDebugInfo) {
            std::cout << "Error initializing minhook." << std::endl << std::flush;
        }
        return status;
    }

    status = MH_CreateHookApi(L"python37.dll", "PyGILState_Ensure", reinterpret_cast<void*>(&Detour_PyGILState_Ensure), reinterpret_cast<LPVOID*>(&pPyGILState_Ensure));
    if (status != MH_OK) {
        if (showDebugInfo) {
            std::cout << "Error creating hook API." << std::endl << std::flush;
        }
        return status;
    }
    
    if (showDebugInfo) {
        std::cout << "MinHook applied ok." << std::endl << std::flush;
    }

    return MH_EnableHook(MH_ALL_HOOKS);
}

}
