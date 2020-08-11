#pragma once
#include <iostream>
#include "Handler.h"

using namespace std;

class UI
{
private:
	Handler h;
public:
	UI()
	{
		h.Loadmysql();
	}
	int mainMenu()
	{
		int num;
		cout << "======================" << endl;
		cout << " 1. ���� ����" << endl;
		cout << " 2. ��� ����" << endl;
		cout << " 3. �ݳ� ����" << endl;
		cout << " 4. ����" << endl;
		cout << "======================" << endl;
		cout << "�Է�: ";
		cin >> num;
		return num;
	}
	int mainRun()
	{
		system("cls");
		int num = mainMenu();
		switch (num)
		{
		case 1:
		{
			//���� ���� 
			bookRun();
			break;
		}
		case 2:
		{
			//��� ����
			eventRun();
			break;
		}
		case 3:
		{
			//�ݳ� ����
			break;
		}
		case 4:
		{
			//����
			cout << "�ȳ��� ���ʽÿ�." << endl;
			return 1;
		}
		}
		return 0;
	}
	int selectBookMenu()
	{
		int num;
		cout << "=======================" << endl;
		cout << "    ���� ����" << endl;
		cout << "=======================" << endl;
		cout << "1. å ���" << endl;
		cout << "2. å ����" << endl;
		cout << "3. å ��ȸ" << endl;
		cout << "4. �ڷΰ���" << endl;
		cout << "-----------------------" << endl;
		cout << "�Է�: ";
		cin >> num;
		return num;
	}
	void bookRun()
	{
		system("cls");
		int num = selectBookMenu();
		switch (num)
		{
		case 1:
		{
			h.BookRegistration();
			Sleep(3000);
			break;
		}
		case 2:
		{
			h.BookDelete();
			Sleep(3000);
			break;
		}
		case 3:
		{
			h.BookSearch();
			Sleep(3000);
			break;
		}
		case 4:
			break;
		}
	}
	int selectEventMenu()
	{
		int num;
		cout << "=======================" << endl;
		cout << "    ��� ����" << endl;
		cout << "=======================" << endl;
		cout << "1. ��� ���" << endl;
		cout << "2. ��� ����" << endl;
		cout << "3. ��� ��ȸ" << endl;
		cout << "4. �ڷ� ����" << endl;
		cout << "-----------------------" << endl;
		cout << "�Է�: ";
		cin >> num;
		return num;
	}
	void eventRun()
	{
		system("cls");
		int num = selectEventMenu();
		switch (num)
		{
		case 1:
		{
			h.EventRegistration();
			Sleep(3000);
			break;
		}
		case 2:
		{
			h.EventDelete();
			Sleep(3000);
			break;
		}
		case 3:
		{
			h.EventSearch();
			Sleep(3000);
			break;
		}
		case 4:
			break;
		}
	}
};