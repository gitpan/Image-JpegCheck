/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.19 from the
 * contents of JpegCheck.xs. Do not edit this file, edit JpegCheck.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "JpegCheck.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "ppport.h"

#define SIZE_FIRST  0xC0
#define SIZE_LAST   0xC3

#define RET(n) XSRETURN_IV((n))

#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#line 25 "JpegCheck.c"

XS(XS_Image__JpegCheck__is_jpeg); /* prototype to pass -Wmissing-prototypes */
XS(XS_Image__JpegCheck__is_jpeg)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       Perl_croak(aTHX_ "Usage: %s(%s)", "Image::JpegCheck::_is_jpeg", "fp");
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 18 "JpegCheck.xs"
    unsigned char buf[4];
    long len;
#line 44 "JpegCheck.c"
	PerlIO *	fp = IoIFP(sv_2io(ST(0)));
#line 21 "JpegCheck.xs"
    /* jpeg magick */
    if (PerlIO_getc(fp) != 0xFF || PerlIO_getc(fp) != 0xD8) {
        XSRETURN_NO;
    }

    /* validate segments */
    while (1) {
        if (PerlIO_read(fp, buf, 4) != 4) {
            XSRETURN_NO;
        }

        if (buf[0] != 0xFF) {
            XSRETURN_NO; /* invalid marker */
        }
        if ((buf[1] >= SIZE_FIRST) && (buf[1] <= SIZE_LAST)) {
            XSRETURN_YES;
        }

        /* skip segment body */
        len = (buf[2]<<8) | buf[3]; /* network byte order */
        if (PerlIO_seek(fp, len-2, SEEK_CUR) != 0) {
            XSRETURN_NO;
        }
    }
#line 71 "JpegCheck.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Image__JpegCheck); /* prototype to pass -Wmissing-prototypes */
XS(boot_Image__JpegCheck)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    char* file = __FILE__;

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
    XS_VERSION_BOOTCHECK ;

        newXS("Image::JpegCheck::_is_jpeg", XS_Image__JpegCheck__is_jpeg, file);
    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}
