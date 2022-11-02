#define ft_sensor 16
#define ledR 35
#define ledG 37
#define ledB 39
#define ledW 41
#define btn1 3
#define buzzer 5
#define btn2 1

int btn1State=0;
int btn2State=0;
int binaryValue;
int vetor[4] = {0,0,0,0};
int posicao = 0;
int decimalValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(btn1,INPUT);
  pinMode(ft_sensor,INPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledB,OUTPUT);
  pinMode(ledW,OUTPUT);
}

void loop() {
  int analogValue = analogRead(ft_sensor);
  btn1State = digitalRead(btn1);
  btn2State = digitalRead(btn2);
  if(btn1State==0){
    definirValores(analogValue);
    delay(3000);
    ligarLeds(0,0,0,0);
  }
  if(btn2State==0){
    tocarVetor();
    ligarLeds(0,0,0,0);
    zerarVetor();
  }
  delay(500);
}

void definirValores(int analogValue){
  if(analogValue<=273){
    decimalValue = 1;
    ligarLeds(1,0,0,0);
  }
  else if(analogValue>273 && analogValue<=546){
    decimalValue = 2;
    ligarLeds(0,1,0,0);
  }
  else if(analogValue>546 && analogValue<=819){
    decimalValue = 3;
    armazenarValor(decimalValue);
    ligarLeds(1,1,0,0);
  }
  else if(analogValue>819 && analogValue<=1092){
    decimalValue = 4;
    ligarLeds(0,0,1,0);
  }
  else if(analogValue>1092 && analogValue<=1365){
    decimalValue = 5;
    ligarLeds(1,0,1,0);
  }
  else if(analogValue>1365 && analogValue<=1638){
    decimalValue = 6;
    ligarLeds(0,1,1,0);
  }
  else if(analogValue>1638 && analogValue<=1911){
    decimalValue = 7;
    ligarLeds(1,1,1,0);
  }
  else if(analogValue>1911 && analogValue<=2184){
    decimalValue = 8;
    ligarLeds(0,0,0,1);
  }
  else if(analogValue>2184 && analogValue<=2457){
    decimalValue = 9;
    ligarLeds(1,0,0,1);
  }
  else if(analogValue>2457 && analogValue<=2730){
    decimalValue = 10;
    ligarLeds(0,1,0,1);
  }
  else if(analogValue>2730 && analogValue<=3003){
    decimalValue = 11;
    ligarLeds(1,1,0,1);
  }
  else if(analogValue>3003 && analogValue<=3276){
    decimalValue = 12;
    ligarLeds(0,0,1,1);
  }
  else if(analogValue>3276 && analogValue<=3549){
    decimalValue = 13;
    ligarLeds(1,0,1,1);
  }
  else if(analogValue>3549 && analogValue<=3822){
    decimalValue = 14;
    ligarLeds(0,1,1,1);
  }
  else if(analogValue>3822 && analogValue<=4095){
    decimalValue = 15;
    ligarLeds(1,1,1,1);
  }
  armazenarValor(decimalValue);
  tocarBuzzer(decimalValue);
}

void ligarLeds(int valLedR,int valLedG,int valLedB,int valLedW){
digitalWrite(ledR,valLedR);
digitalWrite(ledG,valLedG);
digitalWrite(ledB,valLedB);
digitalWrite(ledW,valLedW);
}

void armazenarValor(int decimalValue){
  if(posicao==4){
    posicao=0;
  }
  vetor[posicao] = decimalValue;
  posicao += 1;
}

void tocarBuzzer(int decimalValue){
  int freq = decimalValue*100;
  tone(5,freq,3000);
}

void tocarVetor(){
  int bin[4] = {0,0,0,0};
  for (int i=0;i<sizeof(vetor)/4;i++){
    int frq = vetor[i];
    int num = vetor[i];
    for(int j = 0;j<4;j++){
      if (num>0){
        int res = num % 2;
        num = num/2;
        bin[j]=res;
      }
      else{
        bin[j]=0;
      }
    }
    Serial.println(num);
    ligarLeds(bin[0],bin[1],bin[2],bin[3]);
    tocarBuzzer(frq);
    delay(3000);
  }
}

void zerarVetor(){
    for (int i=0;i<sizeof(vetor)/4;i++){
    vetor[i]=0;
  }
}