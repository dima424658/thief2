//        LZW.H       Header file for LZW compressor/expander (see lzw.c for info)
//        Rex E. Bradford (REX)
/*
* $Header: x:/prj/tech/libsrc/res/RCS/lzw.h 1.11 1997/01/06 17:51:27 TOML Exp $
*/

#ifndef __LZW_H
#define __LZW_H

#ifdef __cplusplus
extern "C"
{
#endif

//  Options

//#define OPTIMIZED_LZW_EXPAND_FD2BUFF        // uncomment for hard-coded routine

//  Initialization and shutdown

void LzwInit(void);                                      // Justs sets AtExit routine (LzwTerm)
void LzwTerm(void);                                      // Calls LzwFreeBuffer()

//  Lzw buffer management (if lzw compress/expand routine called and no
//  buffer has been set or allocated, one will automatically be allocated).

int LzwSetBuffer(void *buff, long buffSize);         // Set buffer for lzw use
int LzwMallocBuffer();                                   // Malloc buffer for lzw use
void LzwFreeBuffer();                                    // free alloced buffer if any

//  Sizing constants (just needed to define LZW_BUFF_SIZE)

#define LZW_BITS 14                          // # bits in compress codes (12,13,14)

#if LZW_BITS == 14
#define LZW_TABLE_SIZE 18041                             /* The string table size needs to be a  */
#endif /* prime number that is somwhat larger  */
#if LZW_BITS == 13                                       /* than 2**BITS.                                 */
#define LZW_TABLE_SIZE 9029
#endif
#if LZW_BITS <= 12
#define LZW_TABLE_SIZE 5021
#endif

#define LZW_FD_READ_BUFF_SIZE   8192
#define LZW_FD_WRITE_BUFF_SIZE  8192
#define LZW_DECODE_STACK_SIZE   4096
#define LZW_TABLE_BUFF_SIZE     18044


//  LzwSetBuffer() requires a buffer of at least this size:

typedef short  tLzwCodeValue;
typedef uint   tLzwPrefixCode;
typedef uchar  tLzwAppendChar;

#define LZW_BUFF_SIZE (LZW_DECODE_STACK_SIZE + LZW_FD_READ_BUFF_SIZE + LZW_FD_WRITE_BUFF_SIZE + \
    (LZW_TABLE_BUFF_SIZE * (sizeof(tLzwCodeValue) + sizeof(tLzwPrefixCode) + sizeof(tLzwAppendChar))))


//  Other constants

typedef enum
{
    BEGIN, END, SUSPEND, RESUME
} LzwCtrl;                                                   // LzwCtrl's used to start/stop lzw
 // data sources and destinations

#define LZW_MAXSIZE 0x7FFFFFFFL     // maximum output size

//  Overall buffer info

extern void *lzwBuffer;                                  // total buffer
extern bool lzwBufferMalloced;                       // buffer malloced?

//  The Ginzo compression knife

typedef void (*tLzwCompressCtrlFunc) (long srcOrDestLoc, LzwCtrl ctrl);
typedef uchar(*tLzwCompressSrcGetFunc) (void);
typedef void (*tLzwCompressDestPutFunc) (uchar);

long LzwCompress( tLzwCompressCtrlFunc f_SrcCtrl,// func to control source
                        tLzwCompressSrcGetFunc f_SrcGet,          // func to get bytes from source
                        long srcLoc,                         // source "location" (ptr, FILE *, etc.)
                        long srcSize,                        // size of source in bytes
                        tLzwCompressCtrlFunc f_DestCtrl,          // func to control dest
                        tLzwCompressDestPutFunc f_DestPut,    // func to put bytes to dest
                        long destLoc,                        // dest "location" (ptr, FILE *, etc.)
                        long destSizeMax                     // max size of dest (or LZW_MAXSIZE)
                     );
//  And its expansion counterpart, both for $19.95 while supplies last

long LzwExpand( tLzwCompressCtrlFunc f_SrcCtrl,  // func to control source
                     tLzwCompressSrcGetFunc f_SrcGet, // func to get bytes from source
                     long srcLoc,                            // source "location" (ptr, FILE *, etc.)
                     tLzwCompressCtrlFunc f_DestCtrl, // func to control dest
                     tLzwCompressDestPutFunc f_DestPut,       // func to put bytes to dest
                     long destLoc,                           // dest "location" (ptr, FILE *, etc.)
                     long destSkip,                      // # dest bytes to skip over (or 0)
                     long destSize                           // # dest bytes to capture (if 0, all)
                     );
// But, if you order RIGHT NOW, you also get this fine partial expander!

