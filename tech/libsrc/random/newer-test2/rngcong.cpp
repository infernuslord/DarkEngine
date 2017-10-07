//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "rng.h"
#include "rngcong.h"




//----- (008FB610) --------------------------------------------------------
__thiscall RNGCongruential::RNGCongruential(RNGCongruential* rngc)
{
	RNGCongruential *v1; // ST00_4@1

	v1 = rngc;
	RNG::RNG((RNG*)&v1->var);
	v1->baseclass_0.vfptr = (RNGVtbl *)RNGCongruential::_vftable_;
	v1->seed = 0;
}
// 9A955C: using guessed type int (__stdcall *RNGCongruential___vftable_[4])(int __flags);

//----- (008FB639) --------------------------------------------------------
void __thiscall RNGCongruential::_RNGCongruential(RNGCongruential *this)
{
	this->baseclass_0.vfptr = (RNGVtbl *)RNGCongruential::_vftable_;
	RNG::_RNG(&this->baseclass_0);
}
// 9A955C: using guessed type int (__stdcall *RNGCongruential___vftable_[4])(int __flags);

//----- (008FB655) --------------------------------------------------------
void *__thiscall RNGCongruential::GetState(RNGCongruential *this, int *sz)
{
	RNGCongruential *v2; // ST04_4@1
	void *result; // eax@1

	v2 = this;
	*sz = 8;
	result = operator new(8u);
	*(_DWORD *)result = 23479589;
	*((_DWORD *)result + 1) = v2->seed;
	return result;
}

//----- (008FB698) --------------------------------------------------------
void __thiscall RNGCongruential::SetState(RNGCongruential *this, void *buf)
{
	RNGCongruential *thisa; // [sp+0h] [bp-8h]@1

	thisa = this;
	if (*(_DWORD *)buf != 23479589)
		_CriticalMsg("Invalid state for RNGCongruential::SetState", "x:\\prj\\tech\\libsrc\\random\\rngcong.cpp", 0x21u);
	thisa->seed = *((_DWORD *)buf + 1);
}

//----- (008FB6DD) --------------------------------------------------------
void __thiscall RNGCongruential::Seed(RNGCongruential *this, int sd)
{
	this->seed = sd;
}

//----- (008FB6F3) --------------------------------------------------------
int __thiscall RNGCongruential::GetLong(RNGCongruential *this)
{
	this->seed = 1664525 * this->seed + 12345;
	return this->seed >> 1;
}

//----- (008FB720) --------------------------------------------------------
void *__thiscall RNGCongruential::_scalar_deleting_destructor_(RNGCongruential *this, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	RNGCongruential::_RNGCongruential(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}




/*

__thiscall RNGCongruential::RNGCongruential()
{
	RNGCongruential *v1;

	v1 = (RNGVtbl *)RNGCongruential::SetState();

	v1->seed = 0;
}



__thiscall RNGCongruential::~RNGCongruential()
{
	this->baseclass_0.vfptr = (RNGVtbl *)RNGCongruential::_vftable_;
	RNG::_RNG(&this->baseclass_0);
}

void* __thiscall RNGCongruential::GetState(int *sz)
{
	RNGCongruential *v2; // ST04_4@1
	void *result; // eax@1

	v2 = this;
	*sz = 8;
	result = operator new(8u);
	*(_DWORD *)result = 23479589;
	*((_DWORD *)result + 1) = v2->seed;
	return result;
}


void __thiscall RNGCongruential::SetState(void *buf)
{
	RNGCongruential *thisa; // [sp+0h] [bp-8h]@1

	thisa = this;
	if (*(_DWORD *)buf != 23479589)
		_CriticalMsg("Invalid state for RNGCongruential::SetState", "x:\\prj\\tech\\libsrc\\random\\rngcong.cpp", 0x21u);
	thisa->seed = *((_DWORD *)buf + 1);
}


void __thiscall RNGCongruential::Seed(int sd)
{
	this->
}


int __thiscall RNGCongruential::GetLong()
{
	this->seed = 1664525 * this->seed + 12345;
	return this->seed >> 1;
}


void* __thiscall RNGCongruential::_scalar_deleting_destructor_(unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	RNGCongruential::_RNGCongruential(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}



RNG *__cdecl CreateRNGCongruential()
{
	RNG *v0; // eax@2
	RNG *v2; // [sp+0h] [bp-8h]@2
	void* xxx; // [sp+4h] [bp-4h]@1

	xxx = operator new(8u);
	if (xxx)
	{
		RNGCongruential::RNGCongruential();
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}

*/