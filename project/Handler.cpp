#include <iostream>
#include <mysql.h>
#include <string>
#include <Windows.h>
#include "Handler.h"
using namespace std;

void Handler::BookRegistration() //책등록
{
	string name, pub;

	cout << "이름을 입력해 주세요 : ";
	cin >> name;

	cout << "출판사를 입력해 주세요 : ";
	cin >> pub;

	string query = "insert into BookTBL(name_book,publisher) values('" + name + "','" + pub + "')";

	if (mysql_query(conn, query.c_str())) 
	{
		error_check();
	}

	cout << "책 정보가 정상적으로 등록되었습니다." << endl;
}
void Handler::EventRegistration() //행사 등록
{
	string name, day;

	cout << "행사 이름을 입력해 주세요 : ";
	cin >> name;

	cout << "행사 날짜를 입력해 주세요 : ";
	cin >> day;

	string query = "insert into eventTBL(name_event,day_event) values('" + name + "','" + day + "')";

	if (mysql_query(conn, query.c_str())) 
	{
		error_check();
	}

	cout << "행사 정보가 정상적으로 등록되었습니다." << endl;
}
void Handler::BookDelete() //책삭제
{
	string name;

	cout << "삭제할 책 이름을 입력해 주세요 : ";
	cin >> name;

	string query = "delete from BookTBL where name_book='" + name + "'";

	if (mysql_query(conn, query.c_str())) 
	{
		error_check();
	}
	cout << "해당 책이 정상적으로 삭제되었습니다." << endl;
}
void Handler::EventDelete() //행상 삭제
{
	string name;

	cout << "삭제할 행사 이름을 입력해 주세요 : ";
	cin >> name;

	string query = "delete from eventTBL where name_event='" + name + "'";

	if (mysql_query(conn, query.c_str())) 
	{
		error_check();
	}

	cout << "해당 행사가 정상적으로 삭제되었습니다." << endl;
}
void Handler::BookSearch() //책 조회
{
	cout << "No.\t책이름\t출판사" << endl;

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
			cout << (row[i] ? row[i] : "NULL") << "\t";
		}
		cout << endl;
	}
	mysql_free_result(res);
}
void Handler::EventSearch() //행사 조회
{
	cout << "No.\t행사 이름\t행사 날짜" << endl;

	if (mysql_query(conn, "SELECT * FROM eventTBL"))
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
			cout << (row[i] ? row[i] : "NULL")<<"\t";
		}
		cout << endl;
	}
	mysql_free_result(res);
}
void Handler::Loadmysql()	//MYSQL 서버 불러오기
{
	if (conn == NULL) //cons가 초기화를 못했으면
	{
		fprintf(stderr, "%s\n", mysql_error(conn));		//에러 프린트, printf("%s")와 같음
		exit(1);
	}
	SetInfo();
	if (!(mysql_real_connect(conn, MYSQLIP, id.c_str(), password.c_str(), "libdb", 3306, NULL, 0)==NULL)) //mysql서버로 연결 성공하면 0 아니면 다른수 반환
	{
		printf("DB Connecting 성공\n");
		mysql_set_character_set(conn, "euckr");				//MySQL 문자를 지정한다. 만약 안하면 한글이 짤림.
		/*mysql_query(conn, "set session character_set_connection=euckr;");
		mysql_query(conn, "set session character_set_results=euckr;");
		mysql_query(conn, "set session character_set_client=euckr;");*/
		printf("MySQL server version: %lu\n", mysql_get_server_version(conn)); //서버 버젼확인
		printf("MySQL client version: %lu\n", mysql_get_client_version()); //클라이언트 버젼확인
		printf("MySQL Ping: %d\n", mysql_ping(conn)); //int형 반환
		Sleep(1000);
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