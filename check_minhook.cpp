#include <iostream>
#include "check_minhook.h"

DECLDIR int PatchPyGILState_Ensure(bool showDebugInfo) {

    return 0;
    // ModuleInfo moduleInfo = GetPythonModule();
    // if (moduleInfo.errorGettingModule != 0) {
    //     return moduleInfo.errorGettingModule;
    // }
    // HMODULE module = moduleInfo.module;
    // if (showDebugInfo) {
    //     std::cout << "Setting sys trace for existing threads." << std::endl << std::flush;
    // }

    
    // DEFINE_PROC(gilEnsure, PyGILState_Ensure*, "PyGILState_Ensure", 0);
    // MH_STATUS status = MH_Initialize();
    
    // if (status != MH_OK) {
    //     if (showDebugInfo) {
    //         std::cout << "Error initializing minhook." << std::endl << std::flush;
    //     }
    //     return status;
    // }

    // status = MH_CreateHookApi(L"python37.dll", "PyGILState_Ensure", reinterpret_cast<void*>(&Detour_PyGILState_Ensure), reinterpret_cast<LPVOID*>(&pPyGILState_Ensure));
    // if (status != MH_OK) {
    //     if (showDebugInfo) {
    //         std::cout << "Error creating hook API." << std::endl << std::flush;
    //     }
    //     return status;
    // }
    
    // if (showDebugInfo) {
    //     std::cout << "minhook applied ok." << std::endl << std::flush;
    // }

    // return MH_EnableHook(MH_ALL_HOOKS);
}