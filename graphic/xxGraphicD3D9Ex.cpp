#include "xxGraphicD3D9.h"
#include "xxGraphicD3D9PS.h"
#include "xxGraphicD3D9Ex.h"
#include "xxGraphicInternal.h"

#if defined(_DEBUG)
#define D3D_DEBUG_INFO 1
#endif
#include "dxsdk/d3d9.h"
typedef HRESULT (WINAPI *PFN_DIRECT3D_CREATE9EX)(UINT, LPDIRECT3D9EX*);

static HMODULE g_d3dLibrary = nullptr;

//==============================================================================
//  Instance
//==============================================================================
uint64_t xxCreateInstanceD3D9Ex()
{
    if (g_d3dLibrary == nullptr)
        g_d3dLibrary = LoadLibraryW(L"d3d9.dll");
    if (g_d3dLibrary == nullptr)
        return 0;

    PFN_DIRECT3D_CREATE9EX Direct3DCreate9Ex;
    (void*&)Direct3DCreate9Ex = GetProcAddress(g_d3dLibrary, "Direct3DCreate9Ex");
    if (Direct3DCreate9Ex == nullptr)
        return 0;

    LPDIRECT3D9EX d3d = nullptr;
    HRESULT hResult = Direct3DCreate9Ex(D3D_SDK_VERSION, &d3d);
    if (hResult != S_OK)
        return 0;

    xxRegisterFunction(D3D9);

    xxDestroyInstance = xxDestroyInstanceD3D9Ex;
    xxTestDevice = xxTestDeviceD3D9Ex;
    xxGetDeviceString = xxGetDeviceStringD3D9Ex;

    return reinterpret_cast<uint64_t>(d3d);
}
//------------------------------------------------------------------------------
uint64_t xxCreateInstanceD3D9ExPS()
{
    uint64_t instance = xxCreateInstanceD3D9Ex();
    if (instance == 0)
        return 0;

    xxCreateInstance = xxCreateInstanceD3D9PS;
    xxGetDeviceString = xxGetDeviceStringD3D9PS;
    xxCreateVertexAttribute = xxCreateVertexAttributeD3D9PS;
    xxDestroyVertexAttribute = xxDestroyVertexAttributeD3D9PS;
    xxCreateVertexShader = xxCreateVertexShaderD3D9PS;
    xxCreateFragmentShader = xxCreateFragmentShaderD3D9PS;
    xxDestroyShader = xxDestroyShaderD3D9PS;
    xxCreatePipeline = xxCreatePipelineD3D9PS;
    xxSetVertexBuffers = xxSetVertexBuffersD3D9PS;
    xxSetVertexConstantBuffer = xxSetVertexConstantBufferD3D9PS;
    xxSetFragmentConstantBuffer = xxSetFragmentConstantBufferD3D9PS;
    xxSetTransform = xxSetTransformD3D9PS;

    xxDestroyInstance = xxDestroyInstanceD3D9Ex;
    xxTestDevice = xxTestDeviceD3D9Ex;
    xxGetDeviceString = xxGetDeviceStringD3D9ExPS;

    return instance;
}
//------------------------------------------------------------------------------
void xxDestroyInstanceD3D9Ex(uint64_t instance)
{
    LPDIRECT3D9 d3d = reinterpret_cast<LPDIRECT3D9>(instance);
    if (d3d == nullptr)
        return;
    d3d->Release();

    if (g_d3dLibrary)
    {
        FreeLibrary(g_d3dLibrary);
        g_d3dLibrary = nullptr;
    }

    xxUnregisterFunction();
}
//==============================================================================
//  Device
//==============================================================================
bool xxTestDeviceD3D9Ex(uint64_t device)
{
    return true;
}
//------------------------------------------------------------------------------
const char* xxGetDeviceStringD3D9Ex(uint64_t device)
{
    return "Direct3D 9Ex Fixed Function";
}
//------------------------------------------------------------------------------
const char* xxGetDeviceStringD3D9ExPS(uint64_t device)
{
    return "Direct3D 9Ex Programmable Shader";
}
//------------------------------------------------------------------------------