long LzwExpandPartial( tLzwCompressCtrlFunc f_SrcCtrl,  // func to control source
                              tLzwCompressSrcGetFunc f_SrcGet, // func to get bytes from source
                              long srcLoc,                   // source "location" (ptr, FILE *, etc.)
                              tLzwCompressCtrlFunc f_DestCtrl, // func to control dest
                              tLzwCompressDestPutFunc f_DestPut,         // func to put bytes to dest
                              long destLoc,              // dest "location" (ptr, FILE *, etc.)
                              long destSkip,                 // # dest bytes to skip over (or 0)
                              long destSize,                 // # dest bytes to capture (if 0, all)
                              void *state,                   // internal state structure
                              long cycles                    // how many iterations of actual processing
                          );

void LzwExpandPartialStart( tLzwCompressCtrlFunc f_SrcCtrl,      // func to control source
                                     tLzwCompressSrcGetFunc f_SrcGet,    // func to get bytes from source
                                     long srcLoc,            // source "location" (ptr, FILE *, etc.)
                                     tLzwCompressCtrlFunc f_DestCtrl,    // func to control dest
                                     tLzwCompressDestPutFunc f_DestPut,  // func to put bytes to dest
                                     long destLoc,           // dest "location" (ptr, FILE *, etc.)
                                     long destSkip,      // # dest bytes to skip over (or 0)
                                     long destSize,      // # dest bytes to capture (if 0, all)
                                     void *state,            // internal state structure
                                     uchar * buffer      // buffer for storing "global" lzw state
                                  );
// this must change if the LzwE struct size changes!
#define LZW_PARTIAL_STATE_SIZE      ((sizeof(int) * 5) + (sizeof(long) * 4) + (sizeof(uchar *) * 5))

//  Macros which implement all the varied compression forms, using the
//  standard supplied sources and destinations, or user-supplied ones.
//
//  LzwCompressBuff2Buff     - src is memory block, dest is memory block
//  LzwCompressBuff2Fd  - src is memory block, dest is file desc (int fd)
//  LzwCompressBuff2Fp  - src is memory block, dest is file ptr (FILE *fp)
//  LzwCompressBuff2Null     - src is memory block, no dest (used to find size)
//  LzwCompressBuff2User     - src is memory buffer, dest is user-supplied
//  LzwCompressFd2Buff  - src is file desc (int fd), dest is memory block
//  LzwCompressFd2Fd         - src is file desc, dest is file desc
//  LzwCompressFd2Fp             - src is file desc, dest is file ptr
//  LzwCompressFd2Null  - src is file desc, no dest (used to find size)
//  LzwCompressFd2User  - src is file desc, dest is user-supplied
//  LzwCompressFp2Buff  - src is file ptr (FILE *fp), dest is memory block
//  LzwCompressFp2Fd         - src is file ptr, dest is file desc
//  LzwCompressFp2Fp             - src is file ptr, dest is file ptr
//  LzwCompressFp2Null  - src is file ptr, no dest (used to find size)
//  LzwCompressFp2User  - src is file ptr, dest is user-supplied
//  LzwCompressUser2Buff     - src is user-supplied, dest is memory block
//  LzwCompressUser2Fd  - src is user-supplied, dest is file desc (int fd)
//  LzwCompressUser2Fp  - src is user-supplied, dest is file ptr (FILE *fp)
//  LzwCompressUser2Null     - src is user-supplied, no dest (used to find size)
//  LzwCompressUser2User     - src is user-supplied, dest is user-supplied

#define LzwCompressBuff2Buff(psrc, srcSize, pdest, destSizeMax) \
     LzwCompress(LzwBuffSrcC(psrc, srcSize), LzwBuffDestC(pdest, destSizeMax))

#define LzwCompressBuff2Fd(psrc, srcSize, fdDest) \
     LzwCompress(LzwBuffSrcC(psrc, srcSize), LzwFdDestC(fdDest))

#define LzwCompressBuff2Fp(psrc, srcSize, fpDest) \
     LzwCompress(LzwBuffSrcC(psrc, srcSize), LzwFpDestC(fpDest))

#define LzwCompressBuff2Null(psrc, srcSize) \
     LzwCompress(LzwBuffSrcC(psrc, srcSize), LzwNullDestC())

#define LzwCompressBuff2User(psrc, srcSize, f_destCtrl, f_destPut, destLoc, \
     destSizeMax) \
     LzwCompress(LzwBuffSrcC(psrc, srcSize), f_destCtrl, f_destPut, destLoc, destSizeMax)


