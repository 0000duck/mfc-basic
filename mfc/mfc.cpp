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

// Windows �ַ���
// ANSI            ���ֽڣ�1�ֽ�/�ַ�
// ���� ����...    ���ֽڣ�1���ַ���Ӧ����ֽ� Unicode utf8 3�ֽ�/�ַ� gbk 2�ֽ�/�ַ�

// ���ֽ� ת ���ֽ� �ļ��ַ�ʽ
// MessageBox(L"aaaaaaa");
// MessageBox(TEXT("aaaaaa")); // TEXT��TCHAR �Զ�����ת��

// ͳ�ƿ��ֽ��ַ����ĳ���
// char* p = "aaaa";
// int n = 0;
// n = strlen(p);
//
// wchar_t * p2 = L"bbbbb";
// n = wcslen(p2);

// string��char* char[]֮���ת�� https://www.cnblogs.com/cs0915/p/13060525.html

// CString �� char* ֮���ת��
// char* p3 = "aa";
// CString str = CString(p3);
//
// CString str2 = TEXT("abc");
// CStringA tmp;
// tmp = str2;
// char* pp = tmp.GetBuffer();
// MessageBox(CString(pp));
