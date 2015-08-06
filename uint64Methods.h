/*
* Copyright (C) 2010 - 2015 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef UINT64METHODS_H
#define UINT64METHODS_H

/***
 * Lua can not represent uint64 values so we created support for it through our class system.
 *
 * Almost all metamethods including concat, tostring, comparing and math metamethods are implemented.
 * To convert an uint64 value back to a number you must call `tonumber(tostring(myuint64))` which returns nil if conversion failed.
 */
namespace Luauint64
{
    // Template by Mud from http://stackoverflow.com/questions/4484437/lua-integer-type/4485511#4485511
    int __add(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (l && r)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) + Eluna::CHECKVAL<uint64>(L, 2));
        }
        else if (l)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) + luaL_checkinteger(L, 2));
        }
        else if (r)
        {
            Eluna::Push(L, luaL_checkinteger(L, 1) + Eluna::CHECKVAL<uint64>(L, 2));
        }
        return 1;
    }
    int __sub(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (l && r)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) - Eluna::CHECKVAL<uint64>(L, 2));
        }
        else if (l)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) - luaL_checkinteger(L, 2));
        }
        else if (r)
        {
            Eluna::Push(L, luaL_checkinteger(L, 1) - Eluna::CHECKVAL<uint64>(L, 2));
        }
        return 1;
    }
    int __mul(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (l && r)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) * Eluna::CHECKVAL<uint64>(L, 2));
        }
        else if (l)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) * luaL_checkinteger(L, 2));
        }
        else if (r)
        {
            Eluna::Push(L, luaL_checkinteger(L, 1) * Eluna::CHECKVAL<uint64>(L, 2));
        }
        return 1;
    }
    int __div(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (lua_isuserdata(L, 1) != 0)
            Eluna::Push(L, static_cast<lua_Integer>(Eluna::CHECKVAL<uint64>(L, 1)));
        else
            lua_pushvalue(L, 1);
        if (lua_isuserdata(L, 2) != 0)
            Eluna::Push(L, static_cast<lua_Integer>(Eluna::CHECKVAL<uint64>(L, 2)));
        else
            lua_pushvalue(L, 2);
        lua_arith(L, LUA_OPDIV);
        return 1;
    }
    int __idiv(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (l && r)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) / Eluna::CHECKVAL<uint64>(L, 2));
        }
        else if (l)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) / luaL_checkinteger(L, 2));
        }
        else if (r)
        {
            Eluna::Push(L, luaL_checkinteger(L, 1) / Eluna::CHECKVAL<uint64>(L, 2));
        }
        return 1;
    }
    int __mod(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (l && r)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) % Eluna::CHECKVAL<uint64>(L, 2));
        }
        else if (l)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) % luaL_checkinteger(L, 2));
        }
        else if (r)
        {
            Eluna::Push(L, luaL_checkinteger(L, 1) % Eluna::CHECKVAL<uint64>(L, 2));
        }
        return 1;
    }
    int __pow(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (lua_isuserdata(L, 1) != 0)
            Eluna::Push(L, static_cast<lua_Integer>(Eluna::CHECKVAL<uint64>(L, 1)));
        else
            lua_pushvalue(L, 1);
        if (lua_isuserdata(L, 2) != 0)
            Eluna::Push(L, static_cast<lua_Integer>(Eluna::CHECKVAL<uint64>(L, 2)));
        else
            lua_pushvalue(L, 2);
        lua_arith(L, LUA_OPPOW);
        return 1;
    }
    int __eq(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (l && r)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) == Eluna::CHECKVAL<uint64>(L, 2));
        }
        else if (l)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) == luaL_checkinteger(L, 2));
        }
        else if (r)
        {
            Eluna::Push(L, luaL_checkinteger(L, 1) == Eluna::CHECKVAL<uint64>(L, 2));
        }
        return 1;
    }
    int __lt(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (l && r)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) < Eluna::CHECKVAL<uint64>(L, 2));
        }
        else if (l)
        {
            lua_Integer i = luaL_checkinteger(L, 2);
            Eluna::Push(L, i >= 0 && Eluna::CHECKVAL<uint64>(L, 1) < static_cast<uint64>(i));
        }
        else if (r)
        {
            lua_Integer i = luaL_checkinteger(L, 1);
            Eluna::Push(L, i < 0 || static_cast<uint64>(i) < Eluna::CHECKVAL<uint64>(L, 2));
        }
        return 1;
    }
    int __le(lua_State* L)
    {
        bool l = lua_isuserdata(L, 1) != 0;
        bool r = lua_isuserdata(L, 2) != 0;
        if (l && r)
        {
            Eluna::Push(L, Eluna::CHECKVAL<uint64>(L, 1) <= Eluna::CHECKVAL<uint64>(L, 2));
        }
        else if (l)
        {
            lua_Integer i = luaL_checkinteger(L, 2);
            Eluna::Push(L, i >= 0 && Eluna::CHECKVAL<uint64>(L, 1) <= static_cast<uint64>(i));
        }
        else if (r)
        {
            lua_Integer i = luaL_checkinteger(L, 1);
            Eluna::Push(L, i < 0 || static_cast<uint64>(i) <= Eluna::CHECKVAL<uint64>(L, 2));
        }
        return 1;
    }
    int __tostring(lua_State* L)
    {
        Eluna::Push(L, std::to_string(Eluna::CHECKVAL<uint64>(L, 1)));
        return 1;
    }
    int gc(lua_State* L)
    {
        Eluna::GetEluna(L)->storeduints.erase(Eluna::CHECKVAL<uint64>(L, 1));
        return ElunaTemplate<uint64>::CollectGarbage(L);
    }

    /**
     * Returns true if the value can be safely casted to a lua integer
     *
     * @return bool fits
     */
    int fitsint(lua_State* L)
    {
        lua_Number imin = std::numeric_limits<lua_Integer>::min();
        lua_Number imax = std::numeric_limits<lua_Integer>::max();
        uint64 val = Eluna::CHECKVAL<uint64>(L, 1);
        if ((imin < 0 || static_cast<uint64>(imin) < val) && (imax >= 0 && val <= static_cast<uint64>(imax)))
            Eluna::Push(L, true);
        else
            Eluna::Push(L, false);
        return 1;
    }

    /**
     * Casts the uint64 number into a lua integer and returns it
     *
     * @return int64 value
     */
    int toint(lua_State* L)
    {
        Eluna::Push(L, static_cast<int64>(Eluna::CHECKVAL<uint64>(L, 1)));
        return 1;
    }

    /**
     * Casts the uint64 number into a lua number and returns it
     *
     * @return double value
     */
    int tonumber(lua_State* L)
    {
        Eluna::Push(L, static_cast<lua_Number>(Eluna::CHECKVAL<uint64>(L, 1)));
        return 1;
    }

    /**
     * Returns the uint64 as a hex string
     *
     * @return string hexstr
     */
    int tohex(lua_State* L)
    {
        std::ostringstream oss;
        oss << std::hex << Eluna::CHECKVAL<uint64>(L, 1);
        Eluna::Push(L, oss.str().c_str());
        return 1;
    }
};
#endif
