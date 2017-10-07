///////////////////////////////////////////////////////////////////////////////
// $Source: x:/prj/tech/hsrc/RCS/nameconv.h $
// $Author: TOML $
// $Date: 1996/10/23 10:25:15 $
// $Revision: 1.2 $
//
// Multiple compiler vendor type/function/data name conversion macros
//
//

#ifndef __NAMECONV_H
#define __NAMECONV_H

#if defined(_MSC_VER) || defined(__SC__)
    #define __va_list       va_list
    #define S_IWRITE        _S_IWRITE
    #define S_IREAD         _S_IREAD
    #define outp            _outp
    #define inp             _inp
    #define outpw           _outpw
    #define inpw            _inpw
    #define snprintf        _snprintf
    #define vsnprintf       _vsnprintf
#endif

#if defined (__WATCOMC__)
    #define snprintf        _bprintf
    #define vsnprintf       _vbprintf
#endif

#endif /* !__NAMECONV_H */
