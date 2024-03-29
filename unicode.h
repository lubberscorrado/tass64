/*
    $Id: unicode.h 751 2014-06-28 22:01:53Z soci $

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
#ifndef _UNICODE_H
#define _UNICODE_H
#include <stdio.h>
#include "inttypes.h"
#include "unicodedata.h"

struct ubuff_s {
    uint32_t *data;
    size_t len, p;
};

extern unsigned int utf8in(const uint8_t *, uint32_t *);
extern unsigned int utf8rin(const uint8_t *, uint32_t *);
extern uint8_t *utf8out(uint32_t, uint8_t *);
extern void unfc(struct ubuff_s *);
extern void unfkc(str_t *, const str_t *, int);
extern void argv_print(const char *, FILE *);
extern void printable_print(const uint8_t *, FILE *);
extern size_t printable_print2(const uint8_t *, FILE *, size_t);
extern void caret_print(const uint8_t *, FILE *, size_t);

static inline int utf8len(uint8_t ch) {
    if (ch < 0x80) return 1;
    if (ch < 0xe0) return 2;
    if (ch < 0xf0) return 3;
    if (ch < 0xf8) return 4;
    if (ch < 0xfc) return 5;
    return 6;
}
#endif
