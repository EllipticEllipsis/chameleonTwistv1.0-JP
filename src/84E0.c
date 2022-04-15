#include "common.h"
#include "84E0.h"

const char padRodata[] = "\0\0\0\0\0\0\0";

f32 func_800C8C14(f32, f32);                        /* extern */
f32 func_800DAD80(f32);                             /* extern */
f32 func_800DB0B0(f32);                             /* extern */
f32 func_800DB0C0(f32);                             /* extern */

// Sum of Two Squares: Elisiah
f32 func_8002D0E0(f32 arg0, f32 arg1) {
    //return SQ(arg0) + SQ(arg1);
    return (arg0 * arg0) + (arg1 * arg1);
}

// Set f32 in the open set (0, 360) : Elisiah
void func_8002D0F4(f32* arg0) {
    f32 temp_f0;

loop_1:
    temp_f0 = *arg0;
    if (temp_f0 >= 360.0f) {
        *arg0 = temp_f0 - 360.0f;
        goto loop_1;
    }
    if (temp_f0 < 0.0f) {
        *arg0 = temp_f0 + 360.0f;
        goto loop_1;
    }
}

// if a^2+b^2 > c^2 -> set a and b st. a^2+b^2=c^2 : Elisiah
void func_8002D148(f32* a, f32* b, f32 c) {
    f32 sqrtASquaredPlusBSquared;
    f32 aSquaredPlusBSquared;

    aSquaredPlusBSquared = (((*a) * (*a) + (*b) * (*b)));
    if (!(aSquaredPlusBSquared <= (c * c))) {
        sqrtASquaredPlusBSquared = func_800DB0B0(aSquaredPlusBSquared);    //sqrt func
        *a = (*a * c) / sqrtASquaredPlusBSquared;
        *b = (*b * c) / sqrtASquaredPlusBSquared;
    }
}

// Unknown Function: Elisiah 
f32 func_8002D1CC(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    return func_800C8C14(arg2 - arg0, -(arg3 - arg1));
}

// Input 0-360, counts from 0 to 180 then down to 0: Elisiah
f32 func_8002D214(f32 arg0) {

    if (arg0 < 0.0f) {
        arg0 = -arg0;
    }
    if (arg0 > 180.0f) {
        arg0 = 360.0f - arg0;
    }
    return arg0;
}

// 1 or 0 depending on unk func: Elisiah
s32 func_8002D258(f32 arg0, f32 arg1, f32 arg2) {

    if (func_8002D214(arg0 - arg1) <= arg2) {
        return 1;
    }
    return 0;
}

// : Elisiah
s32 func_8002D2A0(f32 arg0, f32 arg1) {
    if (arg0 < 180.0f) {
        if ((arg0 < arg1) && (arg1 <= (arg0 + 180.0f))) {
            return 1;
        }
        return -1;
    }
    if (((arg0 - 180.0f) < arg1) && (arg1 <= arg0)) {
        return -1;
    }
    return 1;
}

// Unknown Function: Elisiah
void func_8002D328(f32 arg0, f32 arg1) {
    f32 temp_f12;
    f32* temp_a0;

    temp_f12 = arg0 - 90.0f;
    temp_a0 = &arg0;
    arg0 = temp_f12;
    func_8002D0F4(/*temp_f12,*/temp_a0);    // Why does everything keep calling this with 2??
    func_8002D2A0(arg0, arg1);
}

// Unkown Function: Elisiah
s32 func_8002D36C(f32* arg0, f32 arg1, f32 arg2) {
    s32 phi_v1;
    f32 phi_f0;
    s32 sp1C;

    phi_v1 = 0;
    if (*arg0 < arg1) {
        phi_f0 = -(*arg0 - arg1);
    } else {
        phi_f0 = *arg0 - arg1;
    }
    if (phi_f0 > 180.0f) {
        phi_f0 = 360.0f - phi_f0;
    }
    if (arg2 <= phi_f0) {
        sp1C = 0;
        *arg0 += arg2 * (f32) func_8002D2A0(*arg0, arg1);
    } else {
        *arg0 = arg1;
        phi_v1 = 1;
    }
    sp1C = phi_v1;
    func_8002D0F4(arg0);
    return sp1C;
}

