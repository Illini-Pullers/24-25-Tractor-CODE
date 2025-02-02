#ifndef GUIDE_stg_h
#define GUIDE_stg_h

#ifndef GUIDE_BOOL
  #define GUIDE_BOOL
#endif
//Types:
#include <stdint.h>
#include <limits.h>
typedef float F32;
typedef double F64;

typedef union {
  uint16_t u16[4];
  int16_t  s16[4];
  uint32_t u32[2];
  int32_t  s32[2];
  F32      f32[2];
  uint64_t u64;
  int64_t  s64;
  F64      f64;
} _TYPE_HELPER_T;

#include "math.h"
static inline int32_t _NormU32ITanS32(uint32_t angle)
{
  if(9000 == angle){
    return 2147483647;
  } else {
    int inv = 1;
    if(angle > 9000){
      inv = -1;
      angle = 18000 - angle;
    }
    return inv * (int32_t)(0.5 + 10000.0 * tan(angle * 3.141592653/18000.0));
  }
}
static inline int32_t _U32ITanS32(uint32_t angle)
{
  return _NormU32ITanS32(angle % 18000);
}
static inline int32_t _S32ITanS32(int32_t angle)
{
  if(angle < 0){
    angle = 18000 + angle % 18000;
  } else {
    angle = angle % 18000;
  }
  return _NormU32ITanS32(angle);
}


//Macros to convert from 16 to 8 bits:
#define _MACRO_FixU8Exp(Exp) ((Exp) & 0xFF)
#define _MACRO_FixS8Exp(Exp) (((Exp) & 0x80) ? ((S16)((Exp) | 0xFF00)) : ((Exp) & 0xFF))
#define _MACRO_FixS8Var(FixVar) if(FixVar & 0x0080){FixVar = FixVar | 0xFF00;}else{FixVar = FixVar & 0x00FF;}

