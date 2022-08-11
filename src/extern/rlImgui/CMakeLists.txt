add_library(rlmimgui STATIC rlImGui.cpp imgui.cpp imgui_widgets.cpp imgui_tables.cpp imgui_draw.cpp imgui_demo.cpp imgui_stdlib.cpp)
target_include_directories(rlmimgui PUBLIC ${raylib400_src})