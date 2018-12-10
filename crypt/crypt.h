// crypt.h 
#pragma once

#ifdef CRYPTLIBRARY_EXPORTS
#define CRYPTLIBRARY_API __declspec(dllexport)
#else
#define CRYPTLIBRARY_API __declspec(dllimport)
#endif



extern "C"  CRYPTLIBRARY_API const wchar_t * rot13(const wchar_t * source);