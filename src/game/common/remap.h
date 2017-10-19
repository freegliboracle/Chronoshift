/**
 * @file
 *
 * @author CCHyper
 * @author OmniBlade
 *
 * @brief Structure containing color info for remaps.
 *
 * @copyright Redalert++ is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#ifndef REMAP_H
#define REMAP_H

#include "always.h"

enum RemapType
{
    REMAP_NONE = -1,
    REMAP_0,
    REMAP_1,
    REMAP_2,
    REMAP_3,
    REMAP_4,
    REMAP_5,
    REMAP_6,
    REMAP_7,
    REMAP_8,
    REMAP_9,
    REMAP_10,
    REMAP_COUNT,
};

struct RemapControlType
{
    uint8_t BrightColor;
    uint8_t MediumColor;
    uint8_t RemapPalette[256];
    uint8_t FontPalette[16];
    uint8_t WindowPalette[8];
};

#ifndef RAPP_STANDALONE
#include "hooker.h"

extern RemapControlType *ColorRemaps;
extern RemapControlType &MetalScheme;
extern RemapControlType &GreyScheme;
#else
extern RemapControlType ColorRemaps[REMAP_COUNT];
extern RemapControlType MetalScheme;
extern RemapControlType GreyScheme;
#endif

#endif // REMAP_H