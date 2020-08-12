#pragma once
#include <iostream>
#include <string>
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
		cout << "��¥ :" << h.Getdate() << endl;
		cout << "======================" << endl;
		cout << " 1. ���� ����" << endl;
		cout << " 2. ��� ����" << endl;
		cout << " 3. �ݳ� ����" << endl;
		cout << " 4. ����" << endl;
		cout << " 5. ����" << endl;
		cout << "======================" << endl;
		cout << "�Է�: ";
		cin >> num;
		return num;
	}
	void mainRun()
	{
		while (1)
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
				//�뿩 ����
				RentalRun();
				break;
			}
			case 4:
			{
				//����
				h.Deadline();
				break;
			}
			case 5:
			{
				//����
				cout << "�ȳ��� ���ʽÿ�." << endl;
				return;
			}
			default:
			{
				cout << "���� ���" << endl;
				Sleep(1000);
				break;
			}
			}
		}
	}
	int selectRentalMenu()
	{
		int num;
		cout << "=======================" << endl;
		cout << "      �뿩 ����" << endl;
		cout << "=======================" << endl;
		cout << " 1. å �ݳ�" << endl;
		cout << " 2. �뿩 ��ȸ" << endl;
		cout << " 3. �ݳ� ��ȸ" << endl;
		cout << " 4. �ڷΰ���" << endl;
		cout << "-----------------------" << endl;
		cout << "�Է�: ";
		cin >> num;
		return num;
	}
	void RentalRun()
	{
		while(1)
		{
			system("cls");
			int num = selectRentalMenu();
			switch (num)
			{
			case 1:
			{
				h.BookReturn();
				break;
			}
			case 2:
			{
				h.RentalSearch();
				break;
			}
			case 3:
			{
				h.ReturnSearch();
				break;
			}
			case 4:
				return;
			default:
			{
				cout << "���� ���" << endl;
				Sleep(1000);
				break;
			}
			}
		}
		
	}
	int selectBookMenu()
	{
		int num;
		cout << "=======================" << endl;
		cout << "      ���� ����" << endl;
		cout << "=======================" << endl;
		cout << " 1. å ���" << endl;
		cout << " 2. å ����" << endl;
		cout << " 3. å ��ȸ" << endl;
		cout << " 4. å �뿩" << endl;
		cout << " 5. �ڷΰ���" << endl;
		cout << "-----------------------" << endl;
		cout << "�Է�: ";
		cin >> num;
		return num;
	}
	void bookRun()
	{
		while (1)
		{
			system("cls");
			int num = selectBookMenu();
			switch (num)
			{
			case 1:
			{
				h.BookRegistration();
				break;
			}
			case 2:
			{
				h.BookDelete();
				break;
			}
			case 3:
			{
				h.BookSearch();
				break;
			}
			case 4:
			{
				h.BookRental();
				break;
			}
			case 5:
				return;
			default:
			{
				cout << "���� ���" << endl;
				Sleep(1000);
				break;
			}
			}
		}
	}
	int selectEventMenu()
	{
		int num;
		cout << "=======================" << endl;
		cout << "      ��� ����" << endl;
		cout << "=======================" << endl;
		cout << " 1. ��� ���" << endl;
		cout << " 2. ��� ����" << endl;
		cout << " 3. ��� ��ȸ" << endl;
		cout << " 4. �ڷ� ����" << endl;
		cout << "-----------------------" << endl;
		cout << "�Է�: ";
		cin >> num;
		return num;
	}
	void eventRun()
	{
		while (1)
		{
			system("cls");
			int num = selectEventMenu();
			switch (num)
			{
			case 1:
			{
				h.EventRegistration();
				
				break;
			}
			case 2:
			{
				h.EventDelete();
				break;
			}
			case 3:
			{
				h.EventSearch();
				break;
			}
			case 4:
				return;
			default:
			{
				cout << "���� ���" << endl;
				Sleep(1000);
				break;
			}
			}
		}
	}
};