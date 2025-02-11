//---------------------------------------------------------------------------
#ifndef MySQLH
#define MySQLH

#include <vcl.h>
#include <System.hpp>
//Librairie permettant d'interroger la bdd
#include "include/mysql.h"
//Librairie vector qui permet de realiser des tableaux dynamique, utile pour enregistrer les resultats des SELECT
#include <vector>
using namespace std;
//---------------------------------------------------------------------------
class ClassBDD
{
		bool Etat;
		//Suite de variables utilisees pour lire les resultats des requetes
		MYSQL *MyS;
		MYSQL_RES *myRES;
		MYSQL_ROW myROW;
		AnsiString aStr;
		//Variables utilisees pour renvoyer les messages d'erreur
		unsigned int myErrorCode;
		AnsiString myErrorMsg;
	public:
		ClassBDD();
		bool Connexion(String IPMys,String IDMys,String MDPMys,String BaseMys, String *MSG_Error);
		bool Select(vector<String> *resultats, String *MSG_Error, String requeteMyS);
		bool Query(String *MSG_Error, String requeteMyS);
		bool Deconnexion();
};
#endif
