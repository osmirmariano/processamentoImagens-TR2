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
    Form1->Color = clWhite;//
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	Image1->Picture->LoadFromFile("os.bmp"); // Carregando imagem
//	Image1->Stretch = true; //redimensiona
	Image1->Refresh(); //atualiza
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	int x, y, R, G, B, rotulo = 1, media;

	int **label;

	label = new int*[ Image1->Width ];			//
	for (x = 0; x < Image1->Width; x++)			// LABEL do tamanho da imagem
		label[x] = new int[ Image1->Height ];		//

	for (x = 0; x < Image1->Width; x++) {
		for (y = 0; y < Image1->Height; y++) {
			cor = Image1->Canvas->Pixels[x][y];
			R = GetRValue(cor);  //Retorna Intensidade de cor vermelha
			G = GetGValue(cor);  //Retorna Intensidade de cor Verde
			B = GetBValue(cor);
			if(R > 100 && R <= 255 && G > 100 && G <= 255 && B > 100 && B <= 255){
			   Image1->Canvas->Pixels[x][y] = RGB(255,255,255);
			}
			else{
				Image1->Canvas->Pixels[x][y] = RGB(0,0,0);
			}
			label[x][y] = 0;
		}
	}

	for(x = 1; x < Image1->Width - 1; x++){
		for(y = 1; y < Image1->Height - 1; y++){

			if(Image1->Canvas->Pixels[x][y] == RGB(0,0,0)){

				if(Image1->Canvas->Pixels[x-1][y] == RGB(255,255,255) && Image1->Canvas->Pixels[x][y-1] == RGB(255,255,255)){
					 //Image1->Canvas->Pixels[x][y] = label;
					label[x][y] = rotulo;
					rotulo = rotulo + 50;
				}
				else{

					if(( Image1->Canvas->Pixels[x-1][y] == RGB(255,255,255) && Image1->Canvas->Pixels[x][y-1] == RGB(0,0,0) )){
						label[x][y] = label[x][y-1];		// rotulo antigo [R]
					}
					else if(( Image1->Canvas->Pixels[x-1][y] == RGB(0,0,0) && Image1->Canvas->Pixels[x][y-1] == RGB(255,255,255) )){
						label[x][y] = label[x-1][y];		// rotulo antigo [T]
					}
					else{

						if(Image1->Canvas->Pixels[x-1][y] == RGB(0,0,0) && Image1->Canvas->Pixels[x][y-1] == RGB(0,0,0) /* && Fazer tratamento de verificar se as labels são iguais*/) {
							if( label[x-1][y] == label[x][y-1] )
								label[x][y] = label[x-1][y];		// rotulo de qualquer um
							else {
								label[x][y] = label[x-1][y];		// necessario declarar equivalencia
								// label[x-1][y] é igual ao label[x][y-1]
							}
					}
				   }
				}
			}
			else
				label[x][y] = 0;
		}
	}

	int aux;
	for(x = 0; x < Image1->Width; x++){
		for(y = 0; y < Image1->Height; y++){

			if(label[x][y] == 0){
				Image1->Canvas->Pixels[x][y] = RGB(255,255,255);
			}
			else{
					Image1->Canvas->Pixels[x][y] = aux;
			}
			aux = label[x][y];
		}
	}
}
//---------------------------------------------------------------------------


