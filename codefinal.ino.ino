#include <LiquidCrystal.h> // declara a utilização da biblioteca LiquidCrystal

#define Luz_Fundo  7
#define LigaMaquina  6
#define TamanhoFita 4
//cria um objeto tipo LiquidCrystal que chamei de "lcd" nos pinos citados:
LiquidCrystal lcd(1, 0, 5, 4, 3, 2);
bool continua = true;
int cabecote = 0;
int estado = 0;
bool divisivel = false;
int fita[TamanhoFita];
bool pegarvalor = true;
void setup()
{
  lcd.begin(16, 2); // Iniciando o objeto "lcd" de 2 linhas e 16 colunas
  pinMode(Luz_Fundo, OUTPUT); //define o pino como saída
  pinMode(LigaMaquina, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  digitalWrite(Luz_Fundo, HIGH); // Liga a luz do display.
  lcd.setCursor(0, 0); // seta o cursor para: (coluna = 0, linha = 0)
  lcd.print(" Maquina Turing ");
  delay(1800);

}

void loop()
{
  if (digitalRead(LigaMaquina) == 1)//MAQUINA LIGADA
  {
    if (continua)//FITA NÃO ACABOU AINDA
    {
      lcd.clear();
      if(pegarvalor){
      fita[0] = digitalRead(11);
      fita[1] = digitalRead(10);
      fita[2] = digitalRead(9);
      fita[3] = digitalRead(8);
      pegarvalor=false;
      }

      lcd.setCursor(0, 0);
      for (int i = 0; i < TamanhoFita; i++)
      {
        lcd.print(fita[i]);
        delay(500);
      }

    lcd.setCursor(0, 1);
            for (int i = 0; i < TamanhoFita; i++)
            {
                if (i == cabecote-1)
                {
                    lcd.print("|");
                }
                else
                {
                    lcd.print(" ");
                }
                //delay(500);
            }

            lcd.print(" EST: ");
            lcd.print(estado);
            delay(500);

            switch (estado)
            {
            case 0:
                if (fita[cabecote] == 1)
                {
                    estado = 1;
                }
                if (cabecote >= TamanhoFita)
                {
                    estado = 3;
                    continua = false;
                }
                break;
            case 1:
                if (fita[cabecote] == 1)
                {
                    estado = 0;
                }
                if (fita[cabecote] == 0)
                {
                    estado = 2;
                }
                if (cabecote >= TamanhoFita)
                {
                    continua = false;
                }
                break;
            case 2:
                if (fita[cabecote] == 0)
                {
                    estado = 1;
                }
                if (cabecote >= TamanhoFita)
                {
                    continua = false;
                }
                break;
            }
            cabecote += 1;

            if (estado == 3)
            {
                continua = false;
                divisivel = true;
            }
        }
        else//FITA JA ACABOU
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            for (int i = 0; i < TamanhoFita; i++)//COLOCAR VALOR
            {
                lcd.print(fita[i]);
                delay(500);
            }
            if (divisivel == true)//E DIVISIVEL
            {
                lcd.setCursor(0, 1);
                lcd.print("DIVISIVEL");
            }
            else//NAO DIVISIVEL
            {
                lcd.setCursor(0, 1);
                lcd.print("NAO DIVISIVEL");
            }
        }
  }
  else//DESLIGADO
  {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("   DESLIGADO  ");
    
    cabecote = 0;
    estado = 0;
    continua = true;
    divisivel = false;
    pegarvalor=true;
  }
  delay(500);
}
