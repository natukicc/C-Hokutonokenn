#pragma once
#ifndef NTKGDI_H_INCLUDED
#define NTKGDI_H_INCLUDED

#pragma comment(lib,"Msimg32.lib")
#pragma comment(lib,"Kernel32.lib")

/*===Const Definition===*/
const int NOTRANSPARENT = -1;
#define NTK_WINDOW_WIDTH 1120
#define NTK_WINDOW_HEIGHT 610

/*===Be compatible with VC6===*/
#if _MSC_VER <= 1200
typedef struct _CONSOLE_FONT_INFO {
	DWORD nFont;
	COORD dwFontSize;
} CONSOLE_FONT_INFO, *PCONSOLE_FONT_INFO;

bool WINAPI GetCurrentConsoleFont(
	HANDLE hConsoleOutput,
	bool bMaximumWindow,
	PCONSOLE_FONT_INFO lpConsoleCurrentFont
	);

COORD WINAPI GetConsoleFontSize(
	HANDLE hConsoleOutput,
	DWORD nFont
	);
#endif

/*===Structure Definition===*/
typedef struct {
	HBITMAP img;
	int width;
	int height;
} NImage;

/*===Global Varible Definition===*/
static HDC NtkGDI_Global_Hdc = NULL;  //Real hardware HDC
static HDC NtkGDI_Global_mHdc = NULL; //Software HDC
static HBITMAP NtkGDI_Global_mGdiBmp;
static HBITMAP NtkGDI_Global_mGdiBmpOld;
/*===Function Reference===*/

/*
 *@method: SetWindowsSize
 *@for   : NtkGDI
 *@desc  : Set console buffer size and windows size
 *@return: void
 */
void NtkGDI_SetWindowsSize(
	int x,
	int y,
	int width,
	int height
);

/*
 *@method: GetGetWindowHanle
 *@for   : NtkGDI
 *@desc  : Get handle of current window
 *@return: {HWND} Handle of current window
 */
HWND NtkGDI_GetWindowHanle();

/*
 *@method: GetDC
 *@for   : NtkGDI
 *@desc  : Get handle of DC
 *@return: {HDC} Handle of DC
 */
HDC NtkGDI_GetDC();

/*
 *@method: init
 *@for   : NtkGDI
 *@desc  : Init Bitmap and HDC
 *@return: void
 */
void NtkGDI_init();

/*
 *@method: uninit
 *@for   : NtkGDI
 *@desc  : Release Bitmap and HDC
 *@return: void
 */
void NtkGDI_uninit();

/*
 *@method: update
 *@for   : NtkGDI
 *@desc  : Put mHDC content to HDC(Update Content)
 *@return: void
 */
void NtkGDI_update();

/*
 *@method: LoadImage
 *@for   : NtkGDI
 *@desc  : Load bmp image
 *@return: void
 */
void NtkGDI_LoadImage(
	NImage* pImg,
	const TCHAR* filename,
	int width, //Stretched width
	int height //Stretched height
);

/*
 *@method: PutImage
 *@for   : NtkGDI
 *@desc  : Put bmp image to console windows
 *@return: void
 */
void NtkGDI_PutImage(
	NImage* pImg,
	int nXDest,
	int nYDest,
	int nWidth,
	int nHeight,
	BOOL hidden,
	int transparentColor,
	int dwRop
);

/*
 *@method: PutImage
 *@for   : NtkGDI
 *@desc  : Put bmp image to console windows(Extends)
 *@return: void
 */
void NtkGDI_PutImageEx(
	NImage* pImg,
	int nXDest,
	int nYDest,
	int nWidth,
	int nHeight,
	int nXSrc,
	int nYSrc,
	int nWidthSrc,
	int nHeightSrc,
	BOOL hidden,
	int transparentColor,
	int dwRop
);

/*
 *@method: DrawSolidLine
 *@for   : NtkGDI
 *@desc  : Draw a solid Line
 *@return: void
 */
void NtkGDI_DrawSolidLine(
	int xS,
	int yS,
	int xE,
	int yE,
	int lineColor,
	int lineSize
);

/*
 *@method: PrintText
 *@for   : NtkGDI
 *@desc  : Print text to console windows
 *@return: void
 */
void NtkGDI_PrintText(
	int x,
	int y,
	TCHAR* str,
	int len,
	int textColor,
	int bgColor,
	BOOL isTransparent,
	int fontsize,
	TCHAR* font
);

