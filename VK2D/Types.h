/// \file Types.h
/// \author Paolo Mazzon
/// \brief Declares all the types (and build options) the renderer needs
#pragma once
#include <vulkan/vulkan.h>

/******************* Build options *******************/

// Comment any of these out to disable the option

/// Maximum number of frames to be processed at once
#define VK2D_MAX_FRAMES_IN_FLIGHT 3

/// Whether or not to enable validation layers/debugging callbacks
#define VK2D_ENABLE_DEBUG

/// Whether or not to enable printing logs to stdout
#define VK2D_STDOUT_LOGGING

/// Whether or not errors are allowed to quit the program
#define VK2D_QUIT_ON_ERROR

/// Enables printing errors to a file
#define VK2D_ERROR_FILE "vk2derror.log"

/******************* Constants *******************/

/// Tells vk2dPhysicalDeviceFind to use the best device it finds (basically just the first non-integrated it finds that meets criteria)
const int32_t VK2D_DEVICE_BEST_FIT = -1;

/******************* Typedefs *******************/

/// \brief Abstraction to make managing pointers easer for VK2DRenderer
typedef struct VK2DRenderer *VK2DRenderer;

/// \brief Abstraction to make managing pointers easer for VK2DImage
typedef struct VK2DImage *VK2DImage;

/// \brief Abstraction to make managing pointers easer for VK2DLogicalDevice
typedef struct VK2DLogicalDevice *VK2DLogicalDevice;

/// \brief Abstraction to make managing pointers easer for VK2DPhysicalDevice
typedef struct VK2DPhysicalDevice *VK2DPhysicalDevice;

/// \brief Abstraction to make managing pointers easer for VK2DBuffer
typedef struct VK2DBuffer *VK2DBuffer;

/// \brief 2D vector of floats
typedef float vec2[2];

/// \brief 3D vector of floats
typedef float vec3[3];

/// \brief 4D vector of floats
typedef float vec4[4];

/// \brief 4x4 matrix of floats
typedef float mat4[16];

/// \brief Vertex data for rendering images
typedef struct {
	vec3 pos;    ///< Position of the vertex
	vec4 colour; ///< Colour of this vertex
	vec2 tex;    ///< Texture coordinate
} VK2DVertexTexture;

/// \brief Vertex data for rendering shapes
typedef struct {
	vec3 pos;    ///< Position of this vertex
	vec4 colour; ///< Colour of this vertex
} VK2DVertexColour;

/// \brief The MVP buffer
typedef struct {
	mat4 model; ///< Model matrix
	mat4 view;  ///< View matrix
	mat4 proj;  ///< Projection matrix
} VK2DUniformBufferObject;

/// \brief How to present images
typedef enum {
	sm_Immediate = 0,   ///< Quickest mode, just plop to screen but may have screen tearing
	sm_VSync = 1,       ///< Slower but prevents screen tearing
	sm_TripleBuffer = 2 ///< Optimal for gaming but a bit slower than immediate (machines may not support this)
} VK2DScreenMode;

/// \brief Level of detail for textures (what mip level to use)
typedef enum {
	td_Max = 0,    ///< Should be fine on 99% of machines
	td_Medium = 1, ///< Eases off the gpu while still providing ok image quality
	td_Low = 2,    ///< Won't look great but high performance
	td_Minimum = 3 ///< Will look like absolute garbage, don't use this unless you hate graphics
} VK2DTextureDetail;

/// \brief Application information
typedef struct VK2DConfiguration {
	const char* applicationName; ///< Name of this program
	const char* engineName;      ///< Name of this engine
	uint32_t applicationVersion; ///< Version of the program
	uint32_t engineVersion;      ///< Version of this engine
	uint32_t apiVersion;         ///< Version of vulkan
} VK2DConfiguration;

/// Default configuration of this renderer
const VK2DConfiguration VK2DDefaultConfig = {
		"VK2D",
		"VK2D Renderer",
		VK_MAKE_VERSION(1, 0, 0),
		VK_MAKE_VERSION(1, 0, 0),
		VK_MAKE_VERSION(1, 2, 0)
};