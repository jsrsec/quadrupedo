#include <VirtualWire.h> //añadimos la libreria del modulo de RF
#include <Adafruit_PWMServoDriver.h> //añadimos la libreria del driver de servomotores 
#include <Wire.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40); //declaramos la direcion I2C del driver de servomotores 
#define SERVOMIN  150 // Minimo (sobre 4096)
#define SERVOMAX  550 // Maximo (sobre 4096)


const unsigned short h1 = 0; //Hombro extremidad 1
const unsigned short p1 = 1; //Pata extremidad 1
const unsigned short h2 = 2; //Hombro extremidad 2
const unsigned short p2 = 3; //Pata extremidad 2
const unsigned short h3 = 4; //Hombro extremidad 3
const unsigned short p3 = 5; //Pata extremidad 3
const unsigned short h4 = 6; //Hombro extremidad 4
const unsigned short p4 = 7; //Pata extremidad 4
const unsigned short c1 = 8; //Cabeza
const unsigned short c2 = 9; //Cuello

int data[6]; //Declaramos la cantidad de datos que recoge el modulo de RF
int ledState = LOW;
int buttonState;
int lastButtonState = HIGH;


void setup() {
  vw_setup(2000);
  vw_set_rx_pin(11);
  vw_rx_start();
    pwm.begin();
    pwm.setPWMFreq(50);
    pinMode(10,OUTPUT);
    pinMode(9,OUTPUT);
    

}

//creamos el estado de pie
void depie()
{
  pwm.setPWM(h1, 0, 350);
  pwm.setPWM(h2, 0, 350);
  pwm.setPWM(h3, 0, 350);
  pwm.setPWM(h4, 0, 350);

  pwm.setPWM(p1, 0, 500);
  pwm.setPWM(p2, 0, 200);
  pwm.setPWM(p3, 0, 500);
  pwm.setPWM(p4, 0, 200);
}

//creamos el estado de andar hacia alante
void andar()
{

  pwm.setPWM(p1, 0, 450);
  pwm.setPWM(p3, 0, 450);
  delay (100);

 for (int i = 0; i < 2; i++)
  {
    pwm.setPWM(h1, 0, 400);
    pwm.setPWM(h3, 0, 300);
    delay (100);

    pwm.setPWM(p1, 0, 500);
    pwm.setPWM(p3, 0, 500);
    delay (100);

    pwm.setPWM(p2, 0, 250);
    pwm.setPWM(p4, 0, 250);
    delay(100);

    pwm.setPWM(h1, 0, 350);
    pwm.setPWM(h3, 0, 350);
    delay(100);

    pwm.setPWM(h2, 0, 300);
    pwm.setPWM(h4, 0, 400);
    delay (100);

    pwm.setPWM(p2, 0, 200);
    pwm.setPWM(p4, 0, 200);
    delay(100);

    pwm.setPWM(p1, 0, 450);
    pwm.setPWM(p3, 0, 450);
    delay (100);

    pwm.setPWM(h2, 0, 350);
    pwm.setPWM(h4, 0, 350);
    delay(100);
  }
  depie();
}

//creamos el estado de andar hacia atras
void atras()
{

  pwm.setPWM(p1, 0, 450);
  pwm.setPWM(p3, 0, 450);
  delay (100);

 for (int i = 0; i < 2; i++)
  {
    pwm.setPWM(h1, 0, 300);
    pwm.setPWM(h3, 0, 400);
    delay (100);

    pwm.setPWM(p1, 0, 500);
    pwm.setPWM(p3, 0, 500);
    delay (100);

    pwm.setPWM(p2, 0, 250);
    pwm.setPWM(p4, 0, 250);
    delay(100);

    pwm.setPWM(h1, 0, 350);
    pwm.setPWM(h3, 0, 350);
    delay(100);

    pwm.setPWM(h2, 0, 400);
    pwm.setPWM(h4, 0, 300);
    delay (100);

    pwm.setPWM(p2, 0, 200);
    pwm.setPWM(p4, 0, 200);
    delay(100);

    pwm.setPWM(p1, 0, 450);
    pwm.setPWM(p3, 0, 450);
    delay (100);

    pwm.setPWM(h2, 0, 350);
    pwm.setPWM(h4, 0, 350);
    delay(100);
  }
  depie();
}

