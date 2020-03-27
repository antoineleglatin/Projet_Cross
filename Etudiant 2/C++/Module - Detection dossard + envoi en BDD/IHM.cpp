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
	//instanciation des classes
	Course = new ClassCourse();
	SQL = new ClassBDD();

	//messages d'erreurs
	mySQL = mysql_init(NULL);
	MSG_Error_Co = "Erreur de connexion BDD";
	MSG_Error_Select = "Erreur sur la requete Select";
	MSG_Error_Insert = "Erreur sur la requete Insert";

	String RequeteSelectCourses = "SELECT `Nom` FROM `Course`";

	//CONNECT BDD
	bool connect = SQL->Connexion(HOST, USER, PASSWORD, DATABASE, &MSG_Error_Co);//fonctionne
	 if (connect == true)//si connexion fonctionne
	 {
		 Panel->Color = clLime; //bouton vert si connect�e
		 //SELECT COURSES
		 SQL->Select(&resultats, &MSG_Error_Select, RequeteSelectCourses);
		 for (int i = 0; i < resultats.size(); i++)
		 {
			ListBoxNomCourse->Items->Add(resultats[i]);
		 }
	 }
	 else//si connexion fonctionne pas
	 {
		//on rend tout invisible
		ListBoxNomCourse->Visible= false;
		MemoCourseChoisie->Visible= false;
		ListBoxNom->Visible=false;
		Label1->Visible=false;
		Label2->Visible=false;
		Resultat->Visible=false;
		ListBoxDossard->Visible=false;
		ValiderCourse->Visible=false;
		NouveauDossard->Visible=false;
	 }
}

//---------------------------------------------------------------------------


void __fastcall TForm1::ValiderCourseClick(TObject *Sender)
{
//------------------------AFFICHAGE------------------------------------//
	Label2->Visible=true;
	ListBoxNom->Visible=true;
	NouveauDossard->Visible=true;
	ListBoxDossard->Visible=true;
	LabelAssocier->Visible=true;
	ButtonAssociation->Visible=true;
	ListBoxNom->Clear();
	MemoCourseChoisie->Clear();

//------------------------SELECT ET INSERT-----------------------------//
	String nomCourseChoisie = ListBoxNomCourse->Items->Strings[ListBoxNomCourse->ItemIndex];//on recupere le nom de la course choisie
	MemoCourseChoisie->Lines->Add(nomCourseChoisie);//affichage de la course choisie

	//on selectionne l'id course en fonction de son nom.
	String selectIdCourseChoisie = "SELECT `IdCourse` FROM `Course` WHERE `Nom` = ";
	selectIdCourseChoisie += "'"+nomCourseChoisie+"'";

	SQL->Select(&resultats, &MSG_Error_Select, selectIdCourseChoisie);
	for (int i = 0; i < resultats.size(); i++)
	{
		MemoCourseChoisie->Lines->Add(resultats[i]);
		IdCourseChoisie=resultats[i];
		Course->setIdCourse(IdCourseChoisie.ToInt());
	}

	String DeleteCourseActuelle = "DELETE FROM `CourseActuelle`";
	String insertCourseActuelle = "INSERT INTO `CourseActuelle`(`IdCourse`) VALUES";
	insertCourseActuelle += "('"+IdCourseChoisie+"')";
	String selectNomUtilisateur = "SELECT `Nom` FROM `Utilisateur`, `Participant`,`CourseActuelle` WHERE";
	selectNomUtilisateur +="'"+IdCourseChoisie+"'";
	selectNomUtilisateur +="= Participant.IdCourse AND Participant.IdUtilisateur = Utilisateur.IdUtilisateur";
	String selectNbTours = "SELECT `NbTours` FROM `Course` WHERE `IdCourse` = ";
	selectNbTours +="'"+IdCourseChoisie+"'";

	SQL->Query(&MSG_Error_Insert, DeleteCourseActuelle);
	SQL->Query(&MSG_Error_Insert, insertCourseActuelle);

	//Select noms des coureurs
	SQL->Select(&resultats, &MSG_Error_Select, selectNomUtilisateur);
	for (int i = 0; i < resultats.size(); i++)
	{
		ListBoxNom->Items->Add(resultats[i]);
	}

	SQL->Select(&resultats, &MSG_Error_Select, selectNbTours);
	for (int i = 0; i < resultats.size(); i++)
	{
		NbToursCourse = resultats[i];
		Course->setNbTours(NbToursCourse.ToInt());
	}
}//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//------------------HORLOGE-----------------------//
	time_t curr_time;
	curr_time = time(NULL);
	tm *tm_local = localtime(&curr_time);

	Memo2->Lines->Add("Heure locale :");
	Memo2->Lines->Add(tm_local->tm_hour);
	Memo2->Lines->Add(tm_local->tm_min);
	Memo2->Lines->Add(tm_local->tm_sec);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::NouveauDossardClick(TObject *Sender)
{
//------------------RANDOM DE DOSSARD-----------//
	ButtonDossard->Visible=true;
    ListBoxVector->Visible=true;
	int numDossard = 0;
	srand(time(NULL)); // initialisation de rand
	numDossard = rand()%(2000000-1000000) + 1000000;
	ListBoxDossard->Clear();
	ListBoxDossard->Items->Add(numDossard);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAssociationClick(TObject *Sender)
{
//----------------ASSOCIATION DE DOSSARDS---------------------//
	String ParticipantChoisi = ListBoxNom->Items->Strings[ListBoxNom->ItemIndex];
	String NumDossard = ListBoxDossard->Items->Strings[ListBoxDossard->ItemIndex];

	String selectIdParticipant = "SELECT `IdUtilisateur` FROM `Utilisateur` WHERE `Nom` = ";
	selectIdParticipant +="'"+ParticipantChoisi+"'";

	AnsiString IdParticipantChoisi;
	Course->ajouterDossard(NumDossard.ToInt());

	SQL->Select(&resultats, &MSG_Error_Select, selectIdParticipant);
	for (int i = 0; i < resultats.size(); i++)
		 {
			IdParticipantChoisi = resultats[i];
		 }

	String updateNumDossard = "UPDATE `Participant` SET `IdDossard`= ";
	updateNumDossard += "'"+NumDossard+"'";
	updateNumDossard += "WHERE `IdUtilisateur`= ";
	updateNumDossard +=	"'"+IdParticipantChoisi+"'";

	SQL->Query(&MSG_Error_Insert, updateNumDossard);
    ButtonDemarrer->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDossardClick(TObject *Sender)
{
//-----------AJOUT DU DOSSARD DANS LE VECTOR-----------//
	std::vector<int> dossards = Course->returnDossards();
	for (int i = 0; i < dossards.size(); i++)
	{
		 ListBoxVector->Items->Add(dossards[i]);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDemarrerClick(TObject *Sender)
{
//-------------DISSIMULATION DES BOUTONS------------//
	ListBoxNomCourse->Visible= false;
	ListBoxNom->Visible=false;
	ListBoxDossard->Visible=false;
	MemoCourseChoisie->Visible= false;

	Label1->Visible=false;
	Label2->Visible=false;
	LabelAssocier->Visible=false;
	Resultat->Visible=false;

	NouveauDossard->Visible=false;
	ValiderCourse->Visible=false;
	ButtonAssociation->Visible=false;
	ButtonDossard->Visible=false;
	ButtonDemarrer->Visible=false;
}
//---------------------------------------------------------------------------

