/*
 * $Source: x:/prj/tech/libsrc/dump/RCS/dump.h $
 * $Revision: 1.5 $
 * $Author: JAEMZ $
 * $Date: 1999/08/23 14:51:23 $
 *
 * Screen Dumping library include file
 *
*/

#ifndef __DUMP_H
#define __DUMP_H

// These dump the 

// needs no buffer, writes out 8 bit pcx or 24 bit
// return -1 if unsuccessful
EXTERN BOOL dmp_pcx_dump_screen(char *pFileName);

// needs no buffer, writes out 8 bit or 24 bit bmp
// return -1 if unsuccessful
EXTERN BOOL dmp_bmp_dump_screen(char *pFileName);


/* Finds the free file in a sequence like
 * "<prefix>000.<suffix>", tries to open it,
 * and stuffs it into buffer.
 * maximum prefix is 5 letters long.
 * maximum suffix is 3 letters long
 * numbers the files in oct.
 * Returns FALSE if unable to open
*/
EXTERN BOOL dmp_find_free_file(char *buff,char *prefix,char *suffix);

// Finds a free file of prefix, "pcx" suffix and tries to write.
// returns FALSE if unsuccessful
// copies name into buff if successful
EXTERN BOOL dmp_pcx_file(char *buff,char *prefix);

// Finds a free file of prefix, "bmp" suffix and tries to write.
// returns FALSE if unsuccessful
// copies name into buff if successful
EXTERN BOOL dmp_bmp_file(char *buff,char *prefix);

#endif




