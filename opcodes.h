/*
    $Id: opcodes.h 745 2014-06-15 16:44:09Z soci $

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
#ifndef _OPCODES_H_
#define _OPCODES_H_
#include <stdint.h>

#define ____ 0x69
enum opr_e {
    ADR_REG=0, ADR_IMPLIED, ADR_IMMEDIATE, ADR_LONG, ADR_ADDR, ADR_ZP,
    ADR_LONG_X, ADR_ADDR_X, ADR_ZP_X, ADR_ADDR_X_I, ADR_ZP_X_I, ADR_ZP_S,
    ADR_ZP_S_I_Y, ADR_ADDR_Y, ADR_ZP_Y, ADR_ZP_LI_Y, ADR_ZP_I_Y, ADR_ZP_I_Z,
    ADR_ADDR_LI, ADR_ZP_LI, ADR_ADDR_I, ADR_ZP_I, ADR_REL_L, ADR_REL,
    ADR_MOVE, ADR_ZP_R, ADR_ZP_R_I_Y, ADR_BIT_ZP, ADR_BIT_ZP_REL, ADR_LEN
};

enum reg_e {
    REG_A, REG_X, REG_Y, REG_S, REG_D, REG_R, REG_I, REG_Z, REG_B, REG_K, REG_P, REG_LEN
};

struct cpu_s {
    const uint32_t *mnemonic;
    const uint8_t *opcode;
    const uint16_t *disasm;
    unsigned int opcodes;
    unsigned int max_address;
    int jmp;
    int brl;
};

extern const char *reg_names;
extern const uint8_t regopcode_table[][REG_LEN];
extern const uint8_t opcode_table[][ADR_LEN];

extern const struct cpu_s w65816;
extern const struct cpu_s c6502;
extern const struct cpu_s c65c02;
extern const struct cpu_s c6502i;
extern const struct cpu_s c65dtv02;
extern const struct cpu_s c65el02;
extern const struct cpu_s r65c02;
extern const struct cpu_s w65c02;
extern const struct cpu_s c65ce02;

#endif
