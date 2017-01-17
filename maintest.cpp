/*  maintest.cpp
**  Edited: January 16th, 2017 - Ben
**  Purpose: lol! Let's showcase how convoluted it is to get Windows to give us a window.
** 	... and then set up a message handler to let us close the freaking thing in disgust.
** 	P.S. - this is mostly taken from the HandmadeHero beginning videos, as Casey Muratori
** 	is far more experienced in Windows platform code than I am.
**	Comments added by me with much research to better explain what the freak is going on 
** 	here, because Window platform code is a maze of horrors.
*/

#include <windows.h>
#include <stdio.h>
#include "maintest.h"

global_variable BITMAPINFO BitmapInfo;
global_variable void *BitmapMemory;
global_variable HBITMAP BitmapHandle;

internal void
Win32ResizeWindow(int Width, int Height)
{

	if(BitmapInfo.bmiHeader.biSize)
	{
		
	}
	BitmapInfo.bmiHeader.biSize = sizeof(BitmapInfo.bmiHeader);
	BitmapInfo.bmiHeader.biWidth = Width;
  	BitmapInfo.bmiHeader.biHeight = Height;
  	BitmapInfo.bmiHeader.biPlanes = 1;
  	BitmapInfo.bmiHeader.biBitCount = 32;
  	BitmapInfo.bmiHeader.biCompression BI_RGB;
  	BitmapInfo.bmiHeader.biSizeImage = 0;
  	BitmapInfo.bmiHeader.biXPelsPerMeter = 0;
  	BitmapInfo.bmiHeader.biYPelsPerMeter = 0;
 	BitmapInfo.bmiHeader.biClrUsed = 0;
  	BitmapInfo.bmiHeader.biClrImportant = 0;
	
	HBITMAP BitmapHandle = CreateDIBSection(
	      DeviceContext, &BitmapInfo,
  	      DIB_RGB_COLORS,
  	      &BitmapMemory,
  	      0, 0);
}

internal void
Win32UpdateWindow(HDC DeviceContext, int X, int Y, int Width, int Height)
{
	StretchDIBits(
        DeviceContext,
        X, Y, Width, Height,
        X, Y, Width, Height,
  		const VOID       *lpBits,
  		const BITMAPINFO *lpBitsInfo,
        DIB_RGB_COLORS, SRCCOPY
	);
}

//to be called when Windows wants to send our program a message
LRESULT CALLBACK
MainWindowCallback(HWND Window, UINT Message, 
				   WPARAM WParam, LPARAM LParam)
{
	LRESULT Result = 0;

	switch(Message)
	{
		case WM_SIZE:
		{
			//Make a rectangle
			RECT ClientRect;
			//get the rectangle representing the inside of the window by passing a ref to
			//our rectangle
			GetClientRect(Window, &ClientRect);

			int Width = ClientRect.right - ClientRect.left;
			int Height = ClientRect.bottom - ClientRect.top;
			//We don't need to define this yet, as we're not really drawing anything yet.
			ResizeWindow();
		} break;
		case WM_CLOSE:
		{
			//If the window gets the close message, change this variable to false (and stop
			//the loop in the main function).
			global_running = false;
		} break;
		case WM_ACTIVATEAPP:
		{

		} break;
		case WM_DESTROY:
		{
			// again - stop the loop.
			global_running = false;
		} break;
		case WM_PAINT:
		{
			PAINTSTRUCT Paint;
			HDC DeviceContext = BeginPaint(Window, &Paint);
			Win32UpdateWindow(DeviceContext, X, Y, Width, Height);
		} break;
		default:
		{
			//if none of the above, let the window perform default behavior.
			Result = DefWindowProc(Window, Message, WParam, LParam);
		} break;
	}
	return(Result);
}

//Program starts here.

int CALLBACK
WinMain(HINSTANCE Instance, HINSTANCE PrevInstance, 
		LPSTR CommandLine, int ShowCode)
{
	//Create an empty windows object for us to fill with options. 
	WNDCLASS WindowClass = {};
	/*
	Sets up some options for the window:
		- CS_OWNDC:
			- 'Allocates a unique device context for each window in the class.'
		- CS_HREDRAW
			- 'Redraws the entire window if a movement or size adjustment changes 
			the width of the client area.'
		- CS_VREDRAW
			- 'Redraws the entire window if a movement or size adjustment changes
			the height of the client window.'
	*/
	WindowClass.style 			= CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
	//Pass a reference to a function that the window can call when it has messages to emit.
	WindowClass.lpfnWndProc 	= MainWindowCallback;
	//Pass the windows Instance reference we received from Windows.
	WindowClass.hInstance  		= Instance;
	//Set the class name.
	WindowClass.lpszClassName 	= "MainTestWindowClass";

	//Register the Window, and if the registration returns true - i.e., it is successful - 
	//then continue
	if(RegisterClassA(&WindowClass))
	{
		//Create the window using our information and get a handle to it
		HWND WindowHandle = CreateWindowExA(
			0,
			WindowClass.lpszClassName,
			"Main Test",
			WS_OVERLAPPEDWINDOW|WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			0,
			0,
			Instance,
			0);
		if(WindowHandle)
		{
			//establish a running variable.
			global_running = true;
			while(global_running)
			{
				MSG Message;
				BOOL MessageResult = GetMessageA(&Message, 0, 0, 0);
				if(MessageResult > 0)
				{
					TranslateMessage(&Message);
					DispatchMessageA(&Message);
				}
				else
				{
					exit(0);
					break;
				}
			}
		}
		else
		{
			//No window handle?
		}
	}
	else
	{
		//do something if the window failed to register.
	}

}