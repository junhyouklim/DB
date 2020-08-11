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
	void BookRegistration(); //å���
	void EventRegistration(); //��� ���
	void BookDelete(); //å����
	void EventDelete(); //��� ����
	void BookSearch(); //å ��ȸ
	void EventSearch(); //��� ��ȸ
	void Loadmysql();	//MYSQL ���� �ҷ�����
	void error_check(); //����üũ
	void SetInfo(); //ID, password ����
};
