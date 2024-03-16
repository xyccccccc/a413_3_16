#include"BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
 #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it 
 #endif 
 BluetoothSerial SerialBT;

int left_ahead_positive = 4, left_ahead_nagative = 2, left_behind_positive = 22, left_behind_negative = 23, right_ahead_positive = 12, right_ahead_nagative = 13, right_behind_positive = 32, right_behind_negative = 33;  //定义引脚变量
int lap = left_ahead_positive,lan = left_ahead_nagative,lbp = left_behind_positive,lbn = left_behind_negative,rap = right_ahead_positive,ran =right_ahead_nagative, rbp =right_behind_positive, rbn =right_behind_negative; //简写

int channel_lap = 0, channel_lan = 1, channel_lbp = 2, channel_lbn = 3, channel_rap = 4, channel_ran = 5, channel_rbp = 6, channel_rbn = 7;  
int freq_pwm = 50;
int res_pwm = 10;

int  la, lb, med, ra, rb;
int r1=15,r2=34,r3=35,r4=39,r5=36;

void setup() {
  // put your setup code here, to run once:
pinMode(ran,OUTPUT);
pinMode(rap,OUTPUT);
pinMode(lap,OUTPUT);
pinMode(lan,OUTPUT);
pinMode(lbp,OUTPUT);
pinMode(lbn,OUTPUT);
pinMode(rbp,OUTPUT);
pinMode(rbn,OUTPUT);
pinMode(r1,INPUT);
pinMode(r2,INPUT);
pinMode(r3,INPUT);
pinMode(r4,INPUT);
pinMode(r5,INPUT);
pinMode(27,OUTPUT);
pinMode(21,OUTPUT);
ledcSetup(channel_lap, freq_pwm, res_pwm);
ledcAttachPin(lap, channel_lap);
ledcSetup(channel_lan, freq_pwm, res_pwm);
ledcAttachPin(lan, channel_lan);
ledcSetup(channel_lbp, freq_pwm, res_pwm);
ledcAttachPin(lbp, channel_lbp);
ledcSetup(channel_lbn, freq_pwm, res_pwm);
ledcAttachPin(lbn, channel_lbn);
ledcSetup(channel_rap, freq_pwm, res_pwm);
ledcAttachPin(rap, channel_rap);
ledcSetup(channel_ran, freq_pwm, res_pwm);
ledcAttachPin(ran, channel_ran);
ledcSetup(channel_rbp, freq_pwm, res_pwm);
ledcAttachPin(rbp, channel_rbp);
ledcSetup(channel_rbn, freq_pwm, res_pwm);
ledcAttachPin(rbn, channel_rbn);
digitalWrite(27,LOW);
digitalWrite(21,LOW);
attachInterrupt(15,INTfunction,FALLING);
attachInterrupt(34,INTfunction2,FALLING);
Serial.begin(115200);
SerialBT.begin("ESP_BLUE");
Serial.println("The device started,now you can pair it with bluethooth!");
}


int x=3;int y=4;

void turn_left();
void straight();

void readline(){
lb = analogRead(r1);
la = analogRead(r2);
med = analogRead(r3);
ra = analogRead(r4);
rb = analogRead(r5);
}
volatile int i = 0;
volatile int j = 0;
void INTfunction(){
  ++i;
  digitalWrite(27,!digitalRead(27));
  //if(i==x){
   // noInterrupts();
  //}
  }
void INTfunction2(){
  digitalWrite(21,!digitalRead(21));
  j++;
}

  //if(j==7){
   //delay(2000);
    //turn_left();
 // }

  

void loop() {
  if(Serial.available()){
    SerialBT.write(Serial.read());
    //Serial.println("由SerialBT打印");
  }
  if(SerialBT.available()){
    Serial.write(SerialBT.read());
    //Serial.println("由Serial打印");
  }
  delay(20);
 //内侧为a外侧为b
//void readline();
void stop();
/*while(x==0){
  x=SerialBT.read();
}
while(y==x){
  y=SerialBT.read();
}*/



//while(SerialBT.read()=='s'){
  /*if(i<x){
straight();
}
else if(i==x){
  detachInterrupt(digitalPinToInterrupt(15));
  digitalWrite(27,LOW);
  turn_left();
  i++;
}  //走完第一次x，拐弯

if(x<j<x+y+2){
  straight();
  }
 if(j==x+y+2){
  stop();
  turn_left();
  j++;
  //interrupts();
}  //走完第一次y，停下，拐弯


if(x+y+2<j<x+x+y+3){
  straight();
  }
if(j==x+x+y+3){
    turn_left2();
  j++;
  //interrupts();
}  //走完第二次x，拐弯


if(2*x+y+5<j<2*x+2*y+5){
  straight();
}
if(j==2*x+2*y+4){
 ledcWrite(channel_lap, 800);
ledcWrite(channel_lan, 0);
ledcWrite(channel_lbp, 800);
ledcWrite(channel_lbn, 0);

ledcWrite(channel_rap, 0);
ledcWrite(channel_ran, 800);
ledcWrite(channel_rbp, 0);
ledcWrite(channel_rbn, 800);
delay(350);
straight();
delay(510);
  ledcWrite(channel_lap, 0);
ledcWrite(channel_lan, 0);
ledcWrite(channel_lbp, 0);
ledcWrite(channel_lbn, 0);

ledcWrite(channel_rap, 0);
ledcWrite(channel_ran, 0);
ledcWrite(channel_rbp, 0);
ledcWrite(channel_rbn, 0);
  
}*/  //第一道题用循迹（没成功）



void straight(){
if(digitalRead(34)==0||digitalRead(15)==0/*(digitalRead(35)==1&&digitalRead(39)==1&&digitalRead(36)==1)&&(digitalRead(34)==0||digitalRead(15)==0)*/){
  ledcWrite(channel_lap, 75);
ledcWrite(channel_lan, 0);
ledcWrite(channel_lbp, 75);
ledcWrite(channel_lbn, 0);

ledcWrite(channel_rap, 400);
ledcWrite(channel_ran, 0);
ledcWrite(channel_rbp,400);
ledcWrite(channel_rbn, 0);
delay(300);
}
if(digitalRead(39)==0||digitalRead(36)==0/*(digitalRead(35)==1&&digitalRead(34)==1&&digitalRead(15)==1)&&(digitalRead(39)==0||digitalRead(36)==0)*/){
ledcWrite(channel_lap,400);
ledcWrite(channel_lan, 0);
ledcWrite(channel_lbp, 400);
ledcWrite(channel_lbn, 0);

ledcWrite(channel_rap,75);
ledcWrite(channel_ran, 0);
ledcWrite(channel_rbp,75);
ledcWrite(channel_rbn, 0);
delay(300);
}
ledcWrite(channel_lap, 150);
ledcWrite(channel_lan, 0);
ledcWrite(channel_lbp, 150);
ledcWrite(channel_lbn, 0);

ledcWrite(channel_rap, 150);
ledcWrite(channel_ran, 0);
ledcWrite(channel_rbp,150);
ledcWrite(channel_rbn, 0);
}

void stop(){
  ledcWrite(channel_lap, 0);
ledcWrite(channel_lan, 0);
ledcWrite(channel_lbp, 0);
ledcWrite(channel_lbn, 0);

ledcWrite(channel_rap, 0);
ledcWrite(channel_ran, 0);
ledcWrite(channel_rbp, 0);
ledcWrite(channel_rbn, 0);
delay(2000);  //急停
}
