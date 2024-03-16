#include"BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
 #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it 
 #endif 
 BluetoothSerial SerialBT;  //BT
int left_ahead_positive = 4, left_ahead_nagative = 2, left_behind_positive = 22, left_behind_negative = 23, right_ahead_positive = 12, right_ahead_nagative = 13, right_behind_positive = 32, right_behind_negative = 33;  //define a port
int lap = left_ahead_positive,lan = left_ahead_nagative,lbp = left_behind_positive,lbn = left_behind_negative,rap = right_ahead_positive,ran =right_ahead_nagative, rbp =right_behind_positive, rbn =right_behind_negative; //abbreviate
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



void INTfunction(){
  digitalWrite(27,!digitalRead(27));
  }
void INTfunction2(){
  digitalWrite(21,!digitalRead(21));
}

  int mod=0,second=0;
 int x1=0,z1=0,x2=0,x3=0,z2=0,z3=0;
void loop() {
delay(15);
while(mod==0||second==0){  //input the mode and question
  if (SerialBT.available()>0&&mod==0){
  mod = SerialBT.read();
  Serial.flush();
  SerialBT.println(mod);
 }
  if (SerialBT.available()>0&&mod>0&&second==0){
  second = SerialBT.read();
  Serial.flush();
  SerialBT.println(second);
 }
}
if(mod==97){
  SerialBT.println("mod1");
  Serial.flush();
  while(x1==0||z1==0){
  if (SerialBT.available()>0&&x1==0){
  x1 = SerialBT.read()-48;
  Serial.flush();
  SerialBT.println(x1);
 }
  if (SerialBT.available()>0&&x1>0&&z1==0){
  z1 = SerialBT.read()-48;
  Serial.flush();
  SerialBT.println(z1);
   }
  }
  for(int i=1;i<=x1;i++){
  straight1();
  SerialBT.println("aaaaaa");
 }
 left();

 for(int i=1;i<=z1;i++){
  straight1();
 }
 SerialBT.println("x");
 left();
 for(int i=1;i<=x1;i++){
  straight1();
 }
 left();
 for(int i=1;i<=z1;i++){
  straight1();
 }
 while(1){stop();}
 }
//mode 1
if(mod==98){
 Serial.flush();
 mod2xz();
}
//mode 2
if(mod==99){  
  Serial.flush();
  SerialBT.println("mod3");
  //while(1){
 if(second==51){
  char3();
 }
 if(second==52){
  char4();
 }
 if(second==119){
  SerialBT.println("wang");
  charw();
 }
 //}
 }
//mode 3

}


