#pragma once
#include <string>

#ifdef FILEWRITERDLL_EXPORTS
#define FILEWRITER_API __declspec(dllexport)
#else
#define FILEWRITER_API __declspec(dllimport)
#endif

FILEWRITER_API void FileWriterr(std::string name, std::string surname, int age);
