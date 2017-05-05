#include <iostream>
#include <windows.h>

using namespace std;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int iCmdShow)
{
	
	string title;
	cout << "Enter the exact title of the window you want to manipulate: ";
	std::getline(std::cin, title);
	//Get the window
	HWND Find = ::FindWindowEx(0, 0, NULL, title.c_str());

	while(true){
			cout << '\n' << endl;
			string const funcMsg = "Success. Enter what you want to do.\n [Minimize(), Switch(), Move()]";
			cout << funcMsg << endl;

			string action;
			cin >> action;

		if(action == "Minimize()"){
			//Minimize the window
			CloseWindow(Find);
		}
		else if(action == "Move()"){
			cout << "Enter x" << endl;
			int x;
			cin >> x;
			cout << "Enter y" << endl;
			int y;
			cin >> y;
			cout << "Enter width" << endl;
			int width;
			cin >> width;
			cout << "Enter height" << endl;
			int height;
			cin >> height;
			MoveWindow(Find, x, y, width, height, true);

		}
		/*else if(action == "AnimFade()"){
			AnimateWindow(Find, 200, AW_BLEND);
		}
		else if(action == "AnimExpand()"){
			AnimateWindow(Find, 200, AW_CENTER);
		}
		else if(action == "AnimCollapse()"){
			AnimateWindow(Find, 200, AW_CENTER | AW_HIDE);
		}
		else if(action == "AnimSlide()"){
			AnimateWindow(Find, 200, AW_HOR_POSITIVE | AW_SLIDE);
		}
		else if(action == "AnimRoll()"){
			AnimateWindow(Find, 200, AW_HOR_POSITIVE);
		}*/
		else if(action == "Switch()"){
			SwitchToThisWindow(Find, true);
		}
		else{
			cout << "Not a command." << endl;
		}
	}

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

