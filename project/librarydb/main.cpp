#include <iostream>
#include <mysql.h>
#include "Handler.h"
#include "UI.h"

using namespace std;

int main()
{
	UI u;

	u.mainRun();

	return 0;
}
/*
c_str()�Լ��� ���ڿ� �迭�� ���� �ּҰ��� ������
int mysql_query(MYSQL* mysql, const char* query)
	query�� ����Ʈ �ϴ� ������ �����Ѵ�. query�� ���� NULL �����̴�.
	���������� query�� �����Ͽ����� 0�� �����Ѵ�.
unsigned int mysql_num_fields(MYSQL_RES*result) Ȥ��
unsigned int mysql_num_fields(MYSQL* mysql)
	�ʵ��� ���� �����Ѵ�.
*/