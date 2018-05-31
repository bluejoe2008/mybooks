

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Jan 26 23:05:11 2009
 */
/* Compiler settings for .\McdOcx.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_McdOcxLib,0x120FBE77,0x6E6D,0x49E0,0xBF,0xC1,0xB9,0x1E,0xB1,0xFD,0x8D,0x14);


MIDL_DEFINE_GUID(IID, DIID__DMcdOcx,0xF7C37EC0,0xEA78,0x45D9,0x8F,0x06,0x82,0x4E,0xBD,0xAA,0x52,0xE5);


MIDL_DEFINE_GUID(IID, DIID__DMcdOcxEvents,0x39D92FC9,0x5F9D,0x452F,0x92,0x3F,0x83,0xE7,0xB8,0x3A,0xD3,0xEB);


MIDL_DEFINE_GUID(CLSID, CLSID_McdOcx,0x1A1B254E,0xD5AA,0x406F,0xA8,0xB6,0xA0,0x21,0x8E,0x88,0x43,0xCC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