/*
 *@method: DrawRectangle
 *@for   : NtkGDI
 *@desc  : Draw rectangle to console windows
 *@return: void
 */
void NtkGDI_DrawRectangle(
	int nLeftX,
	int nLeftY,
	int nRightX,
	int nRightY,
	int color
);

/*===Function Definition===*/
void NtkGDI_SetWindowsSize(int x, int y, int width, int height)
{
	HANDLE hOut;
	CONSOLE_FONT_INFO consoleCurrentFont;
	COORD bufferSize,fontSize;
	HWND hWnd;

	//Set console buffer size
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFont(hOut, FALSE, &consoleCurrentFont);
	fontSize = GetConsoleFontSize(hOut,consoleCurrentFont.nFont);
	bufferSize.X = (int)(width/fontSize.X)-2;
	bufferSize.Y = (int)(height/fontSize.Y)-2;
	SetConsoleScreenBufferSize(hOut, bufferSize);
	//Set console window size
	hWnd = NtkGDI_GetWindowHanle();
	MoveWindow(hWnd,x,y,width,height,TRUE);
}

HWND NtkGDI_GetWindowHanle()
{
	TCHAR title[256];
	GetConsoleTitle(title, 256);
	return FindWindow(0, title);
}

HDC NtkGDI_GetDC()
{
	HDC hdc;

	hdc = GetDC(NtkGDI_GetWindowHanle());
	return hdc;
}

void NtkGDI_init()
{
	HWND hWnd = NtkGDI_GetWindowHanle();
	//Get Real Hardware DC Handle
	NtkGDI_Global_Hdc = NtkGDI_GetDC();
	//Get Software DC Handle
	NtkGDI_Global_mHdc = CreateCompatibleDC(NtkGDI_Global_Hdc);
	//Create Bitmap for Software DC
	NtkGDI_Global_mGdiBmp = CreateCompatibleBitmap(NtkGDI_Global_Hdc, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT);
	NtkGDI_Global_mGdiBmpOld = (HBITMAP)SelectObject(NtkGDI_Global_mHdc, NtkGDI_Global_mGdiBmp);
}

void NtkGDI_uninit()
{
	HWND hWnd = NtkGDI_GetWindowHanle();
	DeleteObject(NtkGDI_Global_mGdiBmp);
	DeleteDC(NtkGDI_Global_mHdc);
	ReleaseDC(hWnd, NtkGDI_Global_Hdc);
	NtkGDI_Global_Hdc = NULL;
	NtkGDI_Global_mHdc = NULL;
}

void NtkGDI_update()
{
	BitBlt(NtkGDI_Global_Hdc, 0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, NtkGDI_Global_mHdc, 0, 0, SRCCOPY);
}

void NtkGDI_LoadImage(NImage* pImg, const TCHAR* filename, int width, int height)
{
	BITMAP bm;
	struct tagSIZE size;

	if (width < 0) {
		width = 0;
	}
	if (height < 0) {
		height = 0;
	}
	pImg->img = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, width, height, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_CREATEDIBSECTION);
	GetObject(pImg->img, sizeof(BITMAP), &bm);
	pImg->width = bm.bmWidth;
	pImg->height = bm.bmHeight;
	SetBitmapDimensionEx(pImg->img, bm.bmWidth, bm.bmHeight, &size);
}

void NtkGDI_PutImage(NImage* pImg, int nXDest, int nYDest, int nWidth, int nHeight, int hidden, int transparentColor, int dwRop)
{
	HDC hdc, hdcMem;
	HBITMAP hOldBmp;

	if (pImg->img == NULL) {
		return;
	}
	if (NtkGDI_Global_Hdc == NULL) {
		return;
	}
	if (!dwRop) {
		dwRop = SRCCOPY;
	}
	hdc = NtkGDI_Global_mHdc;
	hdcMem = CreateCompatibleDC(NtkGDI_Global_Hdc);
	hOldBmp = (HBITMAP)SelectObject(hdcMem, pImg->img);
	if (transparentColor != NOTRANSPARENT) {
		if (hidden) {
			TransparentBlt(hdc, nXDest, nYDest, nWidth, nHeight, hdcMem, 0, 0, nWidth, nHeight, transparentColor);
		}
		else {
			TransparentBlt(hdc, nXDest, nYDest, nWidth, nHeight, hdcMem, 0, 0, pImg->width, pImg->height, transparentColor);
		}
	}
	else {
		if (hidden) {
			BitBlt(hdc, nXDest, nYDest, nWidth, nHeight, hdcMem, 0, 0, dwRop);
		}
		else {
			StretchBlt(hdc, nXDest, nYDest, nWidth, nHeight, hdcMem, 0, 0, pImg->width, pImg->height, dwRop);
		}
	}
	SelectObject(hdcMem, hOldBmp);
	DeleteDC(hdcMem);
}

