#pragma once
// MFC ��Ҫ������ͷ�ļ�
#include <afxwin.h>

// CWinApp Ӧ�ó�����
class MyApp : public CWinApp
{
public:
	// MFC �������
	virtual BOOL InitInstance() override;

};

// ���ڿ����
class MyFrame :public CFrameWnd
{
public:
	// ���ڹ��캯��
	MyFrame();
};
