/* ternary.h - Ternary Search Trees
   $Id: ternary.h 555 2014-01-12 14:55:02Z soci $

   Copyright 2001 Free Software Foundation, Inc.

   Contributed by Daniel Berlin (dan@cgsoftware.com)

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/
#ifndef TERNARY_H_
#define TERNARY_H_
/* Ternary search trees */
#include <stdint.h>

typedef struct ternary_node_def *ternary_tree;

typedef struct ternary_node_def
{
  uint32_t splitchar;
  ternary_tree lokid;
  ternary_tree eqkid;
  ternary_tree hikid;
}
ternary_node;

void init_ternary(void);
void destroy_ternary(void);

/* Insert string S into tree P, associating it with DATA. 
   Return the data in the tree associated with the string if it's
   already there, and replace is 0.
   Otherwise, replaces if it it exists, inserts if it doesn't, and
   returns the data you passed in. */
void *ternary_insert (ternary_tree *, const uint8_t *, const uint8_t *, void *, int);

typedef void (*ternary_free_fn_t)(void *);

/* Delete the ternary search tree rooted at P. 
   Does NOT delete the data you associated with the strings. */
void ternary_cleanup (ternary_tree, ternary_free_fn_t);

/* Search the ternary tree for string S, returning the data associated
   with it if found. */
void *ternary_search (const ternary_node *, const uint8_t *, const uint8_t *);
#endif
