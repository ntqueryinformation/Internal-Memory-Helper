#include <Windows.h>
#include <intrin.h>
#include <iostream>
int String_Size(const char* str)
{
	int Size = 0;
	while (str[Size] != '\0') Size++;
	return Size;
}
#pragma region Writing
void WriteInt32(uintptr_t address, int value)
{
	*reinterpret_cast<int*>(address) = value;
}
void WriteString(uintptr_t address, const char* value, bool NullTerminator = true)
{
	for (int i = 0; i < String_Size(value); i++)
	{
		*reinterpret_cast<uint8_t*>(address + (uintptr_t)i) = value[i];
	}
	if (NullTerminator)
	{
		*reinterpret_cast<uint8_t*>(address + (uintptr_t)String_Size(value)) = '\0';
	}
}
void WriteFloat(uintptr_t address,float value)
{
	*reinterpret_cast<float*>(address) = value;
}
void WriteDouble(uintptr_t address, double value)
{
	*reinterpret_cast<double*>(address) = value;
}
void WriteInt64(uintptr_t address, uintptr_t value)
{
	*reinterpret_cast<uintptr_t*>(address) = value;
}
#pragma endregion

#pragma region Reading
int ReadInt(uintptr_t address)
{
	return *reinterpret_cast<int*>(address);
}
float ReadFloat(uintptr_t address)
{
	return *reinterpret_cast<float*>(address);
}
uintptr_t ReadInt64(uintptr_t address)
{
	return *reinterpret_cast<uintptr_t*>(address);
}
double ReadDouble(uintptr_t address)
{
	return *reinterpret_cast<double*>(address);
}
//const char* ReadString(uintptr_t address,int size) //Does not currently Work
//{
//
//	char test[255];
//	for (int i = 0; i < size; i++)
//	{
//		test[i] = *reinterpret_cast<uint8_t*>(address + (uintptr_t)i);
//	}
//	//test[size] = '\0';
//	const char* ret = test;
//	return test;
//}
#pragma endregion


