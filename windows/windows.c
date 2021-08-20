// �ײ�ʵ�ִ��� ��ͷ�ļ�
#include<Windows.h>


//6�����ڹ���

// CALLBACK  ����__stdcall �����Ĵ���˳�򣺴��ҵ���������ջ�������ں�������ǰ��ն�ջ
LRESULT CALLBACK WindowProc(
	HWND hWnd, //��Ϣ�����Ĵ��ھ��
	UINT uMsg, //������Ϣ����  WM_XXXX ��Ϣ��
	WPARAM wParam, //���̸�����Ϣ
	LPARAM lParam  //��긽����Ϣ
)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		//����xxxWindowΪ��β�ķ��� ����������뵽��Ϣ�����У�����ֱ��ִ��
		DestroyWindow(hWnd); //DestroyWindow ������һ����Ϣ WM_DESTROY
		break;
	case  WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN: //����������
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);

		char buf[1024];
		wsprintf(buf, TEXT("x = %d,y = %d"), xPos, yPos);

		MessageBox(hWnd, buf, TEXT("����������"), MB_OK);

		break;
	}
	case WM_KEYDOWN: //����
		MessageBox(hWnd, TEXT("���̰���"), TEXT("���̰���"), MB_OK);
		break;

	case WM_PAINT: //��ͼ
	{
		PAINTSTRUCT ps; //��ͼ�ṹ��
		const HDC hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 100, 100, TEXT("HELLO"), strlen("HELLO"));
		EndPaint(hWnd, &ps);
	}

	break;
	default: break;
	}

	//����ֵ��Ĭ�ϴ���ʽ
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


// ������ں���
// WINAPI ���� __stdcall �����Ĵ���˳�򣺴��ҵ���������ջ�������ں�������ǰ��ն�ջ

int WINAPI WinMain(
	HINSTANCE hInstance, // Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance, // ��һ��Ӧ�ó��������� Win32 �����£�����һ��Ϊ NULL, ��������
	LPSTR lpCmdLine, // �����в��� char * argv[]
	int nShowCmd) // ��ʾ����
{
	// 1.��ƴ���
	WNDCLASS wc;
	wc.cbClsExtra = 0; // ��Ķ����ڴ�
	wc.cbWndExtra = 0; // ���ڶ�����ڴ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ���ñ���
	wc.hCursor = LoadCursor(NULL, IDC_HAND); // ���ù�꣺�����һ������Ϊ NULL ��ʾʹ��ϵͳ���
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // ͼ�꣺�����һ������Ϊ NULL ��ʾʹ��ϵͳͼ��
	wc.hInstance = hInstance; // Ӧ�ó���ʵ����������� WinMain �е��βμ���
	wc.lpfnWndProc = WindowProc;  // �ص����������ڹ��̣�
	wc.lpszClassName = TEXT("WIN"); // ����������
	wc.lpszMenuName = NULL; // �˵�����
	wc.style = 0; // ������ʾ���0 ����Ĭ�Ϸ��

	// 2.ע�ᴰ��
	RegisterClass(&wc);

	// 3.��������
	/* �����б�
	 * lpClassName, ����
	 * lpWindowName, ������
	 * dwStyle,	��� WS_OVERLAPPEDWINDOW
	 * x, ��ʾ���꣬����ʹ��Ĭ��ֵ CW_USEDEFAULT
	 * y,
	 * nWidth, ��ʾ��ߣ�����ʹ��Ĭ��ֵ CW_USEDEFAULT
	 * nHeight,
	 * hWndParent, ������ NULL
	 * hMenu,   �˵� NULL
	 * hInstance,  ʵ����� hInstance
	 * lpParam  ����꣩����ֵ NULL
	 */
	HWND hWnd = CreateWindow(wc.lpszClassName,
		TEXT("WINDOWS"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	// 4.��ʾ�͸���
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	// 5.ͨ��ѭ��ȡ��Ϣ
	/*
	 * HWND    hwnd;  ������
	 * UINT    message; ��Ϣ����
	 * WPARAM  wParam; �����̣�������Ϣ
	 * LPARAM  lParam; ����꣩������Ϣ
	 * DWORD   time;  ��Ϣ������ʱ��
	 * POINT   pt; ������Ϣ ��� x y ����
	 */
	MSG msg;
	while (1)
	{
		/**
		 * LPMSG lpMsg, ��Ϣ�ṹ��
		 * HWND hWnd, NULL �������д�����Ϣ
		 * UINT wMsgFilterMin, ������С��Ϣ����  0 ����������Ϣ
		 * UINT wMsgFilterMax  ���������Ϣ����  0 ����������Ϣ
		 */
		if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}

		// ������Ϣ
		TranslateMessage(&msg);

		// �ַ���Ϣ
		DispatchMessage(&msg);
	}

	// 6.������Ϣ�����ڹ��̣�

	return 0;
}