void func_8002D434(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 temp_f10;
    f32 temp_f0 = *arg0 - arg2;
    f32 temp_f2 = *arg1 - arg3;
    f32 temp_f0_2 = func_800DB0B0(SQ(temp_f0) + SQ(temp_f2));
    
    if (temp_f0_2 != 0.0f) {
        temp_f10 = func_800C8C14(temp_f0, -temp_f2) + arg4;
        *arg0 = func_800DB0C0(temp_f10 * 2 * PI / 360.0) * temp_f0_2 + arg2;
        *arg1 = arg3 + -(func_800DAD80( temp_f10 * 2 * PI / 360.0) * temp_f0_2);
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002D550.s")
void func_8002D550(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4)
{
  f32 temp_f12;
  f32 *new_var;
  f32 temp_f2;
  f32 temp_f12_2 = func_8002D1CC(arg2, arg3, *arg0, *arg1) * 2;
  temp_f2 = (*arg0) - arg2;
  temp_f12 = (*arg1) - arg3;
  if (((temp_f2 * temp_f2) + (temp_f12 * temp_f12)) < (arg4 * arg4))
  {
    temp_f12_2 = (temp_f12_2 * PI) / 360.0;
    if (temp_f12)
    {
    }
    *arg0 = (func_800DB0C0(temp_f12_2) * arg4) + arg2;
    *arg1 = ((-func_800DAD80(temp_f12_2)) * arg4) + arg3;
  }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002D644.s")
void func_8002D644(s32 actorIndex, s32 actorID, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, f32 argE, f32 argF, f32 arg10, f32 arg11, f32 arg12, f32 arg13, s32 arg14, s32 arg15, s32 arg16, s32 arg17) {
    Actor* actorInstance;
    s32 i;

    actorInstance = &D_8016AC68[actorIndex];

    for (i = 0; i < 6;) {
        actorInstance->unk_10C[i] = 0;
        i++;
    }

    for (i = 0; i < 8; ) {
        actorInstance->unk_134[i] = 0;
        i++;
    }

    actorInstance->actorIndex = actorIndex;
    actorInstance->actorID = actorID;
    actorInstance->lifeDuration = 0;
    actorInstance->unk_24 = arg2;
    actorInstance->unk_28 = arg3;
    actorInstance->unk_2C = arg4;
    actorInstance->unk_90 = arg5;

    for (i = 0; i < 3; i++) {
        actorInstance->unknownPositionThings[i].unk_08 = 0.0f;
        actorInstance->unknownPositionThings[i].unk_04 = 0.0f;
        actorInstance->unknownPositionThings[i].unk_00 = 0.0f;
        actorInstance->unknownPositionThings[i].unk_10 = 0.0f;
        actorInstance->unknownPositionThings[i].unk_0C = 0.0f;
    }
    actorInstance->unk_3C = actorInstance->unknownPositionThings[0].unk_0C = D_8010A6D0[actorID].x;
    actorInstance->unk_40 = actorInstance->unknownPositionThings[0].unk_10 = D_8010A6D0[actorID].y;
    actorInstance->unk_50 = 1;

    actorInstance->unk_F4 = arg6;
    actorInstance->unk_F8 = arg7;
    actorInstance->unk_FC = arg8;
    actorInstance->unk_100 = arg9;
    actorInstance->unk_104 = argA;
    actorInstance->unk_108 = argB;
    actorInstance->position._f32.x = argC;
    actorInstance->position._f32.y = argD;
    actorInstance->unk_15C = argE;
    actorInstance->unk_160 = argF;
    actorInstance->unk_164 = arg10;
    actorInstance->unk_168 = arg11;
    actorInstance->unk_16C = arg12;
    actorInstance->unk_170 = arg13;
    actorInstance->unk_124 = arg14;
    actorInstance->unk_128 = arg15;
    actorInstance->unk_12C = arg16;
    actorInstance->unk_130 = arg17;
    actorInstance->unk_08 = 0;
    actorInstance->unk_30 = 0.0f;
    actorInstance->unk_34 = 0.0f;
    actorInstance->unk_38 = 0.0f;
    actorInstance->unk_44 = 0.0f;
    actorInstance->unk_48 = 0.0f;
    actorInstance->unk_4C = 0.0f;
    actorInstance->unk_94 = 0.0f;
    actorInstance->unk_0C = 0;
    actorInstance->unk_14 = 0;
    actorInstance->unk_18 = 0;
    actorInstance->unk_1C = 0;
    actorInstance->unk_98 = 0;
    actorInstance->unk_9C = 0;
    actorInstance->unk_B0 = 0.0f;
    
    actorInstance->unk_A0.unk_00 = D_8010AA28[actorID].unk_00;
    actorInstance->unk_A0.unk_04 = D_8010AA28[actorID].unk_04;
    actorInstance->unk_A0.unk_08 = D_8010AA28[actorID].unk_08;
    actorInstance->unk_A0.unk_0C = D_8010AA28[actorID].unk_0C;
    

    actorInstance->unk_C4 = 0;
    actorInstance->unk_C8 = 0;
    actorInstance->unk_C0 = 0.0f;

    actorInstance->unk_D0 = actorInstance->unk_CC = 1.0f;
    actorInstance->unk_EC = 0;
    actorInstance->unk_F0 = 0;
    actorInstance->unk_D4 = 0.0f;
    actorInstance->unk_D8 = 0.0f;
    actorInstance->unk_DC = 0.0f;
    actorInstance->unk_E0 = -1;
    actorInstance->unk_E4 = -1;

    switch (actorID) {
    case Red_Ant:
        func_80039368(actorInstance);
        return;
    case Green_Ant:
        func_8003A1B0(actorInstance);
        return;
    case Grey_Ant:
        func_80038510(actorInstance);
        return;
    case Bullet_Hell_Ant:
        func_80038AE0(actorInstance);
        return;
    case Ant_Trio:
        func_80038F70(actorInstance);
        return;
    case Yellow_Ant:
        func_800399A0(actorInstance);
        return;
    case Grey_Ant_Spawner:
        func_800383C0(actorInstance);
        return;
    case Bullet_Hell_Ant_Spawner:
        func_80038990(actorInstance);
        return;
    case Ant_Queen:
        func_8003A3F0(actorInstance);
        return;
    case Ant_Queen_Ant:
        func_8003B894(actorInstance);
        return;
    case White_Bomb_Snake:
        func_8003BA38(actorInstance);
        return;
    case Grenade:
        func_8003BC8C(actorInstance);
        return;
    case Missile_Spawner:
        func_8003BD98(actorInstance);
        return;
    case Missile:
        func_8003BEE8(actorInstance);
        return;
    case Cannon:
        func_8003C20C(actorInstance);
        return;
    case Cannonball:
        func_8003C4B8(actorInstance);
        return;
    case BL_Boss_Segment:
        func_8003C8AC(actorInstance);
        return;
    case Explosion:
        func_8003D574(actorInstance);
        return;
    case Black_Chameleon_Projectile_Spawner:
        func_8003D6A4(actorInstance);
        return;
    case Black_Chameleon_Projectile:
        func_8003D908(actorInstance);
        return;
    case Chomper:
        func_8003D998(actorInstance);
        return;
    case Sand_Crab:
        func_8003DE04(actorInstance);
        return;
    case Vulture:
        func_8003DFB4(actorInstance);
        return;
    case Arrows:
        func_8003E30C(actorInstance);
        return;
    case Boulder:
        func_8003E368(actorInstance);
        return;
    case Armadillo:
        func_8003E62C(actorInstance);
        return;
    case Pogo:
        func_8003FB04(actorInstance);
        return;
    case unk_23:
        func_8003FEB4(actorInstance);
        return;
    case Ice_Cream_Sandwich:
        func_8003FEC4(actorInstance);
        return;
    case Training_Room_Choco_Kid:
        func_80040068(actorInstance);
        return;
    case unk_1F:
        func_800401E8(actorInstance);
        return;
    case Popcorn:
        func_800404D8(actorInstance);
        return;
    case Cake_Boss:
        func_80041050(actorInstance);
        return;
    case Cake_Boss_Strawberry:
        func_800405F8(actorInstance);
        return;
    case unk_28:
        func_80040CDC(actorInstance);
        return;
    case Cake_Boss_Choco_Kid:
        func_80040CEC(actorInstance);
        return;
    case Bowling_Ball:
        func_80042AFC(actorInstance);
        return;
    case Bowling_Pins:
        func_80042FB4(actorInstance);
        return;
    case Cue_Ball:
        func_8004237C(actorInstance);
        return;
    case Billiards_Ball:
        func_8004259C(actorInstance);
        return;
    case unk_2E:
        func_800431E8(actorInstance);
        return;
    case unk_2F:
        func_800434F4(actorInstance);
        return;
    case Cup:
        func_80043998(actorInstance);
        return;
    case Saucer:
        func_800439D8(actorInstance);
        return;
    case Metal_Sheet:
        func_80043A18(actorInstance);
        return;
    case Scroll:
        func_80043A58(actorInstance);
        return;
    case RNG_Room_Spawner:
        func_80043A98(actorInstance);
        return;
    case Mirror:
        func_80043C80(actorInstance);
        return;
    case Barrel_Jump_Fire_Spawner:
        func_80043FE8(actorInstance);
        return;
    case Barrel_Jump_Fire:
        func_800440FC(actorInstance);
        return;
    case Fire_Spitter:
        func_800442E0(actorInstance);
        return;
    case Candles:
        func_80044504(actorInstance);
        return;
    case Fire_Spawner:
        func_80044544(actorInstance);
        return;
    case Fire:
        func_80044584(actorInstance);
        return;
    case Sandal:
        func_80044708(actorInstance);
        return;
    case Pile_of_Books:
        func_80044878(actorInstance);
        return;
    case Pile_of_Books_Arm_Segments:
        func_80046DDC(actorInstance);
        return;
    case Pile_of_Books_Arm_Spitter:
        func_80046FB0(actorInstance);
        return;
    case Pile_of_Books_Projectile:
        func_8004709C(actorInstance);
        return;
    case Spider_Spawner:
        func_8004718C(actorInstance);
        return;
    case Spider:
        func_80047350(actorInstance);
        return;
    case Spider_Trio:
        func_80047520(actorInstance);
        return;
    case Golem:
        func_800477C4(actorInstance);
        return;
    case Hedgehog:
        func_800479CC(actorInstance);
        return;
    case Fish:
        func_80047C04(actorInstance);
        return;
    case Lizard_Kong_Butterfly:
        func_800480EC(actorInstance);
        return;
    case Golem_Room_Spider_Spawner:
        func_8004769C(actorInstance);
        return;
    case Lizard_Kong_Butterfly_Spawner:
        func_800487D8(actorInstance);
        return;
    case Lizard_Kong_Boulder:
        func_800488C4(actorInstance);
        return;
    case Lizard_Kong:
        func_80048A68(actorInstance);
        return;
    case Popcorn_Bucket_Spawner:
        func_80049780(actorInstance);
        return;
    case Popcorn_Bucket:
        func_800498B4(actorInstance);
        return;
    case unk_4E:
        func_800498F4(actorInstance);
        return;
    case Choco_Kid_Spawner:
        func_80049934(actorInstance);
        return;
    case Choco_Kid:
        func_80049A24(actorInstance);
        return;
    case unk_51:
        func_80049A64(actorInstance);
        return;
    case unk_52:
        func_80049AA4(actorInstance);
        return;
    case Battle_Mode_Sand_Crab_Spawner:
        func_80049AE4(actorInstance);
        return;
    case Battle_Mode_Sand_Crab:
        func_80049C34(actorInstance);
        return;
    case unk_55:
        func_80049D0C(actorInstance);
        return;
    case Battle_Mode_Fire:
        func_80049F04(actorInstance);
        return;
    case Battle_Mode_Saucer_Spawner:
        func_80049F14(actorInstance);
        return;
    case Battle_Mode_Saucer:
        func_8004A0A0(actorInstance);
        return;
    case unk_59:
        func_8004A184(actorInstance);
        return;
    case unk_5A:
        func_8004A310(actorInstance);
        return;
    case Power_Up_Spawner:
        func_8004A39C(actorInstance);
        return;
    case Falling_Grey_Ant_Spawner:
        func_8004A544(actorInstance);
        return;
    case Falling_Grey_Ant:
        func_8004A658(actorInstance);
        return;
    case unk_5E:
        func_8004AB00(actorInstance);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002DE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002DF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002E04C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002E0CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002E5DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002E9F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002ECCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F3D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F6DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F7F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F884.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002F9BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8002FA34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80030DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80030F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800311C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800312B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800312FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800313BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800314E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80031518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800317A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80031898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80031DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80032074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800320EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800321F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80032720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80032A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80033048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80033C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80034104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800343B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003449C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80034744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80034B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80034FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80035374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80035460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800360E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003624C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80036490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80036900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80036D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80036F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003749C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80037504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80037538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80037584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003760C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80037D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80037F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800382B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800382F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800383A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800383C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800383E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80038510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80038574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80038990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003899C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80038AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80038B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80038C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80038E64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80038F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80038FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80039368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80039500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800397DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800399A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80039B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003A1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003A208.s")

// Ant Queen Function: Elisiah
void func_8003A3F0(Actor* antQueenActor) {
    antQueenActor->unk_120 = (s32) antQueenActor->unk_12C;
    antQueenActor->unk_50 = 3;
    antQueenActor->unknownPositionThings[1].unk_0C = 150.0f;
    antQueenActor->unknownPositionThings[1].unk_10 = (f32) D_8010A6D0[Ant_Queen].y;
    antQueenActor->unknownPositionThings[2].unk_0C = 200.0f;
    antQueenActor->unknownPositionThings[2].unk_10 = (f32) D_8010A6D0[Ant_Queen].y;
    antQueenActor->unknownPositionThings[1].unk_04 = 150.0f;
    antQueenActor->unknownPositionThings[2].unk_04 = 300.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003A444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003AAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003B894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003B8D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003BA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003BADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003BC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003BC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003BD98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003BDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003BEE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003BF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003C20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003C308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003C4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003C584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003C734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003C8AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003CAD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D5C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D6AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003D9D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003DE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003DE4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003DFB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003DFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E30C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E32C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E62C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E6C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003E968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003EB38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003FA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003FB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003FB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003FC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003FEAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003FEB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003FEBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003FEC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8003FEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80040068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800400C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800401E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80040214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800404D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80040590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800405F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80040638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80040CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80040CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80040CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80040CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80041050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800410B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800410EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80041C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80042174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004237C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80042388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004259C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800425A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004263C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80042AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80042B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80042FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800431E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800431FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800434F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800434FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800439B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800439D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800439F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043A58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80043FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800440FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800442E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800442F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800445CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800448C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80044EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004501C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80046DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80046E50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80046FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80046FB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004709C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800470C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004718C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80047194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80047350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80047384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80047520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80047568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004769C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800476A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800477C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800477CC.s")

// Hedgehog Function: Elisiah
void func_800479CC(Actor* hedgehogActor) {
    hedgehogActor->unk_134[0] = (f32) hedgehogActor->unk_24;
    hedgehogActor->unk_134[1] = (f32) hedgehogActor->unk_2C;
    hedgehogActor->unk_134[2] = (f32) hedgehogActor->unk_90;
}

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800479E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80047C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80047C18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80047FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800480EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80048284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800486E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800487D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800487E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800488C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800488FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800489B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80048A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80048AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80048B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800498B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800498D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_800498F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004993C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049A44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049A84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049AC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049AEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049D0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_80049F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A0A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A0AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A31C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A39C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A3A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004A6C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004AB00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004AB08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004AC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004AC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004AD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004BA5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004BAC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004BC48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004BD7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004BE90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004BF88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004C110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004C1C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004C374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004C3A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004C43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004C600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004CC6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004CCBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004CD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/84E0/func_8004DDE0.s")
