// pract12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <Ctime>
#include <thread>

using namespace std;


wchar_t print[] = L"C:\\Users\\st310-09\\Desktop\\pract12sys\\pract12\\x64\\Debug\\PrintProcess.exe";


int main()
{
    
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    DWORD p;
    if (!CreateProcess((LPWSTR)print, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        cout<<"Error create" << GetLastError()<<endl;
        return 0;
    }
    
    
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    

    
}


