#pragma once
// MFC ��Ҫ������ͷ�ļ�
#include <afxwin.h>

// CWinApp Ӧ�ó�����
class MyApp : public CWinApp
{
public:
	// MFC �������
	virtual BOOL InitInstance();

};

// ���ڿ����
class MyFrame :public CFrameWnd
{
public:
	// ���ڹ��캯��
	MyFrame();

	// ������Ϣӳ��
	DECLARE_MESSAGE_MAP()

	// �����������Ĵ�����
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	// �������̰����Ĵ�����
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);

	// ������ͼ�Ĵ�����
	afx_msg void OnPaint();
};
