// PrintProcess.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <Ctime>
#include <thread>
using namespace std;

DWORD getRandomDelay(int minMs, int maxMs) {
    return minMs + rand() % (maxMs - minMs + 1);
}


int main()
{
    HANDLE hMutex = CreateMutex(nullptr, FALSE, L"mutex");
    if (!hMutex)
    {
        cout << "Err create mutex" << endl;
        return 0;
    }

    //10 минут?

    DWORD Out = 60 * 10 * 1000;
    DWORD start = GetTickCount();

    //сам процесс
    while (true)
    {

        //проверка что принтер используется
        HANDLE hClient = OpenMutex(SYNCHRONIZE, FALSE, L"mutex");
        if (hClient)
        {
            DWORD wait = WaitForSingleObject(hClient, 0);
            if (wait == WAIT_OBJECT_0)
            {
                start = GetTickCount();
                cout<<"time out 00 min" << endl;
                ReleaseMutex(hClient);
            }
            CloseHandle(hClient);
        }


        
        
        
        DWORD end = GetTickCount();
        if ((end - start) > 10000)
        {
            system("cls");
            cout << "Print Error" << endl;
        }
       
            system("cls");
            cout << "Pechataet..." << endl;
        
            
        
        WaitForSingleObject(hMutex, getRandomDelay(5000, 15000));

         
        
    }
    ReleaseMutex(hMutex);
    system("cls");
    cout << "Completed" << endl;
    


    


}


