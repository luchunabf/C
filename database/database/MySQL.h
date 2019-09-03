#pragma once
#include <iostream>
#include <WinSock2.h>
#include <mysql.h>
#include <string>
#include <vector>
using namespace std;

#pragma comment(lib, "libmysql.lib")


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