void mod2xz(){  //input the coordinates
while(x1*z1*x2*x3*z2*z3==0){
  if (SerialBT.available()>0&&x1==0){
  x1 = SerialBT.read()-48;
  Serial.flush();
  SerialBT.println(x1);
 }
  if (SerialBT.available()>0&&x1>0&&z1==0){
  z1 = SerialBT.read()-48;
  Serial.flush();
  SerialBT.println(z1);
   }
  if (SerialBT.available()>0&&x1>0&&z1>0&&x2==0){
  x2 = SerialBT.read()-48;
  Serial.flush();
  SerialBT.println(x2); 
  }
  if (SerialBT.available()>0&&x1>0&&z1>0&&x2>0&&z2==0){
  z2 = SerialBT.read()-48;
  Serial.flush();
  SerialBT.println(z2);
 }
 if (SerialBT.available()>0&&x1>0&&z1>0&&x2>0&&z2>0&&x3==0){
  x3 = SerialBT.read()-48;
  Serial.flush();
  SerialBT.println(x3);
 }
 if (SerialBT.available()>0&&x1>0&&z1>0&&x2>0&&z2>0&&x3>0&&z3==0){
  z3 = SerialBT.read()-48;
  Serial.flush();
  SerialBT.println(z3);
 }
 } 
 if(x1*x1+z1*z1>x2*x2+z2*z2 && x2*x2+z2*z2>x3*x3+z3*z3){
  for(int i= 1;i<=x3;i++){straight1();}
  left();
  for(int i= 1;i<=z3;i++){straight1();}
  right();
  for(int i= 1;i<=x2-x3;i++){straight1();}
  left();
  for(int i= 1;i<=z2-z3;i++){straight1();}
  right();
  for(int i= 1;i<=x1-x2;i++){straight1();}
  left();
  for(int i= 1;i<=z1-z2;i++){straight1();}
  left();
  for(int i= 1;i<=x1;i++){straight1();}
  left();
  for(int i= 1;i<=z1;i++){straight1();}
  while(1){stop();}}
if(x1*x1+z1*z1>x3*x3+z3*z3 && x3*x3+z3*z3>x2*x2+z2*z2){
  for(int i= 1;i<=x2;i++){straight1();}
  for(int i= 1;i<=z2;i++){straight1();}
  for(int i= 1;i<=x3-x2;i++){straight1();}
  for(int i= 1;i<=z3-z2;i++){straight1();}
  for(int i= 1;i<=x1-x3;i++){straight1();}
  for(int i= 1;i<=z1-z3;i++){straight1();}}
if(x2*x2+z2*z2>x1*x1+z1*z1 && x1*x1+z1*z1>x3*x3+z3*z3){
  for(int i= 1;i<=x3;i++){straight1();}
  for(int i= 1;i<=z3;i++){straight1();}
  for(int i= 1;i<=x1-x3;i++){straight1();}
  for(int i= 1;i<=z1-z3;i++){straight1();}
  for(int i= 1;i<=x2-x1;i++){straight1();}
  for(int i= 1;i<=z2-z1;i++){straight1();}}
if(x2*x2+z2*z2>x3*x3+z3*z3 && x3*x3+z3*z3>x1*x1+z1*z1){
  for(int i= 1;i<=x1;i++){straight1();}
  for(int i= 1;i<=z1;i++){straight1();}
  for(int i= 1;i<=x3-x1;i++){straight1();}
  for(int i= 1;i<=z3-z1;i++){straight1();}
  for(int i= 1;i<=x2-x3;i++){straight1();}
  for(int i= 1;i<=z2-z3;i++){straight1();}}
if(x3*x3+z3*z3>x1*x1+z1*z1 && x1*x1+z1*z1>x2*x2+z2*z2){
  for(int i= 1;i<=x2;i++){straight1();}
  for(int i= 1;i<=z2;i++){straight1();}
  for(int i= 1;i<=x1-x2;i++){straight1();}
  for(int i= 1;i<=z1-z2;i++){straight1();}
  for(int i= 1;i<=x3-x1;i++){straight1();}
  for(int i= 1;i<=z3-z1;i++){straight1();}}
if(x3*x3+z3*z3>x2*x2+z2*z2 && x2*x2+z2*z2>x1*x1+z1*z1){
  for(int i= 1;i<=x1;i++){straight1();}
  for(int i= 1;i<=z1;i++){straight1();}
  for(int i= 1;i<=x2-x1;i++){straight1();}
  for(int i= 1;i<=z2-z1;i++){straight1();}
  for(int i= 1;i<=x3-x2;i++){straight1();}
  for(int i= 1;i<=z3-z2;i++){straight1();}}
 }
void char3(){
 straight1();
 left();
 straight1();
 right();
 straight2();
 left();
 straight1();
 left();
 straight2();
 right();
 straight1();
 right();
 straight2();
 left();
 straight1();
 left();
 straight2();
 right();
 straight1();
 right();
 straight3();
 right();;
 straight5();
 right();
 straight4();  //form a shape like the number 3
 while(1){stop();} 
 }
void char4(){
  straight3();
  left();
  straight2();
  left();
  straight2();
  right();
  straight3();
  right();
  straight1();
  right();
  straight2();
  left();
  straight1();
  left();
  straight2();
  right();
  straight1();
  right();
  straight2();
  left();
  straight1();
  right();
  straight1();
  right();
  straight1();
  left();
  straight2();
  right();
  straight4();  //form a shape like the number 4
  while(1){
    stop();
   }

 }
 
void charw(){
 straight4_2140();
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 straight1();
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0);
  ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 ledcWrite(channel_lap, 1023);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(880);//2
 ledcWrite(channel_lap, 800);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 800);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 0);
 ledcWrite(channel_ran, 1000);
 ledcWrite(channel_rbp, 0);
 ledcWrite(channel_rbn, 1000);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);///右拐拐
 straight1();
 ledcWrite(channel_lap, 800);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 800);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 0);
 ledcWrite(channel_ran, 1000);
 ledcWrite(channel_rbp, 0);
 ledcWrite(channel_rbn, 1000);

 delay(510);///右拐
 straight1();
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 straight1();
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800); 

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 straight1();
 ledcWrite(channel_lap, 800);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 800);
 ledcWrite(channel_lbn, 0); 

 ledcWrite(channel_rap, 0);
 ledcWrite(channel_ran, 1000);
 ledcWrite(channel_rbp, 0);
 ledcWrite(channel_rbn, 1000);
 //if(digitalRead(34)==0){
 //  break;
 //}
