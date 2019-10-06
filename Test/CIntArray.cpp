#include "CIntArray.h"
#include <iostream>
#include <memory>
#include <process.h>

#define ELEM(array)   (sizeof (array) / sizeof *(array))

using namespace std;

// �R���X�g���N�^
CIntArray::CIntArray()
{
	memset(m_anum, 0, sizeof m_anum);
}

// �����o�ւ̃A�N�Z�X�֐�
int CIntArray::Get(const int index)
{
	CheckIndex(index);
	return m_anum[index];
}

void CIntArray::Set(const int index, const int value)
{
	CheckIndex(index);
	m_anum[index] = value;
}

// �C���f�b�N�X�̃`�F�b�N
void CIntArray::CheckIndex(const int index)
{
	if ((unsigned int)index < ELEM(m_anum))
		return;

	cout << "�C���f�b�N�X���s���ł��I" << endl
		<< "�l : " << index << endl;
	exit(1);
}

