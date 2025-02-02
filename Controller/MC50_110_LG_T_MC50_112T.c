/*Danfoss PLUS+1 GUIDE Software: [chpargu2] Version: 2024.2.4*/
/*Type: Educational       */
/*Id: 31977       */
/*Sub ID: 0       */
/*Maintenance until: 15-Sep-2025       */
/*Time limit: 15-Sep-2025       */
/*       */
/*       */
#include "header.h"
#ifdef R1
  //This is a workaround for HWD error: P1McX00000506:
  #undef R1
#endif
static void _FNC_123_b(void);
static BOOL aUN2;
static BOOL aUN7;
static BOOL aUN10;
static void _FNC_123_c(void);
extern U32 _OS_MicroSec(void);
static U32 _LoopStart;
static U32 _ExecTimeOut_us;
int LoopDeadlineTimePassed(void)
{
  U32 now = _OS_MicroSec();
  if( now < _LoopStart) {
    return 0xFFFFFFFF - _LoopStart + now > _ExecTimeOut_us;
  } else {
    return (now - _LoopStart) > _ExecTimeOut_us;
  }
}
static uint32_t _TimeSinceStartupInMilliSeconds = 0;
uint32_t GetTimeSinceStartupInMilliSeconds(void)
{
  return _TimeSinceStartupInMilliSeconds;
}

void _INITMAINTASK(void)
{
OS.ExecTimeOut = 1;
C1p06.PinConfig = 2;
C1p07.PinConfig = 2;
C1p10.PinConfig = 1;
C1p11.PinConfig = 1;
C1p12.PinConfig = 1;
C1p13.PinConfig = 2;
C1p14.PinConfig0 = 0;
C1p14.PinConfig1 = 0;
C1p14.DigInConfigHigh = 3000;
C1p14.DigInConfigLow = 2000;
C1p15.PinConfig0 = 0;
C1p15.PinConfig1 = 0;
C1p15.DigInConfigHigh = 3000;
C1p15.DigInConfigLow = 2000;
C1p16.PinConfig0 = 0;
C1p16.PinConfig1 = 0;
C1p16.DigInConfigHigh = 3000;
C1p16.DigInConfigLow = 2000;
C1p17.PinConfig0 = 0;
C1p17.PinConfig1 = 0;
C1p17.DigInConfigHigh = 3000;
C1p17.DigInConfigLow = 2000;
C1p18.PinConfig0 = 0;
C1p18.PinConfig1 = 0;
C1p18.DigInConfigHigh = 3000;
C1p18.DigInConfigLow = 2000;
C1p18.FreqConfig = 0;
C1p19.PinConfig0 = 0;
C1p19.PinConfig1 = 0;
C1p19.DigInConfigHigh = 3000;
C1p19.DigInConfigLow = 2000;
C1p23.PinConfig0 = 0;
C1p23.PinConfig1 = 0;
C1p23.DigInConfigHigh = 3000;
C1p23.DigInConfigLow = 2000;
C1p24.PinConfig0 = 0;
C1p24.PinConfig1 = 0;
C1p24.DigInConfigHigh = 3000;
C1p24.DigInConfigLow = 2000;
C1p24.FreqConfig = 0;
C1p25.PinConfig0 = 0;
C1p25.PinConfig1 = 0;
C1p25.DigInConfigHigh = 3000;
C1p25.DigInConfigLow = 2000;
C1p26.PinConfig0 = 0;
C1p26.PinConfig1 = 0;
C1p26.DigInConfigHigh = 3000;
C1p26.DigInConfigLow = 2000;
C1p27.PinConfig = 0;
C1p28.PinConfig = 0;
C1p29.PinConfig = 0;
C1p30.PinConfig = 0;
CAN[0].Baudrate = 250000;
ID.Net[0].Addr = 0;
ID.Node.ServerAddr = 3;
CAN[1].Baudrate = 250000;
ID.Net[1].Addr = 1;
C1p37.PinConfig = 0;
C1p37.CurChgLim = 111;
C1p38.PinConfig = 0;
C1p39.PinConfig = 0;
C1p40.PinConfig = 0;
C1p41.PinConfig = 0;
C1p42.PinConfig = 0;
C1p42.CurChgLim = 111;
C1p43.PinConfig = 0;
C1p44.PinConfig = 0;
C1p45.PinConfig = 0;
C1p46.PinConfig = 0;
}
void _EndLoop_MAINTASK(void){
}
void _BeginLoop_MAINTASK(void){
}
static void _FNC_123_b(void)
{
       BOOL aUN31;
       U8 aUN34;
  S32 _ShLocTmpVar_S32_1;
       U8 aUN30;
static U8 aUN35;
       BOOL aUN32;
       BOOL aUN26;
static BOOL aUN26Old1;
static U16 aUN26Old2;
static BOOL aUN25;
       BOOL aUN24;
static BOOL aN274;
static BOOL aN274Old1;
       BOOL aUN19;
       U8 aUN22;
       U8 aUN18;
static U8 aUN23;
       BOOL aUN20;
       BOOL aUN14;
static BOOL aUN14Old1;
static U16 aUN14Old2;
static BOOL aUN13;
       BOOL aUN12;
static BOOL aN273;
static BOOL aN273Old1;
static U8 aUN10Old1;
static U8 aUN10Old2;
C1p06.PinConfig = 2;
C1p07.PinConfig = 2;
C1p10.PinConfig = 1;
C1p11.PinConfig = 1;
C1p12.PinConfig = 1;
C1p13.PinConfig = 2;
C1p14.PinConfig0 = 0;
C1p14.PinConfig1 = 0;
C1p14.DigInConfigHigh = 3000;
C1p14.DigInConfigLow = 2000;
C1p15.PinConfig0 = 0;
C1p15.PinConfig1 = 0;
C1p15.DigInConfigHigh = 3000;
C1p15.DigInConfigLow = 2000;
C1p16.PinConfig0 = 0;
C1p16.PinConfig1 = 0;
C1p16.DigInConfigHigh = 3000;
C1p16.DigInConfigLow = 2000;
C1p17.PinConfig0 = 0;
C1p17.PinConfig1 = 0;
C1p17.DigInConfigHigh = 3000;
C1p17.DigInConfigLow = 2000;
C1p18.PinConfig0 = 0;
C1p18.PinConfig1 = 0;
C1p18.DigInConfigHigh = 3000;
C1p18.DigInConfigLow = 2000;
C1p18.FreqConfig = 0;
C1p19.PinConfig0 = 0;
C1p19.PinConfig1 = 0;
C1p19.DigInConfigHigh = 3000;
C1p19.DigInConfigLow = 2000;
C1p23.PinConfig0 = 0;
C1p23.PinConfig1 = 0;
C1p23.DigInConfigHigh = 3000;
C1p23.DigInConfigLow = 2000;
C1p24.PinConfig0 = 0;
C1p24.PinConfig1 = 0;
C1p24.DigInConfigHigh = 3000;
C1p24.DigInConfigLow = 2000;
C1p24.FreqConfig = 0;
C1p25.PinConfig0 = 0;
C1p25.PinConfig1 = 0;
C1p25.DigInConfigHigh = 3000;
C1p25.DigInConfigLow = 2000;
C1p26.PinConfig0 = 0;
C1p26.PinConfig1 = 0;
C1p26.DigInConfigHigh = 3000;
C1p26.DigInConfigLow = 2000;
C1p27.PinConfig = 0;
C1p28.PinConfig = 0;
C1p29.PinConfig = 0;
C1p30.PinConfig = 0;
aUN31=CAN[0].DriverError | CAN[0].BussOff;
  _ShLocTmpVar_S32_1 = !(aN274);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN34 = 1;
      break;
    default:
      aUN34 = 0;
  }
