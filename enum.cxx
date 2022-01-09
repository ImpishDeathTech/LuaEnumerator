#include <lua.hpp>
#include <vector>
#include <string>
#include <iostream>


static int enum_erate(lua_State* L) 
{
    std::vector<std::string> newEnum;
    int begin   = 1,
        end     = 0,
        tableSz = lua_gettop(L);

    if (lua_isinteger(L, -1)) {
        begin = lua_tointeger(L, -1);
        tableSz = tableSz - 1;
    }
    
    for (int i = 1; i <= lua_gettop(L); i++) {
        newEnum.push_back(lua_tostring(L, i));
        end++;
    }

    lua_createtable(L, tableSz, 0);
    
    for (int i = begin, j = 0; j < end; i++, j++) {
        lua_pushinteger(L, i);
        lua_setfield(L, -2, newEnum.at(j).c_str());
    }
    
    lua_pushinteger(L, tableSz);
    lua_setfield(L, -2, "COUNT");
    
    return 1;
}

static int enum_from0(lua_State* L) 
{
    std::vector<std::string> newEnum;
    int end = lua_gettop(L);

    for (int i = 1; i <= end; i++) {
        if (lua_isstring(L, i))
            newEnum.push_back(lua_tostring(L, i));
        else return -1;
    }
    lua_createtable(L, lua_gettop(L) + 1, 0);
    
    for (int i = 1, j = 0; i <= end; i++, j++) {
        lua_pushinteger(L, j);
        lua_setfield(L, -2, newEnum.at(j).c_str());
    }

    lua_pushinteger(L, end);
    lua_setfield(L, -2, "COUNT");

    return 1;
}

/*
static int enum_oneUp(lua_State* L) 
{
    std::vector<std::string> newEnum;
    int end = lua_gettop(L);

    for (int i = 1; i <= end; i++) {
        if (lua_isstring(L, i))
            newEnum.push_back(lua_tostring(L, i));
        else return -1;
    }
    lua_createtable(L, lua_gettop(L) + 1, 0);
    
    for (int i = 1, j = 0; i <= end; i++, j++) {
        lua_pushinteger(L, i);
        lua_setfield(L, -2, newEnum.at(j).c_str());
    }

    lua_pushinteger(L, end);
    lua_setfield(L, -2, "COUNT");

    return 1;
}
*/

static int enum_neg(lua_State* L) 
{
    std::vector<std::string> newEnum;
    int end = lua_gettop(L);
    for (int i = 1; i <= end; i++) {
        if (lua_isstring(L, i))
            newEnum.push_back(lua_tostring(L, i));
        else return -1;
    }
    lua_createtable(L, lua_gettop(L) + 1, 0);

    for (int i = 1, j = 0; i <= end; i++, j++) {
        lua_pushinteger(L, -j);
        lua_setfield(L, -2, newEnum.at(j).c_str());
    }

    lua_pushinteger(L, end);
    lua_setfield(L, -2, "COUNT");

    return 1;
}

static int enum_rev(lua_State* L) 
{
    std::vector<std::string> newEnum;
    int end = lua_gettop(L);
    for (int i = 1; i <= end; i++) {
        if (lua_isstring(L, i))
            newEnum.push_back(lua_tostring(L, i));
        else return -1;
    }
    lua_createtable(L, lua_gettop(L) + 1, 0);

    for (int i = -end, j = 0; i <= -1; i++, j++) {
        lua_pushinteger(L, -i);
        lua_setfield(L, -2, newEnum.at(j).c_str());
    }

    lua_pushinteger(L, end);
    lua_setfield(L, -2, "COUNT");

    return 1;
}

extern "C" 
{
    int luaopen_snowlynx_enum(lua_State* L) 
    {
        static const luaL_Reg enumLib[] {
            { "erate", enum_erate },
            { "from0", enum_from0 },
            //{ "oneUp", enum_oneUp },
            { "neg", enum_neg },
            { "rev", enum_rev },
            { nullptr, nullptr }
        };

        lua_createtable(L, 4, 0);
        luaL_setfuncs(L, enumLib, 0);
        return 1;
    }
}