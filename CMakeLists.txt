cmake_minimum_required(VERSION 3.14)
project(WaveInterference)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Source/Application.cpp Source/Context.cpp Source/Renderer/RenderMaster.cpp Source/Renderer/QuadRenderer.cpp Source/Model.cpp Source/Shaders/Shader.cpp Source/Shaders/BasicShader.cpp Source/Texture/BasicTexture.cpp Source/Camera.cpp Source/Maths/Matrix.cpp Source/States/PlayingState.cpp Source/Player/Player.cpp Source/Shaders/ShaderLoader.cpp Source/Util/FileUtil.cpp Source/stb_image/stb_image.cpp Source/stb_image/stb_image.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package (GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR}  ${GLEW_INCLUDE_DIRS} ${SFML_INCLUDE_DIRS} ${glfw3_INCLUDE_DIRS} )


target_link_libraries (${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} glfw  )
