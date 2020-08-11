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
		cout << " 1. 도서 관리" << endl;
		cout << " 2. 행사 관리" << endl;
		cout << " 3. 반납 관리" << endl;
		cout << " 4. 종료" << endl;
		cout << "======================" << endl;
		cout << "입력: ";
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
			//도서 관리 
			bookRun();
			break;
		}
		case 2:
		{
			//행사 관리
			eventRun();
			break;
		}
		case 3:
		{
			//반납 관리
			break;
		}
		case 4:
		{
			//종료
			cout << "안녕히 가십시오." << endl;
			return 1;
		}
		}
		return 0;
	}
	int selectBookMenu()
	{
		int num;
		cout << "=======================" << endl;
		cout << "    도서 관리" << endl;
		cout << "=======================" << endl;
		cout << "1. 책 등록" << endl;
		cout << "2. 책 삭제" << endl;
		cout << "3. 책 조회" << endl;
		cout << "4. 뒤로가기" << endl;
		cout << "-----------------------" << endl;
		cout << "입력: ";
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
		cout << "    행사 관리" << endl;
		cout << "=======================" << endl;
		cout << "1. 행사 등록" << endl;
		cout << "2. 행사 삭제" << endl;
		cout << "3. 행사 조회" << endl;
		cout << "4. 뒤로 가기" << endl;
		cout << "-----------------------" << endl;
		cout << "입력: ";
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