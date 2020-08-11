#pragma once
#define MYSQLIP "10.10.20.229"

using namespace std;
class Handler
{
private:
	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
	string id ,password;
public:
	Handler()
	{
		conn = mysql_init(NULL);
	}
	void BookRegistration(); //책등록
	void EventRegistration(); //행사 등록
	void BookDelete(); //책삭제
	void EventDelete(); //행상 삭제
	void BookSearch(); //책 조회
	void EventSearch(); //행사 조회
	void Loadmysql();	//MYSQL 서버 불러오기
	void error_check(); //에러체크
	void SetInfo(); //ID, password 설정
};
