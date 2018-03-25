#include <LiquidCrystal.h>

/*******************************************************
 * 
Ovaj program namijenjen je za korištenje s LCD Shieldom
Prikazivanje poruka i testiranje rada tipkala

Marko Miroslav Bača, 2018

********************************************************/

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int tipkalo_odabir     = 0;
int tipkalo_vrijednost  = 0; //analogna vrijednost

int desna = 0;
int lijeva = 1;
int gore = 2;
int dolje = 3;
int odaberi = 4;
int nista = 5;


int citaj_tipkalo()
{
 tipkalo_vrijednost = analogRead(0);
 // Koristite analogno čitanje pina 0 kako bi pročitali vrijednosti svojih tipki moje vrijednosti: 0, 100, 258, 413, 645,1023
 // te na tu vrijednost dodajemo 50 kako bi bili sigurni da će očitanje biti dobro
 if (tipkalo_vrijednost > 1000) return nista; 
 if (tipkalo_vrijednost < 50)   return desna;  
 if (tipkalo_vrijednost < 150)  return gore; 
 if (tipkalo_vrijednost < 300)  return dolje; 
 if (tipkalo_vrijednost < 460)  return lijeva; 
 if (tipkalo_vrijednost < 700)  return odaberi;  

 return nista;
}

void setup(){

 lcd.begin(16, 2);             
 lcd.setCursor(0,0);
 lcd.print("LCD shield");
}
 
void loop()

{

 lcd.setCursor(0,1);
 tipkalo_odabir = citaj_tipkalo();

 switch (tipkalo_odabir) // izvršavanje radnje ovisno o pritisnutom tipkalu
 {
   case 0:
     {
     lcd.print("Tipka: Desno    ");
     break;
     }
   case 1:
     {
     lcd.print("Tipka: Lijeva   ");
     break;
     }
   case 2:
     {
     lcd.print("Tipka: Gore     ");
     break;
     }
   case 3:
     {
     lcd.print("Tipka: Dolje    ");
     break;
     }
   case 4:
     {
     lcd.print("Tipka: Odaberi  ");
     break;
     }
     case 5:
     {
     lcd.print("Nije pritisnuta ");
     break;
     }
 }
}

