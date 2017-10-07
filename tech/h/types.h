/*
 * $Source: x:/prj/tech/hsrc/RCS/types.h $
 * $Revision: 1.31 $
 * $Author: TOML $
 * $Date: 1998/09/29 11:23:32 $
 *
 * extra typedefs and macros for use by all code.
 *
 */

#ifndef __TYPES_H
#define __TYPES_H

//#define _MSC_VER 0x01200
#define _MFC_VER 0x0600
//#define WIN32
//#define _WIN32
#define _WIN32_WINNT 0x0400
#define WINVER 0x0400

#include <windows.h>

//
// Include any compiler headers that get messed up by this file...
//

// Microsoft
#if defined(_MSC_VER)
   #include <yvals.h>
#endif

//
// COMPILER VENDOR SPECIFIC ADJUSTEMENTS (placed first so will affect this file)
//

// Watcom
#if defined(__WATCOMC__)

  #if !defined(SHOW_ALL_WARNINGS)
    #if defined(__cplusplus)
        // Address Watcom 10.0 and higher C++ parser complaint about
        // "do { } while (0)" and "if ([0|1]) ;" that often show up in macros
         // also turn off unreferenced params
        #pragma warning 555 9
        #pragma warning 689 9
        #pragma warning 656 9
        #pragma warning 657 9
        // turn off truncated values warning since it gives false
        // positives everywhere for short = short - short;
        #pragma warning 389 9
    #else
        // Preprocessing symbol 'X' has not been declared in Watcom C front end only
        #pragma warning 203 9
    #endif

    #ifdef NOUNREF
        #pragma off (unreferenced)
    #endif
  #endif

#endif

// Microsoft
#if defined(_MSC_VER)

    #if !defined(SHOW_ALL_WARNINGS)
        // unknown pragma
        #pragma warning(disable:4068)
        // 'this' : used in base member initializer list
        #pragma warning(disable:4355)
        // nonstandard extension used : 'bool' keyword is reserved for future use
        #pragma warning (disable:4237)
        // nonstandard extension used : zero-sized array in struct/union
        #pragma warning (disable:4200)
        // template-class specialization 'blah' already instantiated
        // to be honest, im not C++ boy enough to know what is up here - tom?
        #pragma warning (disable:4660)
        // truncation from 'const double ' to 'float'
        #pragma warning (disable:4305)

        // these probably dont want to be here, but rather be in
        // SHOW_SMALL_BUT_MAYBE_A_BUG_WARNINGS or something

        // conversion from blah to blah, possible loss of data
        #pragma warning (disable:4244)
        // integral size mismatch in argument; conversion supplied
        #pragma warning (disable:4761)
        // (bool-op) : signed/unsigned mismatch (op is ==, >=, so on)
        #pragma warning (disable:4018)

        #pragma warning (3:4706)

    #endif

#endif


//
// NULL
//

#ifndef NULL
    #define NULL 0
#endif /* !NULL */


//
// COMMON SCALAR TYPES
//

#ifndef NO_SCALAR_TYPEDEFS

// Size neutral
typedef unsigned char   uchar;
typedef unsigned short  ushort;
typedef unsigned int    uint;
typedef unsigned long   ulong;

typedef   signed char   schar;
typedef   signed short  sshort;
typedef   signed int    sint;
typedef   signed long   slong;

// Size sensitive
typedef   signed char   sbyte;
typedef unsigned char   ubyte;
typedef unsigned char   uint8;
typedef   signed char   sint8;
typedef   signed char   int8;
typedef unsigned char   BYTE;

typedef unsigned short  uint16;
typedef   signed short  sint16;
typedef   signed short  int16;
typedef unsigned short  WORD;

typedef unsigned long   uint32;
typedef   signed long   sint32;
typedef   signed long   int32;
typedef unsigned long   DWORD;

#endif /* !NO_SCALAR_TYPEDEFS */


//
// BOOLEANS
//

#ifndef NO_BOOLEAN_TYPEDEFS

typedef int BOOL;                       // Microsoft-style
typedef unsigned char sbool;            // small bool

// "True" bool that is own type and matches C++ standard behavior
#ifndef NO_TRUE_BOOL
#ifdef __cplusplus
struct true_bool
{
   true_bool()         : value(0)        {}
   true_bool(int v)    : value(v != 0)   {}
   true_bool & operator=(int v)          { value = (v != 0); return (*this); }
   operator int() const                  { return (value); }

private:
   int value;
};
#else
typedef int true_bool;
#endif
#endif

#if defined(_MSC_VER) || defined(WAT110)
#define bool sbool
#else
typedef unsigned char bool;             // Warning: future C++ keyword collision
#endif

#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif

#endif /* !NO_BOOLEAN_TYPEDEFS */


//
// GLOBALLY UNIQUE IDENTIFIERS (GUIDs)
//

// Forward declare a guid
#define F_DECLARE_GUID(guid) \
    EXTERN_C const GUID CDECL FAR guid

#if !defined(NO_GUIDS) && !defined(GUID_DEFINED)
#define GUID_DEFINED

typedef struct  _GUID
    {
    DWORD Data1;
    WORD  Data2;
    WORD  Data3;
    BYTE  Data4[ 8 ];
    }	GUID;

#define MAKE_GUID(p, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
   do \
   { \
      const GUID _temp = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }; \
      *p = _temp; \
   } while (0)

#if !defined(_MSC_VER) && !defined(WAT110)
   #define DEFINE_GUID_UNCONDITIONAL(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
            EXTERN_C const GUID CDECL name \
                     = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
#else
   #define DEFINE_GUID_UNCONDITIONAL(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
            EXTERN_C const GUID name \
                     = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
#endif

