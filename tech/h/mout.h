

#ifndef __MOUT_H
#define __MOUT_H

#include <iostream.h>
#ifdef __WATCOMC__
#include <streambu.h>
#endif

extern "C"
{
#include "mprintf.h"
}

class mstreambuf : public streambuf
{
public:
   mstreambuf();
   ~mstreambuf();
   mstreambuf( streambuf & );
   mstreambuf( mstreambuf & );

   virtual int overflow( int = EOF );
   virtual int underflow() { return EOF; }
   virtual int	sync()      { return EOF; }

private:
   void init_mstreambuf( void );
} ;

extern mstreambuf __mout_mstreambuf;
extern ostream mout;

#endif /* !__MOUT_H */
