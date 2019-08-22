#pragma once

#include "xxGraphicD3D9.h"

//==============================================================================
//  Instance
//==============================================================================
xxAPI uint64_t   xxCreateInstanceD3D9PS();
//==============================================================================
//  Device
//==============================================================================
xxAPI const char*xxGetDeviceStringD3D9PS(uint64_t device);
//==============================================================================
//  Vertex Attribute
//==============================================================================
xxAPI uint64_t   xxCreateVertexAttributeD3D9PS(uint64_t device, int count, ...);
xxAPI void       xxDestroyVertexAttributeD3D9PS(uint64_t vertexAttribute);
//==============================================================================
//  Shader
//==============================================================================
xxAPI uint64_t   xxCreateVertexShaderD3D9PS(uint64_t device, const char* shader, uint64_t vertexAttribute);
xxAPI uint64_t   xxCreateFragmentShaderD3D9PS(uint64_t device, const char* shader);
xxAPI void       xxDestroyShaderD3D9PS(uint64_t device, uint64_t shader);
//==============================================================================
//  Pipeline
//==============================================================================
xxAPI uint64_t   xxCreatePipelineD3D9PS(uint64_t device, uint64_t blendState, uint64_t depthStencilState, uint64_t rasterizerState, uint64_t vertexAttribute, uint64_t vertexShader, uint64_t fragmentShader);
//==============================================================================
//  Command
//==============================================================================
xxAPI void       xxSetVertexBuffersD3D9PS(uint64_t commandBuffer, int count, const uint64_t* buffers, uint64_t vertexAttribute);
xxAPI void       xxSetVertexConstantBufferD3D9PS(uint64_t commandBuffer, uint64_t buffer, unsigned int size);
xxAPI void       xxSetFragmentConstantBufferD3D9PS(uint64_t commandBuffer, uint64_t buffer, unsigned int size);
//==============================================================================
//  Fixed-Function
//==============================================================================
xxAPI void       xxSetTransformD3D9PS(uint64_t commandBuffer, const float* world, const float* view, const float* projection);
