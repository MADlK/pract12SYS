// pract12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <Conio.h>
#include <thread>

using namespace std;



//wchar_t print[] = L"C:\\Users\\st310-09\\Desktop\\pract12SYS-main\\pract12sys\\pract12\\x64\\Debug\\PrintProcess.exe";
//wchar_t print[] = L"C:\\Users\\m20er\\OneDrive\\Рабочий стол\\pract12sys\\pract12\\x64\\Debug\\PrintProcess.exe";


int main()
{
    
    //STARTUPINFO si;
    //PROCESS_INFORMATION pi;
    //ZeroMemory(&si, sizeof(STARTUPINFO));
    //si.cb = sizeof(STARTUPINFO);
    //DWORD p;
    //if (!CreateProcess(NULL, print, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    //{
    //    cout<<"Error create" << GetLastError()<<endl;
    //    return 0;
    //}
   


    
    
    
 /* 
 CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    */
    
    HANDLE hMutex = CreateMutex(NULL, TRUE, L"mutex");
    if (!hMutex)
    {
        cout << "Err create mutex" << endl;
        return 0;
    }
    cout << "wait" <<endl;
    WaitForSingleObject(hMutex, INFINITE);
    cout << "waited" << endl;
    Sleep(2000);
    ReleaseMutex(hMutex);
    CloseHandle(hMutex);
    
    
    
}


