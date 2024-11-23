int value[32]={
  91,629,774,841,905,923,936,946,
  335,680,796,852,911,928,939,948,
  478,720,814,863,916,932,941,951,
  571,751,829,872,  0, 0 , 0 , 0 ,
};
char key[32] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
  'Y', 'Z', '1', '2', '3', '4', '5', '6'
};

String keyword ="";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  //Checks the all the keys
  for(int i =0;i<32;i++){
    if(abs(val - value[i]) < 2){
      char pressed = key[i];
      //Check is thare any integer
      if((key[i] != '1')&&(key[i] != '2')){ 
        keyword += pressed;
      }
      //Key to erase data
      if(key[i]=='1'){
        keyword ="";
      }
      //Key to trnsmit the data
      if(key[i]=='2'){
        Serial.println("U have Send This " + keyword);
      }
      //Serial.println(keyword);           // This line is for testing purpose
      //Hold on until key is Relese
      while(true){
        val = analogRead(A0);
        if(abs(val - value[i]) > 15){break;}
      }

    }
  }
  //Serial.println(val);
  delay(50);
}

