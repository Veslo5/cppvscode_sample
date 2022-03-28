cmake_minimum_required(VERSION 3.4)

project(cppvscode VERSION 1.0)

#PATHS
if(MSVC)
    set(raylib400_src ${PROJECT_SOURCE_DIR}/include/raylib400w32/include)
    set(raylib400_lib ${PROJECT_SOURCE_DIR}/include/raylib400w32/lib)
    set(raylib400_file raylib.lib)    

    set(lua542_src ${PROJECT_SOURCE_DIR}/include/lua542/include)
    set(lua542_lib ${PROJECT_SOURCE_DIR}/include/lua542)
    set(lua542_file lua54.lib)
elseif(EMSCRIPTEN)
    set(raylib400_src ${PROJECT_SOURCE_DIR}/include/raylib400WASM/include)
    set(raylib400_lib ${PROJECT_SOURCE_DIR}/include/raylib400WASM/lib)
    set(raylib400_file libraylib.a)    
    
    set(lua542_src ${PROJECT_SOURCE_DIR}/include/lua542WASM/include)
    set(lua542_lib ${PROJECT_SOURCE_DIR}/include/lua542WASM)
    set(lua542_file liblua.a)
    
    set(CMAKE_EXECUTABLE_SUFFIX ".html")

endif(MSVC)

#These are same for every platform
set(raylibcpp_src ${PROJECT_SOURCE_DIR}/include/raylibcpp/include)
set(rllmGui_src ${PROJECT_SOURCE_DIR}/src/extern/rlImgui)
set(client_src ${PROJECT_SOURCE_DIR}/src/client)
set(core_src ${PROJECT_SOURCE_DIR}/src/core)

message("raylibcpp path: ${raylibcpp_src}")
message("rllmGui path: ${rllmGui_src}")
message("raylib400 path: ${raylib400_src}")
message("lua542 path: ${lua542_src}")
message("client path: ${client_src}")

message("raylib400_lib path: ${raylib400_lib}/${raylib400_file}")
message("lua542_lib path: ${lua542_lib}/${lua542_file}")
#END PATHS

#SUBDIRS
add_subdirectory(${rllmGui_src})
add_subdirectory(${core_src})
#END SUBDIRS

#EXE (OUTPUT)
add_executable(${PROJECT_NAME} 
${PROJECT_SOURCE_DIR}/test.cpp
${client_src}/scenes/TopScene.cpp)
#END EXE

#INCLUDES
target_include_directories(${PROJECT_NAME} 
PUBLIC ${raylibcpp_src} 
PUBLIC ${raylib400_src} 
PUBLIC ${rllmGui_src} 
PUBLIC ${lua542_src}
PUBLIC ${core_src}
PUBLIC ${client_src})
#END INCLUDES

#LINKING (.a .so .lib)
target_link_libraries(${PROJECT_NAME} 
${raylib400_lib}/${raylib400_file} 
${lua542_lib}/${lua542_file})

target_link_libraries(${PROJECT_NAME} rlmimgui)
target_link_libraries(${PROJECT_NAME} vengine)

if(MSVC)
    target_link_libraries(${PROJECT_NAME} winmm.lib)
elseif(EMSCRIPTEN)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s USE_GLFW=3 -s ASYNCIFY -Os -Wall --preload-file res")    
    target_compile_options(vengine PUBLIC "-std=c++17") 

endif(MSVC)
#END LINKING

#RESOURCES
if(MSVC)
    add_custom_command(
            TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_SOURCE_DIR}/res
                    ${CMAKE_CURRENT_BINARY_DIR}/debug/res)
elseif(EMSCRIPTEN)
    add_custom_command(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/res
                ${CMAKE_CURRENT_BINARY_DIR}/res)                
endif()
#END RESOURCES