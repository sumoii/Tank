//-----------------------------------������˵����----------------------------------------------
//  ��������:��Tank-Bitty
//	2025��4�� Create by sumoii
//  ������̹�˴�ս���临��
//------------------------------------------------------------------------------------------------

//-----------------------------------��ͷ�ļ��������֡�---------------------------------------
//	����������������������ͷ�ļ�
//------------------------------------------------------------------------------------------------
#include <windows.h>
#include  <time.h> //ʹ�û�ȡϵͳʱ��time()������Ҫ������ͷ�ļ�
#include "Tank.h"
#include "Bullet.h"

//-----------------------------------�����ļ��������֡�---------------------------------------
//	���������������������Ŀ��ļ�
//------------------------------------------------------------------------------------------------
#pragma comment(lib,"winmm.lib")  //����PlaySound����������ļ�

//-----------------------------------���궨�岿�֡�--------------------------------------------
//	����������һЩ������
//------------------------------------------------------------------------------------------------
#define WINDOW_WIDTH	932						//Ϊ���ڿ�ȶ���ĺ꣬�Է����ڴ˴��޸Ĵ��ڿ��
#define WINDOW_HEIGHT	932							//Ϊ���ڸ߶ȶ���ĺ꣬�Է����ڴ˴��޸Ĵ��ڸ߶�
#define WINDOW_TITLE	L"̹�˴�ս"	//Ϊ���ڱ��ⶨ��ĺ�
#define BULLET_MAX  50

//-----------------------------------��ȫ�ֱ����������֡�-------------------------------------
//	������ȫ�ֱ���������
//------------------------------------------------------------------------------------------------
HDC			g_hdc = NULL, g_mdc = NULL, g_bufdc = NULL;//ȫ���豸�������
HBITMAP g_hBitmap = NULL , g_hBackGround = NULL;	//ȫ��λͼ���
DWORD		g_tPre = 0, g_tNow = 0,g_tStart = 0;					//����������������¼ʱ��,g_tPre��¼��һ�λ�ͼ��ʱ�䣬g_tNow��¼�˴�׼����ͼ��ʱ��
Tank Play1;	//�����������̹��;
Bullet Bullet_Arry[BULLET_MAX];
int g_iPicNum1 = 0, g_iPicNum2 = 0, x = 0, y = 0, g_iDirection1 = 0, g_iBulletNum = 0;

//-----------------------------------��ȫ�ֺ����������֡�-------------------------------------
//	������ȫ�ֺ�����������ֹ��δ�����ı�ʶ��ϵ�д���
//------------------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);//���ڹ��̺���
BOOL Game_Init(HWND hwnd);			//�ڴ˺����н�����Դ�ĳ�ʼ��
VOID Game_Paint(HWND hwnd);		//�ڴ˺����н��л�ͼ�������д
BOOL Game_CleanUp(HWND hwnd);	//�ڴ˺����н�����Դ������

//-----------------------------------��WinMain( )������--------------------------------------
//	������WindowsӦ�ó������ں��������ǵĳ�������￪ʼ
//------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//��1�����ڴ����Ĳ���֮һ����ʼ���һ�������Ĵ�����
	WNDCLASSEX wndClass = { 0 };							//��WINDCLASSEX������һ��������
	wndClass.cbSize = sizeof(WNDCLASSEX);			//���ýṹ����ֽ�����С
	wndClass.style = CS_HREDRAW | CS_VREDRAW;	//���ô��ڵ���ʽ
	wndClass.lpfnWndProc = WndProc;					//����ָ�򴰿ڹ��̺�����ָ��
	wndClass.cbClsExtra = 0;								//������ĸ����ڴ棬ȡ0�Ϳ�����
	wndClass.cbWndExtra = 0;							//���ڵĸ����ڴ棬��Ȼȡ0������
	wndClass.hInstance = hInstance;						//ָ���������ڹ��̵ĳ����ʵ�������
	wndClass.hIcon = (HICON)::LoadImage(NULL, L"../Tank_resource/resources/favicon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);  //���ؼ����Զ���icoͼ��
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);    //ָ��������Ĺ������
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);  //ΪhbrBackground��Աָ��һ����ɫ��ˢ���	
	wndClass.lpszMenuName = NULL;						//��һ���Կ���ֹ���ַ�����ָ���˵���Դ�����֡�
	wndClass.lpszClassName = L"ForTheDreamOfGameDevelop";		//��һ���Կ���ֹ���ַ�����ָ������������֡�

	//��2�����ڴ����Ĳ���֮����ע�ᴰ����
	if (!RegisterClassEx(&wndClass))				//����괰�ں���Ҫ�Դ��������ע�ᣬ�������ܴ��������͵Ĵ���
		return -1;

	//��3�����ڴ����Ĳ���֮������ʽ��������
	HWND hwnd = CreateWindow(L"ForTheDreamOfGameDevelop", WINDOW_TITLE,				//ϲ���ּ��Ĵ������ں���CreateWindow
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH,
		WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	//��4�����ڴ����Ĳ���֮�ģ����ڵ��ƶ�����ʾ�����
	MoveWindow(hwnd, 300, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);		//����������ʾʱ��λ�ã�ʹ�������Ͻ�λ�ڣ�300,80����
	ShowWindow(hwnd, nShowCmd);    //����ShowWindow��������ʾ����
	UpdateWindow(hwnd);						//�Դ��ڽ��и��£��������������·���Ҫװ��һ��

	//��Ϸ��Դ�ĳ�ʼ��������ʼ��ʧ�ܣ�����һ����Ϣ�򣬲�����FALSE
	if (!Game_Init(hwnd))
	{
		MessageBox(hwnd, L"��Դ��ʼ��ʧ��", L"��Ϣ����", 0); //ʹ��MessageBox����������һ����Ϣ����
		return FALSE;
	}
	PlaySound(L"../Tank_resource/sound/stage_start.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //ѭ�����ű������� 
	
	
	//��5����Ϣѭ������
	MSG msg = { 0 };				//���岢��ʼ��msg
	while (msg.message != WM_QUIT)		//ʹ��whileѭ���������Ϣ����WM_QUIT��Ϣ���ͼ���ѭ��
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))   //�鿴Ӧ�ó�����Ϣ���У�����Ϣʱ�������е���Ϣ�ɷ���ȥ��
		{
			TranslateMessage(&msg);		//���������Ϣת��Ϊ�ַ���Ϣ
			DispatchMessage(&msg);			//�ַ�һ����Ϣ�����ڳ���
		}	
		else
		{
			g_tNow = GetTickCount();   //��ȡ��ǰϵͳʱ��
			if (g_tNow - g_tPre >= 100)        //���˴�ѭ���������ϴλ�ͼʱ�����0.1��ʱ�ٽ����ػ����
				for (int i = 0; i <= g_iBulletNum; i++)
					Bullet_Arry[i].Bullet_Move();
				Game_Paint(hwnd);
		}
	}

	//��6���������ע��
	UnregisterClass(L"ForTheDreamOfGameDevelop", wndClass.hInstance);  //����׼��������ע��������
	return 0;
}

//-----------------------------------��WndProc( )������--------------------------------------
//	���������ڹ��̺���WndProc,�Դ�����Ϣ���д���
//------------------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT paintStruct;			//����һ��PAINTSTRUCT�ṹ������¼һЩ������Ϣ

	switch (message)						//switch��俪ʼ
	{
	case WM_KEYDOWN:					// ���Ǽ��̰�����Ϣ
		switch (wParam)
		{
		case VK_ESCAPE://����Esc��
			DestroyWindow(hwnd); //���ٴ��ڣ�������һ��WM_DESTROY��Ϣ
			PostQuitMessage(0); //��������
			break;
		case 87:
			Play1.Tank_move(0);
			break;
		case 65:
			Play1.Tank_move(1);
			break;
		case 83:
			Play1.Tank_move(2);
			break;
		case 68:
			Play1.Tank_move(3);
			break;
		case 74:
			Play1.Tank_Shoot(&x,&y);
			g_iDirection1 = Play1.Tank_Getdirection();
			Bullet_Arry[g_iBulletNum].Bullet_Shoot(g_iDirection1, x, y);
			g_iBulletNum++;
			break;
		}
		break;

	case WM_DESTROY:					//���Ǵ���������Ϣ
		Game_CleanUp(hwnd);			//�����Զ������Դ������Game_CleanUp���������˳�ǰ����Դ����
		PostQuitMessage(0);			//��ϵͳ�����и��߳�����ֹ����������ӦWM_DESTROY��Ϣ
		break;									//������switch���

	default:										//������case�����������ϣ���ִ�и�default���
		return DefWindowProc(hwnd, message, wParam, lParam);		//����ȱʡ�Ĵ��ڹ���
	}

	return 0;									//�����˳�
}

