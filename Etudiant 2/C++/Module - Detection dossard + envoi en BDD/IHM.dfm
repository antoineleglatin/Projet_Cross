object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Application Course '#224' pied'
  ClientHeight = 467
  ClientWidth = 1022
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Resultat: TLabel
    Left = 8
    Top = 48
    Width = 98
    Height = 16
    Caption = 'Liste des courses'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object BDDPanel: TLabel
    Left = 39
    Top = 14
    Width = 20
    Height = 13
    Caption = 'BDD'
    Color = clRed
    ParentColor = False
  end
  object Label1: TLabel
    Left = 8
    Top = 211
    Width = 83
    Height = 16
    Caption = 'Course choisie'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 160
    Top = 48
    Width = 120
    Height = 16
    Caption = 'Nom des participants'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object LabelAssocier: TLabel
    Left = 312
    Top = 384
    Width = 373
    Height = 18
    Caption = 'Choisir un participant et un dossard et cliquer sur associer'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Panel: TPanel
    Left = 8
    Top = 8
    Width = 25
    Height = 25
    Color = clRed
    ParentBackground = False
    TabOrder = 0
  end
  object ListBoxNomCourse: TListBox
    Left = 8
    Top = 67
    Width = 129
    Height = 102
    ItemHeight = 13
    TabOrder = 1
  end
  object ValiderCourse: TButton
    Left = 8
    Top = 175
    Width = 129
    Height = 25
    Caption = 'Valider ce choix'
    TabOrder = 2
    OnClick = ValiderCourseClick
  end
  object MemoCourseChoisie: TMemo
    Left = 8
    Top = 230
    Width = 129
    Height = 51
    TabOrder = 3
  end
  object ListBoxNom: TListBox
    Left = 160
    Top = 67
    Width = 129
    Height = 133
    ItemHeight = 13
    TabOrder = 4
    Visible = False
  end
  object Memo2: TMemo
    Left = 864
    Top = 8
    Width = 150
    Height = 49
    TabOrder = 5
  end
  object ListBoxDossard: TListBox
    Left = 909
    Top = 148
    Width = 105
    Height = 37
    ItemHeight = 13
    TabOrder = 6
    Visible = False
  end
  object NouveauDossard: TButton
    Left = 907
    Top = 117
    Width = 105
    Height = 25
    Caption = 'Nouveau Dossard'
    TabOrder = 7
    Visible = False
    OnClick = NouveauDossardClick
  end
  object ButtonAssociation: TButton
    Left = 440
    Top = 408
    Width = 121
    Height = 45
    Caption = 'Association'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    Visible = False
    OnClick = ButtonAssociationClick
  end
  object ButtonDossard: TButton
    Left = 907
    Top = 228
    Width = 107
    Height = 25
    Caption = 'Liste des dossards'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    Visible = False
    OnClick = ButtonDossardClick
  end
  object ListBoxVector: TListBox
    Left = 907
    Top = 259
    Width = 107
    Height = 200
    ItemHeight = 13
    TabOrder = 10
    Visible = False
  end
  object ButtonDemarrer: TButton
    Left = 416
    Top = 102
    Width = 205
    Height = 67
    Caption = 'D'#233'marrer la course'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Trebuchet MS'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    Visible = False
    OnClick = ButtonDemarrerClick
  end
  object ButtonPassage: TButton
    Left = 784
    Top = 259
    Width = 117
    Height = 25
    Caption = 'Passage de ce dossard'
    TabOrder = 12
    Visible = False
    OnClick = ButtonPassageClick
  end
  object ButtonFin: TButton
    Left = 456
    Top = 175
    Width = 129
    Height = 34
    Caption = 'Fin de Course'
    TabOrder = 13
    Visible = False
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 824
    Top = 8
  end
end
