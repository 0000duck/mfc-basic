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

// ��Ϣӳ��� �ֽ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	// ���������� ��
	ON_WM_LBUTTONDOWN()
	// ���̰��� ��
	ON_WM_CHAR()
	// ��ͼ ��
	ON_WM_PAINT()

END_MESSAGE_MAP();

MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC WINDOW"));
}

// �����������¼����� ʵ��
void MyFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	{
		// TCHAR buf[1024];
		// wsprintf(buf, TEXT("x = %d, y = %d"), point.x, point.y);
		// MessageBox(buf);
	}

	// MFC �е��ַ���
	CString str;
	str.Format(TEXT("x = %d, y = %d"), point.x, point.y);
	MessageBox(str);
}

// ���̰��������¼����� ʵ��
void MyFrame::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	{
		// TCHAR buf[1024];
		// wsprintf(buf, TEXT("�������� %c ��"), nChar);
		// MessageBox(buf);
	}

	// MFC �е��ַ���
	CString str;
	str.Format(TEXT("�������� %c ��"), nChar);
	MessageBox(str);
}

// ��ͼ�¼����� ʵ��
void MyFrame::OnPaint()
{
	// ���� ������ǰ������
	CPaintDC dc(this);
	// ������
	dc.TextOutW(100, 100, TEXT("Hello MFC"));
	// ��ͼ��
	dc.Ellipse(10, 10, 100, 100);
}


