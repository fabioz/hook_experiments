#ifndef _CHECK_MINHOOK_DLL_H_
#define _CHECK_MINHOOK_DLL_H_

#define DECLDIR __declspec(dllexport)

DECLDIR int PatchPyGILState_Ensure(bool showDebugInfo);

#endif