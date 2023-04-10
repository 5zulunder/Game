#include <windows.h>
#include "Game.h"
using namespace std;


int main() {
	Sleep(5000);
	//::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);// вывод консоли во весь экран
	
	HANDLE soh = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfi;
	memset(&cfi, 0, sizeof(cfi));
	cfi.cbSize = sizeof(cfi);
	GetCurrentConsoleFontEx(soh, FALSE, &cfi);
	cfi.dwFontSize.Y = 16;
	SetCurrentConsoleFontEx(soh, FALSE, &cfi);//Установка размера шрифта
	
		
	Game game;
	game.show_task(5, 5);
	Decoration d;
	//d.beep_end();
	
	
	
	


	

	


}