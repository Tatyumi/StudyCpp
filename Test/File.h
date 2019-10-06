#pragma once
#ifndef _FILE_H_INCLUDED__
#define _FILE_H_INCLUDED__
#endif

#include <iostream>
using namespace std;

class File
{
	// �����o�ϐ�
private:
	FILE* m_pfile;	// �t�@�C��
	bool m_bCopy;	// �R�s�[�R���X�g���N�^�ō��ꂽ���ǂ���
	errno_t error;	// �G���[�̗L��

	// �R���X�g���N�^�A�f�X�g���N�^
public:
	File();						// �R���X�g���N�^
	File(const File& rother);	// �R�s�[
	~File();					// �f�X�g���N�^

	// �t�@�C������֐�
public:
	bool Open(const char* pszFile, const char* pszFlags);
	// �t�@�C�����J��

	size_t Read(void* pData, size_t nSize);         // �t�@�C������ǂݏo��
	size_t Write(const void* pData, size_t nSize);	// �t�@�C���ɏ�������
	void Close();	// �t�@�C�������

private:
	bool ModifyFlags(const char* pszSource, char* pszDest, int nSize);
	// �t���O�̒���
		// �]��
public:
	bool IsValid() const;  // m_pfile �̒l���L�����ǂ���
	bool Eof();  // �t�@�C���̏I�[�ɒB�������ǂ���

};

// m_pfile �̒l���L�����ǂ���
bool File::IsValid()const
{
	return (m_pfile != NULL);
}



