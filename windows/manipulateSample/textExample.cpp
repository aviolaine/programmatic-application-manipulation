#include <iostream>
#include <windows.h>

using namespace std;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int iCmdShow)
{
	
	HWND Find = ::FindWindowEx(0, 0, NULL, "Example title"); //gets whole window
	HWND Edit = ::FindWindowEx(Find, NULL, "Edit", NULL); //gets first edit box

	//PostMessage(Edit, WM_KEYDOWN, 0, 0); //sometimes needed in more graphical fields
	PostMessage(Edit, WM_CHAR, 'a', 0); 
	//PostMessage(Edit, WM_KEYUP, 0, 0); //sometimes needed in more graphical fields

	return 0;
	//EnumWindows(EnumWindowsProc, NULL);
}

/*
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{

	char class_name[80];
	char title[80];
	GetClassName(hwnd,class_name, sizeof(class_name));
	GetWindowText(hwnd,title,sizeof(title));
	//cout << globalTitle << endl;
    	cout <<"Window title: "<<title<<endl;
    //cout <<"Class name: "<<class_name<<endl<<endl;


	return TRUE;
}
*/