#define LzwCompressFd2Buff(fdSrc, srcSize, pdest, destSizeMax) \
     LzwCompress(LzwFdSrcC(fdSrc, srcSize), LzwBuffDestC(pdest, destSizeMax))

#define LzwCompressFd2Fd(fdSrc, srcSize, fdDest) \
     LzwCompress(LzwFdSrcC(fdSrc, srcSize), LzwFdDestC(fdDest))

#define LzwCompressFd2Fp(fdSrc, srcSize, fpDest) \
     LzwCompress(LzwFdSrcC(fdSrc, srcSize), LzwFpDestC(fpDest))

#define LzwCompressFd2Null(fdSrc, srcSize) \
     LzwCompress(LzwFdSrcC(fdSrc, srcSize), LzwNullDestC())

#define LzwCompressFd2User(fdSrc, srcSize, f_destCtrl, f_destPut, destLoc, \
     destSizeMax) \
     LzwCompress(LzwFdSrcC(fdSrc, srcSize), f_destCtrl, f_destPut, destLoc, destSizeMax)


#define LzwCompressFp2Buff(fpSrc, srcSize, pdest, destSizeMax) \
     LzwCompress(LzwFpSrcC(fpSrc, srcSize), LzwBuffDestC(pdest, destSizeMax))

#define LzwCompressFp2Fd(fpSrc, srcSize, fdDest) \
     LzwCompress(LzwFpSrcC(fpSrc, srcSize), LzwFdDestC(fdDest))

#define LzwCompressFp2Fp(fpSrc, srcSize, fpDest) \
     LzwCompress(LzwFpSrcC(fpSrc, srcSize), LzwFpDestC(fpDest))

#define LzwCompressFp2Null(fpSrc, srcSize) \
     LzwCompress(LzwFpSrcC(fpSrc, srcSize), LzwNullDestC())

#define LzwCompressFp2User(fpSrc, srcSize, f_destCtrl, f_destPut, destLoc, \
     destSizeMax) \
     LzwCompress(LzwFpSrcC(fpSrc, srcSize), f_destCtrl, f_destPut, destLoc, destSizeMax)


#define LzwCompressUser2Buff(f_SrcCtrl, f_SrcGet, srcLoc, srcSize, pdest, destSizeMax) \
     LzwCompress(f_SrcCtrl, f_SrcGet, srcLoc, srcSize, LzwBuffDestC(pdest, destSizeMax))

#define LzwCompressUser2Fd(f_SrcCtrl, f_SrcGet, srcLoc, srcSize, fdDest) \
     LzwCompress(f_SrcCtrl, f_SrcGet, srcLoc, srcSize, LzwFdDestC(fdDest))

#define LzwCompressUser2Fp(f_SrcCtrl, f_SrcGet, srcLoc, srcSize, fpDest) \
     LzwCompress(f_SrcCtrl, f_SrcGet, srcLoc, srcSize, LzwFpDestC(fpDest))

#define LzwCompressUser2Null(f_SrcCtrl, f_SrcGet, srcLoc, srcSize) \
     LzwCompress(f_SrcCtrl, f_SrcGet, srcLoc, srcSize, LzwNullDestC())

#define LzwCompressUser2User(f_SrcCtrl, f_SrcGet, srcLoc, srcSize, \
     f_DestCtrl, f_DestPut, destLoc, destSizeMax) \
     LzwCompress(f_SrcCtrl, f_SrcGet, srcLoc, srcSize, \
     f_DestCtrl, f_DestPut, destLoc, destSizeMax)

//  These macros are used to help implement the compression macros

#define LzwBuffSrcC(psrc,srcSize) LzwBuffSrcCtrl, LzwBuffSrcGet, (long) psrc, srcSize
#define LzwFdSrcC(fdSrc,srcSize) LzwFdSrcCtrl, LzwFdSrcGet, (long) fdSrc, srcSize
#define LzwFpSrcC(fpSrc,srcSize) LzwFpSrcCtrl, LzwFpSrcGet, (long) fpSrc, srcSize

#define LzwBuffDestC(pdest,destSizeMax) LzwBuffDestCtrl, LzwBuffDestPut, (long) pdest, destSizeMax
#define LzwFdDestC(fdDest) LzwFdDestCtrl, LzwFdDestPut, (long) fdDest, LZW_MAXSIZE
#define LzwFpDestC(fpDest) LzwFpDestCtrl, LzwFpDestPut, (long) fpDest, LZW_MAXSIZE
#define LzwNullDestC() LzwNullDestCtrl, LzwNullDestPut, NULL, LZW_MAXSIZE