//-----------------------------------��Game_Init( )������--------------------------------------
//	��������ʼ������������һЩ�򵥵ĳ�ʼ��
//------------------------------------------------------------------------------------------------
BOOL Game_Init(HWND hwnd)
{
	srand((unsigned)time(NULL));
	HBITMAP bmp;

	g_hdc = GetDC(hwnd);  //��ȡ�豸�������
	//��������DC
	g_mdc = CreateCompatibleDC(g_hdc);
	g_bufdc = CreateCompatibleDC(g_hdc);
	bmp = CreateCompatibleBitmap(g_hdc, WINDOW_WIDTH, WINDOW_HEIGHT);//��һ���ʹ��ڼ��ݵĿյ�λͼ����

	SelectObject(g_mdc, bmp);
	//����λͼ
	g_hBitmap = (HBITMAP)LoadImage(NULL, L"../Tank_resource/resources/tank.bmp", IMAGE_BITMAP, 400, 256, LR_LOADFROMFILE);
	g_hBackGround = (HBITMAP)LoadImage(NULL, L"../Tank_resource/resources/black.bmp", IMAGE_BITMAP, 1920, 1080, LR_LOADFROMFILE);
	g_tStart = GetTickCount();
	Game_Paint(hwnd);
	return TRUE;
}

//-----------------------------------��Game_Paint( )������--------------------------------------
//	���������ƺ������ڴ˺����н��л��Ʋ���
//--------------------------------------------------------------------------------------------------
VOID Game_Paint(HWND hwnd)
{
	if (g_iPicNum1 == 4)
		g_iPicNum1 = 0;
	if (g_iPicNum2 == 2)
		g_iPicNum2 = 0;

	//ѡ��λͼ����
	SelectObject(g_bufdc, g_hBackGround);
	//���ϱ���ͼƬ
	BitBlt(g_mdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, g_bufdc, 0, 0, SRCCOPY);

	//ѡ��λͼ����
	SelectObject(g_bufdc, g_hBitmap);
	Play1.Tank_Getcoord(&x, &y);
	g_tNow = GetTickCount();
	if ((g_tNow - g_tStart) < 1000) {
		StretchBlt(g_mdc, x, y, 32, 32, g_bufdc,  (16+g_iPicNum1)* 16, 16*6, 16, 16, SRCPAINT);
		BitBlt(g_hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, g_mdc, 0, 0, SRCCOPY);
		g_iPicNum1++;
	}
	else{
		g_iDirection1 = Play1.Tank_Getdirection();
		BitBlt(g_mdc, x, y, 16, 16, g_bufdc, g_iDirection1 *2* 16, 0, SRCPAINT);
		//StretchBlt(g_mdc, x, y, 32, 32, g_bufdc, g_iDirection1 * 2 * 16, 0, 16, 16, SRCPAINT);
		if ((g_tNow - g_tStart) < 3000){
			BitBlt(g_mdc, x, y, 16, 16, g_bufdc, (16 + g_iPicNum2) * 16, 16*9, SRCPAINT);
			//StretchBlt(g_mdc, x, y, 32, 32, g_bufdc, (16 + g_iPicNum2) * 16, 16 * 9, 16, 16, SRCPAINT);
			g_iPicNum2++;
		}
		for (int i = 0; i <= g_iBulletNum; i++)
		{
			g_iDirection1 = Bullet_Arry[i].Bullet_GetDirection();
			Bullet_Arry[i].Bullet_Getcoord(&x, &y);
			BitBlt(g_mdc, x, y, 8, 8, g_bufdc, (40 + g_iDirection1) * 8, 16*6, SRCPAINT);
			//StretchBlt(g_mdc, x, y, 16, 32, g_bufdc, (40 + g_iDirection1) * 8, 16 * 6, 8, 16, SRCPAINT);
		}
		BitBlt(g_hdc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, g_mdc, 0, 0, SRCCOPY);
	}
	g_tPre = GetTickCount(); //��¼�˴λ�ͼʱ��
}

//-----------------------------------��Game_CleanUp( )������--------------------------------
//	��������Դ���������ڴ˺����н��г����˳�ǰ��Դ��������
//---------------------------------------------------------------------------------------------------
BOOL Game_CleanUp(HWND hwnd)
{
	DeleteDC(g_mdc);
	DeleteDC(g_bufdc);
	DeleteObject(g_hBackGround);
	DeleteObject(g_hBitmap);
	ReleaseDC(hwnd, g_hdc);  //�ͷ��豸����
	return TRUE;
}