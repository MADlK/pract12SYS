// PrintProcess.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

#include <thread>
using namespace std;


DWORD Out = 15000;
//DWORD Out = 60 * 10 * 1000;
DWORD startproc = GetTickCount();
bool con = false;
DWORD getRandomDelay(int minMs, int maxMs) {
    return minMs + rand() % (maxMs - minMs + 1);
}
void timereset()
{
    //проверка что принтер используется
    HANDLE hClient = OpenMutex(SYNCHRONIZE, FALSE, L"mutex");
    if (hClient)//если мьютекс создан
    {

        DWORD wait = WaitForSingleObject(hClient, 1);
        if (wait == WAIT_TIMEOUT)
        {
            con = true;
            startproc = GetTickCount();
            
            ReleaseMutex(hClient);
        }
        else//если никого нет
        {
            con = false;
        }
            
        CloseHandle(hClient);
    }
}
void pech(HANDLE hMutex)
{
    //удержание мютекса 2 сек
    
    
    
    
        cout << "Pechataet..." << endl;
    
    Sleep(getRandomDelay(2000, 3000));
    system("cls");
}


int main()
{
    setlocale(0, "ru");


    HANDLE hMutex = CreateMutex(NULL, FALSE, L"mutex");
    if (!hMutex)
    {
        cout << "Err create mutex" << endl;
        return 0;
    }
    //ReleaseMutex(hMutex);
    ////ждем подключения
    cout << "подключение" << endl;
    //while (!con)
    //{
    //    timereset();
    //}
    DWORD now = 0;
    bool gotovo = false;
    bool pech = false;

    while (startproc + Out > now)
    {
        
        DWORD wait = WaitForSingleObject(hMutex, 1);
        if (wait == WAIT_TIMEOUT)
        {
            if(!pech)
            {
                cout << "pechat" << endl;
                pech = true;
            }
            




            con = true;
            startproc = GetTickCount();
            gotovo = true;

            
        }
        else if (wait == WAIT_OBJECT_0)
        {
            ReleaseMutex(hMutex);

            if (gotovo)
            {
                pech = false;
                gotovo = false;
                cout << "GOTOVO" << endl;
            }
            
        }
        
        now = GetTickCount();
    }

    
    cout << "time out" << endl;
    
   /* system("cls");
    cout << "1234" << endl;
    DWORD now =0;*/
    
    //while(startproc + Out> now) //подумать над условием
    //{

    //    
    //    
    //    pech(hMutex);
    //    cout << "Gotovo" << endl;
    //    Sleep(1000);
    //    system("cls");
    //    
    //    now = GetTickCount();
    //}
    //
    //ReleaseMutex(hMutex);
    //

    //

    //
   
    //
    //cout << "Completed" << endl;
    //WaitForSingleObject(hMutex, getRandomDelay(2000, 3000));


    


}


