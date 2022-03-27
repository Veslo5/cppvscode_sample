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
set(rllmGui_src ${PROJECT_SOURCE_DIR}/include/rllmGui)
set(imgui187_src ${PROJECT_SOURCE_DIR}/include/imgui187)


message("raylibcpp path: ${raylibcpp_src}")
message("rllmGui path: ${rllmGui_src}")
message("imgui187 path: ${imgui187_src}")
message("raylib400 path: ${raylib400_src}")
message("lua542 path: ${lua542_src}")

message("raylib400_lib path: ${raylib400_lib}/${raylib400_file}")
message("lua542_lib path: ${lua542_lib}/${lua542_file}")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/test.cpp ${rllmGui_src}/rlImGui.cpp ${imgui187_src}/imgui.cpp ${imgui187_src}/imgui_widgets.cpp ${imgui187_src}/imgui_tables.cpp ${imgui187_src}/imgui_draw.cpp ${imgui187_src}/imgui_demo.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${raylibcpp_src} PUBLIC ${raylib400_src} PUBLIC ${rllmGui_src} PUBLIC ${imgui187_src} PUBLIC ${lua542_src})
target_link_libraries(${PROJECT_NAME} ${raylib400_lib}/${raylib400_file} ${lua542_lib}/${lua542_file})

if(MSVC)
    target_link_libraries(${PROJECT_NAME} winmm.lib)
else()
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-o test.html -s USE_GLFW=3 -s ASYNCIFY -Os -Wall")
endif(MSVC)
