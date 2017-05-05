# programmatic-application-manipulation (for CS460)
This project demonstrates desktop application manipulation APIs in Windows and Unix.

The purpose of using a script as opposed to manually clicking and typing is so that one can complete repetitive tasks automatically. 
Note that many applications prohibit the use of third-party clients and/or scripts that will manipulate application usage outside of the actual application. This is why much of the project relies on the use of a created binary as opposed to an existing one.

However, even though the scripts are run on a created binary, it is easy to edit these scripts and use them on existing applications to perform complex, repetitive operations.

In Windows, it is common to use Spy++ to find out what names/ids elements in an application have, or what WinAPI functions are being used at application runtime. One can also use EnumWindows on the window to find all of the children of the window (AKA all of the elements in a window, like buttons or text fields). Once you know the names/ids of the elements, it is extremely simple to manipulate them like in the provided scripts.

In Linux, ...

## File description + usage
#### Windows:
##### Find and manipulate:
findAndManipulate.exe: This executable will prompt you for the title of the application you want to manipulate (the text in bar at the top of any window). From there, it will allow you to programmatically minimize, alt-tab, move the x/y coordinates of the window, and change the width/height of the window.

##### Manipulate a sample application:
createExample.exe: This creates a window programmatically that will be used to demonstrate the text insertion and button clicking scripts. This script has to be running for the next two scripts to work.

buttonExample.exe: This script programmatically clicks the button in the createExample window.
textExample.exe: This script programmatically enters text into the edit field in the createExample window. In particular, it enters the letter 'a'.

#### Linux:
...

## Installing
For windows scripts: If you are only using the executables, make sure that you are using a Windows computer. Preferably use a Windows 10 computer; it is where the code was compiled originally.
If you would like to compile the scripts yourself, make sure g++ is installed, then run 'make' in any directory to create the executables.

For linux scripts: ...
