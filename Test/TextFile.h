#pragma once
#ifndef __TEXTFILE_H__INCLUDED__
#define __TEXTFILE_H__INCLUDED__

#endif // !__TEXTFILE_H__INCLUDED__

#include <string.h>
#include "File.h"

class TextFile : public File
{
public:
	int WriteString(const char* pszString);
};

inline int TextFile::WriteString(const char* pszString)
{
	return Write(pszString, strlen(pszString));
}