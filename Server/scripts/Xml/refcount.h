// Author: Grzegorz "Atom" Jagiella
// This file is public domain.

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef __REFCOUNT_H__
#define __REFCOUNT_H__

#ifdef XML_DEBUG
#include <string>
using namespace std;
#endif

// ref counting behavior for Angelscript reference types
class RefCount
{
public:
	RefCount();
	virtual ~RefCount();

	void SetGCFlag();
	bool GetGCFlag();
	int GetRefCount();
	void AddRef();
	void Release();

#ifdef XML_DEBUG
	string TypeId;
#endif

protected:
	mutable int refCount;
};

template<class T>
class RefPtr
{
public:
	RefPtr() : ptr(NULL) { }

	RefPtr(const RefPtr<T>& other)
	{
		ptr=other.ptr;
		if(ptr) ptr->AddRef();
	}

	RefPtr(T* obj)
	{
		ptr=obj;
		if(ptr) ptr->AddRef();
	}

	~RefPtr()
	{
		if(ptr) ptr->Release();
	}

	RefPtr<T>& operator=(const RefPtr<T>& other)
	{
		if(ptr==other.ptr) return *this;
		if(ptr) ptr->Release();
		ptr=other.ptr;
		if(ptr) ptr->AddRef();
		return *this;
	}

	RefPtr<T>& operator=(T* obj)
	{
		if(ptr==obj) return *this;
		if(ptr) ptr->Release();
		ptr=obj;
		if(ptr) ptr->AddRef();
		return *this;
	}

	bool operator==(size_t pptr) const { return ptr==(T*)pptr; }
	
	bool operator!() const { return !ptr; }

	operator T*() const { return ptr; }

    T& operator* () const { return *ptr; }
    T* operator-> () const { return ptr; }

	bool IsNull() const { return ptr==NULL; }

	T* ptr;
};

#endif