

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __McdOcxidl_h__
#define __McdOcxidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DMcdOcx_FWD_DEFINED__
#define ___DMcdOcx_FWD_DEFINED__
typedef interface _DMcdOcx _DMcdOcx;
#endif 	/* ___DMcdOcx_FWD_DEFINED__ */


#ifndef ___DMcdOcxEvents_FWD_DEFINED__
#define ___DMcdOcxEvents_FWD_DEFINED__
typedef interface _DMcdOcxEvents _DMcdOcxEvents;
#endif 	/* ___DMcdOcxEvents_FWD_DEFINED__ */


#ifndef __McdOcx_FWD_DEFINED__
#define __McdOcx_FWD_DEFINED__

#ifdef __cplusplus
typedef class McdOcx McdOcx;
#else
typedef struct McdOcx McdOcx;
#endif /* __cplusplus */

#endif 	/* __McdOcx_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __McdOcxLib_LIBRARY_DEFINED__
#define __McdOcxLib_LIBRARY_DEFINED__

/* library McdOcxLib */
/* [control][helpstring][helpfile][version][uuid] */ 


EXTERN_C const IID LIBID_McdOcxLib;

#ifndef ___DMcdOcx_DISPINTERFACE_DEFINED__
#define ___DMcdOcx_DISPINTERFACE_DEFINED__

/* dispinterface _DMcdOcx */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DMcdOcx;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F7C37EC0-EA78-45D9-8F06-824EBDAA52E5")
    _DMcdOcx : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMcdOcxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMcdOcx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMcdOcx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMcdOcx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMcdOcx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMcdOcx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMcdOcx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMcdOcx * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DMcdOcxVtbl;

    interface _DMcdOcx
    {
        CONST_VTBL struct _DMcdOcxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMcdOcx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DMcdOcx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DMcdOcx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DMcdOcx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DMcdOcx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DMcdOcx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DMcdOcx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMcdOcx_DISPINTERFACE_DEFINED__ */


#ifndef ___DMcdOcxEvents_DISPINTERFACE_DEFINED__
#define ___DMcdOcxEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DMcdOcxEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DMcdOcxEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("39D92FC9-5F9D-452F-923F-83E7B83AD3EB")
    _DMcdOcxEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DMcdOcxEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DMcdOcxEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DMcdOcxEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DMcdOcxEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DMcdOcxEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DMcdOcxEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DMcdOcxEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DMcdOcxEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DMcdOcxEventsVtbl;

    interface _DMcdOcxEvents
    {
        CONST_VTBL struct _DMcdOcxEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DMcdOcxEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _DMcdOcxEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _DMcdOcxEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _DMcdOcxEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _DMcdOcxEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _DMcdOcxEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _DMcdOcxEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DMcdOcxEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_McdOcx;

#ifdef __cplusplus

class DECLSPEC_UUID("1A1B254E-D5AA-406F-A8B6-A0218E8843CC")
McdOcx;
#endif
#endif /* __McdOcxLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


