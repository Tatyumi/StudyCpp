#include "File.h"
#include <stdio.h>
#include <string.h>
#include "MainDefs.h"

// コンストラクタ
File::File()
{
	m_pfile = NULL;
	m_bCopy = false;
}

// コピーコンストラクタ
File::File(const File& rother)
{
	m_pfile = rother.m_pfile;
	m_bCopy = true;
}

// デストラクタ
File::~File()
{
	if (m_bCopy == false)
		Close();
}

// ファイルを開く
bool File::Open(const char* pszFile, const char* pszFlags)
{
	Close();

	char bufFlags[8];
	if (ModifyFlags(pszFlags, bufFlags, numof(bufFlags)) == false)
		return false;

	error = fopen_s(&m_pfile,pszFile, bufFlags);
	return (error != NULL);
}

// ファイルを閉じる
void File::Close()
{
	if (IsValid() == true)
	{
		fclose(m_pfile);
		m_pfile = 0;
	}
}

// フラグの調整
bool File::ModifyFlags(const char* pszSource, char* pszDest, int nSize)
{
	bool bBinary;  // 'b' の指定があるかどうか

	// strchr は、指定した文字が初めに出てくる位置を返す関数です
	// ただ単に文字が含まれているかどうかを確認するのにも使えます

	// バイナリか判別
	bBinary = (strchr(pszSource, 'b') != NULL);

	// フラグが多すぎるときは false を返す
	if ((int)strlen(pszSource) > nSize - 1 - !bBinary)
		return false;

	// 強制的にバイナリモードで開きます
	// strcpy は文字列をコピーする関数、strcat は文字列を追加する関数です
	strcpy_s(pszDest, nSize,pszSource);
	if (bBinary == false)
		strcat_s(pszDest, nSize,"b");
	return true;
}

// ファイルから読み出す
size_t File::Read(void* pData, size_t nSize)
{
	if (IsValid() == false)
		return 0;
	return fread(pData, 1, nSize, m_pfile);
}

// ファイルに書き込む
size_t File::Write(const void* pData, size_t nSize)
{
	if (IsValid() == false)
		return 0;
	return fwrite(pData, 1, nSize, m_pfile);
}

// ファイルの終端に達したかどうか
bool File::Eof()
{
	if (IsValid() == false)
		return true;
	return (feof(m_pfile) != 0);
}