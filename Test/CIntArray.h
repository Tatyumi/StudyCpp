#pragma once
class CIntArray
{
private:
	int m_anum[100];

public:
	CIntArray();

public:
	int Get(const int index);
	void Set(const int index, const int value);

private:
	void CheckIndex(const int index);
};

