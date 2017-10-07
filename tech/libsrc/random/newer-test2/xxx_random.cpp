



//----- (008FB380) --------------------------------------------------------
void __cdecl RandInit(int seed)
{
	gRNGCongruential = CreateRNGCongruential();
	gRNGCongruential->vfptr->Seed(gRNGCongruential, seed);
	gRNGFibonacci = CreateRNGFibonacci();
	gRNGFibonacci->vfptr->Seed(gRNGFibonacci, seed);
}

//----- (008FB3C3) --------------------------------------------------------
void *__cdecl RandShutdown()
{
	void *result; // eax@1

	result = gRNGCongruential;
	if (gRNGCongruential)
		result = gRNGCongruential->vfptr->__vecDelDtor(gRNGCongruential, 1u);
	if (gRNGFibonacci)
		result = gRNGFibonacci->vfptr->__vecDelDtor(gRNGFibonacci, 1u);
	return result;
}

//----- (008FB426) --------------------------------------------------------
void __cdecl RandSeed(int seed)
{
	gRNGFibonacci->vfptr->Seed(gRNGFibonacci, seed);
}

//----- (008FB440) --------------------------------------------------------
int __cdecl RandLong()
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

//----- (008FB489) --------------------------------------------------------
void __cdecl RandSeedQ(int seed)
{
	gRNGCongruential->vfptr->Seed(gRNGCongruential, seed);
}

//----- (008FB4A3) --------------------------------------------------------
int __cdecl RandLongQ()
{
	return gRNGCongruential->vfptr->GetLong(gRNGCongruential);
}

//----- (008FB4B8) --------------------------------------------------------
float __cdecl RandFloatQ()
{
	double v0; // st7@1
	float result; // st7@2

	v0 = RNG::GetFloat(gRNGCongruential);
	LODWORD(result) = LODWORD(v0);
	return result;
}

//----- (008FB4C8) --------------------------------------------------------
float __cdecl RandNormQ()
{
	double v0; // st7@1
	float result; // st7@2

	v0 = RNG::GetNorm(gRNGCongruential);
	LODWORD(result) = LODWORD(v0);
	return result;
}

//----- (008FB4D8) --------------------------------------------------------
int __cdecl RandRangeLongQ(int n)
{
	return RNG::GetRange(gRNGCongruential, n);
}

