#ifndef EXPORT_H_INCLUDED
#define EXPORT_H_INCLUDED

#ifdef BUILD_DLL
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __declspec(dllimport)
#endif

#endif // EXPORT_H_INCLUDED
