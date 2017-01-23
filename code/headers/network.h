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
#ifndef __network_h_
#define __network_h_
#include "prerequisites.h"
#ifdef __cplusplus
extern "C" {
#endif

BL_API BLVoid blConnectNetwork(
	IN BLAnsi* _Host, 
	IN BLU16 _Port, 
	IN BLEnum _Type);
    
BL_API BLVoid blDisconnectNetwork();
    
BL_API BLVoid blSendNetMsg(
	IN BLU32 _MsgID, 
	IN BLVoid* _Msgbuf,
	IN BLU32 _Msgsz, 
	IN BLBool _Critical,
	IN BLBool _Overwrite,
	IN BLBool _Autocompress,
	IN BLEnum _Nettype);

BL_API BLBool blHttpBlockRequest(
	IN BLAnsi* _Url,
	IN BLAnsi** _Argv,
	IN BLU32 _Argc,
	IN BLAnsi* _Encryptkey,
	IN BLBool _Get,
	OUT BLAnsi _Response[1025]
);

BL_API BLBool blAddDownloadList(
	IN BLAnsi* _Host,
	IN BLAnsi* _Localpath, 
	OUT BLU32* _Taskid);

BL_API BLVoid blBeginDownload();

BL_API BLVoid blQueryProgress(
	OUT BLU32* _Curtask, 
	OUT BLU32* _Downloaded, 
	OUT BLU32* _Total, 
	OUT BLU32 _Finish[64]);
    
#ifdef __cplusplus
}
#endif

#endif/* __network_h_ */