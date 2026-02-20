// PrintProcess.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <Ctime>
#include <thread>
using namespace std;


DWORD Out = 10000;
DWORD startproc = GetTickCount();
DWORD getRandomDelay(int minMs, int maxMs) {
    return minMs + rand() % (maxMs - minMs + 1);
}
void timereset()
{
    //проверка что принтер используется
    HANDLE hClient = OpenMutex(SYNCHRONIZE, FALSE, L"mutex");
    if (hClient)
    {
        DWORD wait = WaitForSingleObject(hClient, 0);
        if (wait == WAIT_OBJECT_0)
        {
            startproc = GetTickCount();
            cout << "time out 00 min" << endl;
            ReleaseMutex(hClient);
        }
        CloseHandle(hClient);
    }
}
void pech(HANDLE hMutex)
{
    //удержание мютекса 2 сек
    
    
    
    
        cout << "Pechataet..." << endl;
    
    WaitForSingleObject(hMutex, getRandomDelay(2000, 3000));
    system("cls");
}


int main()
{
    HANDLE hMutex = CreateMutex(nullptr, FALSE, L"mutex");
    if (!hMutex)
    {
        cout << "Err create mutex" << endl;
        return 0;
    }

 

    
    //DWORD Out = 60 * 10 * 1000;
    
  

   
    
    if (Out - startproc > 0)
    {
        pech(hMutex);
        cout << "Gotovo" << endl;
        system("cls");
        ReleaseMutex(hMutex);
        timereset();
    }

    
    

    

    
   
    
    cout << "Completed" << endl;
    


    


}


