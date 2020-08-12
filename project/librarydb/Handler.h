#pragma once

#define MYSQLIP "10.10.20.229"
#define DATE "2020-08-12"

using namespace std;
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
		date = DATE;
	}
	string Getdate() const;
	void BookRegistration(); //å���
	void EventRegistration(); //��� ���
	void BookDelete(); //å����
	void EventDelete(); //��� ����
	void BookSearch(); //å ��ȸ
	void EventSearch(); //��� ��ȸ
	void BookRental(); //å �뿩
	void BookReturn(); //å �ݳ�
	void RentalSearch(); //�뿩 ��ȸ
	void ReturnSearch(); //�ݳ� ��ȸ
	void Deadline(); //����
	void IncreaseLate_fee(); //��ü�� ����
	void IncreaseDay(); //�Ϸ� ����
	void Loadmysql();	//MYSQL ���� �ҷ�����
	void error_check(); //����üũ
	void SetInfo(); //ID, password ����
};