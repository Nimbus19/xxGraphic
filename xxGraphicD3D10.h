//==============================================================================
// xxGraphic : Direct3D 10.0 Header
//
// Copyright (c) 2019-2023 TAiGA
// https://github.com/metarutaiga/xxGraphic
//==============================================================================
#pragma once

#include "xxGraphic.h"

//==============================================================================
//  Instance
//==============================================================================
xxAPI uint64_t      xxCreateInstanceD3D10();
xxAPI void          xxDestroyInstanceD3D10(uint64_t instance);
//==============================================================================
//  Device
//==============================================================================
xxAPI uint64_t      xxCreateDeviceD3D10(uint64_t instance);
xxAPI void          xxDestroyDeviceD3D10(uint64_t device);
xxAPI bool          xxResetDeviceD3D10(uint64_t device);
xxAPI bool          xxTestDeviceD3D10(uint64_t device);
xxAPI const char*   xxGetDeviceNameD3D10();
//==============================================================================
//  Framebuffer
//==============================================================================
//==============================================================================
//  Swapchain
//==============================================================================
xxAPI uint64_t      xxCreateSwapchainD3D10(uint64_t device, uint64_t renderPass, void* view, int width, int height, uint64_t oldSwapchain);
xxAPI void          xxDestroySwapchainD3D10(uint64_t swapchain);
xxAPI void          xxPresentSwapchainD3D10(uint64_t swapchain);
xxAPI uint64_t      xxGetCommandBufferD3D10(uint64_t device, uint64_t swapchain);
xxAPI uint64_t      xxGetFramebufferD3D10(uint64_t device, uint64_t swapchain, float* scale);
//==============================================================================
//  Command Buffer
//==============================================================================
xxAPI bool          xxBeginCommandBufferD3D10(uint64_t commandBuffer);
xxAPI void          xxEndCommandBufferD3D10(uint64_t commandBuffer);
xxAPI void          xxSubmitCommandBufferD3D10(uint64_t commandBuffer, uint64_t swapchain);
//==============================================================================
//  Render Pass
//==============================================================================
xxAPI uint64_t      xxCreateRenderPassD3D10(uint64_t device, bool clearColor, bool clearDepth, bool clearStencil, bool storeColor, bool storeDepth, bool storeStencil);
xxAPI void          xxDestroyRenderPassD3D10(uint64_t renderPass);
xxAPI uint64_t      xxBeginRenderPassD3D10(uint64_t commandBuffer, uint64_t framebuffer, uint64_t renderPass, int width, int height, float color[4], float depth, unsigned char stencil);
xxAPI void          xxEndRenderPassD3D10(uint64_t commandEncoder, uint64_t framebuffer, uint64_t renderPass);
//==============================================================================
//  Vertex Attribute
//==============================================================================
xxAPI uint64_t      xxCreateVertexAttributeD3D10(uint64_t device, int count, int* attribute);
xxAPI void          xxDestroyVertexAttributeD3D10(uint64_t vertexAttribute);
//==============================================================================
//  Buffer
//==============================================================================
xxAPI uint64_t      xxCreateConstantBufferD3D10(uint64_t device, int size);
xxAPI uint64_t      xxCreateIndexBufferD3D10(uint64_t device, int size);
xxAPI uint64_t      xxCreateVertexBufferD3D10(uint64_t device, int size, uint64_t vertexAttribute);
xxAPI void          xxDestroyBufferD3D10(uint64_t device, uint64_t buffer);
xxAPI void*         xxMapBufferD3D10(uint64_t device, uint64_t buffer);
xxAPI void          xxUnmapBufferD3D10(uint64_t device, uint64_t buffer);
//==============================================================================
//  Texture
//==============================================================================
xxAPI uint64_t      xxCreateTextureD3D10(uint64_t device, int format, int width, int height, int depth, int mipmap, int array, const void* external);
xxAPI void          xxDestroyTextureD3D10(uint64_t texture);
xxAPI void*         xxMapTextureD3D10(uint64_t device, uint64_t texture, int* stride, int level, int array);
xxAPI void          xxUnmapTextureD3D10(uint64_t device, uint64_t texture, int level, int array);
//==============================================================================
//  Sampler
//==============================================================================
xxAPI uint64_t      xxCreateSamplerD3D10(uint64_t device, bool clampU, bool clampV, bool clampW, bool linearMag, bool linearMin, bool linearMip, int anisotropy);
xxAPI void          xxDestroySamplerD3D10(uint64_t sampler);
//==============================================================================
//  Shader
//==============================================================================
xxAPI uint64_t      xxCreateVertexShaderD3D10(uint64_t device, const char* shader, uint64_t vertexAttribute);
xxAPI uint64_t      xxCreateFragmentShaderD3D10(uint64_t device, const char* shader);
xxAPI void          xxDestroyShaderD3D10(uint64_t device, uint64_t shader);
//==============================================================================
//  Pipeline
//==============================================================================
xxAPI uint64_t      xxCreateBlendStateD3D10(uint64_t device, const char* sourceColor, const char* operationColor, const char* destinationColor, const char* sourceAlpha, const char* operationAlpha, const char* destinationAlpha);
xxAPI uint64_t      xxCreateDepthStencilStateD3D10(uint64_t device, const char* depthTest, bool depthWrite);
xxAPI uint64_t      xxCreateRasterizerStateD3D10(uint64_t device, bool cull, bool scissor);
xxAPI uint64_t      xxCreatePipelineD3D10(uint64_t device, uint64_t renderPass, uint64_t blendState, uint64_t depthStencilState, uint64_t rasterizerState, uint64_t vertexAttribute, uint64_t vertexShader, uint64_t fragmentShader);
xxAPI void          xxDestroyBlendStateD3D10(uint64_t blendState);
xxAPI void          xxDestroyDepthStencilStateD3D10(uint64_t depthStencilState);
xxAPI void          xxDestroyRasterizerStateD3D10(uint64_t rasterizerState);
xxAPI void          xxDestroyPipelineD3D10(uint64_t pipeline);
//==============================================================================
//  Command
//==============================================================================
xxAPI void          xxSetViewportD3D10(uint64_t commandEncoder, int x, int y, int width, int height, float minZ, float maxZ);
xxAPI void          xxSetScissorD3D10(uint64_t commandEncoder, int x, int y, int width, int height);
xxAPI void          xxSetPipelineD3D10(uint64_t commandEncoder, uint64_t pipeline);
xxAPI void          xxSetVertexBuffersD3D10(uint64_t commandEncoder, int count, const uint64_t* buffers, uint64_t vertexAttribute);
xxAPI void          xxSetVertexTexturesD3D10(uint64_t commandEncoder, int count, const uint64_t* textures);
xxAPI void          xxSetFragmentTexturesD3D10(uint64_t commandEncoder, int count, const uint64_t* textures);
xxAPI void          xxSetVertexSamplersD3D10(uint64_t commandEncoder, int count, const uint64_t* samplers);
xxAPI void          xxSetFragmentSamplersD3D10(uint64_t commandEncoder, int count, const uint64_t* samplers);
xxAPI void          xxSetVertexConstantBufferD3D10(uint64_t commandEncoder, uint64_t buffer, int size);
xxAPI void          xxSetFragmentConstantBufferD3D10(uint64_t commandEncoder, uint64_t buffer, int size);
xxAPI void          xxDrawD3D10(uint64_t commandEncoder, int vertexCount, int instanceCount, int firstVertex, int firstInstance);
xxAPI void          xxDrawIndexedD3D10(uint64_t commandEncoder, uint64_t indexBuffer, int indexCount, int instanceCount, int firstIndex, int vertexOffset, int firstInstance);
//==============================================================================
