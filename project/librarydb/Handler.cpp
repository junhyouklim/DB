#include <iostream>
#include <mysql.h>
#include <string>
#include <cstdio>
#include <sstream>
#include <iomanip>
#include <Windows.h>
#include "Handler.h"

using namespace std;
string Handler::Getdate() const
{
	return date;
}
void Handler::BookRegistration() //책등록
{
	string name, pub;

	cout << "이름을 입력해 주세요(등록취소 : 0) : ";
	cin >> name;
	if (name == "0") return;
	cout << "출판사를 입력해 주세요(등록취소 : 0) : ";
	cin >> pub;
	if (name == "0") return;
	string query = "insert into BookTBL(name_book,publisher) values('" + name + "','" + pub + "')";

	if (mysql_query(conn, query.c_str()))
	{
		error_check();
	}

	cout << "책 정보가 정상적으로 등록되었습니다." << endl;
	Sleep(3000);
}
void Handler::EventRegistration() //행사 등록
{
	string name, day;

	cout << "행사 이름을 입력해 주세요(등록취소 : 0) : ";
	cin >> name;
	if (name == "0") return;
	cout << "행사 날짜를 입력해 주세요(등록취소 : 0) : ";
	cin >> day;
	if (name == "0") return;
	string query = "insert into EventTBL(name_event,day_event) values('" + name + "','" + day + "')";

	if (mysql_query(conn, query.c_str()))
	{
		error_check();
	}

	cout << "행사 정보가 정상적으로 등록되었습니다." << endl;
	Sleep(3000);
}
void Handler::BookDelete() //책삭제
{
	string name;

	BookSearch();
	cout << "삭제할 책 이름을 입력해 주세요(삭제취소 : 0) : ";
	cin >> name;
	if (name == "0") return;
	string query = "delete from BookTBL where name_book='" + name + "'";

	if (mysql_query(conn, query.c_str()))
	{
		error_check();
	}
	cout << "해당 책이 정상적으로 삭제되었습니다." << endl;
	Sleep(3000);
}
void Handler::EventDelete() //행상 삭제
{
	string name;

	EventSearch();
	cout << "삭제할 행사 이름을 입력해 주세요(삭제취소 : 0) : ";
	cin >> name;
	if (name == "0") return;
	string query = "delete from EventTBL where name_event='" + name + "'";

	if (mysql_query(conn, query.c_str()))
	{
		error_check();
	}

	cout << "해당 행사가 정상적으로 삭제되었습니다." << endl;
	Sleep(3000);
}
void Handler::BookSearch() //책 조회
{
	cout << "serialNo.\t 책 이름\t 출 판 사" << endl;
	cout << "=================================================" << endl;

	if (mysql_query(conn, "SELECT * FROM BookTBL"))
	{
		error_check();
	}
	res = mysql_store_result(conn);
	if (res == NULL)
	{
		error_check();
	}
	int num_fields = mysql_num_fields(res); //columns(fields)의 수 반환
	while ((row = mysql_fetch_row(res)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			cout << (row[i] ? row[i] : "NULL") << " \t ";
		}
		cout << endl;
	}
	mysql_free_result(res);
	Sleep(3000);
}
void Handler::EventSearch() //행사 조회
{
	cout << "serialNo.\t 행사 이름\t 행사 날짜" << endl;
	cout << "==========================================" << endl;

	if (mysql_query(conn, "SELECT * FROM EventTBL"))
	{
		error_check();
	}
	res = mysql_store_result(conn);
	if (res == NULL)
	{
		error_check();
	}
	int num_fields = mysql_num_fields(res);
	while ((row = mysql_fetch_row(res)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			cout << (row[i] ? row[i] : "NULL") << "\t";
		}
		cout << endl;
	}
	mysql_free_result(res);
	Sleep(3000);
}
void Handler::BookRental() //책 대여
{
	int num;
	ostringstream oss;

	BookSearch();
	cout << "==========================================" << endl;
	cout << "대여할 SerialNO. 입력(대여취소 : 0): ";
	cin >> num;
	if (num == 0) return;
	oss << "insert into RentalTBL(name_book) select name_book from BookTBL where serial_book = " << num;
	string query = oss.str();
	if (mysql_query(conn, query.c_str()))
	{
		error_check();
	}
	query= "update RentalTBL set day_rent='"+ date +"'order by name_book desc LIMIT 1";
	if (mysql_query(conn, query.c_str()))
	{
		error_check();
	}
	cout << "대여가 정상적으로 완료되었습니다." << endl;
	Sleep(3000);
}
void Handler::BookReturn() //책 반납
{
	int num;
	ostringstream oss;

	RentalSearch();
	cout << "====================================================" << endl;
	cout << "반납할 RentalNO. 입력(반납취소 : 0): ";
	cin >> num;
	if (num == 0) return;
	oss << "update RentalTBL set state=1,return_rent=date_format(now(),'%Y-%m-%d') where serial_rent =" << num;
	string query = oss.str();
	if (mysql_query(conn, query.c_str()))
	{
		error_check();
	}
	cout << "반납이 정상적으로 처리되었습니다." << endl;
	Sleep(3000);
}
void Handler::RentalSearch() //대여 조회
{
	cout << "RentalNo.\t대여 책이름\t대여 날짜\t연체료" << endl;
	cout << "====================================================" << endl;
	string query = "select serial_rent,name_book,date_format(day_rent,'%Y-%m-%d'),late_fee from RentalTBL where state=0";
	if (mysql_query(conn,query.c_str()))
	{
		error_check();
	}
	res = mysql_store_result(conn);
	if (res == NULL)
	{
		error_check();
	}
	int num_fields = mysql_num_fields(res);
	while ((row = mysql_fetch_row(res)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			cout << (row[i] ? row[i] : "NULL") << "\t";
		}
		cout << endl;
	}
	mysql_free_result(res);
	Sleep(3000);
}
void Handler::ReturnSearch() //반납 조회
{
	cout << "RentalNo.\t반납 책이름\t반납 날짜" << endl;
	cout << "==========================================" << endl;
	string query = "select serial_rent,name_book,date_format(return_rent,'%Y-%m-%d') from RentalTBL where return_rent is not NULL";
	if (mysql_query(conn,query.c_str()))
	{
		error_check();
	}
	res = mysql_store_result(conn);
	if (res == NULL)
	{
		error_check();
	}
	int num_fields = mysql_num_fields(res);
	while ((row = mysql_fetch_row(res)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			cout << (row[i] ? row[i] : "NULL") << "\t";
		}
		cout << endl;
	}
	mysql_free_result(res);
	Sleep(3000);
}
void Handler::IncreaseDay() //일수 증가
{
	cout << "일수 1일 추가" << endl;
	string query = "select date_add('" + date + "',interval 1 day)";
	if (mysql_query(conn, query.c_str()))
	{
		error_check();
	}
	res = mysql_store_result(conn);
	if (res == NULL)
	{
		error_check();
	}
	row = mysql_fetch_row(res);
	date = row[0];
	mysql_free_result(res);
}
void Handler::IncreaseLate_fee() //연체료 증가
{
	string query = "select serial_rent from RentalTBL where timestampdiff(day,day_rent,'"+ date+"')>3 and state=0";
	if (mysql_query(conn, query.c_str()))
	{
		error_check();
	}
	res = mysql_store_result(conn);
	if (res == NULL)
	{
		error_check();
	}
	while ((row = mysql_fetch_row(res)))
	{
		string temp = row[0];
		query="update RentalTBL set late_fee=late_fee+100 where serial_rent= '" + temp + "'";
		if (mysql_query(conn, query.c_str()))
		{
			error_check();
		}
	}
	mysql_free_result(res);
}
void Handler::Deadline() //마감
{
	IncreaseDay();
	IncreaseLate_fee();
	Sleep(1000);
}
void Handler::Loadmysql()	//MYSQL 서버 불러오기
{
	if (conn == NULL) //conn가 초기화를 못했으면
	{
		fprintf(stderr, "%s\n", mysql_error(conn));		//에러 프린트, printf("%s")와 같음
		exit(1);
	}
	SetInfo();
	if (!(mysql_real_connect(conn, MYSQLIP, id.c_str(), password.c_str(), "libdb", 3306, NULL, 0) == NULL)) //mysql서버로 연결 성공하면 0 아니면 다른수 반환
	{
		printf("DB Connecting 성공\n");
		mysql_set_character_set(conn, "euckr");				//MySQL 문자를 지정한다. 만약 안하면 한글이 짤림.
		printf("MySQL server version: %s\n", mysql_get_server_info(conn)); //서버 버젼확인
		printf("MySQL client version: %s\n", mysql_get_client_info()); //클라이언트 버젼확인
		printf("MySQL HOST INFO: %s\n", mysql_get_host_info(conn)); //host 정보확인
		printf("MySQL Ping: %d\n", mysql_ping(conn)); //int형 반환
		Sleep(2000);
		system("cls");
	}
	else {
		fprintf(stderr, "연결 오류 : %s\n", mysql_error(conn));
		exit(1);
	}
}
void Handler::error_check()
{
	fprintf(stderr, "%s\n", mysql_error(conn));
	mysql_close(conn);
	exit(1);
}
void Handler::SetInfo()
{
	cout << "DB ID 입력: ";
	cin >> id;
	cout << "DB PASSWORD 입력: ";
	cin >> password;
}