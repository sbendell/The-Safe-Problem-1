#include "stdafx.h"
#include "CombinationLock.h"


CombinationLock::CombinationLock(int Size, int* Root)
{
	size = Size;
	for (int i = 0; i < size; i++)
	{
		ROOT[i] = Root[i];
	}
}

CombinationLock::CombinationLock()
{
}

CombinationLock::~CombinationLock()
{
}

ostream& operator<<(ostream& ostr, const CombinationLock& cl) {
	ostr << "\nRoot: ";

	for (int i = 0; i < cl.GetSize(); i++)
	{
		ostr << cl.GetROOT(i) << " ";
	}

	ostr << "\nCN:   ";
	for (int i = 0; i < cl.GetSize(); i++)
	{
		ostr << cl.GetCN(i) << " ";
	}

	ostr << "\nLN:   ";
	for (int i = 0; i < cl.GetSize(); i++)
	{
		ostr << cl.GetLN(i) << " ";
	}

	ostr << "\nHN:   ";
	for (int i = 0; i < cl.GetSize(); i++)
	{
		ostr << cl.GetHN(i) << " ";
	}

	//ostr << "\nValid? " << cl.IsValid();

	return ostr;
}

void CombinationLock::SetROOT(const int value, const int position) {
	int newVal = value;
	while (newVal > 9) {
		newVal -= 10;
	}
	while (newVal < 0) {
		newVal += 10;
	}
	ROOT[position] = newVal;
}

void CombinationLock::SetCN(const int value, const int position) {
	int newVal = value;
	while (newVal > 9) {
		newVal -= 10;
	}
	while (newVal < 0) {
		newVal += 10;
	}
	CN[position] = newVal;
}

void CombinationLock::SetLN(const int value, const int position) {
	int newVal = value;
	while (newVal > 9) {
		newVal -= 10;
	}
	while (newVal < 0) {
		newVal += 10;
	}
	LN[position] = newVal;
}

void CombinationLock::SetHN(const int value, const int position) {
	int newVal = value;
	while (newVal > 9) {
		newVal -= 10;
	}
	while (newVal < 0) {
		newVal += 10;
	}
	HN[position] = newVal;
}

bool CombinationLock::IsValid() {
	bool valid = true;
	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size; k++)
		{
			if (i != k) {
				if (CN[i] == CN[k]) {
					valid = false;
				}
			}
		}
	}
	return valid;
}