void NtkGDI_PutImageEx(NImage* pImg, int nXDest, int nYDest, int nWidth, int nHeight, int nXSrc, int nYSrc, int nWidthSrc, int nHeightSrc, int hidden, int transparentColor, int dwRop)
{
	HDC hdc, hdcMem;
	HBITMAP hOldBmp;

	if (pImg->img == NULL) {
		return;
	}
	if (NtkGDI_Global_Hdc == NULL) {
		return;
	}
	if (!dwRop) {
		dwRop = SRCCOPY;
	}
	hdc = NtkGDI_Global_mHdc;
	hdcMem = CreateCompatibleDC(NtkGDI_Global_Hdc);
	hOldBmp = (HBITMAP)SelectObject(hdcMem, pImg->img);
	if (transparentColor != NOTRANSPARENT) {
		if (hidden) {
			TransparentBlt(hdc, nXDest, nYDest, nWidth, nHeight, hdcMem, nXSrc, nYSrc, nWidth, nHeight, transparentColor);
		}
		else {
			TransparentBlt(hdc, nXDest, nYDest, nWidth, nHeight, hdcMem, nXSrc, nYSrc, nWidthSrc, nHeightSrc, transparentColor);
		}
	}
	else {
		if (hidden) {
			BitBlt(hdc, nXDest, nYDest, nWidth, nHeight, hdcMem, nXSrc, nYSrc, dwRop);
		}
		else {
			StretchBlt(hdc, nXDest, nYDest, nWidth, nHeight, hdcMem, nXSrc, nYSrc, nWidthSrc, nHeightSrc, dwRop);
		}
	}
	SelectObject(hdcMem, hOldBmp);
	DeleteDC(hdcMem);
}

void NtkGDI_DrawSolidLine(int xS, int yS, int xE, int yE, int lineColor, int lineSize)
{
	HPEN hPen, hPenOld;
	HDC hdc = NtkGDI_Global_mHdc;
	hPen = CreatePen(PS_SOLID, lineSize, lineColor);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	MoveToEx(hdc, xS, yS, NULL);
	LineTo(hdc, xE, yE);
	DeleteObject(hPen);
}

void NtkGDI_PrintText(int x, int y, TCHAR *str, int len, int textColor, int bgColor, BOOL isTransparent, int fontsize, TCHAR* font)
{
	HFONT hFont;
	HDC hdc;
	hdc = NtkGDI_Global_mHdc;
	hFont = CreateFont(
		fontsize,                                    //FontSize   
		0,                                          //  FontWidth
		0,                                          //  nEscapement 
		0,                                          //  nOrientation   
		FW_NORMAL,                                  //   nWeight   
		FALSE,                                      //   bItalic   
		FALSE,                                      //   bUnderline   
		0,                                                   //   cStrikeOut   
		DEFAULT_CHARSET,                             //   nwchar_tSet   
		OUT_DEFAULT_PRECIS,                 //   nOutPrecision   
		CLIP_DEFAULT_PRECIS,               //   nClipPrecision   
		DEFAULT_QUALITY,                       //   nQuality   
		DEFAULT_PITCH|FF_SWISS,     //   nPitchAndFamily     
		font
		);
	SelectObject(hdc, hFont);
	SetTextColor(hdc, textColor);
	SetBkColor(hdc, bgColor);
	if(isTransparent)
	{
		SetBkMode(hdc, TRANSPARENT);
	}
	TextOut(hdc, x, y, str, len);
	SetBkMode(hdc, TRANSPARENT);
	TextOut(hdc, 0, 0, " ", 1);
	DeleteObject(hFont);
}

void NtkGDI_DrawRectangle(int nLeftX, int nLeftY, int nRightX, int nRightY, int color)
{
	HPEN hPen;
	HBRUSH hBrush;
	HDC hdc = NtkGDI_Global_mHdc;
	hBrush = CreateSolidBrush(color);
	hPen = CreatePen(PS_SOLID, 0, color);
	SelectObject(hdc, hBrush);
	SelectObject(hdc, hPen);
	Rectangle(hdc, nLeftX, nLeftY+1, nRightX+1, nRightY+1);
	DeleteObject(hPen);
	DeleteObject(hBrush);
}
#endif