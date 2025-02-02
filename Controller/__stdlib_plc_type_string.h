/*------------------------------------------------------------------------------
String type definitions
-------------------------------------------------------------------------------
Copyright (c) 2019 Danfoss

Warning: This header file is subject to change.
Do not use anything defined here directly in manually written C code, unless otherwise specified.

@Author  mponomarenko
@Version 10.0 2017.08.30 pliapota  plc2c-611 Header update
@Version 11.0 2018.09.01 pliapota  plc2c-587 string structure update
@Version 11.0 2018.09.25 pliapota  plc2c-646 added string functions to be used in manually written C code
-------------------------------------------------------------------------------*/

#ifndef _FILE___STDLIB_PLC_TYPE_STRING_H
#define _FILE___STDLIB_PLC_TYPE_STRING_H

#include <stdint.h>
#include <string.h>

typedef struct {
    uint16_t max_len;
    uint16_t cur_len_val;
    uint16_t* cur_len_ref;
    unsigned char* value;
} PLC_STRING_REF;

static inline uint16_t PLC_STRING_GET_LENGTH(PLC_STRING_REF str_ref) {
    return str_ref.cur_len_ref ? *str_ref.cur_len_ref : str_ref.cur_len_val;
}

static inline const unsigned char* PLC_STRING_GET_VALUE(PLC_STRING_REF str_ref) {
    return str_ref.value;
}

static inline void PLC_STRING_SET_VALUE(PLC_STRING_REF str_ref, unsigned char* value, uint16_t value_length) {
    if (!str_ref.cur_len_ref) return;

    if (!value) {
        value_length = 0;
    } else if (value_length > str_ref.max_len) {
        value_length = str_ref.max_len;
    }

    if (value_length > 0) {
        memcpy(str_ref.value, value, sizeof(unsigned char) * value_length);
    }

    *str_ref.cur_len_ref = value_length;
}

#endif /* _FILE___STDLIB_PLC_TYPE_STRING_H */
