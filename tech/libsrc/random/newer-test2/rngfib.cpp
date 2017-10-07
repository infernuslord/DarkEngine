#include <windows.h>
#include <lg.h>
#include <comtools.h>


#include "rngfib.h"
#include "rng.h"





void __thiscall RNGFibonacci::RNGFibonacci(RNGFibonacci *this)
{
	RNGFibonacci *thisa; // [sp+0h] [bp-8h]@1
	signed int ix; // [sp+4h] [bp-4h]@1

	thisa = this;
	RNG::RNG(&this->baseclass_0);
	thisa->baseclass_0.vfptr = (RNGVtbl *)RNGFibonacci::_vftable_;
	thisa->pI = thisa->data;
	thisa->pJ = thisa->pI + 31;
	for (ix = 0; ix < 55; ++ix)
		thisa->data[ix] = 0;

















/*
__thiscall RNGFibonacci::RNGFibonacci()
{
	RNGFibonacci *thisa; // [sp+0h] [bp-8h]@1
	signed int ix; // [sp+4h] [bp-4h]@1

	thisa = this;
	thisa->
	(RNGVtbl *)RNGFibonacci::_vftable_;
	thisa->pI = thisa->data;
	thisa->pJ = thisa->pI + 31;
	for (ix = 0; ix < 55; ++ix)
		thisa->data[ix] = 0;
}


__thiscall RNGFibonacci::~RNGFibonacci()
{
	this->baseclass_0.vfptr = (RNGVtbl *)RNGFibonacci::_vftable_;
	RNG::~RNG(&this->baseclass_0);
}
// 9A9584: using guessed type int (__stdcall *RNGFibonacci___vftable_[4])(int __flags);

//----- (008FB840) --------------------------------------------------------
void* __thiscall RNGFibonacci::GetState(int *sz)
{
	RNGFibonacci *v2; // ST0C_4@1
	void *v3; // eax@1
	void *v4; // ST14_4@1

	v2 = this;
	*sz = 228;
	v3 = operator new(0xE4u);
	v4 = v3;
	*(_DWORD *)v3 = 21796;
	*((_DWORD *)v3 + 1) = (signed int)((char *)v2->pI - (signed int)v2->data) >> 2;
	memcpy((char *)v3 + 8, v2->data, 0xDCu);
	return v4;
}

//----- (008FB8AC) --------------------------------------------------------
void __thiscall RNGFibonacci::SetState(void *buf)
{
	RNGFibonacci *thisa; // [sp+0h] [bp-8h]@1

	thisa = this;
	if (*(_DWORD *)buf != 21796 || *((_DWORD *)buf + 1) >= 55)
		_CriticalMsg("Invalid state for RNGFibonacci::SetState", "x:\\prj\\tech\\libsrc\\random\\rngfib.cpp", 0x28u);
	thisa->pI = &thisa->data[*((_DWORD *)buf + 1)];
	thisa->pJ = thisa->pI + 31;
	if ((signed int)((char *)thisa->pJ - (signed int)thisa->data) >> 2 > 55)
		thisa->pJ -= 55;
	memcpy(thisa->data, (char *)buf + 8, 0xDCu);
}

//----- (008FB953) --------------------------------------------------------
void __thiscall RNGFibonacci::Seed(int seed)
{
	RNGFibonacci *thisa; // [sp+4h] [bp-14h]@1
	signed int i; // [sp+10h] [bp-8h]@1
	signed int ia; // [sp+10h] [bp-8h]@4
	RNG *cong; // [sp+14h] [bp-4h]@1

	thisa = this;
	cong = CreateRNGCongruential();
	cong->vfptr->Seed(cong, seed);
	thisa->data[0] = 2147483647;
	for (i = 1; i < 55; ++i)
		thisa->data[i] = cong->vfptr->GetLong(cong);
	for (ia = 0; ia < 1000; ++ia)
		thisa->baseclass_0.vfptr->GetLong((RNG *)thisa);
	if (cong)
		cong->vfptr->__vecDelDtor(cong, 1u);
}

//----- (008FBA04) --------------------------------------------------------
int __thiscall RNGFibonacci::GetLong()
{
	++this->pI;
	if (this->pI >= (unsigned int *)&this[1])
		this->pI = this->data;
	++this->pJ;
	if (this->pJ >= (unsigned int *)&this[1])
		this->pJ = this->data;
	*this->pI ^= *this->pJ;
	return *this->pI;
}

//----- (008FBA90) --------------------------------------------------------
void* __thiscall RNGFibonacci::_scalar_deleting_destructor_(unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	RNGFibonacci::_RNGFibonacci(this);
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}

//----- (008FB5CF) --------------------------------------------------------
RNG* __cdecl CreateRNGFibonacci()
{
	RNG *v0; // eax@2
	RNG *v2; // [sp+0h] [bp-8h]@2
	void *this; // [sp+4h] [bp-4h]@1

	this = operator new(0xE8u);
	if (this)
	{
		RNGFibonacci::RNGFibonacci((RNGFibonacci *)this);
		v2 = v0;
	}
	else
	{
		v2 = 0;
	}
	return v2;
}


//----- (008FB426) --------------------------------------------------------
void __cdecl RandSeed(int seed)
{
	gRNGFibonacci->vfptr->Seed(gRNGFibonacci, seed);
}

//----- (008FB440) --------------------------------------------------------
RNG* __cdecl RandLong()
{
	return gRNGFibonacci->vfptr->GetLong(gRNGFibonacci);
}

//----- (008FB455) --------------------------------------------------------
float __cdecl RandFloat()
{
	double v0; // st7@1
	float result; // st7@2

	v0 = RNG::GetFloat(gRNGFibonacci);
	LODWORD(result) = LODWORD(v0);
	return result;
}

//----- (008FB465) --------------------------------------------------------
float __cdecl RandNorm()
{
	double v0; // st7@1
	float result; // st7@2

	v0 = RNG::GetNorm(gRNGFibonacci);
	LODWORD(result) = LODWORD(v0);
	return result;
}

//----- (008FB475) --------------------------------------------------------
int __cdecl RandRangeLong(int n)
{
	return RNG::GetRange(gRNGFibonacci, n);
}




*/