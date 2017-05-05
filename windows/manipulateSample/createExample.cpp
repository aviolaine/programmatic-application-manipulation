#include <windows.h>
#include <string.h>

#define BUTTON_ID      1001
#define EDIT_ID 5
using namespace std;
const char g_szClassName[] = "myWindowClass";

int GetTextSize (LPSTR a0)
{
    for (int iLoopCounter = 0; ;iLoopCounter++)
    {
        if (a0 [iLoopCounter] == '\0')
            return iLoopCounter;
    }
}
   LPSTR text [] = {
    "Hello World"
};
 static HWND hButton;
 HINSTANCE hinst;
//use -lcomdlg32 -lgdi32
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    // Function I made to get the size of the text

    switch(msg){
        case WM_CREATE:

        //Create edit field
        CreateWindowEx(
             WS_EX_CLIENTEDGE,
             "EDIT",
             "",
             WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT,
             120, 0, 240, 120,
             hwnd, (HMENU)EDIT_ID, hinst, NULL);
      
        CreateWindow( 
    "BUTTON",  // Predefined class; Unicode assumed 
    "OK",      // Button text 
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
    10,         // x position 
    10,         // y position 
    100,        // Button width
    50,        // Button height
    hwnd,     // Parent window
    (HMENU) BUTTON_ID,       // No menu.
    hinst,
    NULL);      // Pointer not needed.;
        
      

        break;
        case WM_COMMAND:
                if ( LOWORD( wParam ) == BUTTON_ID ) {
                MessageBox(hwnd, TEXT("Button Pressed"), TEXT(""), 0);
                }
            break;
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);

            // Here your application is laid out.
            // For this introduction, we just print out "Hello, World!"
            // in the top left corner.
            /*TextOut(hdc,
                5, 5,
                text[0], GetTextSize(text[0]));*/
            // End application-specific layout section.

            EndPaint(hwnd, &ps);
        break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
            break;
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,    LPSTR lpCmdLine, int nCmdShow){
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    hinst = hInstance;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc   = WndProc;
    
        wc.cbClsExtra    = 0; 
           wc.cbWndExtra    = 0;
               wc.hInstance     = hInstance;   
                wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);   
                 wc.hCursor       = LoadCursor(NULL, IDC_ARROW);    
                 wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
        wc.lpszMenuName  = NULL;    
        wc.lpszClassName = g_szClassName;   
         wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

         if(!RegisterClassEx(&wc)){
             MessageBox(NULL, "Window Registration Failed!", "Error!",
             MB_ICONEXCLAMATION | MB_OK);
             return 0;
         }

         hwnd = CreateWindowEx(
             WS_EX_CLIENTEDGE,
             g_szClassName,
             "Example title", 
             WS_OVERLAPPEDWINDOW,
             CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
             NULL, NULL, hInstance, NULL);


         
         if(hwnd == NULL){
             MessageBox(NULL, "Window Creation Failed!", "Error!",            MB_ICONEXCLAMATION | MB_OK);
             return 0;
         }

         ShowWindow(hwnd, nCmdShow);    
         UpdateWindow(hwnd);

         while(GetMessage(&Msg, NULL, 0, 0) > 0)
         {
             TranslateMessage(&Msg);
             DispatchMessage(&Msg);
             //SendMessage(hwnd, WM_COMMAND, 1, NULL);
         }

         
         return Msg.wParam;
}