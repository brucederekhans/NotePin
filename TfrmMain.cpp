//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TfrmMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
	SetWindowPos(this->Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(!(this->mmText->Lines->Text.IsEmpty()))
	{
		CanClose = (MessageBox(this->Handle, String("文本框中存在文本，是否确认关闭？").w_str(), L"提示",  MB_YESNO | MB_ICONQUESTION) == IDYES);
	}
}
//---------------------------------------------------------------------------

