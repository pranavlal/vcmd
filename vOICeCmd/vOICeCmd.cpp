/* vOICeCMD Copyright Pranav Lal 2008
This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
#include <windows.h>
#include <stdlib.h>
#include <string>

using namespace std;
#define AppName  "vOICeControl"
//define exit error codes and constants
const int q_ok=0; //program exit normally.
const int q_iv=1; //invalid command.
const int q_blc=2; //Blank commandline.
const int q_nv=3; //The vOICe is not running.

//Code from http://www.seeingwithsound.com
// Global variable
BOOL vOICeDone = FALSE;



/* Function to turn The vOICe sound ON or OFF.
 * Returns FALSE if a time-out error occurs.
 */
BOOL vOICeSound(HWND hWnd, BOOL Sound) { 

   static char *message;
   static COPYDATASTRUCT copydata;
   int time_out = 0, TIME_OUT = 100;
   HWND hvOICeWnd = NULL;

   // The vOICe target window is named "The vOICe"
   hvOICeWnd = FindWindow("The vOICe", NULL);

   // Just return OK if The vOICe is not running: nothing to [un]mute
   if (hvOICeWnd == NULL) return TRUE;

   // Start or stop sound generation by The vOICe
   if (Sound) message = "STARTSOUND";
   else       message = "STOPSOUND";

   // Fill the struct
   copydata.dwData = (DWORD) hWnd;
   copydata.cbData = lstrlen(message) + 1;
   copydata.lpData = message;

   // The vOICe still needs to know what you are about to ask
   vOICeDone = FALSE; 
   
   // Now tell The vOICe what you want...
   SendMessage(hvOICeWnd, WM_COPYDATA, (WPARAM) hWnd, (LPARAM) &copydata);

   // Wait until The vOICe confirms that is has indeed processed your request.
   // (E.g., a STOPSOUND request takes some time to release the audio device.)
   while (!vOICeDone && time_out < TIME_OUT) { Sleep(100); time_out++; }

   // The vOICe *is* running, but nevertheless it does not respond???
   if (time_out == TIME_OUT) return FALSE;  // Error situation

   return TRUE;
}


/* The vOICe will return a message after it processed your request:
 * put a call to this function in your WM_COPYDATA event handler.
 */
BOOL vOICeConfirm(HWND hWnd, HWND hWndSrc, PCOPYDATASTRUCT pcds) {
   
   if (strcmp((LPSTR)pcds->lpData, "The vOICe: Done!") == 0) vOICeDone = TRUE;

   return TRUE;
}


BOOL vOICeCommand(HWND hWnd, char *cmd) {

   int time_out = 0, TIME_OUT = 100;
   HWND hvOICeWnd = NULL;
   static COPYDATASTRUCT copydata;

   // The vOICe target window is named "The vOICe"
   hvOICeWnd = FindWindow("The vOICe", NULL);

   // Just return OK if The vOICe is not running
   if (hvOICeWnd == NULL) return TRUE;

   copydata.dwData = (DWORD) hWnd;
   copydata.cbData = lstrlen(cmd) + 1;
   copydata.lpData = cmd;

   vOICeDone = FALSE; 

   SendMessage(hvOICeWnd, WM_COPYDATA, (WPARAM) hWnd, (LPARAM) &copydata);

   while (!vOICeDone && time_out < TIME_OUT) { Sleep(100); time_out++; }

   if (time_out == TIME_OUT) return FALSE;  // Error situation

   return TRUE;
}

/******************** END of code from http://www.seeingwithsound.com. **********************/
//message callback
LRESULT CALLBACK myWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg) 
	{     
	case WM_COPYDATA:
vOICeConfirm(hWnd, (HWND) wParam, (PCOPYDATASTRUCT) lParam);
break;
      
      case WM_CLOSE:
      case WM_DESTROY:
         PostQuitMessage(0);
         break;


	default:
return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
return 0L;
}
//exit the application
		void Quit(int res)
{
	exit(res);
	//PostQuitMessage(WM_QUIT);		   
}

