//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "rng.h"






__thiscall RNG::RNG(RNG* rng)
{
	rng = this;
	rng->GetFloat = &RNG::GetFloat;
	rng->GetLong = &RNG::GetLong;
	rng->GetNorm = &RNG::GetNorm;
	rng->GetRange = &RNG::GetRange;
	rng->GetState = &RNG::GetState;
	rng->Seed = &RNG::Seed;
	rng->SetState = &RNG::SetState;
	rng->_vector_deleting_destructor_ = &RNG::_vector_deleting_destructor_;

	//this->vfptr = (RNGVtbl *)&RNG::_vftable_;
}

void* __thiscall RNG::_vector_deleting_destructor_(RNG *rng, unsigned int __flags)
{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	RNG::~RNG();
	if (__flags & 1)
		operator delete(thisa);
	return thisa;
}








/*
__thiscall RNG::~RNG()
{
	this->vfptr = (RNGVtbl *)&RNG::_vftable_;
}
*/


	
	/*
	//----- (008FB750) --------------------------------------------------------
	__thiscall RNG::RNG()
	{
	RNG* vfptr = (RNGVtbl *)&RNG::RNG();
	}



	float __thiscall RNG::GetFloat()
	{
	double v1;
	float result;

	v1 = COERCE_FLOAT((unsigned int)loc_7FFFFF & ((int(*)(void))this->vfptr.GetLong()) | 0x3F800000) - 1.0;
	v1 =
	LODWORD(result) = LODWORD(v1);
	return result;
	}


	float __thiscall RNG::GetNorm()
	{
	RNG *v1;
	double v2;
	double v3;
	int v4;
	double v5;
	double v6;
	int v7;
	double v8;
	double v9;
	double v10;
	int v11;
	double v12;
	float result;

	v1 = this;
	v2 = RNG::GetFloat();
	v3 = v2;
	log(v4, SLOBYTE(v3));
	v5 = v2 * -2.0;
	v6 = v5;
	sqrt(v7, SLOBYTE(v6));
	v8 = v5;
	v9 = RNG::GetFloat() * 6.283185307179586;
	v10 = v9;
	cos(v11, SLOBYTE(v10));
	v12 = v9 * v8;
	LODWORD(result) = LODWORD(v12);
	return result;
	}

	long __thiscall RNG::GetRange(long max)
	{
	return ((long)this.GetFloat())(this) % max;
	}










	void* __thiscall RNG::_vector_deleting_destructor_(unsigned int __flags)
	{
	void *thisa; // [sp+0h] [bp-4h]@1

	thisa = this;
	RNG::~RNG();
	if (__flags & 1)
	operator delete(thisa);
	return thisa;
	}

	//----- (008FB7A0) --------------------------------------------------------
	__thiscall RNG::~RNG()
	{
	this->vfptr = (RNGVtbl *)&RNG::_vftable_;
	}
	// 9A9570: using guessed type int (__stdcall *RNG___vftable_)(int __flags);



*/