//  Macros which implement all the varied expansionn forms, using the
//  standard supplied sources and destinations, or user-supplied ones.
//
//  LzwExpandBuff2Buff  - src is memory block, dest is memory block
//  LzwExpandBuff2Fd             - src is memory block, dest is file desc (int fd)
//  LzwExpandBuff2Fp             - src is memory block, dest is file ptr (FILE *fp)
//  LzwExpandBuff2Null  - src is memory block, no dest (used to find size)
//  LzwExpandBuff2User  - src is memory buffer, dest is user-supplied
//  LzwExpandFd2Buff             - src is file desc (int fd), dest is memory block
//  LzwExpandFd2Fd           - src is file desc, dest is file desc
//  LzwExpandFd2Fp           - src is file desc, dest is file ptr
//  LzwExpandFd2Null             - src is file desc, no dest (used to find size)
//  LzwExpandFd2User             - src is file desc, dest is user-supplied
//  LzwExpandFp2Buff             - src is file ptr (FILE *fp), dest is memory block
//  LzwExpandFp2Fd           - src is file ptr, dest is file desc
//  LzwExpandFp2Fp           - src is file ptr, dest is file ptr
//  LzwExpandFp2Null             - src is file ptr, no dest (used to find size)
//  LzwExpandFp2User             - src is file ptr, dest is user-supplied
//  LzwExpandUser2Buff  - src is user-supplied, dest is memory block
//  LzwExpandUser2Fd             - src is user-supplied, dest is file desc (int fd)
//  LzwExpandUser2Fp             - src is user-supplied, dest is file ptr (FILE *fp)
//  LzwExpandUser2Null  - src is user-supplied, no dest (used to find size)
//  LzwExpandUser2User  - src is user-supplied, dest is user-supplied

#define LzwExpandBuff2Buff(psrc, pdest, destSkip, destSize) \
     LzwExpand(LzwBuffSrcE(psrc), LzwBuffDestE(pdest, destSkip, destSize))

#define LzwExpandBuff2Fd(psrc, fdDest, destSkip, destSize) \
     LzwExpand(LzwBuffSrcE(psrc), LzwFdDestE(fdDest, destSkip, destSize))

#define LzwExpandBuff2Fp(psrc, fpDest, destSkip, destSize) \
     LzwExpand(LzwBuffSrcE(psrc), LzwFpDestE(fpDest, destSkip, destSize))

#define LzwExpandBuff2Null(psrc, destSkip, destSize) \
     LzwExpand(LzwBuffSrcE(psrc), LzwNullDestE(destSkip, destSize))

#define LzwExpandBuff2User(psrc, f_destCtrl, f_destPut, destLoc, destSkip, destSize) \
     LzwExpand(LzwBuffSrcE(psrc), f_destCtrl, f_destPut, destLoc, destSkip, destSize)

#ifdef OPTIMIZED_LZW_EXPAND_FD2BUFF

long LzwExpandFd2Buff(int fdSrc, uchar * pdest, long destSkip, long destSize);
#else

#define LzwExpandFd2Buff(fdSrc, pdest, destSkip, destSize) \
     LzwExpand(LzwFdSrcE(fdSrc), LzwBuffDestE(pdest, destSkip, destSize))

#endif

#define LzwExpandFd2Fd(fdSrc, fdDest, destSkip, destSize) \
     LzwExpand(LzwFdSrcE(fdSrc), LzwFdDestE(fdDest, destSkip, destSize))

#define LzwExpandFd2Fp(fdSrc, fpDest, destSkip, destSize) \
     LzwExpand(LzwFdSrcE(fdSrc), LzwFpDestE(fpDest, destSkip, destSize))

#define LzwExpandFd2Null(fdSrc, destSkip, destSize) \
     LzwExpand(LzwFdSrcE(fdSrc), LzwNullDestE(destSkip, destSize))

#define LzwExpandFd2User(fdSrc, f_destCtrl, f_destPut, destLoc, destSkip, destSize) \
     LzwExpand(LzwFdSrcE(fdSrc), f_destCtrl, f_destPut, destLoc, destSkip, destSize)


#define LzwExpandFp2Buff(fpSrc, pdest, destSkip, destSize) \
     LzwExpand(LzwFpSrcE(fpSrc), LzwBuffDestE(pdest, destSkip, destSize))

#define LzwExpandFp2Fd(fpSrc, fdDest, destSkip, destSize) \
     LzwExpand(LzwFpSrcE(fpSrc), LzwFdDestE(fdDest, destSkip, destSize))

#define LzwExpandFp2Fp(fpSrc, fpDest, destSkip, destSize) \
     LzwExpand(LzwFpSrcE(fpSrc), LzwFpDestE(fpDest, destSkip, destSize))

