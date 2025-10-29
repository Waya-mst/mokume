#include "../include/globals.hpp"
#include "../include/window.hpp"
#include "../include/vk_setup.hpp"
#include "../include/uniform.hpp"
#include "../include/descriptors.hpp"
#include "../include/loader.hpp"
#include "../include/geometry.hpp"
#include "../include/shaders.hpp"
#include "../include/render.hpp"
#include <iostream>

int main(){
    std::cout << "hello" << std::endl;
    SetupGLFW();
    SetupVulkan(extensions);
    VkPhysicalDeviceProperties physProps;
    vkGetPhysicalDeviceProperties(physicalDevice, &physProps);
    std::cout << "PhysicalDevice: " << physProps.deviceName << std::endl;
    printf("Device API %u.%u.%u\n",
    VK_VERSION_MAJOR(physProps.apiVersion),
    VK_VERSION_MINOR(physProps.apiVersion),
    VK_VERSION_PATCH(physProps.apiVersion));
    recreateSwapchain();
    createUniformBuffer();
    createDescriptor(swapchainImages.size());
    loadModel();
    loadTexture();
    std::cout << "vertices: " << vertices.size() << std::endl;
    std::cout << "indices: " << indices.size() << std::endl;
    createBLAS();
    createTLAS();
    prepareShaders();
    createRayTracingPipeline();
    createShaderBindingTable();
    drawCall();
    return 0;
}