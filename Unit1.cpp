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
int pointsPlayer1 = 0;
int pointsPlayer2 = 0;
int counterRebound = 0;
unsigned int speedBall = 30;
int counterCurrentRebound = 5;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void showMenu()
{
        Form1->labelPlayer1->Visible = true;
        Form1->labelPlayer2->Visible = true;
        Form1->labelPointsPlayer1->Visible = true;
        Form1->labelSeparation->Visible = true;
        Form1->labelPointsPlayer2->Visible = true;
        Form1->labelInformationRebound->Visible = true;
        Form1->labelRebound->Visible = true;
        Form1->menuButton->Visible = true;
        Form1->roundButton->Visible = true;

        Form1->labelPointsPlayer2->Caption = pointsPlayer2;
        Form1->labelPointsPlayer1->Caption = pointsPlayer1;
        Form1->labelRebound->Caption = counterRebound;
}

void hideMenu()
{
        Form1->labelPlayer1->Visible = false;
        Form1->labelPlayer2->Visible = false;
        Form1->labelPointsPlayer1->Visible = false;
        Form1->labelSeparation->Visible = false;
        Form1->labelPointsPlayer2->Visible = false;
        Form1->labelInformationRebound->Visible = false;
        Form1->labelRebound->Visible = false;
        Form1->menuButton->Visible = false;
        Form1->roundButton->Visible = false;
}

void changeSpeedBall()
{
        if ( counterRebound  == counterCurrentRebound)
        {
                counterCurrentRebound += 5;
                speedBall = speedBall - 5;
                Form1->TimerBall->Interval = speedBall;

        }
}

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
        ball->Left += x;
        ball->Top  += y;

        // Bound from the top edge
        if (ball->Top - 5 <= background->Top)
        {
               y = -y;
        }
        // Bound from the bottom edge
        if (ball->Top + ball->Height >= background->Height)
        {
               y = -y;
        }

        // Game over
        if (ball->Left <= background->Left || ball->Left + ball->Width < player1->Left)
        {
                TimerBall->Enabled = false;
                ball->Visible = false;
                pointsPlayer2++;
                showMenu();


        }

        if (ball->Left >= background->Left + background->Width + 10 || ball->Left + ball->Width > player2->Left + player2->Width)
        {
                TimerBall->Enabled = false;
                pointsPlayer1++;
                ball->Visible = false;
                showMenu();
        }

        
        else if (ball->Left < player1->Left + player1->Width - ball->Width / 2 && ball->Top + ball->Height / 2 <= player1->Top + player1->Height && player1->Top <= ball->Top + ball->Height / 2)
        {
                if (x < 0)
                {
                        x = -x;
                        counterRebound++;
                        changeSpeedBall();
                }

        }
        else if (ball->Left > player2->Left - ball->Width && ball->Top + ball->Height / 2 <= player2->Top + player2->Height && player2->Top <= ball->Top + ball->Height / 2)
        {
                if ( x > 0)
                {
                        x = -x;
                        counterRebound++;
                        changeSpeedBall();
                }
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::upPlayer1Timer(TObject *Sender)
{
        if(player1->Top >= background->Top + 5)
        player1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::downPlayer1Timer(TObject *Sender)
{
       if(player1->Top <= background->Height - player1->Height - 2)
       player1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if (Key == 0x57) upPlayer1->Enabled = true;
       if (Key == 0x53) downPlayer1->Enabled = true;
       if (Key == VK_UP) upPlayer2->Enabled = true;
       if (Key == VK_DOWN) downPlayer2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x57) upPlayer1->Enabled = false;
        if (Key == 0x53) downPlayer1->Enabled = false;
        if (Key == VK_UP) upPlayer2->Enabled = false;
        if (Key == VK_DOWN) downPlayer2->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::upPlayer2Timer(TObject *Sender)
{
        if(player2->Top >= background->Top + 4)
        player2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::downPlayer2Timer(TObject *Sender)
{
       if(player2->Top <= background->Height - player2->Height - 2)
       player2->Top += 10;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::roundButtonClick(TObject *Sender)
{
        counterRebound = 0;
        speedBall = 30;
        ball->Visible = true;
        ball->Left = 504;
        ball->Top = 208;
        player1->Top = 208;
        player2->Top = 208;

        hideMenu();

        TimerBall->Interval = speedBall;
        TimerBall->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::controlInstructionButtonClick(TObject *Sender)
{
        AnsiString strMessage = "Witam w grze!\n";
        AnsiString strMessage2 = "INSTRUKCJA OBS£UGI\n";
        AnsiString strMessage3 = "Obs³uga jest bardzo prosta :)\n";
        AnsiString strMessage4 = "Gracz 1 porusza siê klawiszami W - góra i S - Dó³\n Gracz 2 porusza siê klawiszami strza³ka do góry i strza³ka na dó³.";
        AnsiString strMessage5 = "\n\n Niech rozpocznie siê gra :)";

        ShowMessage(strMessage + strMessage2 + strMessage3 + strMessage4 + strMessage5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::startGameButtonClick(TObject *Sender)
{
        startGameButton->Visible = false;
        controlInstructionButton->Visible = false;
        labelTitle->Visible = false;
        counterRebound = 0;
        pointsPlayer1 = 0;
        pointsPlayer2 = 0;
        speedBall = 30;
        counterCurrentRebound = 5;
        TimerBall->Enabled = true;
        TimerBall->Interval = speedBall;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::menuButtonClick(TObject *Sender)
{
        startGameButton->Visible = true;
        controlInstructionButton->Visible = true;
        labelTitle->Visible = true;
        ball->Visible = true;
        ball->Left = 504;
        ball->Top = 208;
        player1->Top = 208;
        player2->Top = 208;
        speedBall = 30;
        counterCurrentRebound = 5;

        hideMenu();

        TimerBall->Interval = speedBall;
        TimerBall->Enabled = false;
}
//---------------------------------------------------------------------------

