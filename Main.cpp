#include "head.h"
void Request();
const char* space = "\t\t";
HWND console = nullptr;
POINT PosConsole = { 510,1 };
POINT sizeConsole = { 850,170 };
#pragma warning(disable : 4996)
using namespace std;

string url = "https://www.hackthebox.eu/api/invite/generate";
string curl = "curl -XPOST " + url;

void menu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
	cls();
	setCursorPosition(33, 4);
	size_t i = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
	cout << "HackTheBox Invite-Code Generator\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
	Request();
}




void Request()
{
	while (!GetAsyncKeyState(VK_RETURN))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 26);
		setCursorPosition(2, 1);
		system(curl.c_str());
		setCursorPosition(2, 1);
		cout << "_____________________________ ";
		setCursorPosition(71, 1);
		cout << " _____________________________";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
		setCursorPosition(40, 7);
		cout << "Press Enter To Exit";
		Sleep(1000);
	}
}

//Main
int main()
{
	console = GetConsoleWindow();
	SetWindowPos(console, NULL, PosConsole.x, PosConsole.y, sizeConsole.x, sizeConsole.y, NULL);
	SetWindowLong(console, GWL_STYLE, WS_BORDER);
	ShowWindow(console, SW_SHOW);
	ExConsole();
	menu();
	return 0;
}