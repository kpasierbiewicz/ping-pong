//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *TimerBall;
        TImage *player1;
        TTimer *upPlayer1;
        TTimer *downPlayer1;
        TImage *player2;
        TTimer *upPlayer2;
        TTimer *downPlayer2;
        TButton *menuButton;
        TButton *roundButton;
        TLabel *labelPlayer1;
        TLabel *labelPlayer2;
        TLabel *labelPointsPlayer1;
        TLabel *labelSeparation;
        TLabel *labelPointsPlayer2;
        TLabel *labelInformationRebound;
        TLabel *labelRebound;
        TLabel *labelTitle;
        TButton *startGameButton;
        TButton *controlInstructionButton;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall upPlayer1Timer(TObject *Sender);
        void __fastcall downPlayer1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall upPlayer2Timer(TObject *Sender);
        void __fastcall downPlayer2Timer(TObject *Sender);
        void __fastcall roundButtonClick(TObject *Sender);
        void __fastcall controlInstructionButtonClick(TObject *Sender);
        void __fastcall startGameButtonClick(TObject *Sender);
        void __fastcall menuButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