aUN30 = (aUN35)+(aUN34);
  _ShLocTmpVar_S32_1 = !(aUN31);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN35 = aUN30;
      break;
    default:
      aUN35 = 0;
  }
if ((aN274 == 0 && aUN31 == 0) || (aN274 != 0 && aUN31 != 0)) 
aUN32=0;
else
aUN32=1;
if (aUN32 && !aUN26Old1)
aUN26Old2 = 1000;
if (aUN26Old2 > _ElapsedTime[T1M])
{
aUN26Old2 = aUN26Old2 - _ElapsedTime[T1M];
aUN26=0;
}
else
{
aUN26Old2 = 0;
aUN26=aUN32;
}
aUN26Old1 = aUN32;
if (5 <= aUN35)
aUN25=0;
if ((5) > aUN35)
aUN25=1;
aUN24=aUN26 && aUN25;
if (aUN24 && !aN274Old1)
aN274=1;
else
aN274=0;
aN274Old1 = aUN24;
CAN[0].Reset=CAN[0].BussOff && aN274;
CAN[0].DriverReset=CAN[0].DriverError && aN274;
CAN[0].Baudrate = 250000;
aUN19=CAN[1].DriverError | CAN[1].BussOff;
  _ShLocTmpVar_S32_1 = !(aN273);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN22 = 1;
      break;
    default:
      aUN22 = 0;
  }
aUN18 = (aUN23)+(aUN22);
  _ShLocTmpVar_S32_1 = !(aUN19);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN23 = aUN18;
      break;
    default:
      aUN23 = 0;
  }
