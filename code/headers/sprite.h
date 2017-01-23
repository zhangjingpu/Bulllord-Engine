/*
 Bulllord Game Engine
 Copyright (C) 2010-2017 Trix
 
 This software is provided 'as-is', without any express or implied
 warranty.  In no event will the authors be held liable for any damages
 arising from the use of this software.
 
 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it
 freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must not
 claim that you wrote the original software. If you use this software
 in a product, an acknowledgment in the product documentation would be
 appreciated but is not required.
 2. Altered source versions must be plainly marked as such, and must not be
 misrepresented as being the original software.
 3. This notice may not be removed or altered from any source distribution.
 */
#ifndef __sprite_h_
#define __sprite_h_
#include "prerequisites.h"
#include "streamio.h"
#ifdef __cplusplus
extern "C" {
#endif

  BL_API  BLVoid dump();

  BL_API BLVoid dump32(BLGuid _ID);
BL_API BLGuid blGenSprite(
	IN BLAnsi* _Filename,
	IN BLAnsi* _Archive,
	IN BLAnsi* _Tag,
    IN BLF32 _Width,
    IN BLF32 _Height,
    IN BLF32 _Zv,
	IN BLU32 _FPS,
	IN BLBool _AsTile);

BL_API BLVoid blDeleteSprite(
	IN BLGuid _ID);

BL_API BLBool blSpriteAttach(
	IN BLGuid _Parent,
	IN BLGuid _Child,
    IN BLBool _AttrInherit);

BL_API BLBool blSpriteDetach(
	IN BLGuid _Parent,
	IN BLGuid _Child);

BL_API BLBool blSpriteQuery(
	IN BLGuid _ID,
    OUT BLF32* _Width,
    OUT BLF32* _Height,
	OUT BLF32* _XPos,
	OUT BLF32* _YPos,
	OUT BLF32* _Zv,
	OUT BLF32* _Rotate,
	OUT BLF32* _XScale,
	OUT BLF32* _YScale,
	OUT BLF32* _Alpha,
	OUT BLBool* _Show);

BL_API BLBool blSpriteVisibility(
	IN BLGuid _ID,
	IN BLBool _Show,
    IN BLBool _Passdown);
    
BL_API BLBool blSpritePivot(
    IN BLGuid _ID,
    IN BLF32 _PivotX,
    IN BLF32 _PivotY,
    IN BLBool _Passdown);

BL_API BLBool blSpriteAlpha(
	IN BLGuid _ID,
	IN BLF32 _Alpha,
    IN BLBool _Passdown);

BL_API BLBool blSpriteZValue(
	IN BLGuid _ID,
    IN BLF32 _Zv,
    IN BLBool _Passdown);

BL_API BLBool blSpriteUV(
	IN BLGuid _ID,
	IN BLF32 _Uu,
	IN BLF32 _Vv,
	IN BLBool _Passdown);

BL_API BLBool blSpriteStroke(
	IN BLGuid _ID,
	IN BLU32 _Color,
    IN BLU32 _Pixel,
    IN BLBool _Passdown);

BL_API BLBool blSpriteGlow(
	IN BLGuid _ID,
	IN BLU32 _Color,
    IN BLU32 _Pixel,
    IN BLBool _Passdown);

BL_API BLBool blSpriteDyeing(
	IN BLGuid _ID,
	IN BLU32 _Color,
    IN BLBool _Dye,
    IN BLBool _Passdown);
    
BL_API BLBool blSpriteTransformReset(
    IN BLGuid _ID,
    IN BLF32 _XPos,
    IN BLF32 _YPos,
    IN BLF32 _Rotate,
    IN BLF32 _ScaleX,
    IN BLF32 _ScaleY);

BL_API BLBool blSpriteMove(
	IN BLGuid _ID,
	IN BLF32 _XVec,
	IN BLF32 _YVec);

BL_API BLBool blSpriteScale(
	IN BLGuid _ID,
	IN BLF32 _XScale,
	IN BLF32 _YScale);

BL_API BLBool blSpriteRotate(
	IN BLGuid _ID,
	IN BLF32 _Rotate);
    
BL_API BLBool blSpriteScissor(
    IN BLGuid _ID,
    IN BLF32 _XPos,
    IN BLF32 _YPos,
    IN BLF32 _Width,
    IN BLF32 _Height);
    
BL_API BLBool blSpriteAsEmit(
	IN BLGuid _ID,
	IN BLEnum _Emitter,
	IN BLU32 _EmitterParam,
	IN BLF32 _Life,
	IN BLU32 _MaxAlive,
	IN BLU32 _GenPerSec,
	IN BLF32 _VelocityX,
	IN BLF32 _VelocityY,
	IN BLF32 _AccelerationX,
	IN BLF32 _AccelerationY,
	IN BLF32 _DisturbanceX,
	IN BLF32 _DisturbanceY,
	IN BLF32 _EmitAngle,
	IN BLU32 _FadeColor,
	IN BLF32 _FadeScale);
    
BL_API BLBool blSpriteAsCursor(
    IN BLGuid _ID);

BL_API BLBool blSpriteActionBegin(
	IN BLGuid _ID);

BL_API BLBool blSpriteActionEnd(
	IN BLGuid _ID,
    IN BLBool _Delete);

BL_API BLBool blSpriteActionPlay(
	IN BLGuid _ID);

BL_API BLBool blSpriteActionStop(
	IN BLGuid _ID);

BL_API BLBool blSpriteParallelBegin(
	IN BLGuid _ID);

BL_API BLBool blSpriteParallelEnd(
	IN BLGuid _ID);

BL_API BLBool blSpriteActionMove(
	IN BLGuid _ID,
	IN BLF32* _XPath,
	IN BLF32* _YPath,
	IN BLU32 _PathNum,
	IN BLF32 _Acceleration,
	IN BLF32 _Time,
	IN BLBool _Loop);

BL_API BLBool blSpriteActionRotate(
	IN BLGuid _ID,
	IN BLF32 _Angle,
	IN BLF32 _Time,
	IN BLBool _Loop);

BL_API BLBool blSpriteActionScale(
	IN BLGuid _ID,
	IN BLF32 _XScale,
	IN BLF32 _YScale,
	IN BLF32 _Time,
	IN BLBool _Loop);

BL_API BLBool blSpriteActionAlpha(
	IN BLGuid _ID,
	IN BLF32 _Alpha,
	IN BLF32 _Time,
	IN BLBool _Loop);

BL_API BLVoid blViewportMove(
	IN BLF32 _XVec,
	IN BLF32 _YVec);

BL_API BLVoid blViewportShake(
	IN BLF32 _Time,
	IN BLBool _Vertical,
	IN BLF32 _Force);
#ifdef __cplusplus
}
#endif
#endif/*__sprite_h_*/