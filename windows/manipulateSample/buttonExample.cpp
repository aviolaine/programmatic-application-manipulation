#include <iostream>
#include <windows.h>

using namespace std;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int iCmdShow)
{
	
	HWND Find = ::FindWindowEx(0, 0, NULL, "Example title");

	//1001 is the buttonid, which can be found through spy++ or sifting through the parent window (Find's) child windows
	SendMessage(Find, WM_COMMAND, 1001, NULL);


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

