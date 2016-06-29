#include <Servo.h>
#include <MsTimer2.h>
#include <EEPROM.h> 
#include <SoftwareSerial.h>



int ledpin = 13;//设置系统启动指示灯
int ENA = 5;//
int ENB = 6;//
int INPUT2 = 7;//
int INPUT1 = 8;//
int INPUT3 = 12;//
int INPUT4 = 13;//

int inputPin = A0;  // 定义超音波信号接收脚位  
int outputPin =A1;  // 定义超音波信号发射脚位
int Input_Detect_LEFT = A2;    //定义小车左侧红外
int Input_Detect_RIGHT = A3;  //定义小车右侧红外
int Input_Detect=A4;//定义小车前方红外
int Carled = 2;
int Cruising_Flag = 0;
int Pre_Cruising_Flag = 0 ;

#define MOTOR_GO_FORWARD  {digitalWrite(INPUT1,LOW);digitalWrite(INPUT2,HIGH);digitalWrite(INPUT3,LOW);digitalWrite(INPUT4,HIGH);}    //车体前进                              
#define MOTOR_GO_BACK   {digitalWrite(INPUT1,HIGH);digitalWrite(INPUT2,LOW);digitalWrite(INPUT3,HIGH);digitalWrite(INPUT4,LOW);}    //车体前进
#define MOTOR_GO_RIGHT    {digitalWrite(INPUT1,HIGH);digitalWrite(INPUT2,LOW);digitalWrite(INPUT3,LOW);digitalWrite(INPUT4,HIGH);}    //车体前进
#define MOTOR_GO_LEFT   {digitalWrite(INPUT1,LOW);digitalWrite(INPUT2,HIGH);digitalWrite(INPUT3,HIGH);digitalWrite(INPUT4,LOW);}    //车体前进
#define MOTOR_GO_STOP   {digitalWrite(INPUT1,LOW);digitalWrite(INPUT2,LOW);digitalWrite(INPUT3,LOW);digitalWrite(INPUT4,LOW);}    //车体前进
void setup()
{
    pinMode(ledpin,OUTPUT); 
    pinMode(ENA,OUTPUT); 
    pinMode(ENB,OUTPUT); 
    pinMode(INPUT1,OUTPUT); 
    pinMode(INPUT2,OUTPUT); 
    pinMode(INPUT3,OUTPUT); 
    pinMode(INPUT4,OUTPUT); 
    pinMode(Input_Detect_LEFT,INPUT);
    pinMode(Input_Detect_RIGHT,INPUT);
    pinMode(Carled, OUTPUT);
    pinMode(Input_Detect,INPUT);
    pinMode(inputPin,INPUT);
    pinMode(outputPin,OUTPUT);
   
    digitalWrite(ledpin,LOW);
    
    Serial.begin(9600);//串口波特率设置为9600 bps
    digitalWrite(ENA,HIGH);
    digitalWrite(ENB,HIGH);
   
 

}
void loop()
{   
    if (Serial.available() > 0) {
      char cmd;
    cmd = Serial.read();
      switch (cmd){
      
   
      case'F':
       MOTOR_GO_FORWARD;
         break;;
      case  'B':
        MOTOR_GO_BACK;   
        break;
      case'L':
      MOTOR_GO_LEFT;   
      break;
            case 'R':
            MOTOR_GO_RIGHT;  
            break;
      
        } 
    }
}

