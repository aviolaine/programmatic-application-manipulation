# programmatic-application-manipulation (for CS460)
This project demonstrates desktop application manipulation APIs in Windows and Unix. It specifically utilizes WinAPI and xdotool. Automated web inputs are also briefly explored through Selenium.

The purpose of using a script as opposed to manually clicking and typing is so that one can complete repetitive tasks automatically.

This is particularly useful if you wish to hijack the functionality of a closed source application, but reverse engineering the application is improbable/time-consuming. In this case, sticking with the already-provided GUI is ideal. Automatic scripting can also be used for automated testing of applications (which is Selenium's primary usage).

Note that many applications prohibit the use of third-party clients and/or scripts that will manipulate application usage outside of the actual application. This is why much of the project relies on the use of a created binary as opposed to an existing one.

However, even though the scripts are run on a created binary, it is easy to edit these scripts and use them on existing applications to perform complex, repetitive operations.

In Windows, it is common to use Spy++ to find out what names/ids elements in an application have, or what WinAPI functions are being used at application runtime. One can also use EnumWindows on the window to find all of the children of the window (AKA all of the elements in a window, like buttons or text fields). Once you know the names/ids of the elements, it is extremely simple to manipulate them like in the provided scripts.

In Unix, X11 (the window system) buttons and edit fields do not have ids and you have to find the position of the element you wish to manipulate yourself. However, the scripting can be fully automatic if you set the mouse position to 0,0/top-left absolutely in the window and then move the mouse relatively in the script (which is easy because you can grab the window's position/dimensions using xdotool as in http://pratyeka.org/fake-x-input/). Using this, it is simple to perform any input you want on most applications using the manipulations demonstrated in the provided scripts. (Using 'visgrep' is another viable option; given a picture of the element you want to manipulate, visgrep will find the coordinates of it for you.) (Technically, xwininfo can provide you with a hierarchy tree of all window elements from which you could find the element you want, but they are often nameless with only number ids and it would take less time to just perform the above tasks.) 

In Web, Selenium's webdriver is (in my opinion) already adequately robust enough to automate tasks without doing anything extra because you can pick out any element in the DOM by name/xpath/css and directly manipulate it. 

## File description + usage
### Windows:
##### Find and manipulate:
findAndManipulate.exe: This executable will prompt you for the title of the application you want to manipulate (the text in bar at the top of any window). From there, it will allow you to programmatically minimize, alt-tab, move the x/y coordinates of the window, and change the width/height of the window. [Note: you have to literally type in 'Minimize()', 'Move()' for the program to work.]

##### Manipulate a sample application:
createExample.exe: This creates a window programmatically that will be used to demonstrate the text insertion and button clicking scripts. This script has to be running for the next two scripts to work.

buttonExample.exe: This script programmatically clicks the button in the createExample window.
textExample.exe: This script programmatically enters text into the edit field in the createExample window. In particular, it enters the letter 'a'.

### Unix:
##### Find and manipulate:
findAndManipulate.sh: Runs with 'sh ./findAndManipulate.sh'. Prompts the user to click on a window they wish to manipulate. Enter M, K, S, C, or R to manipulate the window as the program specifies. 

##### Manipulate a sample application:
createExample.py: Runs with 'python createExample.py' or 'python3 createExample.py'. This python script creates a basic tkinter GUI-based application to demonstrate the text insertion and button clicking scripts. This script has to be running for the next two scripts to work. MAKE SURE THERE ARE NO OTHER tkinter GUIS RUNNING, OR THE SCRIPTS WILL LIKELY NOT BEHAVE AS INTENDED.

buttonExample.sh: Runs with 'sh ./buttonExample.sh'. Programmatically clicks the button in the createExample window.
textExample.sh: Runs with 'sh ./textExample.sh'. Programmatically enters the text 'A ROBOT WAS HERE' into the createExample window.

### Web:
##### Automated testing:
autoTest.py: Runs with 'python3 autoTest.py'. Automatically opens a chrome window, goes to google.com, asserts the website's title is 'Google', types in 'bing', asserts that the character 'a' appears somewhere in the source code of the website.

## Installing
##### For Windows scripts:
Make sure that you are using a Windows computer. Preferably use a Windows 10 computer; it is where the code was compiled successfully originally.
To compile the scripts, make sure g++ is installed, then run 'make' in any directory to create the executables.

##### For Unix scripts:
On debian/ubuntu run:

    sudo apt-get install xdotool
    sudo apt-get install xautomation

Otherwise:

http://www.semicomplete.com/projects/xdotool

https://www.hoopajoo.net/projects/xautomation.html

^ check out the links above for the .tar.gz or alternative installation.

ALSO make sure you have python/python3 installed. 
Make sure 'tkinter' is installed on python.

##### For Web script:
Make sure you have python3 installed.
Make sure 'selenium' is installed on python3.

https://chromedriver.storage.googleapis.com/index.html?path=2.29/

^unzip this, and store the executable in a PATH location (i.e. /usr/local/bin for Ubuntu)
