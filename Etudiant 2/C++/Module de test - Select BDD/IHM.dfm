object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
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
    Left = 258
    Top = 45
    Width = 82
    Height = 13
    Caption = 'Liste des courses'
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
  object Panel: TPanel
    Left = 8
    Top = 8
    Width = 25
    Height = 25
    Color = clRed
    ParentBackground = False
    TabOrder = 0
  end
  object ListBox1: TListBox
    Left = 258
    Top = 64
    Width = 121
    Height = 73
    ItemHeight = 13
    TabOrder = 1
  end
  object ValiderCourse: TButton
    Left = 258
    Top = 143
    Width = 121
    Height = 25
    Caption = 'Valider ce choix'
    TabOrder = 2
    OnClick = ValiderCourseClick
  end
  object Memo1: TMemo
    Left = 556
    Top = 203
    Width = 71
    Height = 89
    Lines.Strings = (
      '')
    TabOrder = 3
  end
end
