#include "File.h"
#include <stdio.h>
#include <string.h>
#include "MainDefs.h"

// �R���X�g���N�^
File::File()
{
	m_pfile = NULL;
	m_bCopy = false;
}

// �R�s�[�R���X�g���N�^
File::File(const File& rother)
{
	m_pfile = rother.m_pfile;
	m_bCopy = true;
}

// �f�X�g���N�^
File::~File()
{
	if (m_bCopy == false)
		Close();
}

// �t�@�C�����J��
bool File::Open(const char* pszFile, const char* pszFlags)
{
	Close();

	char bufFlags[8];
	if (ModifyFlags(pszFlags, bufFlags, numof(bufFlags)) == false)
		return false;

	error = fopen_s(&m_pfile,pszFile, bufFlags);
	return (error != NULL);
}

// �t�@�C�������
void File::Close()
{
	if (IsValid() == true)
	{
		fclose(m_pfile);
		m_pfile = 0;
	}
}

// �t���O�̒���
bool File::ModifyFlags(const char* pszSource, char* pszDest, int nSize)
{
	bool bBinary;  // 'b' �̎w�肪���邩�ǂ���

	// strchr �́A�w�肵�����������߂ɏo�Ă���ʒu��Ԃ��֐��ł�
	// �����P�ɕ������܂܂�Ă��邩�ǂ������m�F����̂ɂ��g���܂�

	// �o�C�i��������
	bBinary = (strchr(pszSource, 'b') != NULL);

	// �t���O����������Ƃ��� false ��Ԃ�
	if ((int)strlen(pszSource) > nSize - 1 - !bBinary)
		return false;

	// �����I�Ƀo�C�i�����[�h�ŊJ���܂�
	// strcpy �͕�������R�s�[����֐��Astrcat �͕������ǉ�����֐��ł�
	strcpy_s(pszDest, nSize,pszSource);
	if (bBinary == false)
		strcat_s(pszDest, nSize,"b");
	return true;
}

// �t�@�C������ǂݏo��
size_t File::Read(void* pData, size_t nSize)
{
	if (IsValid() == false)
		return 0;
	return fread(pData, 1, nSize, m_pfile);
}

// �t�@�C���ɏ�������
size_t File::Write(const void* pData, size_t nSize)
{
	if (IsValid() == false)
		return 0;
	return fwrite(pData, 1, nSize, m_pfile);
}

// �t�@�C���̏I�[�ɒB�������ǂ���
bool File::Eof()
{
	if (IsValid() == false)
		return true;
	return (feof(m_pfile) != 0);
}