delay(510);///右拐
 ledcWrite(channel_lap, 1023);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(440);//走一个
 ledcWrite(channel_lap, 800); 
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 800);
 ledcWrite(channel_lbn, 0);
 ledcWrite(channel_rap, 0);
 ledcWrite(channel_ran, 1000);
 ledcWrite(channel_rbp, 0);
 ledcWrite(channel_rbn, 1000);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);///右拐
 ledcWrite(channel_lap, 1023);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(880);//2
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800); 

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0);
  ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 straight1();
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 straight4();
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800); 
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 straight1(); 
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0); 
 ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 ledcWrite(channel_lap, 1023);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0); 

 ledcWrite(channel_rap, 1023); 
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(880);//2
 ledcWrite(channel_lap, 800);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 800);
 ledcWrite(channel_lbn, 0);
 ledcWrite(channel_rap, 0);
 ledcWrite(channel_ran, 1000);
 ledcWrite(channel_rbp, 0);
 ledcWrite(channel_rbn, 1000);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);///右拐
 straight1(); 
 ledcWrite(channel_lap, 800);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 800);
 ledcWrite(channel_lbn, 0);
 ledcWrite(channel_rap, 0); 
 ledcWrite(channel_ran, 1000);
 ledcWrite(channel_rbp, 0);
 ledcWrite(channel_rbn, 1000);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);///右拐 
 straight1();
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 straight1();
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0); 
 ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);//左拐弯
 straight1();
 ledcWrite(channel_lap, 800); 
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 800);
 ledcWrite(channel_lbn, 0);
 ledcWrite(channel_rap, 0);
 ledcWrite(channel_ran, 1000);
 ledcWrite(channel_rbp, 0);
 ledcWrite(channel_rbn, 1000); 
 //if(digitalRead(34)==0){
 //  break;
 //}
 delay(510);///右拐
 straight1();
 ledcWrite(channel_lap, 800);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 800);
 ledcWrite(channel_lbn, 0);
 ledcWrite(channel_rap, 0);
 ledcWrite(channel_ran, 1000);
 ledcWrite(channel_rbp, 0);
 ledcWrite(channel_rbn, 1000); 
 delay(510);///右拐
 ledcWrite(channel_lap, 1023);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0); 
 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(880);//2
 ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 1000);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp, 1000);
 ledcWrite(channel_rbn, 0);
 //if(digitalRead(34)==0){
 //  break; 
 //}
 delay(510);//左拐弯
 straight1();
 while(1)
 {
  stop();
 }
 }
void straight4(){
    ledcWrite(channel_lap, 1023);
  ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(1780);//move 4 squares
 }
void straight5(){
    ledcWrite(channel_lap, 1023);
  ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(2500);//move 5 squares
 }
void straight4_2140(){
    ledcWrite(channel_lap, 1023);
  ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(2130);//走一个
 }
void straight3(){
    ledcWrite(channel_lap, 1023);
  ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(1320);//move 3 squares
 }
void straight2(){
    ledcWrite(channel_lap, 1023);
  ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(880);//move 2 squares
 }
void straight1(){
  ledcWrite(channel_lap, 1023);
  ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 1023);
 ledcWrite(channel_lbn, 0);

 ledcWrite(channel_rap, 1023);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp,1023);
 ledcWrite(channel_rbn, 0);
 delay(440);//move 1 square
if(digitalRead(34)==0||digitalRead(15)==0){
  ledcWrite(channel_lap, 900);
  ledcWrite(channel_lan, 0);
  ledcWrite(channel_lbp, 900);
  ledcWrite(channel_lbn, 0);

  ledcWrite(channel_rap, 1023);
  ledcWrite(channel_ran, 0);
  ledcWrite(channel_rbp,1023);
  ledcWrite(channel_rbn, 0);
  }  //adjust the angle when to the right
  if(digitalRead(39)==0||digitalRead(36)==0){
  ledcWrite(channel_lap,1023);
  ledcWrite(channel_lan, 0);
  ledcWrite(channel_lbp, 1023);
  ledcWrite(channel_lbn, 0);

  ledcWrite(channel_rap,900);
  ledcWrite(channel_ran, 0);
  ledcWrite(channel_rbp,900);
  ledcWrite(channel_rbn, 0);
 } ////adjust the angle when to the left
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
 } //stop the car
void right(){
  ledcWrite(channel_lap, 800);
 ledcWrite(channel_lan, 0);
 ledcWrite(channel_lbp, 800);
 ledcWrite(channel_lbn, 0);
 ledcWrite(channel_rap, 0);
 ledcWrite(channel_ran, 1000);
 ledcWrite(channel_rbp, 0);
 ledcWrite(channel_rbn, 1000); 
 delay(510);///turn right
 }
void left(){
  ledcWrite(channel_lap, 0);
 ledcWrite(channel_lan, 800);
 ledcWrite(channel_lbp, 0);
 ledcWrite(channel_lbn, 800);

 ledcWrite(channel_rap, 800);
 ledcWrite(channel_ran, 0);
 ledcWrite(channel_rbp, 800);
 ledcWrite(channel_rbn, 0);
 delay(510);//turn left
 }

