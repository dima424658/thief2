//==========================================================================;
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (c) 1992 - 1996  Microsoft Corporation.  All Rights Reserved.
//
//--------------------------------------------------------------------------;

// Class that holds and manages media type information, December 1994

// helper class that derived pin objects can use to compare media
// types etc. Has same data members as the struct AM_MEDIA_TYPE defined
// in the streams IDL file, but also has (non-virtual) functions

#include <mtype.h>
#include <lgassert.h>

CMediaType::~CMediaType(){
    FreeMediaType(*this);
}


CMediaType::CMediaType()
{
    InitMediaType();
}


CMediaType::CMediaType(const GUID * type)
{
    InitMediaType();
    majortype = *type;
}


// copy constructor does a deep copy of the format block

CMediaType::CMediaType(const AM_MEDIA_TYPE& rt)
{
    CopyMediaType(this, &rt);
}

CMediaType::CMediaType(const CMediaType& rt)
{
    CopyMediaType(this, &rt);
}

// this class inherits publicly from AM_MEDIA_TYPE so the compiler could generate
// the following assignment operator itself, however it could introduce some
// memory conflicts and leaks in the process because the structure contains
// a dynamically allocated block (pbFormat) which it will not copy correctly

CMediaType&
CMediaType::operator=(const AM_MEDIA_TYPE& rt)
{
    FreeMediaType(*this);
    CopyMediaType(this, &rt);
    return *this;
}


CMediaType&
CMediaType::operator=(const CMediaType& rt)
{
    *this = (AM_MEDIA_TYPE &) rt;
    return *this;
}

BOOL
CMediaType::operator == (const CMediaType& rt) const
{
    // I don't believe we need to check sample size or
    // temporal compression flags, since I think these must
    // be represented in the type, subtype and format somehow. They
    // are pulled out as separate flags so that people who don't understand
    // the particular format representation can still see them, but
    // they should duplicate information in the format block.

    return ((IsEqualGUID(majortype,rt.majortype) == TRUE) &&
        (IsEqualGUID(subtype,rt.subtype) == TRUE) &&
        (IsEqualGUID(formattype,rt.formattype) == TRUE) &&
        (cbFormat == rt.cbFormat) &&
        ( (cbFormat == 0) ||
          (memcmp(pbFormat, rt.pbFormat, cbFormat) == 0)));
}


BOOL
CMediaType::operator != (const CMediaType& rt) const
{
    /* Check to see if they are equal */

    if (*this == rt) {
        return FALSE;
    }
    return TRUE;
}


BOOL
CMediaType::IsValid() const
{
    return (!IsEqualGUID(majortype,GUID_NULL));
}


void
CMediaType::SetType(const GUID* ptype)
{
    majortype = *ptype;
}


void
CMediaType::SetSubtype(const GUID* ptype)
{
    subtype = *ptype;
}


ULONG
CMediaType::GetSampleSize() const {
    if (IsFixedSize()) {
        return lSampleSize;
    } else {
        return 0;
    }
}


void
CMediaType::SetSampleSize(ULONG sz) {
    if (sz == 0) {
        SetVariableSize();
    } else {
        bFixedSizeSamples = TRUE;
        lSampleSize = sz;
    }
}


void
CMediaType::SetVariableSize() {
    bFixedSizeSamples = FALSE;
}


void
CMediaType::SetTemporalCompression(BOOL bCompressed) {
    bTemporalCompression = bCompressed;
}

BOOL
CMediaType::SetFormat(BYTE * pformat, ULONG cb)
{
    if (NULL == AllocFormatBuffer(cb))
	return(FALSE);

    Assert_(pbFormat);
    memcpy(pbFormat, pformat, cb);
    return(TRUE);
}


// set the type of the media type format block, this type defines what you
// will actually find in the format pointer. For example FORMAT_VideoInfo or
// FORMAT_WaveFormatEx. In the future this may be an interface pointer to a
// property set. Before sending out media types this should be filled in.

void
CMediaType::SetFormatType(const GUID *pformattype)
{
    formattype = *pformattype;
}


// reset the format buffer

void CMediaType::ResetFormatBuffer()
{
    if (cbFormat) {
        CoTaskMemFree((PVOID)pbFormat);
    }
    cbFormat = 0;
    pbFormat = NULL;
}


// allocate length bytes for the format and return a read/write pointer
// If we cannot allocate the new block of memory we return NULL leaving
// the original block of memory untouched (as does ReallocFormatBuffer)

BYTE*
CMediaType::AllocFormatBuffer(ULONG length)
{
    Assert_(length);

    // do the types have the same buffer size

    if (cbFormat == length) {
        return pbFormat;
    }

    // allocate the new format buffer

    BYTE *pNewFormat = (PBYTE)CoTaskMemAlloc(length);
    if (pNewFormat == NULL) {
        if (length <= cbFormat) return pbFormat; //reuse the old block anyway.
        return NULL;
    }

    // delete the old format

    if (cbFormat != 0) {
        Assert_(pbFormat);
        CoTaskMemFree((PVOID)pbFormat);
    }

    cbFormat = length;
    pbFormat = pNewFormat;
    return pbFormat;
}


