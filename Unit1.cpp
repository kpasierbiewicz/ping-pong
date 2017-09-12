//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;
int punktyGracza1 = 0;
int punktyGracza2 = 0;
int iloscOdbic = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void pokazMenu()
{
        Form1->Label1->Visible = true;
        Form1->Label2->Visible = true;            Form1->Label5->Caption = punktyGracza2;
        Form1->Label3->Visible = true;
        Form1->Label4->Visible = true;
        Form1->Label5->Visible = true;
        Form1->Label6->Visible = true;
        Form1->Label7->Visible = true;
        Form1->menu->Visible = true;
        Form1->runda->Visible = true;

        Form1->Label5->Caption = punktyGracza2;
        Form1->Label3->Caption = punktyGracza1;
        Form1->Label7->Caption = iloscOdbic;
}

void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
        pilka->Left += x;
        pilka->Top  += y;

        // odbij od gornej krawendzi
        if (pilka->Top - 5 <= tlo->Top)
        {
               y = -y;
        }
        // odbij od dolnej krawendzi
        if (pilka->Top + pilka->Height >= tlo->Height)
        {
               y = -y;
        }

        // skucha
        if (pilka->Left <= tlo->Left)
        {
                Timer_pilka->Enabled = false;
                pilka->Visible = false;
                punktyGracza2++;
                pokazMenu();


        }

        if (pilka->Left >= tlo->Left + tlo->Width + 10)
        {
                Timer_pilka->Enabled = false;
                punktyGracza1++;
                pilka->Visible = false;
                pokazMenu();
        }

        
        else if (pilka->Left < p1->Left  && p1->Top < pilka->Top + pilka->Height && p1->Top + p1->Height > pilka->Top)
        {
                if ( x < 0)
                {
                x = -x;
                iloscOdbic++;
                }

        }
        else if (pilka->Left > p2->Left - 10 && p2->Top < pilka->Top + pilka->Height && p2->Top + p2->Height > pilka->Top)
        {
                if ( x > 0)
                {
                x = -x;
                iloscOdbic++;
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gora_p1Timer(TObject *Sender)
{
        if(p1->Top >= tlo->Top + 5)
        p1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::dol_p1Timer(TObject *Sender)
{
       if(p1->Top <= tlo->Height - p1->Height - 2)
       p1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if (Key == 0x57) gora_p1->Enabled = true;
       if (Key == 0x53) dol_p1->Enabled = true;
       if (Key == VK_UP) gora_p2->Enabled = true;
       if (Key == VK_DOWN) dol_p2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x57) gora_p1->Enabled = false;
        if (Key == 0x53) dol_p1->Enabled = false;
        if (Key == VK_UP) gora_p2->Enabled = false;
        if (Key == VK_DOWN) dol_p2->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gora_p2Timer(TObject *Sender)
{
        if(p2->Top >= tlo->Top + 4)
        p2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::dol_p2Timer(TObject *Sender)
{
       if(p2->Top <= tlo->Height - p2->Height - 2)
       p2->Top += 10;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::rundaClick(TObject *Sender)
{
        iloscOdbic = 0;
        pilka->Visible = true;
        pilka->Left = 504;
        pilka->Top = 208;
        p1->Top = 208;
        p2->Top = 208;

        Form1->Label1->Visible = false;
        Form1->Label2->Visible = false;
        Form1->Label3->Visible = false;
        Form1->Label4->Visible = false;
        Form1->Label5->Visible = false;
        Form1->Label6->Visible = false;
        Form1->Label7->Visible = false;
        Form1->menu->Visible = false;
        Form1->runda->Visible = false;
        Timer_pilka->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        AnsiString strMessage = "Witam w grze!\n";
        AnsiString strMessage2 = "INSTRUKCJA OBS�UGI\n";
        AnsiString strMessage3 = "Obs�uga jest bardzo prosta :)\n";
        AnsiString strMessage4 = "Gracz 1 porusza si� klawiszami W - g�ra i S - D�\n Gracz 2 porusza si� klawiszami strza�ka do g�ry i strza�ka na d�.";
        AnsiString strMessage5 = "\n\n Niech rozpocznie si� gra :)";

        ShowMessage(strMessage + strMessage2 + strMessage3 + strMessage4 + strMessage5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Button1->Visible = false;
        Button2->Visible = false;
        tytul->Visible = false;
        iloscOdbic = 0;
        punktyGracza1 = 0;
        punktyGracza2 = 0;
        Timer_pilka->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::menuClick(TObject *Sender)
{
        Button1->Visible = true;
        Button2->Visible = true;
        tytul->Visible = true;
        pilka->Visible = true;
        pilka->Left = 504;
        pilka->Top = 208;
        p1->Top = 208;
        p2->Top = 208;

        Form1->Label1->Visible = false;
        Form1->Label2->Visible = false;
        Form1->Label3->Visible = false;
        Form1->Label4->Visible = false;
        Form1->Label5->Visible = false;
        Form1->Label6->Visible = false;
        Form1->Label7->Visible = false;
        Form1->menu->Visible = false;
        Form1->runda->Visible = false;
        Timer_pilka->Enabled = false;
}
//---------------------------------------------------------------------------

