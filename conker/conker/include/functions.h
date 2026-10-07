#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ultra64.h>

#include "structs.h"

extern f32 fabsf(f32);
#pragma intrinsic (fabsf)

/* matching */
void func_10001050();
void func_100010F8();
void func_10001444();
void func_100014A0();
s32  func_10002070();
void func_1000349C();
s32  func_1000390C();
void func_10003930();
void func_100039B0();
void func_100039C0();
void func_10004250();
void func_10004308();
void func_1000440C();
void func_10004470();
s32  func_10004514();
void func_10004674();
void func_10004F00();
void func_10004FE0();
void func_10005020();
void func_100051C8();
void func_100051E8();
void func_10005218();
void func_10005298();
void func_100084D8(u8 idx);
s32  func_1000853C(u8 idx);
void func_10008570(u8 idx, s32 arg1);
void func_100085A4();
void func_100085B8(u8 idx, s32 arg1, u8 arg2);
void func_100085F8(u8 idx, s32 arg1);
void func_1000862C(u8 idx, s32 arg1);
void func_10008660(u8 idx, u8 chan, u8 arg2, s32 arg3);
void func_100086FC(u8 idx, u8 arg1, u8 arg2);
void func_10008744(u8 idx, u8 arg1, u8 arg2);
void func_10008790(u8 idx, s32 mask, u8 arg2, s32 arg3);
void func_10008824(u8 idx, u8 arg1, u8 arg2);
void func_1000886C(u8 idx, s32 mask, u8 arg2);
void func_100088F0(u8 idx, s32 mask, s32 enable);
void func_10008988(u8 idx, s32 mask, s32 enable);
u8   func_10008A4C(u8 idx, u8 chan);
void func_10008A94(u8 idx, s32 mask, s32 arg2);
void func_10008B2C(u8 idx);
void func_10008B60(u8 idx, u8 arg1, u8 arg2, u8 arg3, s32 arg4);
void func_10008BC0(u8 idx, f32 arg1, f32 arg2);
void func_10008EE0(u8 idx, s32 arg1);
void func_10008F24(u8 idx);
void func_10008F58(u8 idx);
void func_100093CC();
s32  func_10009980();
void func_10009B2C();
void func_10009B4C();
void func_10009B90();
s32  func_1000BA18(u32 arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4);
struct151 *func_1000B1B0();
s32  func_1000B830();
s32  func_1000B8B8(s32 arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4);
s32  func_1000BBE8();
s32  func_1000BC28(s32 arg0, u8 arg1, s32 arg2, s32 arg3);
void func_1000CBA8();
s32  func_1000CD40();
void func_1000E054();
s32  func_1000E0F8();
void func_1000E40C();
s32  func_1000E654();
s32  func_1000E704();
void func_1000E75C();
s32  func_1000E770();
u16  func_1000EA94();
s32  func_1000EB00();
s32  func_1000EBC4();
s32  func_1000EF40();
void func_1000F248();
s32  func_1000F3D0(u16 arg0);
s32  func_1000F44C(u16 arg0);
void func_1000F91C(u16 arg0, u16 arg1, s16 arg2, u8 arg3, s32 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9);
void func_1000F9D4(u16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_10010720(u16 arg0, struct127 *arg1, s32 arg2, s16 arg3, u16 arg4, s32 arg5);
s32  func_100107F8();
s32  func_10010894();
void func_100109D0();
void func_10010A3C();
void func_10010AA8();
s32 func_10010F30(s32 arg0, u16 arg1, u8 arg2, s16 arg3, u8 arg4);
void func_100111C8(u16 arg0);
void func_1001123C(u16 arg0);
s32  func_100112BC();
s32  func_1001147C(u16 arg0);
void func_10011E88();
void func_10011E94();
void func_10011FA0();
void func_10011FB0();
void func_10011FDC();
void func_10011FEC();
void func_10012560();
void func_10012588();
void func_100125CC();
void func_1001263C();
s32 func_100126E8();
s32  func_10012718(u16 arg0, struct127 *arg1, s32 arg2, s16 arg3, u16 arg4);
s32  func_100127D0();
void func_10012A28();
void func_10012B84();
void func_10012BD0();
void func_10012C5C();
void func_10012CFC();
f32  func_10012D80(u8 arg0);
s32  func_10012E04();
s32  func_10012F94();
void func_100131D8();
void func_100131FC();
void func_10015550();
s32  func_10015878();
void func_10016E90();
void func_10016F00();
struct31 *func_10017100();
void func_10017298();
s32  func_100173C4();
void func_10017594();
void func_100176C4();
void func_100176EC();
void func_10017714();
void func_10017870();
void func_10017944();
s32  func_10017A80();
void func_10017AA0();
void func_10017AF0();
void func_10017B04(void *, s32 chan, u8 arg2);
void func_10017B30();
void func_10017BB8();

void func_10017D80(void *, u8 chan, u8 prog);
void func_10017DF0(void *, f32 arg1, f32 arg2);
void func_10017E4C(void *, u8 chan, u8 arg2);
void func_10017F10(void *, u8 arg1, u8 arg2, u8 arg3, s32 arg4);

void n_alInit();
void n_alClose();
s32  _n_timeToSamplesNoRound();
s32  _n_timeToSamples();
f32  alCents2Ratio();
void func_10019B50();
void func_10019C28();
void func_10019CD0();
void func_10019D6C();
void func_10019ED8();
void func_10019F38();
void func_10019F98();
void func_1001A224();
void func_1001A2F8();
void func_1001A39C();
void func_1001A3E0();
void func_1001A3FC();
void func_1001A9DC();
void func_1001AA08();
s32  __n_vsDelta();
void func_1001B620();
void func_1001CBF0(f32 arg0, f32 arg1, f32 arg2, f32 arg3[3], f32 arg4[3]);
void func_1001CD54();
f32  func_1001CEA4();
void func_1001D6E8(struct42 *arg0, s32 (*arg1)(s32 arg), struct15 *arg2);
s32  func_1001D9B0(s16 arg0);
s32  func_1001DA28();
void func_1001DAA0();
void func_1001DAE4(void *, s16 arg1, s32 *arg2);
// void func_1001E170(struct22 *arg0, s32 *w, f32 pitch, s16 vol, u8 pan, u8 fxmix, u8 arg6, f32 arg7, u8 arg8, s32 arg9);
// void func_1001E400(struct26 *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4);
s32  func_1001E4A0();
f32  func_1001FA78(f32 arg0[4][4], s32 arg1);
/* chunk0 */
void func_15000000();
void func_15000090();
void func_15000AC0();
void func_15001B08();
u16* func_15001B10();
void func_15001BC8();
void func_15001970();
void func_150026C4();
void func_150026E8();
void func_15002724();
s32  func_150027F8();
void func_15002F40();
s32  func_15002FA0();
void func_15002FB4();
void func_1500310C();
s32  func_150034B4();
void func_150038A0();
s32  func_1500390C();
void func_150039B0();
void func_150039BC();
void func_150045BC();
void func_15004E00();
void func_15004E80();
void func_15004F00();
void func_15004F10();
void func_15004F30();
void func_15005270();
void func_15005A60();
void func_15005AB0();
void func_15005AF0();
void func_15005B00();
void func_15005B10();
void func_15005B50();
void func_15005B60();
void func_15005B70();
void func_15005BD0();
void func_15005C30();
void func_15005C80();
void func_15005CF0();
void func_15005D00();
void func_15005D60();
void func_15005DB0();
void func_15005E30();
void func_15005E70();
void func_15005EA0();
void func_15005EE0();
void func_15005F20();
void func_15005F60();
void func_15005FA0();
void func_15005FB0();
void func_15006010();
void func_15006140();
void func_15006170();
void func_150061B0();
void func_150064E0();
void func_15007644();
void func_1500764C();
void func_15007668();
void func_15007684();
void func_150076A0();
void func_150076BC();
void func_15007718();
void func_15007750();
void func_15007A20();
void func_15007A70();
void func_150081E4();
void func_15008230();
void func_15008248();
void func_150082CC();
void func_15008840();
void func_15008A10();
void func_15008B90();
void func_15008BB0();
void func_15008BE0();
void func_15008DD0();
void func_15008E00();
void func_15009150();
void func_150095D8();
void func_15009600();
void func_1500969C();
void func_15009740();
void func_15009768();
void func_150097A4();
void func_150097CC();
void func_15009818();
void func_15009844();
void func_15009870();
void func_15009894();
void func_150098D0();
void func_150098F8();
void func_15009944();
void func_15009AA0();
void func_15009AEC();
void func_15009B38();
void func_15009B84();
void func_15009D28();
void func_15009D6C();
void func_15009DB0();
void func_15009DFC();
void func_15009E48();
void func_15009E84();
void func_15009EC8();
void func_15009EF4();
void func_15009F30();
void func_1500A028();
void func_1500A06C();
void func_1500A0B0();
void func_1500A0FC();
void func_1500A148();
void func_1500A194();
void func_1500A1E0();
void func_1500A21C();
void func_1500A260();
void func_1500A33C();
void func_1500A380();
void func_1500A3C4();
void func_1500A410();
void func_1500A454();
void func_1500A490();
void func_1500A4D4();
void func_1500A518();
void func_1500A55C();
void func_1500A5A8();
void func_1500A5F4();
void func_1500A640();
void func_1500A68C();
void func_1500A79C();
void func_1500A8C8();
void func_1500A904();
void func_1500A94C();
void func_1500A990();
void func_1500AB5C();
void func_1500ABA0();
void func_1500BE40();
void func_1500BE68();

void func_1500EB20();
void func_1500EB30();
void func_1500EBC4();
void func_1500ED80();
void func_1500EE18();
void func_1500EE94();
void func_1500EF20();

void func_15010240();
void func_150102C0();
void func_150102D0();
void func_150103E0();
void func_15010538();
void func_15010680();
void func_150106A0();
void func_150106B0();
s32  func_150106D0();
void func_15010780();
void func_15010FB0();
void func_150110F0();
void func_15011170();
void func_15011330();
void func_15011360();
void func_15011A78();
void func_15011B00();
void func_15011B94();
void func_15011C40();
void func_15011C70();
void func_15011CA0();
void func_15011CC0();
void func_15011F20();
void func_15011FA0();
void func_15012020();
u8   func_15012720();
void func_15012770();
void func_15012780();
s32  func_150150A4();
s32  func_15015300();
void func_15016370();
void func_15016500();
void func_15017300(s16 arg0, s16 arg1);
void func_150175E0();
void func_15017790();
void func_150177F8();
void func_1501C860();
void func_1501C870();

void func_15040350();
s32  func_1504082C();
void func_150408CC();
void func_15042D50();
void func_15042D78(u8 arg0);
void func_15042ECC();
void func_150432BC(f32 arg0);
void func_150432CC();
void func_150432FC(s16 arg0, s16 arg1);
void func_1504332C(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_15043A00();
void func_15043D90(Mtx *m, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
void func_15043E68(Mtx *m, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_15043EC8(f32 mtx[4][4], f32 x, f32 y, f32 z, f32 arg4, f32 arg5, f32 arg6);
void func_15043FF0();
void func_150442C0(f32 arg0[4][4], f32 x, f32 y, f32 z);
void func_15047F00();
void func_1504715C();
void func_15048134();
f32  func_150484A0(f32 arg0, f32 arg1);
u16  func_15048664(s16 arg0);
s16  func_150486B8(s16 arg0);
f32  func_15048360(f32 arg0);
f32  func_15048408(f32 arg0);
f32  func_15048720(f32 arg0, f32 arg1, f32 arg2);
void func_15048758();
f32  func_150487E0(f32 arg0);
f32  func_15048864(f32 arg0);
f32 func_150489B0(u8 arg0);
f32 func_15048A40(u8 arg0);
f32  func_15048A70(f32 arg0, f32 arg1);
s32  func_15048AD0();
void func_15048B10();
void func_15048F20();
void func_15048F58();
void func_15048F90();
void func_15049148(struct17 *arg0, f32 arg1, struct17 *arg2);
void func_1504917C();
void func_150491EC();
void func_150492CC(f32 arg0, f32 arg1, f32 arg2);
s32 func_15049440(f32 arg0[4][4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
f32  func_1504A5E0();
s32  func_1504AEF4();
s32  func_1504C078();
s32  func_1504C0B8();
void func_1504C854();

void func_15052408();
void func_15052458();
void func_15052464();
void func_15052490(struct127 *arg0, u16 arg1, f32 arg2, f32 arg3);
void func_15052EF0();
struct127 *func_15052F58();
void func_15053694();
void func_150536D0();
void func_150536E8();
void func_1505371C();
void func_15055D48();
void func_15056150();
void func_15056258();
s32  func_1505693C();
void func_15058EA4(struct127 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_15059140();
void func_1505A184(s32 arg0, f32 arg1, f32 arg2, f32 *arg3, f32 *arg4, f32 *arg5);
void func_150593C4(struct127 *arg0, u16 arg1, f32 arg2, f32 arg3);
void func_15059444();
void func_1505959C();
f32  func_1505A5CC();
u16  func_1505A630(f32 arg0, f32 arg1, s32 arg2);
f32  func_1505A6F8();
s16  func_1505C140();
void * func_1505D024();
void func_1505D2B8(struct127 *arg0, u8 arg1);
f32  func_1505D34C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4);

void func_15060B70();
void func_150615DC();
void func_150627D4();
void func_15062AC4();
void func_15062B1C(struct127 *arg0, f32 arg1);
void func_15062B50(struct127 *arg0, f32 arg1);
void func_15062B84();
void func_15062BDC(struct127 *arg0, f32 arg1, f32 arg2);
void func_1506AF74();
void func_1506AFE0();
void func_1506B020();
void func_1506B070();
void func_1506B078();
void func_1506B100(s32 arg0, f32 arg1, f32 arg2);
void func_1506B14C();
void func_1506B198();
void func_1506B1E8();
void func_1506B228();
void func_1506B268();
void func_1506B2BC();
void func_1506B328();
void func_1506B368();
void func_1506B370();
void func_1506B3B0();
void func_1506B4EC();
void func_1506B50C();
void func_1506B520();
void func_1506B5A4();
void func_1506B5AC();
void func_1506B5B4();
void func_1506B5CC();
void func_1506B5E4();
void func_1506B740();
void func_1506B7F4();
void func_1506B82C();
void func_1506B860();
void func_1506B88C();
void func_1506B8B4();
void func_1506B8F4();
void func_1506B91C();
void func_1506B944();
void func_1506B984();
void func_1506B9AC();
void func_1506BA4C();
void func_1506BAD8();
void func_1506BB64(s32 arg0, s32 arg1);
void func_1506BBA8();
void func_1506BC24();
void func_1506BCA0();
void func_1506BDE8();
void func_1506BE2C();
void func_1506BE54();
void func_1506BE84();
void func_1506BE98();
void func_1506BEC0();
void func_1506BEDC();
void func_1506BF1C();
void func_1506C418();
void func_1506C43C();
void func_1506D4EC();
void func_1506D4F4();
void func_1506D538();
void func_1506D570();
void func_1506D934();
void func_1506D950();
void func_1506DA78();
void func_1506DA94();
void func_1506DB30();
void func_1506DB5C();
void func_1506DB84();
void func_1506DBD4();
void func_1506DCA4();
void func_1506DCC0();
void func_1506DCDC();
void func_1506DCF8();
void func_1506DD44();
void func_1506DD6C();
void func_1506DDB8();
void func_1506DDC0();
void func_1506DE04();
void func_1506E5FC();
void func_1506E63C();
void func_1506E67C();
void func_1506E6BC();
void func_1506E6FC();
void func_1506E73C();
void func_1506E77C();
void func_1506E7BC();
void func_1506E7FC();
void func_1506E848();
void func_1506E898();
void func_1506E8D8();
void func_1506E918();
void func_1506E958();
void func_1506E998();
void func_1506E9D8();
void func_1506EA18();
void func_1506EA58();
void func_1506EC50();
void func_1506ECD0();
void func_1506ECF0();
void func_1506ED0C();
void func_1506ED4C();
void func_1506ED68();
void func_1506ED90();
void func_1506EDAC();
void func_1506EDC8();
void func_1506EDF0();
void func_1506EE14();
void func_1506EE38();
void func_1506EEAC();
void func_1506EED8();
void func_1506EFB4();
void func_1506EFC8();
void func_1506F004();
void func_1506F02C();
void func_1506F05C();
void func_1506F090();
void func_1506F0C4();
void func_1506F0F0();
void func_1506F11C();
void func_1506F14C();
void func_1506F17C();
void func_1506F524();
void func_1506F8C0();
void func_1506FB60();
void func_1506FBE8();
void func_1506FC1C();
void func_1506FC50();
void func_1506FC74();
void func_1506FC9C();
void func_1506FCC8();
void func_1506FCFC();
void func_1506FDF0();
void func_1506FE1C();
void func_1506FE48();
void func_1506FE74();
void func_1506FEA0();
void func_1506FECC();
void func_1506FEF8();
void func_1506FF24();
void func_1506FF50();
void func_1506FF78();
void func_1506FFAC();
void func_1506FFE0();
void func_15070014();
void func_1507003C();
void func_15070084();
void func_150700B4();
void func_150700E4();
void func_15070114();
void func_15070144();
void func_150701C4();
void func_150701F4();
void func_15070690();
void func_150706C4();
void func_150706F8();
void func_15070760();
void func_15070794();
void func_150707C8();
void func_150707F8();
void func_15070830();
void func_15070860();
void func_15070C18();
void func_15070CDC();
void func_15070D00();
void func_15071230();
void func_15071254();
void func_15071278();
void func_15071434();
void func_15071470();
void func_150714AC();
void func_150714E8();
void func_15071544();
void func_1507158C();
void func_150715D4();
void func_1507161C();
void func_15071628();
void func_15071668();
void func_15071690();
void func_150716EC();
void func_15071764();
void func_15071830();
void func_15071860();
void func_15071888();
void func_15071998();
void func_150719CC();
void func_15071A00();
void func_15071A34();
void func_15071D08();
void func_15071D38();
void func_15071D78();
void func_15071DC8();
void func_15071DF4();
void func_15071E20();
void func_15071E3C();
void func_15071E58();
void func_15071ED4();
void func_15071F14();
void func_15071F54();
void func_15071F80();
void func_15071FB0();
struct127 *func_150721E8();
void func_1507233C();
void func_15072360();
void func_15072388();
void func_150723AC();
void func_150723E0();
void func_150727AC();
void func_15072918();
void func_15072940();
void func_15072968();
void func_150729B4();
void func_150729D0();
void func_15072A14();
void func_15072A40();
void func_15072A7C();
void func_15072AF8();
void func_15072DD8();
void func_15072E38();
void func_15072E7C();
void func_15072E98();
void func_15072EC0();
void func_15072EF4();
void func_1507304C();
void func_15073054();
void func_15073070();
void func_15073078();
void func_150730A4();
void func_150739A4();
void func_150739C0();
void func_15073A28();
void func_15073C28();
void func_15073C48();
void func_15073CB8();
void func_15073CF4();
void func_15073D34();
void func_15073D74();
void func_15073DA4();
void func_15073E2C();
void func_15073EA4();
void func_15073F1C();
void func_15073F54();
void func_15073F5C();
void func_15073F78();
void func_15074644();
void func_15074840();
void func_15074870();
void func_150748F4();
void func_15074A44();
void func_15074A6C();
void func_15074B7C();
void func_15074BD8();
void func_15074BEC();
void func_15074C00();
void func_15074DEC();
void mvmt_imp_set_up_smoke_15074E04();
void func_15074E80();
void func_15074EE8();
void func_15074F30();
void func_15074FD4();
void func_15075050();
void func_150750A4();
void func_150750C4();

void func_15075498();
void func_15075A50();
void func_15075B60() ;

void func_1508F9C4();

void func_15093818();
void func_15093878();
void func_1509B4A0();
void func_1509BFB0();
void func_150AECCC();
void func_150AED4C();
s32  func_150C3D48();
void func_150CEF10();

void func_150DE310();
void func_150DE32C(void); // dummy
void func_150DEC90();
void func_150EB430();
void func_150EC4B0();
void func_150F51A0();
s32  func_150F51BC();
void func_150F51E8();
void func_150FE860();
void func_150FCA00();

void func_15100330();
void func_15103800();
void func_15103828();
void func_1510550C(struct102 *arg0, s32 arg1, u8 arg2);
void func_15105548(struct207 *arg0, s32 *arg1, u8 arg2);
void func_15105848(struct207 *arg0, s32 arg1, u8 arg2);
void func_15109064(void *arg0, void *arg1, s32 arg2);
void func_1511FC20();
s32  func_1511FC2C();
s32  func_1511FC44();
void func_15122AE0();
void func_15124B18();
void func_15123508();
void func_15124770();
void func_15124AB4();
void func_1512523C();
void func_15125330();
void func_15125394();
s32  func_151253CC();
void func_15125594();
void func_15125608();
void func_15125690();
void func_15126138();
void func_15127FEC();
void func_15128680();
void func_1512868C();
void func_15128774();
void func_1512D380();
s32  func_1513416C();

struct210 *func_1513C4EC(s32 arg0, s32 arg1, u8 arg2, u8 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u8 arg9, u8 argA, s32 argB, s32 argC, s32 argD, u8 argE, s32 argF);
struct210 *func_1513C5B0(s32 arg0, s32 arg1, u8 arg2, u8 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u8 arg9, u8 argA, s32 argB, u8 argC, s32 argD);
struct210 *func_1513C650(s32 arg0, u8 arg1, u8 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u8 arg9, u8 argA, s32 argB, s32 argC, s32 argD, u8 argE, s32 argF);
struct210 *func_1513C73C(s32 arg0, u8 arg1, u8 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u8 arg9, u8 argA, s32 argB, u8 argC, s32 argD);
struct210 *func_1513C804(s32 arg0, s32 arg1, u8 arg2, u8 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, u8 argA, u8 argB, s32 argC, u8 argD, s32 argE);
void func_1513C8D4();
void func_1513C900();
void func_1513C92C();
void func_1513C9B0();
void func_1513C9FC();
void func_1513CA48();
void func_1513CA6C();
void func_1513CAA0();
void func_1513CAD4();
void func_1513CB58();
void func_1513CBA4();
void *func_1513D4B8(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, s32 arg7, u8 arg8, s32 arg9);
void *func_1513D524(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s32 arg6, u8 arg7, s32 arg8);
s32  func_1513D594(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s16 arg6, f32 arg7, f32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, u8 argD, s32 argE, u8 argF, s32 arg10);
void *func_1513D668(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, s16 arg6, f32 arg7, f32 arg8, s32 arg9, s32 argA, u8 argB, s32 argC, u8 argD, s32 argE);
void func_1513E070();
void func_1513E084(struct210 *arg0, struct212 *arg1, u8 arg2);
void func_1513E134();
void func_1513E2A4();
void func_1513EDB4(s32 arg0, s16 arg1);
s32 func_1513EDE4(s32 arg0, s16 arg1);
void func_1513F4B0(struct210 *arg0, s16 arg1);
void func_151403A8(s32 arg0, u8 arg1);
void func_151403DC(s32 arg0, u8 arg1);
void func_151411A4();
void func_151411C4();
void func_151411E4();
void func_15141250();
s32  func_15141818();
void func_15141970();
void func_15141990();
void func_151419B0();
void func_15141DA4();
s32  func_151422C0();
s32  func_151422DC();
s32  func_151422F8();
void * func_15143134();
s32  func_15143E08();
s32  func_15144C2C(s16 arg0);
f32  func_15144C8C(f32 arg0, f32 arg1);
void func_151450B4();
s32  func_151454BC(u8 arg0, f32 arg1, struct17 *arg2);
f32  func_15145A0C(f32 arg0, f32 arg1, f32 arg2);
void func_15145A50();
void func_15146508();
void func_151467A4(f32 *arg0, f32 arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 *arg7);
struct260 *func_15149130(s16 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, struct37 *arg6, u8 arg7, s32 arg8);
struct260 *func_151491F4(s16 arg0, s8 arg1, s8 arg2, u8 arg3, u8 arg4, struct37 *arg5, u8 arg6, s32 arg7);
void func_15149318();
void func_1514933C();
void func_15149368();
void func_15149394();
void func_151493E4();
void func_15149434(struct260 *arg0, s32 arg1, u8 arg2);
s32  func_15149490(s32 arg0, struct260 *arg1, s16 arg2);
void func_151494E0(s32 arg0, u8 arg1);
void func_15149514(s32 arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_15165F70();
s32 func_1516972C(struct102 *arg0);
void func_1516979C(struct102 *arg0);
void func_15169804();
void func_15169824();
void func_1519EF70();
void func_151C329C();

void func_151DB004();
void func_151DB068();
void func_151DB0CC();
void func_151DB15C();
void func_151DB1EC();
void func_151DB27C();
void func_151DB2A8();
void func_151DB2CC();
void func_151DB330();
void func_151DB3D8();
void func_151DB43C();
void func_151DBBD4(struct17 *arg0, s32 arg1, u8 *arg2, u8 arg3, s32 arg4);
void func_151DC484(void *arg0, void *arg1, u8 arg2, u8 arg3, s32 arg4);
void func_151F0080();
void func_151F00E0();

void func_16000000();
s32  func_16000028();
void func_16000058();
s32  func_16000224();
void func_16000304();
void func_1600030C();
void func_16000314();
s32  func_16000384();
void func_16000424();
void func_160012B0();
void func_16001338();
s32  func_160016F4();
s32  func_16001984();
s32  func_160019A8();
void func_16001A64();
s32  func_16001A6C(f32 arg0);
void func_16001AB0();
u8*  func_16001AD0();
s32  func_16001B8C();


/* non-matching */

void func_10001194();
void func_10001420();
void func_100014C4();
void func_10001550();
// s16  func_100019F0(s16 *arg0, struct05 *arg1);
//func_10001AA8
// s32  func_100020D0(s32 *arg0, s32 arg1, s32 *arg2, s32 arg3);
//func_10002718
// s32  func_10002DB0(s32 arg0, s32 arg1);
//func_10002E50
void func_100030A0();
struct00* func_10003220();
void func_10003330();
//func_100034E0
//func_10003658
// void func_100038C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
// void func_100038E0(void);
void func_10003920();
// void func_10003BD0(void);
//func_10003ACC
s32 func_10003C6C();
//func_10004074
void func_100043B4(void *arg0, s32 arg1);
//func_100046E4
void func_1000480C();
void func_100049E0();
//func_10004DB0
void func_100050A0();
void func_100052A0();
//func_10005570
//func_100056A0
//func_100057E0
//func_10005948
//func_10005AB0
void func_10005B04();
//func_10005BE0
//func_10005C2C
void func_1000709C();
//func_10007C74
//func_10007CC4
//func_10007D28
//func_10007DA0
//func_10007DAC
//func_10008120
//func_10008180
//func_10008B60
//func_10008BC0
//func_10008C04
void func_10008C6C(u8 idx, u8 arg1);
//func_10008CE8
//func_10008F90
void func_10009400();
//func_100095A0
s32 func_100097CC();
//func_100099BC
void func_10009BE4();
s32 func_10009CBC();
s32  func_10009FFC();
//func_1000A03C
//func_1000A348
//func_1000A420
//func_1000A750
//func_1000B060
struct151 *func_1000B1FC();
//func_1000B294
//func_1000B2F4
//func_1000B3D4
//func_1000B548
//func_1000B638
//func_1000B8B8
//func_1000BAFC
//func_1000BCBC
//func_1000BF60
//func_1000C350
s32 func_1000C530(s32 arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4);
//func_1000C7E8
//func_1000C934
//func_1000CA18
//func_1000CAE4
//func_1000CBF0
//func_1000CC54
//func_1000CDA0
//func_1000CEAC
//func_1000D2F8
void func_1000D758(f32 arg0, f32 arg1, s32 arg2);
//func_1000D96C
//func_1000DE1C
//func_1000DEC4
s16 func_1000DF68();
//func_1000E134
//func_1000E17C
//func_1000E2F4
s32 func_1000E46C();
s32 func_1000E588();
//func_1000E654
//func_1000E7A0
//func_1000E8C4
//func_1000E8F0
//func_1000E934
//func_1000EC24
//func_1000ECCC
void func_1000EDA0();
s32  func_1000EE70();
//func_1000EFB4
//func_1000F1A8
//func_1000F44C
//func_1000F4D8
//func_1000F568
s32  func_1000F6B8(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 *arg4, s32 arg5, s32 arg6);
void func_1000F85C(u16 arg0, s16 arg1, s32 arg2);
void func_1000F91C(u16 arg0, u16 arg1, s16 arg2, u8 arg3, s32 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9);
u16  func_1000FA64(u16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u16 arg5, s16 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11);
//func_1000FC18
//func_1000FD38
//func_1000FDF4
//func_1000FE88
//func_1000FEF0
s32  func_1000FF90();
//func_1001001C
//func_100100E0
u16 func_10010154(u16 arg0, void *arg1, u16 arg2, s16 arg3, u16 arg4);
u16 func_10010344(u16 arg0, void *arg1, u16 arg2, s16 arg3, u16 arg4);
//func_10010558
void func_10010630(u16 arg0, void *arg1, s32 arg2, s16 arg3, u16 arg4);
//func_1001091C
u16  func_10010BE8(s32 arg0, s32 arg1, u16 arg2, u8 arg3, s16 arg4, u8 arg5, u8 arg6);
//func_10010E78
s32 func_10010F88(s32 arg0, u16 arg1, s16 arg2, u8 arg3, s32 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9);
//func_10010FFC
//func_10011310
void func_100114D0();
//func_10011624
//func_10011BB8
//func_10011EB8
//func_10012020
//func_1001263C
//func_100126E8
// void func_10017870(u8 arg0);
void func_100186DC();
void func_10018790(void *arg0, void *arg1, u8 arg2, s32 arg3);
// void func_10019D98(struct26 *arg0, u8 arg1);
// void func_1001A030(struct26 *arg0, s32 arg1, s32 arg2, u32 arg3);
// void func_1001A508(struct26 *arg0, struct25 *arg1, s32 arg2, s32 arg3);
//func_1001AAE0
//func_1001ADA4
//func_1001AFEC
//func_1001B07C
//func_1001B200
// s32  func_1001B310(void *arg0, void *arg1);
// u8   func_1001B450(void *arg0, void *arg1);
void func_1001E530();
//func_1019EA88
//func_1019EAB0
//func_1019EAE0
//func_1019ECAC
//func_1019ED8C
//func_1019ED94
//func_1019ED9C
//func_1019EE0C
//func_1019EEAC
//func_1019F018
//func_1019F154
//func_1019F214
//func_1019F4E4
//func_1019F59C
//func_1019FA14
//func_1019FACC
//func_1019FD38
//func_1019FDC0
//func_1019FE18
//func_1019FF78
//func_101A0094
//func_101A0100
//func_101A017C
//func_101A0188
//func_101A02B8
//func_101A0344
//func_101A040C
//func_101A0430
//func_101A04EC
//func_101A04F4
//func_101A0538
void func_1001C224();
void func_1001CF38(void *, f32 arg1);

u16 *func_15001DE0();
void func_1501748C(s16 arg0);

s32  func_1501A490();
s32  func_1502B7F0();
struct126 *func_1503195C();
void func_150403C8();
s32  func_15043BB8();
f32  func_15047C00();
f32  func_15047D60();
f32  func_150488C8();
f32  func_15048C30(f32 arg0);
f32  func_15048FC8();
void func_15049688(f32 *arg0, f32 arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5);
void func_1505841C();
void func_15058898();
f32  func_1505A72C();
void func_1505B5F8();
void func_1505E650(void *arg0, u16 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6);
u32  func_1505E7CC();
void func_1505E874();
struct127* func_1505F0AC();
void func_15060778();
void func_15060F28();
void func_1506160C();
void func_15062B1C(struct127 *arg0, f32 arg1);
void func_15062B50(struct127 *arg0, f32 arg1);
s32 func_1506C460(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, s32 arg8, s32 arg9, s32 arg10);
struct127 *func_15072208();
void func_1507BAD0();
s32  func_15081574(void *arg0, f32 arg1, f32 arg2, void * **arg3, s32 arg4, s32 arg5);
void func_15083568();
s32  func_15083E0C();
struct127 *func_15083E90();
void func_15085710(s16 arg0, s16 arg1, s32 arg2, ...);
s32  func_150859AC(s16 arg0, s32 arg1); // a guess
void func_1508B20C(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
s32  func_150A29C8();
void func_150A7CB0();
void func_150A8050(void *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_150A9B0C(f32 arg0[4][4], f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_150AD770();
f32  func_150AD780(f32 arg0);
f32  func_150AD78C(f32 arg0);
f32  func_150AD900();
f32  func_150AD930();
u8   func_150ADA20();
f32  func_150ADA68();
void func_150E2EA4(void *arg0, u8 arg1, s16 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, s16 arg10, s16 arg11, u16 arg12, f32 arg13, f32 arg14, u8 arg15, f32 arg16);
void func_150EA904();
void func_1510B32C();
void updateCullScales_1510B958(s32 cameraIndex);
s32  func_1510B9D0();
void    func_1510F800();
void *  func_1510FD20();
s32  func_15123934();
s32  func_151239CC();
void func_15127EB8();
void func_1512D748();
struct210 *func_1513C350(struct210 *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6, struct167 *arg7, s32 arg8, u8 arg9, s32 argA);
void *func_1513D2F0(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, s32 arg7, s32 arg8, s32 arg9, u8 arg10, s32 arg11);
s32  func_1513D6FC(void *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6);
void  func_1513E13C(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6);
s32  func_1513E2AC(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, u8 arg8);
f32  func_151423D8(u8 arg0);
f32  func_15144598();
f32  func_1514462C();
f32  func_15144B68(f32 arg0);
void func_1514D3B0(struct127 *arg0, s16 arg1, u8 arg2, u8 arg3);
void *  func_1515D6D0();
void func_1515D4D4();
void func_15169260(void *arg0, s32 arg1, void *arg2, u8 arg3);
void func_1516944C(s32 arg0, void *arg1, u8 arg2);
void func_15169850(void *arg0, u8 arg1, void *arg2, void *arg3, void *arg4);
void func_15174690();
void func_15177410(u8 arg0, u8 arg1, s16 arg2, s16 arg3, s16 arg4, f32 arg5, u16 arg6, f32 arg7, s8 arg8, s8 arg9, u8 arg10, u8 arg11, u8 arg12, u8 arg13, u8 arg14, u8 arg15);
void func_1517E134();
s32  func_1517EFAC();
void func_15178E14(u8 arg0);
s32  func_15187EC0(s32 arg0, f32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void *func_15195AA8();
void func_151B8DB0(s32 arg0, u8 arg1, u8 arg2, s32 arg3);
void func_151BA468(void *arg0, void *arg1, s32 arg2);
void func_151BC5A4(void *arg0, void *arg1, u8 arg2);
void func_151D5404(void *arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s32 arg6, s32 arg7);
void func_151D5714(void *arg0, f32 *arg1, f32 *arg2, u8 arg3, f32 arg4, u8 arg5, s32 arg6);
void * func_151D8868();
void func_151D9B8C(u8 arg0, f32 arg1, u8 arg2, void *arg3, void *arg4, s32 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, s32 arg10);
void func_151DA08C(u8 arg0, f32 arg1, f32 arg2, u8 arg3, s16 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
void func_151DBCBC(u8 arg0, f32 arg1, s16 arg2, void *arg3, void *arg4, u8 arg5, s32 arg6);
s8   func_151E5FAC();
void func_151EF954(s32 arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_151F3C4C();
void func_151FA130();
void func_1019EA88();
#endif
