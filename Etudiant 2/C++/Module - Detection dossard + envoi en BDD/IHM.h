//---------------------------------------------------------------------------

#ifndef IHMH
#define IHMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "include/mysql.h"
#include "ClassCourse.h"
#include "ClassBDD.h"
#include <Vcl.ExtCtrls.hpp>
#include <Windows.h>
#include <deque>
#include <vector>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TLabel *Resultat;
	TPanel *Panel;
	TLabel *BDDPanel;
	TListBox *ListBoxNomCourse;
	TButton *ValiderCourse;
	TMemo *MemoCourseChoisie;
	TLabel *Label1;
	TListBox *ListBoxNom;
	TMemo *Memo2;
	TTimer *Timer1;
	TListBox *ListBoxDossard;
	TLabel *Label2;
	TButton *NouveauDossard;
	TLabel *LabelAssocier;
	TButton *ButtonAssociation;
	TButton *ButtonDossard;
	TListBox *ListBoxVector;
	TButton *ButtonDemarrer;
	TButton *ButtonPassage;
	TButton *ButtonFin;
	void __fastcall ValiderCourseClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall NouveauDossardClick(TObject *Sender);
	void __fastcall ButtonAssociationClick(TObject *Sender);
	void __fastcall ButtonDossardClick(TObject *Sender);
	void __fastcall ButtonDemarrerClick(TObject *Sender);
	void __fastcall ButtonPassageClick(TObject *Sender);
private:	// Déclarations utilisateur
	ClassBDD *SQL;
	ClassCourse *Course;

	String MSG_Error_Co, MSG_Error_Select, MSG_Error_Insert;
	vector<String> resultats;
	//AnsiString NomCourse ;
	AnsiString IdCourseChoisie;
	AnsiString NomParticipantsCourse;
	AnsiString NbToursCourse;
	int TempsDebutCourse;
	int NumTour;

public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
