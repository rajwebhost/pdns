/* Copyright 2001 Netherlabs BV, bert.hubert@netherlabs.nl. See LICENSE 
   for more information.
   $Id: smysql.hh,v 1.2 2002/11/29 15:20:08 ahu Exp $  */
#ifndef SMYSQL_HH
#define SMYSQL_HH

#include <mysql.h>
#include "ssql.hh"

class SMySQL : public SSql
{
public:
  SMySQL(const string &database, const string &host="", 
	 const string &msocket="",const string &user="", 
	 const string &password="");

  ~SMySQL();
  
  SSqlException sPerrorException(const string &reason);
  int doQuery(const string &query, result_t &result);
  int doQuery(const string &query);
  bool getRow(row_t &row);
  string escape(const string &str);    
  void setLog(bool state);
private:
  MYSQL d_db;
  MYSQL_RES *d_rres;
  static bool s_dolog;
};
      
#endif /* SSMYSQL_HH */