//Ensure that the correct command is being sent to the vOICe
BOOL validateCommandline(string cmdl)
{
BOOL result=false;
//If no parameters have been specified, inform the user of that fact and quit.
/*if(cmdl=="")
{
	
	int j=MessageBox(NULL,"The commandline cannot be left blank. Please see http://www.seeingwithsound.com for details.","Error in specifying commandline:",MB_ICONEXCLAMATION|MB_OK);
	Quit(q_blc);
}*/
	if(cmdl== "Stereoscopic")
	{
		result=true;
	}	
	if(cmdl== "Not stereoscopic")
	{
		result=true;
	}
	if(cmdl== "Motion")
	{
		result=true;
		}
	if(cmdl== "No motion")
	{
result=true;
	}
	if(cmdl== "Impact")
	{
		result=true;
		}
	if(cmdl== "No impact")
	{
		result=true;
}
	if(cmdl== "Mute")
	{
		result=true;
		}
	if(cmdl== "UnMute")
	{
		result=true;
}
	if(cmdl== "Wordless")
	{
		result=true;
		}
	if(cmdl== "Not wordless")
	{
		result=true;
		}
	if(cmdl== "Speed/4")
	{
		result=true;
}
	if(cmdl== "Speed/2")
	{
		result=true;
		}
	if(cmdl== "Speed*1")
	{
		result=true;
		}
	if(cmdl== "Speed*2")
	{
		result=true;
		}
	if(cmdl== "Speed*4")
	{
		result=true;
		}
	if(cmdl== "Speed*8")
	{
		result=true;
		}
	if(cmdl== "Zoom*1")
	{
		result=true;
		}
	if(cmdl== "Zoom*2")
	{
		result=true;
		}
	if(cmdl== "Zoom*4")
	{
		result=true;
		}
	if(cmdl== "Zoom*8")
	{
		result=true;
		}
	if(cmdl== "Zoom*16")
	{
		result=true;
		}
	if(cmdl== "Blinders")
	{
		result=true;
		}
	if(cmdl== "No blinders")
	{
		result=true;
		}
	if(cmdl== "Inverse")
	{
		result=true;
		}
	if(cmdl== "Positive")
	{
	result=true;	
	}
	if(cmdl== "Edges")
	{
		result=true;
		}
	if(cmdl== "No edges")
	{
		result=true;
		}
	if(cmdl== "Filter red")
	{
		result=true;
		}
	if(cmdl== "Filter green")
	{
		result=true;
		}
	if(cmdl== "Filter blue")
	{
		result=true;
		}
	if(cmdl== "Filter magenta")
	{
		result=true;
		}
		if(cmdl=="Filter orange")
		{
		result=true;
		}
	if(cmdl== "Filter yellow")
	{
		result=true;
		}
	if(cmdl== "Filter cyan")
	{
		result=true;
		}
	if(cmdl== "Filter skin")
	{
		result=true;
		}
	if(cmdl== "No color filter")
	{
		result=true;
		}
	if(cmdl== "Say color")
	{
		result=true;
		}
	if(cmdl== "Say time")
	{
		result=true;
		}
	if(cmdl== "Say date")
	{
		result=true;
		}
	if(cmdl== "Say charge")
	{
		result=true;
}
	if(cmdl== "Recognize")
	{
		result=true;
		}
	if(cmdl== "Analyze")
	{
		result=true;
		}
	if(cmdl== "Reset")
	{
		result=true;
		}
	if(cmdl== "Home")
	{
		result=true;
		}
	if(cmdl== "Left")
	{
		result=true;
		}
	if(cmdl== "Right")
	{
		result=true;
		}
	if(cmdl== "Up")
	{
		result=true;
		}
	if(cmdl== "Down")
	{
result=true;
		}
	
		//different processing required since these commands take aditional parameters.
string s=cmdl;
if(s.substr(0,6)=="Folder")
{
result=true;
}
else
if(s.substr(0,5)=="Image")
{
	result=true;
}
else
if(s.substr(0,7)=="Saccade")
{
	result=true;
}
		
		return result;
		}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
      MSG  msg;
   HWND hWnd;
BOOL vOICeActive=false;
BOOL isCommandValid=false;
   WNDCLASS wc = {
      CS_DBLCLKS, myWindowProc, 0, 0, hInstance,
      LoadIcon(NULL, IDI_APPLICATION), LoadCursor(NULL, IDC_ARROW),
      (HBRUSH) (COLOR_WINDOW + 1), NULL, AppName
   };
   
   RegisterClass(&wc);

   hWnd = CreateWindowEx(0L, AppName, AppName ": Click left or right!", 
      WS_OVERLAPPEDWINDOW, 100, 100, 320, 200, HWND_DESKTOP, 0, hInstance, NULL);

   //ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   //check whether the vOICe is running
   HWND vHandle=FindWindow("The vOICe", NULL);
   if (vHandle<=0)
   {
int j=MessageBox(NULL,"Please start the vOICe before running this program.","Error in specifying commandline:",MB_ICONEXCLAMATION|MB_OK);
Quit(q_nv);
   }
	
   string cS=lpCmdLine;	
isCommandValid=validateCommandline(cS);

if(isCommandValid==true)
{
		char *vCmd=new char[cS.size()+1];
		vCmd[cS.size()]=0; 
		memcpy(vCmd,cS.c_str(),cS.size()); 
vOICeActive=vOICeSound(hWnd,true);
   if (vOICeActive==true)
   {
	   vOICeCommand(hWnd,vCmd);
   }
}
else
{
	int j=MessageBox(NULL,"Please see http://www.seeingwithsound.com for details.","Error in specifying commandline:",MB_ICONEXCLAMATION|MB_OK);
Quit(q_iv);
}
   
//if the command has been sent to the vOICe
Quit(q_ok);


   while (GetMessage(&msg, 0, 0, 0)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }
   

	
   return msg.wParam;
}