/**
 * @file
 *
 * @author CCHyper
 * @author OmniBlade
 *
 * @brief Class holding information on house types.
 *
 * @copyright Chronoshift is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#ifndef HOUSETYPE_H
#define HOUSETYPE_H

#include "always.h"
#include "abstracttype.h"
#include "fixed.h"
#include "gametypes.h"
#include "heap.h"
#include "remap.h"

class GameINIClass;

class HouseTypeClass : public AbstractTypeClass
{
public:
    HouseTypeClass(HousesType type, const char *name, int uiname, const char *suffix, int lemon_factor,
        PlayerColorType color, char prefix);
    HouseTypeClass(const HouseTypeClass &that);
    HouseTypeClass(const NoInitClass &noinit) : AbstractTypeClass(noinit) {}
    virtual ~HouseTypeClass() {}

    virtual BOOL Read_INI(GameINIClass &ini);

    uint8_t *Remap_Table();
    void Code_Pointers() {}
    void Decode_Pointers() {}

    HousesType Get_Type() const { return m_Type; }
    PlayerColorType Get_Color() const { return m_Color; }
    char Get_Prefix() const { return m_Prefix; }
    HousesType What_Type() const { return m_Type; }
    const fixed_t &Get_Firepower() const { return m_Firepower; }
    const fixed_t &Get_Groundspeed() const { return m_Groundspeed; }
    const fixed_t &Get_Airspeed() const { return m_Airspeed; }
    const fixed_t &Get_Armor() const { return m_Armor; }
    const fixed_t &Get_ROF() const { return m_ROF; }
    const fixed_t &Get_Cost() const { return m_Cost; }
    const fixed_t &Get_BuildTime() const { return m_BuildTime; }

    void *operator new(size_t size);
    void *operator new(size_t size, void *ptr) { return ptr; }
    void operator delete(void *ptr);
#ifndef COMPILER_WATCOM // Watcom doesn't like this, MSVC/GCC does.
    void operator delete(void *ptr, void *place) {}
#endif

    static void One_Time() {}
    static void Init_Heap();
    static const char *Name_From(HousesType mission);
    static HousesType From_Name(const char *name);
    static HouseTypeClass &As_Reference(HousesType type);
    static const char *Name_From_Owner(int owner);
    static int Owner_From_Name(const char *name);
    static BOOL Is_Multiplayer_House(HousesType type);

private:
    HousesType m_Type;
    char m_HouseName[256];
    int m_LemonFactor;
    PlayerColorType m_Color; // Color to use when displaying objects owned by this country.
    char m_Prefix;
    fixed_t m_Firepower; // Multiplier to firepower for all weapons [larger means more damage]
    fixed_t m_Groundspeed; // Multiplier to speed for all ground units [larger means faster]
    fixed_t m_Airspeed; // Multiplier to speed for all air units [larger means faster]
    fixed_t m_Armor; // Multiplier to armor damage for all units and buildings [larger means more damage]
    fixed_t m_ROF; // Multiplier to Rate Of Fire for all weapons [larger means slower ROF]
    fixed_t m_Cost; // Multiplier to cost for all units and buildings [larger means costlier]
    fixed_t m_BuildTime; // Multiplier to general object build time [larger means longer to build]
};

#ifdef GAME_DLL
extern TFixedIHeapClass<HouseTypeClass> &g_HouseTypes;
#else
extern TFixedIHeapClass<HouseTypeClass> g_HouseTypes;
#endif

#endif // HOUSETYPE_H
