//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHM.h"
#include <string.h>
#include <deque>
#include <vector>
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define HOST "192.168.1.68"
#define USER "msv"
#define PASSWORD "msv"
#define DATABASE "Projet_Cross"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	mySQL = mysql_init(NULL);

	conn=mysql_real_connect(mySQL, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0);
	if(conn==NULL)
	{
	}
	else
	{
		Panel->Color = clLime;
		AnsiString selectCourses = "SELECT `Nom` FROM `Course`";

	if (!mysql_query(mySQL, selectCourses.c_str()))
	{
		myRES = mysql_store_result(mySQL);
		if (myRES)
		{
			for(unsigned int i = 0; i < myRES->row_count; i++)
			{
				myROW = mysql_fetch_row(myRES);
				for(unsigned int j = 0; j < mysql_num_fields(myRES); j++)
				{
					aStr = myROW[j];
					ListBox1->Items->Add(aStr);
				}
			}
			mysql_free_result(myRES);
		}
	}
	}
}

//---------------------------------------------------------------------------


void __fastcall TForm1::ValiderCourseClick(TObject *Sender)
{
	String nomCourseChoisie = ListBox1->Items->Strings[ListBox1->ItemIndex];
	Memo1->Lines->Add(nomCourseChoisie);
//	AnsiString selectIdCourseChoisie = "SELECT `IdCourse` FROM `Course` WHERE `Nom` = '"+nomCourseChoisie+"'";
//	int IdCourse = mysql_query(mySQL, selectIdCourseChoisie.c_str());
//	AnsiString insertCourseActuelle = "INSERT INTO `CourseActuelle`(`Nom`) VALUES ('"+IdCourse+"')";
//	mysql_query(mySQL, insertCourseActuelle.c_str());
}
//---------------------------------------------------------------------------