#define LzwExpandFp2Null(fpSrc, destSkip, destSize) \
     LzwExpand(LzwFpSrcE(fpSrc), LzwNullDestE(destSkip, destSize))

#define LzwExpandFp2User(fpSrc, f_destCtrl, f_destPut, destLoc, destSkip, destSize) \
     LzwExpand(LzwFpSrcE(fpSrc), f_destCtrl, f_destPut, destLoc, destSkip, destSize)


#define LzwExpandUser2Buff(f_SrcCtrl, f_SrcGet, srcLoc, pdest, destSkip, destSize) \
     LzwExpand(f_SrcCtrl, f_SrcGet, srcLoc, LzwBuffDestE(pdest, destSkip, destSize))

#define LzwExpandUser2Fd(f_SrcCtrl, f_SrcGet, srcLoc, fdDest, destSkip, destSize) \
     LzwExpand(f_SrcCtrl, f_SrcGet, srcLoc, LzwFdDestE(fdDest, destSkip, destSize))

#define LzwExpandUser2Fp(f_SrcCtrl, f_SrcGet, srcLoc, fpDest, destSkip, destSize) \
     LzwExpand(f_SrcCtrl, f_SrcGet, srcLoc, LzwFpDestE(fpDest, destSkip, destSize))

#define LzwExpandUser2Null(f_SrcCtrl, f_SrcGet, srcLoc, destSkip, destSize) \
     LzwExpand(f_SrcCtrl, f_SrcGet, srcLoc, LzwNullDestE(destSkip, destSize))

#define LzwExpandUserUser(f_SrcCtrl, f_SrcGet, srcLoc, f_DestCtrl, f_DestPut, \
     destLoc, destSkip, destSize) \
     LzwExpand(f_SrcCtrl, f_SrcGet, srcLoc, f_DestCtrl, f_DestPut, destLoc, destSkip, destSize)

// partial buffer expansion
// currently only buffer to buffer is supported for partial expansion!!

#define LzwExpandBuff2BuffPartialStart(psrc, pdest, destSkip, destSize, state, buff) \
     LzwExpandPartialStart(LzwBuffSrcE(psrc), LzwBuffDestE(pdest, destSkip, destSize), state, buff)
#define LzwExpandBuff2BuffPartial(psrc, pdest, destSkip, destSize, state, cycles) \
     LzwExpandPartial(LzwBuffSrcE(psrc), LzwBuffDestE(pdest, destSkip, destSize), state, cycles)

//  These macros are used to help implement the expansion macros

#define LzwBuffSrcE(psrc) LzwBuffSrcCtrl, LzwBuffSrcGet, (long) psrc
#define LzwFdSrcE(fdSrc) LzwFdSrcCtrl, LzwFdSrcGet, (long) fdSrc
#define LzwFpSrcE(fpSrc) LzwFpSrcCtrl, LzwFpSrcGet, (long) fpSrc

#define LzwBuffDestE(pdest, destSkip, destSize) \
     LzwBuffDestCtrl, LzwBuffDestPut, (long) pdest, destSkip, destSize
#define LzwFdDestE(fdDest, destSkip, destSize) \
     LzwFdDestCtrl, LzwFdDestPut, (long) fdDest, destSkip, destSize
#define LzwFpDestE(fpDest, destSkip, destSize) \
     LzwFpDestCtrl, LzwFpDestPut, (long) fpDest, destSkip, destSize
#define LzwNullDestE(destSkip, destSize) \
     LzwNullDestCtrl, LzwNullDestPut, NULL, destSkip, destSize

//  Prototypes of standard sources

void LzwBuffSrcCtrl(long srcLoc, LzwCtrl ctrl);
uchar LzwBuffSrcGet();
void LzwFdSrcCtrl(long srcLoc, LzwCtrl ctrl);
uchar LzwFdSrcGet();
void LzwFpSrcCtrl(long srcLoc, LzwCtrl ctrl);
uchar LzwFpSrcGet();
//  Prototypes of standard destinations

void LzwBuffDestCtrl(long destLoc, LzwCtrl ctrl);
void LzwBuffDestPut(uchar b);
void LzwFdDestCtrl(long destLoc, LzwCtrl ctrl);
void LzwFdDestPut(uchar b);
void LzwFpDestCtrl(long destLoc, LzwCtrl ctrl);
void LzwFpDestPut(uchar b);
void LzwNullDestCtrl(long destLoc, LzwCtrl ctrl);
void LzwNullDestPut(uchar b);

#ifdef __cplusplus
};
#endif

#endif
