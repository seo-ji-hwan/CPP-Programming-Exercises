#pragma once
#include <string>
struct FileException {	// ���� ���� Ŭ����
	string filename;		// ���� �̸�
	bool bRead;		// ���� ���
	FileException(string name, bool b) : filename(name), bRead(b) {}
};