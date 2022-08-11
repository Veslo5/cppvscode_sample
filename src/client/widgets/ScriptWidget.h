#pragma once
#include <memory>
#include <string>

#include "lua.hpp"
#include "lualib.h"
#include "lauxlib.h"

namespace VGameplay
{
 class ScriptWidget
 {
 public:
     ScriptWidget();
     ~ScriptWidget();

     void Draw();
 private:
     lua_State* luaVM;
     std::string luaText1;
     int luaOK1;
 };
 
    
} // namespace VGameplay
