#include <iostream>

#include "raylib-cpp.hpp"
#include "rlImGui.h"
#include "imgui.h"

#include "lua.hpp"
#include "lualib.h"
#include "lauxlib.h"

int main()
{
  int screenWidth = 800;
  int screenHeight = 450;

  auto window = raylib::Window(screenWidth, screenHeight, "raylib-cpp - basic window");
  window.SetState(FLAG_WINDOW_RESIZABLE);

  rlImGuiSetup(true);
  SetTargetFPS(60);

  lua_State *L;
  L = luaL_newstate();

  luaL_openlibs(L);

  luaL_loadstring(L, "x = 10 + 5");
  //luaL_dostring(L, "x = 10 + 5");
  lua_getglobal(L, "x");
  int i = lua_tointeger(L, lua_gettop(L));
  TraceLog(LOG_INFO, std::to_string(i).c_str());
    
  lua_close(L); 

  while (!window.ShouldClose())
  {
    BeginDrawing();

    window.ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    rlImGuiBegin();

    bool open = true;
    ImGui::ShowDemoWindow(&open);

    rlImGuiEnd();

    EndDrawing();
  }

  rlImGuiShutdown();

  return 0;
}