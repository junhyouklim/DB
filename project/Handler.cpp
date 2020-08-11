#include <iostream>
#include <mysql.h>
#include <string>
#include <Windows.h>
#include "Handler.h"
using namespace std;

void Handler::BookRegistration() //å���
{
	string name, pub;

	cout << "�̸��� �Է��� �ּ��� : ";
	cin >> name;

	cout << "���ǻ縦 �Է��� �ּ��� : ";
	cin >> pub;

	string query = "insert into BookTBL(name_book,publisher) values('" + name + "','" + pub + "')";

	if (mysql_query(conn, query.c_str())) 
	{
		error_check();
	}

	cout << "å ������ ���������� ��ϵǾ����ϴ�." << endl;
}
void Handler::EventRegistration() //��� ���
{
	string name, day;

	cout << "��� �̸��� �Է��� �ּ��� : ";
	cin >> name;

	cout << "��� ��¥�� �Է��� �ּ��� : ";
	cin >> day;

	string query = "insert into eventTBL(name_event,day_event) values('" + name + "','" + day + "')";

	if (mysql_query(conn, query.c_str())) 
	{
		error_check();
	}

	cout << "��� ������ ���������� ��ϵǾ����ϴ�." << endl;
}
void Handler::BookDelete() //å����
{
	string name;

	cout << "������ å �̸��� �Է��� �ּ��� : ";
	cin >> name;

	string query = "delete from BookTBL where name_book='" + name + "'";

	if (mysql_query(conn, query.c_str())) 
	{
		error_check();
	}
	cout << "�ش� å�� ���������� �����Ǿ����ϴ�." << endl;
}
void Handler::EventDelete() //��� ����
{
	string name;

	cout << "������ ��� �̸��� �Է��� �ּ��� : ";
	cin >> name;

	string query = "delete from eventTBL where name_event='" + name + "'";

	if (mysql_query(conn, query.c_str())) 
	{
		error_check();
	}

	cout << "�ش� ��簡 ���������� �����Ǿ����ϴ�." << endl;
}
void Handler::BookSearch() //å ��ȸ
{
	cout << "No.\tå�̸�\t���ǻ�" << endl;

	if (mysql_query(conn, "SELECT * FROM BookTBL"))
	{
		error_check();
	}
	res = mysql_store_result(conn);
	if (res == NULL)
	{
		error_check();
	}
	int num_fields = mysql_num_fields(res); //columns(fields)�� �� ��ȯ
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
void Handler::EventSearch() //��� ��ȸ
{
	cout << "No.\t��� �̸�\t��� ��¥" << endl;

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
void Handler::Loadmysql()	//MYSQL ���� �ҷ�����
{
	if (conn == NULL) //cons�� �ʱ�ȭ�� ��������
	{
		fprintf(stderr, "%s\n", mysql_error(conn));		//���� ����Ʈ, printf("%s")�� ����
		exit(1);
	}
	SetInfo();
	if (!(mysql_real_connect(conn, MYSQLIP, id.c_str(), password.c_str(), "libdb", 3306, NULL, 0)==NULL)) //mysql������ ���� �����ϸ� 0 �ƴϸ� �ٸ��� ��ȯ
	{
		printf("DB Connecting ����\n");
		mysql_set_character_set(conn, "euckr");				//MySQL ���ڸ� �����Ѵ�. ���� ���ϸ� �ѱ��� ©��.
		/*mysql_query(conn, "set session character_set_connection=euckr;");
		mysql_query(conn, "set session character_set_results=euckr;");
		mysql_query(conn, "set session character_set_client=euckr;");*/
		printf("MySQL server version: %lu\n", mysql_get_server_version(conn)); //���� ����Ȯ��
		printf("MySQL client version: %lu\n", mysql_get_client_version()); //Ŭ���̾�Ʈ ����Ȯ��
		printf("MySQL Ping: %d\n", mysql_ping(conn)); //int�� ��ȯ
		Sleep(1000);
		system("cls");
	}
	else {
		fprintf(stderr, "���� ���� : %s\n", mysql_error(conn));
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
	cout << "DB ID �Է�: ";
	cin >> id;
	cout << "DB PASSWORD �Է�: ";
	cin >> password;
}