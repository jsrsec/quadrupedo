#include <VirtualWire.h>
int joystick1X = A0; //declaramos el movimiento x del primer joystick en A0
int joystick1Y = A1; //declaramos el movimiento y del primer joystick en A1
int joystick2X = A2; //declaramos el movimiento x del segundo joystick en A2
int joystick2Y = A3; //declaramos el movimiento y del segundo joystick en A3
int button1 = 2; //declaramos el boton del primer joystick en el pin 2
int button2 = 3; //declaramos el boton del segundo joystick en el pin 3
int data[6]; //declaramos la cantidad de datos que luego seran los que enviemos con el modulo de 433Mhz

void setup() {
  vw_setup(2000); //con esto iniciamos el modulo (2000 son los bits por segundo)
  pinMode(button1, INPUT);
  pinMode(button2, INPUT_PULLUP); //en este caso hacemos un imput_pullup para que cuando pulsemops se mantengan los leds encendidos 

}

void loop() {
 int joystick1XValue = analogRead(joystick1X); //leemos el movimiento x del primer joystick
  int joystick1YValue = analogRead(joystick1Y);//leemos el movimiento y del primer joystick
  int joystick2XValue = analogRead(joystick2X);//leemos el movimiento x del segundo joystick
  int joystick2YValue = analogRead(joystick2Y);//leemos el movimiento y del segundo joystick
  int button1Value = digitalRead(button1);//leemos el boton del primer joystick
  int button2Value = digitalRead(button2);//leemos el boton del segundo joystick

//definimos un numero para cada dato que queremos enviar 
  data[0] = joystick1XValue;
  data[1] = joystick1YValue;
  data[2] = joystick2XValue;
  data[3] = joystick2YValue;
  //data[4] = button1Value;
  data[5] = button2Value;

  vw_send((uint8_t *)data, sizeof(data)); //enviamos los datos a traves del modulo
  vw_wait_tx();

  delay(50);
}
