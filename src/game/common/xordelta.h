/**
 * @file
 *
 * @author OmniBlade
 *
 * @brief Implementation of XORDelta, a custom binary diff format used in many Westwood games.
 *
 * @copyright Chronoshift is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#ifndef XORDELTA_H
#define XORDELTA_H

#include "always.h"

/**
 * @brief Get the worst case for XORDelta encoding given the starting size.
 */
inline int XOR_Worst_Case(int bytes)
{
    return bytes + ((bytes / 63) * 3) + 4;
}

void __cdecl Apply_XOR_Delta(void *dst, void *src);
void __cdecl Apply_XOR_Delta_To_Page_Or_Viewport(void *offset, void *delta, int width, int pitch, BOOL copy);
int Generate_XOR_Delta(void *dst, void *src, void *base, int size);

#endif // XORDELTA_H