if ((aN273 == 0 && aUN19 == 0) || (aN273 != 0 && aUN19 != 0)) 
aUN20=0;
else
aUN20=1;
if (aUN20 && !aUN14Old1)
aUN14Old2 = 1000;
if (aUN14Old2 > _ElapsedTime[T1M])
{
aUN14Old2 = aUN14Old2 - _ElapsedTime[T1M];
aUN14=0;
}
else
{
aUN14Old2 = 0;
aUN14=aUN20;
}
aUN14Old1 = aUN20;
if (5 <= aUN23)
aUN13=0;
if ((5) > aUN23)
aUN13=1;
aUN12=aUN14 && aUN13;
if (aUN12 && !aN273Old1)
aN273=1;
else
aN273=0;
aN273Old1 = aUN12;
CAN[1].Reset=CAN[1].BussOff && aN273;
CAN[1].DriverReset=CAN[1].DriverError && aN273;
CAN[1].Baudrate = 250000;
C1p33.DigOut=C1p12.DigIn && C1p11.DigIn && C1p10.DigIn;
aUN2=CAN[1].BussOff | CAN[0].BussOff;
aUN7=CAN[1].DriverError | CAN[0].DriverError;
if (1==0)
{
aUN10Old1 = 0;
aUN10=0;
}
else
{
if (aUN10Old1 > _ElapsedTime[T100M])
aUN10Old1 = aUN10Old1 - _ElapsedTime[T100M];
else
{
if ((aUN10== 0) || ((1!=0)&&(aUN10Old2 == 0)) )
{if (10 > 2){
aUN10Old1 = 2;
aUN10Old2 = 10 - 2;
}else{
aUN10Old1 = 10;
aUN10Old2 = 0;}
if ((aUN10Old1 ==0) && (10 != 0))
aUN10=0;
else
aUN10=1;
}
else
{
aUN10=0;
aUN10Old1 = aUN10Old2;
}
}
}
}
static void _FNC_123_c(void)
{
       BOOL aN231;
       BOOL aUN11;
       BOOL aUN8;
       BOOL aUN9;
       BOOL aN232;
  S32 _ShLocTmpVar_S32_1;
aN231=aUN2 | aUN7;
aUN11=!aUN10;
aUN8=aUN2 && aUN10;
aUN9=aUN7 && aUN11;
aN232=aUN9 | aUN8;
  _ShLocTmpVar_S32_1 = !(aN231);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      Led.Red = aN232;
      break;
    default:
      Led.Red = 0;
  }
Led.Green = 1;
C1p31.DigOut = 0;
C1p32.DigOut = 0;
C1p34.DigOut = 0;
C1p35.DigOut = 0;
C1p36.DigOut = 0;
C1p37.PinConfig = 0;
C1p37.CurChgLim = 111;
C1p37.DitherFreq = 0;
C1p37_C1p40.ReqFreq = 4000;
C1p37.DigOut = 0;
C1p37.OutputValue = 0;
C1p37.DitherAmp = 0;
C1p38.PinConfig = 0;
C1p38.DitherFreq = 0;
C1p38.DigOut = 0;
C1p38.OutputValue = 0;
C1p38.DitherAmp = 0;
C1p39.PinConfig = 0;
C1p39.DitherFreq = 0;
C1p39.DigOut = 0;
C1p39.OutputValue = 0;
C1p39.DitherAmp = 0;
C1p40.PinConfig = 0;
C1p40.DitherFreq = 0;
C1p40.DigOut = 0;
C1p40.OutputValue = 0;
C1p40.DitherAmp = 0;
C1p41.PinConfig = 0;
C1p41.DigOut = 0;
C1p41.OutputValue = 0;
C1p42.PinConfig = 0;
C1p42.CurChgLim = 111;
C1p42.DitherFreq = 0;
C1p42_C1p45.ReqFreq = 4000;
C1p42.DigOut = 0;
C1p42.OutputValue = 0;
C1p42.DitherAmp = 0;
C1p43.PinConfig = 0;
C1p43.DitherFreq = 0;
C1p43.DigOut = 0;
C1p43.OutputValue = 0;
C1p43.DitherAmp = 0;
C1p44.PinConfig = 0;
C1p44.DitherFreq = 0;
C1p44.DigOut = 0;
C1p44.OutputValue = 0;
C1p44.DitherAmp = 0;
C1p45.PinConfig = 0;
C1p45.DitherFreq = 0;
C1p45.DigOut = 0;
C1p45.OutputValue = 0;
C1p45.DitherAmp = 0;
C1p46.PinConfig = 0;
C1p46.DigOut = 0;
C1p46.OutputValue = 0;
}

static void _BeginModule_MAINTASK(void){
  _LoopStart      = _OS_MicroSec();
  _ExecTimeOut_us = OS.ExecTimeOut * 1000;
  _TimeSinceStartupInMilliSeconds = _ElapsedTime[T1M] + _TimeSinceStartupInMilliSeconds;

}

void _MAINTASK(void)
{
  _BeginLoop_MAINTASK();

  _BeginModule_MAINTASK();

_FNC_123_b();
_FNC_123_c();

  _EndLoop_MAINTASK();
}
