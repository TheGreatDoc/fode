#include "fonline_tla.h"
#include <mysql.h>
#pragma comment (lib, "libmariadb.lib")

// Extern data definition
_GlobalVars GlobalVars;

// Entry point
FONLINE_DLL_ENTRY( isCompiler )
{
    if( isCompiler )
        return;

    // Test Memory Level 3 for loaded DLLs
    for( uint i = 0; i < 666; i++ )
        volatile char* leak = new char[ 2 ];
}

EXPORT int SqlQueryti(ScriptString& ServerIp ,int port ,ScriptString& name,ScriptString& pass, ScriptString& BdName, ScriptString& query, ScriptString& result)
{
 MYSQL *conn;
 MYSQL_RES *res;
 MYSQL_ROW row;
 int i = 0;
 bool IsConected = false;
 
 // Получаем дескриптор соединения
 conn = mysql_init(NULL);
 result = "";
 if(conn == NULL)
	{
		// Если дескриптор не получен – выводим сообщение об ошибке
		result = "Error: can't create MySQL-descriptor \n";
		return 1;
	}
 // Connect to the server
 if(!mysql_real_connect(conn, ServerIp.c_str(), name.c_str(), pass.c_str(), BdName.c_str(), port, NULL, 0))
	{
		// If you can't connect to the server
		// Database print an error message
		result = "Error: can't connect to database \n";
		return 2;
	}
else
	{
		// Если соединение успешно установлено
		IsConected = true;
		mysql_set_character_set(conn, "utf8"); //изменяем кодировку на нужную, по умалчанию идёт latin1
		
	}
  
	string tempSrt ="";
	if(IsConected)
	{
		mysql_query(conn, query.c_str()); //Делаем запрос

		if (res = mysql_store_result(conn))
			{
				while(row = mysql_fetch_row(res)) 
				{
					for (i=0 ; i < int(mysql_num_fields(res)); i++)
					{
					//Выводим все что есть в базе через цикл 
						result += row[i]; 
						result += " ";
					}
				}
			
			 return 0;
			}
		else 
		{
		result =(stderr, "\n", mysql_error(conn));
		return 3;
		}
	}
return 0;
}