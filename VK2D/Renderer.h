/// \file Renderer.h
/// \author Paolo Mazzon
/// \brief The main renderer that handles all rendering
#pragma once
#include "VK2D/Types.h"

/// \brief Core rendering data, don't modify values unless you know what you're doing
struct VK2DRenderer {
	// Devices
	VK2DPhysicalDevice pd; ///< Physical device (gpu)
	VK2DLogicalDevice ld;  ///< Logical device
	VkInstance vk;         ///< Core vulkan instance

	// TODO: Stick swapchain stuff in its own file
};