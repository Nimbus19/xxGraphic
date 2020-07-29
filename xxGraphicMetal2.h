//==============================================================================
// xxGraphic : Metal 2 Header
//
// Copyright (c) 2019-2020 TAiGA
// https://github.com/metarutaiga/xxGraphic
//==============================================================================
#pragma once

#include "xxGraphic.h"

//==============================================================================
//  Instance
//==============================================================================
xxAPI uint64_t      xxCreateInstanceMetal2();
//==============================================================================
//  Device
//==============================================================================
xxAPI const char*   xxGetDeviceNameMetal2();
//==============================================================================
//  Swapchain
//==============================================================================
xxAPI uint64_t      xxGetCommandBufferMetal2(uint64_t device, uint64_t swapchain);
//==============================================================================
//  Render Pass
//==============================================================================
xxAPI uint64_t      xxBeginRenderPassMetal2(uint64_t commandBuffer, uint64_t framebuffer, uint64_t renderPass, int width, int height, float r, float g, float b, float a, float depth, unsigned char stencil);
xxAPI void          xxEndRenderPassMetal2(uint64_t commandEncoder, uint64_t framebuffer, uint64_t renderPass);
//==============================================================================
//  Shader
//==============================================================================
xxAPI uint64_t      xxCreateVertexShaderMetal2(uint64_t device, const char* shader, uint64_t vertexAttribute);
xxAPI uint64_t      xxCreateFragmentShaderMetal2(uint64_t device, const char* shader);
//==============================================================================
//  Command
//==============================================================================
xxAPI void          xxSetViewportMetal2(uint64_t commandEncoder, int x, int y, int width, int height, float minZ, float maxZ);
xxAPI void          xxSetScissorMetal2(uint64_t commandEncoder, int x, int y, int width, int height);
xxAPI void          xxSetPipelineMetal2(uint64_t commandEncoder, uint64_t pipeline);
xxAPI void          xxSetIndexBufferMetal2(uint64_t commandEncoder, uint64_t buffer);
xxAPI void          xxSetVertexBuffersMetal2(uint64_t commandEncoder, int count, const uint64_t* buffers, uint64_t vertexAttribute);
xxAPI void          xxSetVertexTexturesMetal2(uint64_t commandEncoder, int count, const uint64_t* textures);
xxAPI void          xxSetFragmentTexturesMetal2(uint64_t commandEncoder, int count, const uint64_t* textures);
xxAPI void          xxSetVertexSamplersMetal2(uint64_t commandEncoder, int count, const uint64_t* samplers);
xxAPI void          xxSetFragmentSamplersMetal2(uint64_t commandEncoder, int count, const uint64_t* samplers);
xxAPI void          xxSetVertexConstantBufferMetal2(uint64_t commandEncoder, uint64_t buffer, unsigned int size);
xxAPI void          xxSetFragmentConstantBufferMetal2(uint64_t commandEncoder, uint64_t buffer, unsigned int size);
xxAPI void          xxDrawIndexedMetal2(uint64_t commandEncoder, uint64_t indexBuffer, int indexCount, int instanceCount, int firstIndex, int vertexOffset, int firstInstance);
