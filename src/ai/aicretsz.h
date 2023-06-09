/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

///////////////////////////////////////////////////////////////////////////////
// $Header: r:/t2repos/thief2/src/ai/aicretsz.h,v 1.2 2000/01/29 12:45:11 adurant Exp $
//
//
//
#pragma once

#ifndef __AICRETSZ_H
#define __AICRETSZ_H

///////////////////////////////////////////////////////////////////////////////

void AICreatureSizeInit();

///////////////////////////////////////////////////////////////////////////////

struct sAICreatureSize
{
   float width;
   float height;
};

///////////////////////////////////////

struct sAICreatureSizes
{
   sAICreatureSize sizes[8];
};

///////////////////////////////////////

extern sAICreatureSizes * g_pAICreatureSizes;

///////////////////////////////////////////////////////////////////////////////

#endif /* !__AICRETSZ_H */
