#include "CIntArray.h"
#include <iostream>
#include <memory>
#include <process.h>

#define ELEM(array)   (sizeof (array) / sizeof *(array))

using namespace std;

// コンストラクタ
CIntArray::CIntArray()
{
	memset(m_anum, 0, sizeof m_anum);
}

// メンバへのアクセス関数
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

// インデックスのチェック
void CIntArray::CheckIndex(const int index)
{
	if ((unsigned int)index < ELEM(m_anum))
		return;

	cout << "インデックスが不正です！" << endl
		<< "値 : " << index << endl;
	exit(1);
}

