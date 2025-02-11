//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo1->Clear();
	// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);


	Memo1->Lines->Add( "Heure/Date actuelle :");
	Memo1->Lines->Add(buf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 Memo2->Clear();
	// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
	time_t     now = time(0);
	struct tm  tstruct;
	char       heure[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(heure, sizeof(heure), "%X",&tstruct);

	Memo2->Lines->Add( "Heure actuelle :");
	Memo2->Lines->Add(heure);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtontimeClick(TObject *Sender)
{
	// Create a raw time_t variable and a tm structure
  time_t rawtime;
  struct tm * timeinfo;

  // Get the current time and place it in time_t
  time (&rawtime);

  // Get the locatime from the time_t and put it into our structure timeinfo
  timeinfo = localtime ( &rawtime );
  // Now we have access to hours, minutes, seconds etc as member variables of all type int
  int hour = timeinfo->tm_hour;
  int min = timeinfo->tm_min;
  int sec = timeinfo->tm_sec;
  // Just print out the hours and minutes to show you
  Memo1->Lines->Add(hour);
  Memo1->Lines->Add(min);
  Memo1->Lines->Add(sec);


}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtontimezeroClick(TObject *Sender)
{
    timezero = time(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Buttontime1Click(TObject *Sender)
{
	timeun = time(0);
	time_t diff = timeun-timezero;
	Memo3->Lines->Add(diff);
}
//---------------------------------------------------------------------------
