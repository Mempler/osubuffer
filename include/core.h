#ifndef OSUBUFFER_CORE_H
#define OSUBUFFER_CORE_H

#ifdef OSUBUFFER_DLL
#ifdef OSUBUFFER_EXPORT
        #define OSUBUFFER_API __declspec(dllexport)
    #else
        #define OSUBUFFER_API __declspec(dllimport)
    #endif
#else
#define OSUBUFFER_API
#endif

typedef enum { false, true } bool;

typedef unsigned char ui8;
typedef char i8;

typedef unsigned short ui16;
typedef short i16;

typedef unsigned int ui32;
typedef int i32;

typedef unsigned long long ui64;
typedef long long i64;

typedef ui64 uleb128;

typedef unsigned int size;

#define nil (void*)0

#endif //OSUBUFFER_CORE_H
