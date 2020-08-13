#pragma once
#include "Common.h"

class Handler
{
private:
	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
	string id, password;
	string date;
public:
	Handler()
	{
		conn = mysql_init(NULL);
	}
	string Getdate() const;
	void BookRegistration(); //책등록
	void EventRegistration(); //행사 등록
	void BookDelete(); //책삭제
	void EventDelete(); //행상 삭제
	void BookAllSearch(); //책 전체 조회
	void BookSearch(); //책 이름 조회
	void EventSearch(); //행사 조회
	void BookRental(); //책 대여
	void BookReturn(); //책 반납
	void RentalSearch(); //대여 조회
	void ReturnSearch(); //반납 조회
	void Deadline(); //마감
	void IncreaseLate_fee(); //연체료 증가
	void IncreaseDay(); //하루 증가
	void Loadmysql();	//MYSQL 서버 불러오기
	void error_check(); //에러체크
	void SetInfo(); //ID, password 설정
	~Handler(); //mysql close
};
