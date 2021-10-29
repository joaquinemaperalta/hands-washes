/* Temporizador Lavado de Manos V0.1
 * ==========================================================================================
 * A D V E R T E N C I A!!! 
 * Este codigo y su esquema de conexiones fue preparado por Maker504, 
 * SE PRESENTA COMO ESTA! NO SOMOS RESPONSABLES DE LOS RESULTADOS QUE PUEDA GENERAR
 * y debe ser implementado bajo su propio riesgo por personal capacitado sobre esta material
 * =========================================================================================
 */

//Librerias
#include "pitches.h" //Buzzer

//Definicion de Pines
#define LP 11 //Salida de Led
#define Aviso 10 //Selector de Aviso
int Luz=A0; //Lectura de Entrada Analogica A0 


//Variables
int Tiempo=30000; //Tiempo para lavado de manos
int Lapso=5000; //Cada cuanto mandara aviso
int DurAviso=150; //Cuanto dura el aviso sonoro y luminoso
int Vueltas=Tiempo/Lapso; //Cuantas veces se ha alcanzado el laps
int MinLuz=50; //Valor de lectura para detectar 
int Modo=0; //Indica en que modo esta 0=sin detectar, 1=detectado y contando
int Ahora=0; //Millis en el momento que se detecta


void setup() 
{
  //Set Pins
  //Inputs
  pinMode(LP, OUTPUT);
  pinMode(Aviso, INPUT_PULLUP);
  tone(12,NOTE_C6, 500); //Tono de inicio
  digitalWrite(LP,HIGH); //Aviso luminoso
  delay(500);
  digitalWrite(LP,LOW);
  //Serial.begin(9600);
}

void loop() 
{
  if(analogRead(Luz)>MinLuz) //Se detecto algo
  {
    tone(12,NOTE_DS7,DurAviso);
    for (int i=0; i<Vueltas; i++)
    {
     if(digitalRead(Aviso)==1)
     {
      tone(12,NOTE_DS7,DurAviso);
     }
      digitalWrite(LP,HIGH); //Aviso luminoso
      delay(DurAviso);
      digitalWrite(LP,LOW);
      delay(Lapso-DurAviso);
    }
    //Se termino las vueltas, enviar aviso final
    tone(12,NOTE_DS7,2000); //Aviso sonoro
    digitalWrite(LP,HIGH); //Aviso luminoso
    delay(5000);
    digitalWrite(LP,LOW);
  }
}
