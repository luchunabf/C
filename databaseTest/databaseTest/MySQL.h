#pragma once
#include <WinSock2.h>
#include <mysql.h>
#include <string>
#include <vector>
using namespace std;

class MySQL
{
public:
	MySQL();
	bool ConnectMySql(const char* host, // ��������
		const char* user, // �û���
		const char* passward, // ����
		const char* dbName, // ���ݿ���
		int port = 3306); // �˿ںţ�Ĭ��Ϊ3306
	~MySQL();
	bool Insert(const string& strSQL);
	bool Delete(const string& strSQL);
	bool Update(const string& strSQL);
	size_t GetCount(const string& strSQL);
	vector<vector<string>> Select(const string& strSQL);
	// �л����ݿ�
	bool SelectDB(const string& daName);
private:
	MYSQL* _mySql; // mysql���ӵ�ʵ������
	std::string _dbName;
	vector<string> _tables;
};

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "libmysql.lib")
MySQL::MySQL()
{
	// ��ʼ��mySql
	_mySql = mysql_init(nullptr);
}
bool MySQL::ConnectMySql(const char* host, const char* user, const char* passward,
	const char* dbName, int port)
{
	// ����mySql���ݿ�
	if (!mysql_real_connect(_mySql, host, user, passward, dbName, port, NULL, 0))
	{
		return false;
	}
	/*
	c++����mysqlʱ�������ѯ����к������ģ����ߵõ�����к������ģ��������ֱ�������������
	�⡣
	VS������Ĭ��ʹ��gbk���롣
	�����mysql����Ϊutf-8���룬����Ҫ�Ƚ�c++�еĸ��������ַ���תΪutf-8��������mysql���õ�
	�Ľ��Ϊutf-8���룬��ҪתΪgbk����������ʾ��ת��תȥ���鷳��
	*/
	mysql_query(_mySql, "set names 'gbk'");
	return true;
}
bool MySQL::SelectDB(const string& dbName)
{
	if (mysql_select_db(_mySql, dbName.c_str()))
	{
		return false;
	}
	return true;
}
bool MySQL::Insert(const string& strSql)
{
	// ִ��sql���
	if (mysql_query(_mySql, strSql.c_str()))
	{
		return false;
	}
	return true;
}
bool MySQL::Update(const string& strSQL)
{
	// ִ��sql���
	if (mysql_query(_mySql, strSQL.c_str()))
	{
		return false;
	}
	return true;
}
vector<vector<string>> MySQL::Select(const string& sql)
{
	vector<vector<string>> vRet;
	// ָ��ָ��SQL���
	if (mysql_query(_mySql, sql.c_str()))
	{
		string vsRet(mysql_error(_mySql));
		return vRet;
	}
	// �������������ݼ����ͻ���
	MYSQL_RES *res = mysql_store_result(_mySql);
	if (res == NULL)
	{
		return vRet;
	}
	// ���������������е���Ϣ
	MYSQL_ROW rows;
	// ��������ܹ��ж���������
	int num_fields = mysql_num_fields(res);
	while (rows = mysql_fetch_row(res))
	{
		int i = 0;
		vector<string> vItem;
		vItem.resize(num_fields);
		for (i = 0; i < num_fields; i++)
		{
			vItem[i] = rows[i];
		}
		vRet.push_back(vItem);
	}
	const char* str = mysql_error(_mySql);
	mysql_free_result(res);
	return vRet;
}
size_t MySQL::GetCount(const string& strSQL)
{
	// ָ��ָ��SQL���
	if (mysql_query(_mySql, strSQL.c_str()))
	{
		return 0;
	}
	// �������������ݼ����ͻ���
	MYSQL_RES *res = mysql_store_result(_mySql);
	if (res == NULL)
	{
		return 0;
	}
	return mysql_num_fields(res);
}
bool MySQL::Delete(const string& strSQL)
{
	// ִ��sql���
	if (mysql_query(_mySql, strSQL.c_str()))
	{
		return false;
	}
	return true;
}
MySQL::~MySQL()
{
	mysql_close(_mySql);
}