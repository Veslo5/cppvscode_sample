#include "ScriptWidget.h"
#include "imgui.h"
#include "imgui_stdlib.h"
#include "raylib.h"
#include "raylib-cpp.hpp"
#include "rlImGuiColors.h"

extern "C" int TestFunc(lua_State* L){
    lua_pushstring(L, "hello from c++");

    return 1;
}

VGameplay::ScriptWidget::ScriptWidget() : luaVM(nullptr), luaText1("--LUA TEST \n local test = 5+5 \n return test \n")
{
    if (this->luaVM = luaL_newstate())
    {
        TraceLog(LOG_INFO, "Lua VM created.");
        lua_register(luaVM, "TestFunc", TestFunc);
    }
    else
    {
        TraceLog(LOG_INFO, "Lua VM creation failed.");
    }
}

VGameplay::ScriptWidget::~ScriptWidget()
{
    lua_close(this->luaVM);
    TraceLog(LOG_INFO, "LUA VM destroyed.");
}

void VGameplay::ScriptWidget::Draw()
{
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoSavedSettings;
    ImGui::Begin("Script editor", nullptr, flags);

    if (ImGui::BeginTabBar("script_bar"))
    {
        if (ImGui::BeginTabItem("SCRIPT#1"))
        {
            ImGui::InputTextMultiline("script_editor", &this->luaText1, ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16));
            ImGui::Spacing();

            if (ImGui::Button("DO SCRIPT"))
            {
                this->luaOK1 = luaL_dostring(this->luaVM, this->luaText1.c_str());
            }

            ImGui::Spacing();

            if (this->luaOK1)
            {
                ImGui::TextColored(rlImGuiColors::Convert(raylib::Color::Red()), "Script ended in error or not started yet.");
            }
            else
            {
                ImGui::TextColored(rlImGuiColors::Convert(raylib::Color::Green()), "Script is OK, have a nice day :)");
                ImGui::SameLine();
                ImGui::Text(lua_tostring(luaVM, -1));
            }

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("SCRIPT#2"))
        {
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("SCRIPT#3"))
        {
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::End();
}