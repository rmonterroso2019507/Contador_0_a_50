/*
Fundacion Kinal
Centro Educativo Tecnico Kinal
Electronica
Grado: Quinto
Curso: Taller de Electronica Digital
Alumno: Roberto Antonio Monterroso Aguilar
Seccion: A
Carne: 2019507
Proyecto: Uso de interrupciones de termporizador
*/

//definir variables a usar
  #define Push_DOWN 2
  #define Push_UP 3
  //display 1
  #define a1 4
  #define b1 5
  #define c1 6
  #define d1 7
  #define e1 8
  #define f1 9
  #define g1 10
//display 2
  #define a2 11
  #define b2 12 
  #define c2 14
  #define d2 15
  #define e2 16
  #define f2 17
  #define g2 18
  #define bled 13

//funciones ISR
  void funcion_ISR_DES(void);
  void funcion_ISR_ASC(void);
  void integrar_num(void);
  void desintegrar_num(void);

//Funciones
int Conteo();
void D_Unidades(void);
void D_descenas(void);
 
//Variables para Volatile Static
  volatile static bool fin_con1 = false;
  volatile static bool fin_con2 = false;
   
// Variables
int Agregar_U = 0;
void setup() 
  {
  Serial.begin(19200);
  pinMode(Push_DOWN,INPUT);//bajara la numeracion 
  pinMode(Push_UP,INPUT);//aumentara la numeracion
  attachInterrupt(digitalPinToInterrupt(Push_DOWN),funcion_ISR_DES,RISING);
  attachInterrupt(digitalPinToInterrupt(Push_UP),funcion_ISR_ASC,FALLING);
  //unidades
  pinMode(a1,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(c1,OUTPUT);
  pinMode(d1,OUTPUT);
  pinMode(e1,OUTPUT);
  pinMode(f1,OUTPUT);
  pinMode(g1,OUTPUT);
  //descenas
  pinMode(a2,OUTPUT);
  pinMode(b2,OUTPUT);
  pinMode(c2,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode(e2,OUTPUT);
  pinMode(f2,OUTPUT);
  pinMode(g2,OUTPUT);
  pinMode(bled ,OUTPUT);

  }

void loop() 
  {
 if(Agregar_U >50){
  Agregar_U = 0;
 }
  if(Agregar_U < 0){
  Agregar_U = 50;
 }
 D_Unidades();
 D_descenas();
 fin_con1 = false;
 fin_con2 = false;
  }
 void funcion_ISR_DES(void)
  {
    
  desintegrar_num();
  
  }
 void funcion_ISR_ASC(void)
  {

  integrar_num();

  }
void integrar_num(void)
{
  Agregar_U ++;
  Serial.println(Agregar_U);
}
void desintegrar_num(void)
{
  Agregar_U --;
  Serial.println(Agregar_U);
}
//display Unidades
void D_Unidades(void){
if (Agregar_U == 0 || Agregar_U == 10 || Agregar_U ==20 || Agregar_U == 30 ||Agregar_U == 40 || Agregar_U ==50){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,HIGH);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,LOW);
}
if (Agregar_U == 1 || Agregar_U == 11 || Agregar_U ==21 || Agregar_U == 31 ||Agregar_U == 41){
  digitalWrite(a1,LOW);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,LOW);
  digitalWrite(e1,LOW);
  digitalWrite(f1,LOW);
  digitalWrite(g1,LOW);
}
if (Agregar_U == 2 || Agregar_U == 12 || Agregar_U ==22 || Agregar_U == 32 ||Agregar_U == 42){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,LOW);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,HIGH);
  digitalWrite(f1,LOW);
  digitalWrite(g1,HIGH);
}
if (Agregar_U == 3 || Agregar_U == 13 || Agregar_U ==23 || Agregar_U == 33 ||Agregar_U == 43){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,LOW);
  digitalWrite(f1,LOW);
  digitalWrite(g1,HIGH);
}
if (Agregar_U == 4 || Agregar_U == 14 || Agregar_U ==24 || Agregar_U == 34 ||Agregar_U == 44){
  digitalWrite(a1,LOW);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,LOW);
  digitalWrite(e1,LOW);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
if (Agregar_U == 5 || Agregar_U == 15 || Agregar_U ==25 || Agregar_U == 35 ||Agregar_U == 45){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,LOW);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,LOW);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
if (Agregar_U == 6 || Agregar_U == 16 || Agregar_U ==26 || Agregar_U == 36 ||Agregar_U == 46){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,LOW);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,HIGH);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
if (Agregar_U == 7 || Agregar_U == 17 || Agregar_U ==27 || Agregar_U == 37 ||Agregar_U == 47){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,LOW);
  digitalWrite(e1,LOW);
  digitalWrite(f1,LOW);
  digitalWrite(g1,LOW);
}
if (Agregar_U == 8 || Agregar_U == 18 || Agregar_U ==28 || Agregar_U == 38 ||Agregar_U == 48 ){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,HIGH);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
if (Agregar_U == 9 || Agregar_U == 19 || Agregar_U == 29 || Agregar_U == 39 ||Agregar_U == 49){
  digitalWrite(a1,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(c1,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(e1,LOW);
  digitalWrite(f1,HIGH);
  digitalWrite(g1,HIGH);
}
}
//display decenas
void D_descenas(void){
if (Agregar_U == 0 || Agregar_U == 9){
  digitalWrite(a2,HIGH);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,HIGH);
  digitalWrite(e2,HIGH);
  digitalWrite(f2,HIGH);
  digitalWrite(g2,LOW);
}
if ( Agregar_U == 10 || Agregar_U ==19){
  digitalWrite(a2,LOW);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,LOW);
  digitalWrite(e2,LOW);
  digitalWrite(f2,LOW);
  digitalWrite(g2,LOW);
}
if ( Agregar_U ==20 || Agregar_U == 29){
  digitalWrite(a2,HIGH);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,LOW);
  digitalWrite(d2,HIGH);
  digitalWrite(e2,HIGH);
  digitalWrite(f2,LOW);
  digitalWrite(g2,HIGH);
}
if (Agregar_U == 30 ||Agregar_U == 39){
  digitalWrite(a2,HIGH);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,HIGH);
  digitalWrite(e2,LOW);
  digitalWrite(f2,LOW);
  digitalWrite(g2,HIGH);
}
if (Agregar_U == 40 || Agregar_U == 49){
  digitalWrite(a2,LOW);
  digitalWrite(b2,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,LOW);
  digitalWrite(e2,LOW);
  digitalWrite(f2,HIGH);
  digitalWrite(g2,HIGH);
}
if (Agregar_U == 50){
  digitalWrite(a2,HIGH);
  digitalWrite(b2,LOW);
  digitalWrite(c2,HIGH);
  digitalWrite(d2,HIGH);
  digitalWrite(e2,LOW);
  digitalWrite(f2,HIGH);
  digitalWrite(g2,HIGH);
}
}
