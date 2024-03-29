/*
    $Id: boolobj.h 860 2014-11-22 20:55:21Z soci $

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/
#ifndef _BOOLOBJ_H
#define _BOOLOBJ_H
extern obj_t BOOL_OBJ;

extern void boolobj_init(void);

extern MUST_CHECK value_t int_from_bool(const value_t);
extern MUST_CHECK value_t float_from_bool(const value_t);
#endif