// VC 4.2 changed the definition of DEFINE_GUID.  Other compilers are sure to follow (toml 11-19-96)
#if !defined(_MSC_VER) && !defined(WAT110)
   #ifndef INITGUID
      #define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
            EXTERN_C const GUID CDECL FAR name
   #else
      #define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
               EXTERN_C const GUID CDECL name \
                        = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
   #endif /* !INITGUID */
#else
   #ifndef INITGUID
      #define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
            EXTERN_C const GUID FAR name
   #else
      #define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
               EXTERN_C const GUID name \
                        = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
   #endif /* !INITGUID */
#endif

#endif /* !NO_GUIDS && !GUID_DEFINED */

//
// Looking Glass GUID definition macro
//
#ifndef NO_LG_GUID

#define MAKE_LG_GUID_HIGH_DWORD(number) ((((ulong)number & 0xff) << 24) | (((ulong)number & 0xff00) << 16) | ((ulong)number & 0xffff))

#define DEFINE_LG_GUID(ident, number) \
    DEFINE_GUID(ident, MAKE_LG_GUID_HIGH_DWORD((number)), \
                       (0x7a80 + (number)), \
                       (0x11cf + (number)), \
                       0x83, 0x48, 0x00, 0xaa, 0x00, 0xa8, 0x2b, 0x51)

#define DEFINE_LG_GUID_UNCONDITIONAL(ident, number) \
    DEFINE_GUID_UNCONDITIONAL(ident, MAKE_LG_GUID_HIGH_DWORD((number)), \
                       (0x7a80 + (number)), \
                       (0x11cf + (number)), \
                       0x83, 0x48, 0x00, 0xaa, 0x00, 0xa8, 0x2b, 0x51)

#define MAKE_LG_GUID(p, number) \
    MAKE_GUID(p, MAKE_LG_GUID_HIGH_DWORD((number)), \
                       (0x7a80 + (number)), \
                       (0x11cf + (number)), \
                       0x83, 0x48, 0x00, 0xaa, 0x00, 0xa8, 0x2b, 0x51)

// Convert an existing guid you know to be a looking glass guid
// back into the 16 bit number, so you can store it or use
// it for smaller comparisons, etc
#define GET_LG_GUID(_pGuid) (*(ushort *)_pGuid)


#endif /* !NO_LG_GUID */


//
// HANDLES
//

#ifndef NO_HANDLES

#ifdef STRICT
    typedef void *HANDLE;
    #define DECLARE_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name
#else
    typedef void * HANDLE;
    #define DECLARE_HANDLE(name) typedef HANDLE name
#endif

#endif /* !NO_HANDLES */


//
// FUNCTION & DATA LINKAGE, STORAGE, AND TYPE QUALIFIERS
//

#ifndef NO_TYPE_QUALIFIERS

#ifndef CDECL
    #define CDECL
#endif

#ifndef EXPORT
    #define EXPORT __export
#endif

// These type qualifiers are archaic, thus defined away

#ifndef BASED_CODE
    #define BASED_CODE
#endif

#ifndef _WIN32
    #define __based(a)
    #define __segname(a)
    #define __export
    #define __import
#endif

#undef far
#undef near
#undef pascal

#define far
#define near
#define pascal __stdcall
#define FAR    far
#define NEAR   near

// Qualifiers for publicly exposed functions and data

#ifdef __cplusplus
    #define EXTERN      extern "C"
    #define EXTERN_C    extern "C"
#else
    #define EXTERN      extern
    #define EXTERN_C    extern
#endif

#if defined(_WIN32)
    #define LGAPI   __stdcall
    #define LGDATA
#else
    #define LGAPI
    #define LGDATA
#endif

// Export/Import qualifiers, used for further macro building

#if defined(_WIN32) && defined(_WINDLL)
    #define __LGIMPORT __declspec(dllimport)
    #define __LGEXPORT __declspec(dllexport)
#else
    #define __LGIMPORT
    #define __LGEXPORT
#endif

#define __LGAX      __LGEXPORT LGAPI
#define __LGDX      __LGEXPORT LGDATA
#define __LGAI      __LGIMPORT LGAPI
#define __LGDI      __LGIMPORT LGDATA

#endif /* !NO_TYPE_QUALAIFIERS */


//
// CROSS-VENDOR DEFINES (WC/VC/Windows/3rd Party/LG compatability)
//

#if defined(ONEOPT)
    // Build system has turned off debugging for the current compile
    #undef DEBUG
    #undef DBG_ON
    #undef SPEW_ON
    #undef WARN_ON
#endif

#if defined(DBG_ON) && !defined(DEBUG)
    #define DEBUG 1
#endif

#if defined(DEBUG) && !defined(DBG_ON)
    #define DBG_ON 1
#endif

#if !defined(DEBUG) && !defined(NDEBUG)
    #define NDEBUG
#endif


//
// COMMON ERROR TYPE
//
// These model 1-1 Windows HRESULTS, but dispense with some
// Microsoft-isms, and add support for "subsystem ids"
//

typedef long            tResult;
typedef unsigned char   tResultCode;

#define kNoError        0L

// Severity values
#define kSuccess        0
#define kError          1


// Generic test for success on any status value (non-negative numbers indicate success).
#define Succeeded(Status) ((HRESULT)(Status) >= 0)

// and the inverse
#define Failed(Status) ((HRESULT)(Status)<0)

// Generic test for error on any status value.
#define IsError(Status) ((unsigned long)(Status) & 0x80000000L)


// Make a result
#define MakeResult(severity, subsystem, code) \
    MAKE_HRESULT(severity, FACILITY_ITF, ((unsigned long)(subsystem) << 8) | ((unsigned long)(code)))

#define FACILITY_ITF    4
#define MAKE_HRESULT(sev,fac,code) \
    ((HRESULT) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )


#endif /* !__TYPES_H */
