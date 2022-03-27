cmake_minimum_required(VERSION 3.2)

project(cppvscode VERSION 1.0)

if(MSVC)
    set(raylib400_src ${PROJECT_SOURCE_DIR}/include/raylib400w32/include)
    set(raylib400_lib ${PROJECT_SOURCE_DIR}/include/raylib400w32/lib)
    set(raylib400_file raylib.lib)    

    set(lua542_src ${PROJECT_SOURCE_DIR}/include/lua542/include)
    set(lua542_lib ${PROJECT_SOURCE_DIR}/include/lua542)
    set(lua542_file lua54.lib)
else()
    set(raylib400_src ${PROJECT_SOURCE_DIR}/include/raylib400WASM/include)
    set(raylib400_lib ${PROJECT_SOURCE_DIR}/include/raylib400WASM/lib)
    set(raylib400_file libraylib.a)    
    
    set(lua542_src ${PROJECT_SOURCE_DIR}/include/lua542WASM/include)
    set(lua542_lib ${PROJECT_SOURCE_DIR}/include/lua542WASM)
    set(lua542_file liblua.a)
    
    set(CMAKE_EXECUTABLE_SUFFIX ".html")

endif(MSVC)

#These are same for every platform
#TODO: I will make library for rlimgui
set(raylibcpp_src ${PROJECT_SOURCE_DIR}/include/raylibcpp/include)
set(rllmGui_src ${PROJECT_SOURCE_DIR}/src/extern/rlImgui)

message("raylibcpp path: ${raylibcpp_src}")
message("rllmGui path: ${rllmGui_src}")
message("raylib400 path: ${raylib400_src}")
message("lua542 path: ${lua542_src}")

message("raylib400_lib path: ${raylib400_lib}/${raylib400_file}")
message("lua542_lib path: ${lua542_lib}/${lua542_file}")

add_subdirectory(src/extern/rlImgui)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/test.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${raylibcpp_src} PUBLIC ${raylib400_src} PUBLIC ${rllmGui_src} PUBLIC ${lua542_src})
target_link_libraries(${PROJECT_NAME} ${raylib400_lib}/${raylib400_file} ${lua542_lib}/${lua542_file})
target_link_libraries(${PROJECT_NAME} rlmimgui)

if(MSVC)
    target_link_libraries(${PROJECT_NAME} winmm.lib)
else()
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s USE_GLFW=3 -s ASYNCIFY -Os -Wall")
endif(MSVC)
