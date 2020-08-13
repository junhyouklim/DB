#pragma once
#include "Common.h"
#include "Handler.h"

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
		cout << "날짜 :" << h.Getdate() << endl;
		cout << "======================" << endl;
		cout << " 1. 도서 관리" << endl;
		cout << " 2. 행사 관리" << endl;
		cout << " 3. 반납 관리" << endl;
		cout << " 4. 마감" << endl;
		cout << " 5. 종료" << endl;
		cout << "======================" << endl;
		cout << "입력: ";
		cin >> num;
		cin.ignore();
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
				//대여 관리
				RentalRun();
				break;
			}
			case 4:
			{
				//마감
				h.Deadline();
				break;
			}
			case 5:
			{
				//종료
				cout << "안녕히 가십시오." << endl;
				return;
			}
			default:
			{
				cout << "범위 벗어남" << endl;
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
		cout << "      대여 관리" << endl;
		cout << "=======================" << endl;
		cout << " 1. 책 반납" << endl;
		cout << " 2. 대여 조회" << endl;
		cout << " 3. 반납 조회" << endl;
		cout << " 4. 뒤로가기" << endl;
		cout << "-----------------------" << endl;
		cout << "입력: ";
		cin >> num;
		cin.ignore();
		return num;
	}
	void RentalRun()
	{
		while (1)
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
				system("pause");
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
				cout << "범위 벗어남" << endl;
				Sleep(1000);
				break;
			}
			}
		}

	}

	int selectSearch()
	{
		int num;
		cout << "=======================" << endl;
		cout << "      조회 선택" << endl;
		cout << "=======================" << endl;
		cout << " 1. 전체 조회" << endl;
		cout << " 2. 이름 조회" << endl;
		cout << " 3. 뒤로가기" << endl;
		cout << "-----------------------" << endl;
		cout << "입력: ";
		cin >> num;
		cin.ignore();
		return num;
	}
	void searchRun()
	{
		while (1)
		{
			system("cls");
			int num = selectSearch();
			switch (num)
			{
			case 1:
			{
				h.BookAllSearch();
				system("pause");
				break;
			}
			case 2:
			{
				h.BookSearch();
				system("pause");
				break;
			}
			case 3:
				return;
			default:
			{
				cout << "범위 벗어남" << endl;
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
		cout << "      도서 관리" << endl;
		cout << "=======================" << endl;
		cout << " 1. 책 등록" << endl;
		cout << " 2. 책 삭제" << endl;
		cout << " 3. 책 조회" << endl;
		cout << " 4. 책 대여" << endl;
		cout << " 5. 뒤로가기" << endl;
		cout << "-----------------------" << endl;
		cout << "입력: ";
		cin >> num;
		cin.ignore();
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
				searchRun();
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
				cout << "범위 벗어남" << endl;
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
		cout << "      행사 관리" << endl;
		cout << "=======================" << endl;
		cout << " 1. 행사 등록" << endl;
		cout << " 2. 행사 삭제" << endl;
		cout << " 3. 행사 조회" << endl;
		cout << " 4. 뒤로 가기" << endl;
		cout << "-----------------------" << endl;
		cout << "입력: ";
		cin >> num;
		cin.ignore();
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
				cout << "범위 벗어남" << endl;
				Sleep(1000);
				break;
			}
			}
		}
	}
};