//NV helpers:
#include "_nvallocation.h"
extern U16 _NVINT[];
extern U16 _NVPND[];
static inline int _NV_GetPending(U16 Index)
{
  return _NVPND[(Index) / 16] &  (1 << ((Index) & (U16)0xF));
}
static inline void _NV_SetPending(U16 Index)
{
  _NVPND[(Index) / 16] |= (1 << ((Index) & (U16)0xF));
}
static inline int _NV_InRange(U16 Index)
{
  return Index < _NVSize;
}
static inline void NVWriteU16(U16 Index, U16 Value)
{
  if  (_NV_InRange(Index) && !_NV_GetPending(Index) && _NVINT[Index] != Value)
  {
    _NVINT[Index] = Value;
    _NV_SetPending(Index);
  }
}
static inline void NVReadU16(U16 Index, U16 * Value)
{
   *Value = _NVINT[Index];
}
//
static inline void NVWriteBOOL(U16 Index, BOOL Value)
{
  if(Value)
  {
    NVWriteU16(Index, 1);
  }
  else
  {
    NVWriteU16(Index, 0);
  }
}
static inline void NVReadBOOL(U16 Index, U8 * Value)
{
  if(_NVINT[Index])
  {
    *Value = 1;
  }
  else
  {
    *Value = 0;
  }
}
//
static inline void NVWriteU8(U16 Index, U8 Value)
{
#if CHAR_BIT == 8
  NVWriteU16(Index, Value);
#else
  NVWriteU16(Index, Value & 0xFF);
#endif
}
static inline void NVReadU8(U16 Index, U8 * Value)
{
#if CHAR_BIT == 8
  *Value = _NVINT[Index];
#else
  *Value = _NVINT[Index] & 0xFF;
#endif
}
//
static inline void NVWriteS8(U16 Index, S8 Value)
{
#if CHAR_BIT == 8
  NVWriteU16(Index, ((U8)Value) & 0xFF);
#else
  if(Value & 0x0080)
  {
	NVWriteU16(Index, ((U16)Value) | 0xFF00);
  }
  else
  {
	NVWriteU16(Index, ((U16)Value) & 0x00FF);
  }
#endif
}
static inline void NVReadS8(U16 Index, S8 * Value)
{
#if CHAR_BIT == 8
  *Value = _NVINT[Index];
#else
  if(_NVINT[Index] & 0x0080)
  {
	*Value = _NVINT[Index] | 0xFF00;
  }
  else
  {
	*Value = _NVINT[Index] & 0x00FF;
  }
#endif
}
//
static inline void NVWriteS16(U16 Index, S16 Value)
{
  NVWriteU16(Index, (U16)Value);
}
static inline void NVReadS16(U16 Index, S16 * Value)
{
   NVReadU16(Index, (U16*)Value);
}
//
static inline void NVWriteU32(U16 Index, U32 Value)
{
  NVWriteU16(Index, Value);
  NVWriteU16(Index+1, Value >> 16);
}
static inline void NVReadU32(U16 Index, U32 * Value)
{
  U16 * buf = (U16*)Value;
  NVReadU16(Index, &buf[0]);
  NVReadU16(Index + 1, &buf[1]);
}
//
static inline void NVWriteS32(U16 Index, S32 Value)
{
  NVWriteU32(Index, (U32)Value);
}
static inline void NVReadS32(U16 Index, S32 * Value)
{
  NVReadU32(Index, (U32*)Value);
}
//
static inline void NVWriteU64(U16 Index, uint64_t Value)
{
  NVWriteU16(Index, Value);
  NVWriteU16(Index+1, Value >> 16);
  NVWriteU16(Index+2, Value >> 32);
  NVWriteU16(Index+3, Value >> 48);
}
static inline void NVReadU64(U16 Index, uint64_t * Value)
{
  U16 * buf = (U16*)Value;
  NVReadU16(Index, &buf[0]);
  NVReadU16(Index + 1, &buf[1]);
  NVReadU16(Index + 2, &buf[2]);
  NVReadU16(Index + 3, &buf[3]);
}
//
static inline void NVWriteS64(U16 Index, int64_t Value)
{
  NVWriteU64(Index, (uint64_t)Value);
}
static inline void NVReadS64(U16 Index, int64_t * Value)
{
  NVReadU64(Index, (uint64_t*)Value);
}
//
static inline void NVWriteF32(U16 Index, F32 Value)
{
  NVWriteU32(Index, *(U32*)&Value);
}
static inline void NVReadF32(U16 Index, F32 * Value)
{
  NVReadU32(Index, (U32*)Value);
}
//
static inline void NVWriteF64(U16 Index, F64 Value)
{
  NVWriteU64(Index, *(uint64_t*)&Value);
}
static inline void NVReadF64(U16 Index, F64 * Value)
{
  NVReadU64(Index, (uint64_t*)Value);
}
#ifdef _NVSize
static inline U32 NVOUTUReadU32(U16 Index)
{
  return (_NVOUTU.u16[Index] & 0xFFFF) | (((U32)_NVOUTU.u16[Index+1] << 16) & 0xFFFF0000);
}
static inline S32 NVOUTUReadS32(U16 Index)
{
  return (S32)NVOUTUReadU32(Index);
}
static inline void NVOUTUWriteU32(U16 Index, U32 Value)
{
  _NVOUTU.u16[Index] = Value & 0xFFFF;
  _NVOUTU.u16[Index+1] = (Value>>16) & 0xFFFF;
}
static inline void NVOUTUWriteS32(U16 Index, S32 Value)
{
  NVOUTUWriteU32(Index, (U32)Value);
}
static inline F32 NVOUTUReadF32(U16 Index)
{
  return (F32)NVOUTUReadU32(Index);
}
static inline void NVOUTUWriteF32(U16 Index, F32 Value)
{
  NVOUTUWriteU32(Index, (U32)Value);
}
static inline uint64_t NVOUTUReadU64(U16 Index)
{
  return (*(uint64_t*)&(_NVOUTU.u16[Index]));
}
static inline void NVOUTUWriteU64(U16 Index, uint64_t Value)
{
  _NVOUTU.u16[Index] = Value & 0xFFFF;
  _NVOUTU.u16[Index+1] = (Value>>16) & 0xFFFF;
  _NVOUTU.u16[Index+2] = (Value>>32) & 0xFFFF;
  _NVOUTU.u16[Index+3] = (Value>>48) & 0xFFFF;
}
static inline int64_t NVOUTUReadS64(U16 Index)
{
  return (int64_t)NVOUTUReadU64(Index);
}
static inline void NVOUTUWriteS64(U16 Index, int64_t Value)
{
  NVOUTUWriteU64(Index, (uint64_t)Value);
}
static inline F64 NVOUTUReadF64(U16 Index)
{
  return (F64)NVOUTUReadU64(Index);
}
static inline void NVOUTUWriteF64(U16 Index, F64 Value)
{
  NVOUTUWriteU64(Index, (uint64_t)Value);
}
#endif
#endif
