#include "mfc.h"

// Ӧ�ó���������ҽ���һ����
MyApp app;

BOOL MyApp::InitInstance()
{
	{
		// // ��������
		// MyFrame* frame = new MyFrame;
		//
		// // ��ʾ �� ����
		// frame->ShowWindow(SW_SHOWNORMAL);
		// frame->UpdateWindow();
		//
		// // ����ִ��Ӧ�ó���������ڵ�ָ��
		// m_pMainWnd = frame;
	}

	// ��������
	m_pMainWnd = new MyFrame;
	// ��ʾ �� ����
	m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
	m_pMainWnd->UpdateWindow();

	// ����������ʼ��
	return TRUE;
}

MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC WINDOW"));
}
