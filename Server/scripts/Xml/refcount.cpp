// Author: Grzegorz "Atom" Jagiella
// This file is public domain.

#include "refcount.h"
#include <stdio.h>

#ifdef XML_DEBUG
int Created=0;
#endif

RefCount::RefCount() : refCount(1)
{
#ifdef XML_DEBUG
	printf("creating ?(%d), total %d\n", (int)this, ++Created);
#endif
}
RefCount::~RefCount()
{
#ifdef XML_DEBUG
	printf("deleting %s(%d), total %d\n", TypeId.c_str(), (int)this, --Created);
#endif
}

void RefCount::SetGCFlag()
{
	refCount|=0x80000000;
}

bool RefCount::GetGCFlag()
{
	return (refCount&0x80000000) ? true : false;
}

int RefCount::GetRefCount()
{
	return (refCount&0x7FFFFFFF);
}

void RefCount::AddRef()
{
	refCount = (refCount&0x7FFFFFFF) + 1;
#ifdef XML_DEBUG
	printf("addref  %s(%d), post refcount %d\n", TypeId.c_str(), (int)this, refCount);
#endif
}

void RefCount::Release()
{
	refCount&=0x7FFFFFFF;
#ifdef XML_DEBUG
	printf("release %s(%d), post refcount %d\n", TypeId.c_str(), (int)this, refCount-1);
#endif
	if( --refCount == 0 )
		delete this;
}