//creamos el estado de girar a la derecha 
void girarderecha()
{

  pwm.setPWM(p1, 0, 450);
  pwm.setPWM(p3, 0, 450);
  delay (100);

  for (int i = 0; i < 2; i++)
  {
    pwm.setPWM(h1, 0, 300);
    pwm.setPWM(h3, 0, 300);
    delay (100);

    pwm.setPWM(p1, 0, 500);
    pwm.setPWM(p3, 0, 500);
    delay (100);

    pwm.setPWM(p2, 0, 250);
    pwm.setPWM(p4, 0, 250);
    delay(100);

    pwm.setPWM(h1, 0, 350);
    pwm.setPWM(h3, 0, 350);
    delay(100);

    pwm.setPWM(h2, 0, 300);
    pwm.setPWM(h4, 0, 300);
    delay (100);

    pwm.setPWM(p2, 0, 200);
    pwm.setPWM(p4, 0, 200);
    delay(100);

    pwm.setPWM(p1, 0, 450);
    pwm.setPWM(p3, 0, 450);
    delay (100);

    pwm.setPWM(h2, 0, 350);
    pwm.setPWM(h4, 0, 350);
    delay(100);
  }
  depie();
}

//creamos el estado de girar a la izquierda
void girarizquierda()
{

  pwm.setPWM(p1, 0, 450);
  pwm.setPWM(p3, 0, 450);
  delay (100);

  for (int i = 0; i < 2; i++)
  {
    pwm.setPWM(h1, 0, 400);
    pwm.setPWM(h3, 0, 400);
    delay (100);

    pwm.setPWM(p1, 0, 500);
    pwm.setPWM(p3, 0, 500);
    delay (100);

    pwm.setPWM(p2, 0, 250);
    pwm.setPWM(p4, 0, 250);
    delay(100);

    pwm.setPWM(h1, 0, 350);
    pwm.setPWM(h3, 0, 350);
    delay(100);

    pwm.setPWM(h2, 0, 400);
    pwm.setPWM(h4, 0, 400);
    delay (100);

    pwm.setPWM(p2, 0, 200);
    pwm.setPWM(p4, 0, 200);
    delay(100);

    pwm.setPWM(p1, 0, 450);
    pwm.setPWM(p3, 0, 450);
    delay (100);

    pwm.setPWM(h2, 0, 350);
    pwm.setPWM(h4, 0, 350);
    delay(100);
  }
  depie();
}


void loop() {
  /*leemos los datos entrantes del modulo RF y deterinamos movimientos
  a diferentes datos que recivimos del modulo*/
  uint8_t buf[VW_MAX_MESSAGE_LEN]; 
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
     if (buflen == sizeof(data)) {
     
      memcpy((void *)data, (void *)buf, buflen);

       int joystick1XValue = data[0];
      int joystick1YValue = data[1];
      int joystick2XValue = data[2];
      int joystick2YValue = data[3];
      int button1Value = data[4];
      int button2Value = data[5];

       int servo1Angle = map(joystick1XValue, 0, 1023, 0, 180);
      int servo2Angle = map(joystick1YValue, 0, 1023, 0, 180);
       int servo1Angle2 = map(joystick2XValue, 0, 1023, 200, 400);
      int servo2Angle2 = map(joystick2YValue, 0, 1023, 200, 400);

       if(servo1Angle >100)
           andar();

       if(servo1Angle <100 || servo1Angle >80)
           depie();

       if(servo1Angle <80)
           atras();

        if(servo2Angle < 80)
           girarderecha();

        if(servo2Angle <100 || servo2Angle >80)
           depie();

        if(servo2Angle >100)
           girarizquierda();


        pwm.setPWM(c1, 0, servo1Angle2);
        pwm.setPWM(c2, 0, servo2Angle2);

       buttonState = button2Value;

        if (buttonState != lastButtonState) {
          if (buttonState == LOW) {
               ledState = !ledState;
                 digitalWrite(9, ledState);
                 digitalWrite(10, ledState);
          }
        }
      
    delay(50);

   
    }
  }
}
