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
        TShape *tlo;
        TImage *pilka;
        TTimer *Timer_pilka;
        TImage *p1;
        TTimer *gora_p1;
        TTimer *dol_p1;
        TImage *p2;
        TTimer *gora_p2;
        TTimer *dol_p2;
        TButton *menu;
        TButton *runda;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *tytul;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Timer_pilkaTimer(TObject *Sender);
        void __fastcall gora_p1Timer(TObject *Sender);
        void __fastcall dol_p1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall gora_p2Timer(TObject *Sender);
        void __fastcall dol_p2Timer(TObject *Sender);
        void __fastcall rundaClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall menuClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
