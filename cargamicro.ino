#include <HX711.h> 
#include "Keyboard.h" // Biblioteca padrão já instalado do Arduino



//configuracao dos pinos para o modulo HX711
const int PINO_DT = 14;
const int PINO_SCK = 15;
float peso = 0; // Inicia a variável peso em 0
//declaracao do intervalo de espera
const int TEMPO_ESPERA = 500;

HX711 escala; //declaracao do objeto ESCALA na classe HX711 da biblioteca

const int FATOR_CALIBRACAO = 10000; //esse valor deve ser alterado para o valor de calibracao obtido com o outro codigo

void setup ()
{


  escala.begin (PINO_DT, PINO_SCK); //inicializacao e definicao dos pinos DT e SCK dentro do objeto ESCALA
  
  escala.tare(); //zera a escala

  escala.set_scale(FATOR_CALIBRACAO); //ajusta a escala para o fator de calibracao
  
}

void loop ()
{
  //verifica se o modulo esta pronto para realizar leituras
  if (escala.is_ready())
  {
  //mensagens de leitura no monitor serial
  peso = escala.get_units(20);
  String peso_string;
  peso_string = String(peso, 3);
  peso_string.replace(".", ",");

  Keyboard.println(peso_string); // Imprime o peso no Excel
  
  }
  else
  {

  }
  delay(TEMPO_ESPERA); //intervalo de espera para leitura

}

