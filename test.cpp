#include <iostream>
#include <memory>

#include "raylib-cpp.hpp"
#include "rlImGui.h"
#include "imgui.h"

#include "lua.hpp"
#include "lualib.h"
#include "lauxlib.h" 

int main()
{
  int screenWidth = 450;
  int screenHeight = 800;

  std::unique_ptr<bool> landscape = std::make_unique<bool>(false);

  auto window = raylib::Window(screenWidth, screenHeight, "raylib-cpp - basic window");
  window.SetState(FLAG_WINDOW_RESIZABLE);

  rlImGuiSetup(true);
  SetTargetFPS(60);

  lua_State *L;
  L = luaL_newstate();

  luaL_openlibs(L);

  // luaL_loadstring(L, "x = 10 + 5");
  luaL_dostring(L, "print('hello world')");
  lua_getglobal(L, "x");
  int i = lua_tointeger(L, lua_gettop(L));
  TraceLog(LOG_INFO, std::to_string(i).c_str());

  lua_close(L);

  while (!window.ShouldClose())
  {
    int imguiWindowWidth =  GetScreenWidth(); //landscape == false ?  GetScreenWidth() : GetScreenWidth() / 3;

    BeginDrawing();

    window.ClearBackground(RAYWHITE);

    rlImGuiBegin();

    if (ImGui::BeginMainMenuBar())
    {
      if (ImGui::BeginMenu("Settings"))
      {
        if (ImGui::MenuItem("Landscape", nullptr, landscape.get()))
        {
        }
        ImGui::EndMenu();
      }
      ImGui::EndMainMenuBar();
    }

    // bool open = true;
    //  ImGui::ShowDemoWindow(&open);
    ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->Size);
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_HorizontalScrollbar;
    ImGui::Begin("MY CPP PROJECT", nullptr, flags);

    ImGui::BeginChild("INFO", ImVec2(imguiWindowWidth , GetScreenHeight() / 2), true);
    ImGui::TextWrapped("Hello, this is just custom window. Hopefully one day this become editor for little platform Iam working on.");
    ImGui::Spacing();
    ImGui::TextWrapped("It is written in C++ with Raylib as rendering backend and Imgui bindings");
    ImGui::TextWrapped("It's gonna be compiled on windows and web.");
    ImGui::TextWrapped("Also Lua is fully included (even in web version!) and propably gonna be used as scripting laguage for events.");
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::TextWrapped("For now, enjoy nothing! :D");
    if (ImGui::Button("Visit my web :)"))
    {
      raylib::OpenURL("https://www.google.com");
    }
    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginChild("MAP", ImVec2(imguiWindowWidth , GetScreenHeight() / 2), true);
    ImGui::TextWrapped("This is gonna be window with grid map.");
    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginChild("PAINT", ImVec2(imguiWindowWidth , GetScreenHeight() / 2), true);
    ImGui::TextWrapped("This is gonna be window.");
    ImGui::EndChild();

    ImGui::End();
    rlImGuiEnd();

    EndDrawing();
  }

  rlImGuiShutdown();

  return 0;
}