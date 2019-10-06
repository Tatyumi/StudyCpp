#pragma once
#ifndef _FILE_H_INCLUDED__
#define _FILE_H_INCLUDED__
#endif

#include <iostream>
using namespace std;

class File
{
	// メンバ変数
private:
	FILE* m_pfile;	// ファイル
	bool m_bCopy;	// コピーコンストラクタで作られたかどうか
	errno_t error;	// エラーの有無

	// コンストラクタ、デストラクタ
public:
	File();						// コンストラクタ
	File(const File& rother);	// コピー
	~File();					// デストラクタ

	// ファイル操作関数
public:
	bool Open(const char* pszFile, const char* pszFlags);
	// ファイルを開く

	size_t Read(void* pData, size_t nSize);         // ファイルから読み出す
	size_t Write(const void* pData, size_t nSize);	// ファイルに書き込む
	void Close();	// ファイルを閉じる

private:
	bool ModifyFlags(const char* pszSource, char* pszDest, int nSize);
	// フラグの調整
		// 評価
public:
	bool IsValid() const;  // m_pfile の値が有効かどうか
	bool Eof();  // ファイルの終端に達したかどうか

};

// m_pfile の値が有効かどうか
bool File::IsValid()const
{
	return (m_pfile != NULL);
}



