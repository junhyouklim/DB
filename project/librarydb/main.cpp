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
c_str()함수는 문자열 배열의 시작 주소값을 리턴함
int mysql_query(MYSQL* mysql, const char* query)
	query가 포인트 하는 쿼리를 수행한다. query의 끝은 NULL 문자이다.
	성공적으로 query를 수행하였으면 0을 리턴한다.
unsigned int mysql_num_fields(MYSQL_RES*result) 혹은
unsigned int mysql_num_fields(MYSQL* mysql)
	필드의 수를 리턴한다.
*/