// reallocate length bytes for the format and return a read/write pointer
// to it. We keep as much information as we can given the new buffer size
// if this fails the original format buffer is left untouched. The caller
// is responsible for ensuring the size of memory required is non zero

BYTE*
CMediaType::ReallocFormatBuffer(ULONG length)
{
    Assert_(length);

    // do the types have the same buffer size

    if (cbFormat == length) {
        return pbFormat;
    }

    // allocate the new format buffer

    BYTE *pNewFormat = (PBYTE)CoTaskMemAlloc(length);
    if (pNewFormat == NULL) {
        if (length <= cbFormat) return pbFormat; //reuse the old block anyway.
        return NULL;
    }

    // copy any previous format (or part of if new is smaller)
    // delete the old format and replace with the new one

    if (cbFormat != 0) {
        Assert_(pbFormat);
        memcpy(pNewFormat,pbFormat,min(length,cbFormat));
        CoTaskMemFree((PVOID)pbFormat);
    }

    cbFormat = length;
    pbFormat = pNewFormat;
    return pNewFormat;
}

// initialise a media type structure

void CMediaType::InitMediaType()
{
    ZeroMemory((PVOID)this, sizeof(*this));
    lSampleSize = 1;
    bFixedSizeSamples = TRUE;
}


// a partially specified media type can be passed to IPin::Connect
// as a constraint on the media type used in the connection.
// the type, subtype or format type can be null.
BOOL
CMediaType::IsPartiallySpecified(void) const
{
    if ((majortype == GUID_NULL) ||
        (subtype == GUID_NULL) ||
        (formattype == GUID_NULL)) {
            return TRUE;
    } else {
        return FALSE;
    }
}

BOOL
CMediaType::MatchesPartial(const CMediaType* ppartial) const
{
    if ((ppartial->majortype != GUID_NULL) &&
        (majortype != ppartial->majortype)) {
            return FALSE;
    }
    if ((ppartial->subtype != GUID_NULL) &&
        (subtype != ppartial->subtype)) {
            return FALSE;
    }

    if (ppartial->formattype != GUID_NULL) {
        // if the format block is specified then it must match exactly
        if (formattype != ppartial->formattype) {
            return FALSE;
        }
        if (cbFormat != ppartial->cbFormat) {
            return FALSE;
        }
        if ((cbFormat != 0) &&
            (memcmp(pbFormat, ppartial->pbFormat, cbFormat) != 0)) {
                return FALSE;
        }
    }

    return TRUE;

}



// general purpose function to delete a heap allocated AM_MEDIA_TYPE structure
// which is useful when calling IEnumMediaTypes::Next as the interface
// implementation allocates the structures which you must later delete
// the format block may also be a pointer to an interface to release

void DeleteMediaType(AM_MEDIA_TYPE *pmt)
{
    // allow NULL pointers for coding simplicity

    if (pmt == NULL) {
        return;
    }

    FreeMediaType(*pmt);
    CoTaskMemFree((PVOID)pmt);
}


// this also comes in useful when using the IEnumMediaTypes interface so
// that you can copy a media type, you can do nearly the same by creating
// a CMediaType object but as soon as it goes out of scope the destructor
// will delete the memory it allocated (this takes a copy of the memory)

AM_MEDIA_TYPE *CreateMediaType(AM_MEDIA_TYPE *pSrc)
{
    Assert_(pSrc);

    // Allocate a block of memory for the media type

    AM_MEDIA_TYPE *pMediaType = (AM_MEDIA_TYPE *)CoTaskMemAlloc(sizeof(AM_MEDIA_TYPE));
    if (pMediaType == NULL) {
        return NULL;
    }

    // Copy the variable length format block

    CopyMediaType(pMediaType,pSrc);
    return pMediaType;
}


//  Copy 1 media type to another

void CopyMediaType(AM_MEDIA_TYPE *pmtTarget, const AM_MEDIA_TYPE *pmtSource)
{
    *pmtTarget = *pmtSource;
    if (pmtSource->cbFormat != 0) {
        Assert_(pmtSource->pbFormat != NULL);
        pmtTarget->pbFormat = (PBYTE)CoTaskMemAlloc(pmtSource->cbFormat);
        if (pmtTarget->pbFormat == NULL) {
            pmtTarget->cbFormat = 0;
        } else {
            CopyMemory((PVOID)pmtTarget->pbFormat, (PVOID)pmtSource->pbFormat,
                       pmtTarget->cbFormat);
        }
    }
    if (pmtTarget->pUnk != NULL) {
        pmtTarget->pUnk->AddRef();
    }
}

//  Free an existing media type (ie free resources it holds)

void FreeMediaType(AM_MEDIA_TYPE& mt)
{
    if (mt.cbFormat != 0) {
        CoTaskMemFree((PVOID)mt.pbFormat);

        // Strictly unnecessary but tidier
        mt.cbFormat = 0;
        mt.pbFormat = NULL;
    }
    if (mt.pUnk != NULL) {
        mt.pUnk->Release();
        mt.pUnk = NULL;
    }
}
// eliminate very many spurious warnings from MS compiler
#pragma warning(disable:4514)
