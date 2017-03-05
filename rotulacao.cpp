//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <jpeg.hpp>
#include "rotulacao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    Form1->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	Image1->Picture->LoadFromFile("cg.bmp"); // Carregando imagem
	Image1->Stretch = true; //redimensiona
	Image1->Refresh(); //atualiza
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	int x, y, R, G, B;
	for (x = 0; x < Image1->Width; x++) {
		for (y = 0; y < Image1->Height; y++) {
			cor = Image1->Canvas->Pixels[x][y];
			R = GetRValue(cor);  //Retorna Intensidade de cor vermelha
			G = GetGValue(cor);  //Retorna Intensidade de cor Verde
			B = GetBValue(cor);
			if(R > 100 && R <= 255 && G > 100 && G <= 255 && B > 100 && B <= 255)
			   Image1->Canvas->Pixels[x][y] = RGB(255,255,255);
			else
				Image1->Canvas->Pixels[x][y] = RGB(0,0,0);
		}
	}

	for(x = 0; x < Image1->Width; x++){
		for(y = 0; y < Image1->Height; y++){
			if(Image1->Canvas->Pixels[x][y] == RGB(255,255,255){
				if(Image1->Canvas->Pixels[x-1][y] == RGB(0,0,0) && Image1->Canvas->Pixels[x][y-1] == RGB(0,0,0)){
					 //Recebe um novo label
				}
				else{

                }
			}
		}
	}
}
//---------------------------------------------------------------------------
