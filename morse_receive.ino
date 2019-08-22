int one [5] = {1,3,3,3,3};                     /* Same array definitions for each of the numbers in morse code as in the send code*/ 
int two [5] = {1,1,3,3,3};
int three [5] = {1,1,1,3,3};
int four [5] = {1,1,1,1,3};
int five [5] = {1,1,1,1,1};
int six [5] = {3,1,1,1,1};
int seven [5] = {3,3,1,1,1};
int eight [5] = {3,3,3,1,1};
int nine [5] = {3,3,3,3,1};
int zero [5] = {3,3,3,3,3};
int num [5];
int ldr = A0;
int first = 0;
int value;
int i = 0;
int count;
int a = 1;
int calib = 0;
int b;
void setup() {
  Serial.begin(9600);                                         /*Initialises the Serial monitor and asks for the morse code to be sent via an LED or a laser module onto the LDR which will receive the data. */
  pinMode(ldr, INPUT);
  Serial.println("Please send a number through the laser.");
}

void loop() {
  if(calib==0){                                             /* Calibration code for the LDR to adjust to the lighting conditions. */
     b = analogRead(ldr);
     calib++;
  }
  value = analogRead(ldr);                                 /* Reads the current signal value of the LDR*/
  /*Serial.println(value);*/
  if(i<5){                                                 // Determines the five values of the array sent by checking if the value of the LDR is high meaning that the light is on and determining the time that it was on for. This will be 1 or 3 seconds. 
    if (value>b+100){                                      // Next it assigns this value to the ith index of the array num. In such a way it completes the array according to the data it received. 
      while(value>b+100){
        value = analogRead(ldr);
        count++;
        delay(100);
      }
      count = count *100;
      count = count / 1000;
      num[i] = count; 
      count = 0;
      i++;
    }
  }
  else if(i==5){                                         // After the array num has been completed, the array is compared to each of the 10 arrays and according to the one that is equal, the corresponding number is printed on the Serial monitor. 
    i = 0;
    for(int j=0;j<5;j++){
      if(num[j] != one[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 1");
    }
    a=1;
    for(int j=0;j<5;j++){
      if(num[j] != two[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 2");
    }
    a=1;
    for(int j=0;j<5;j++){
      if(num[j] != three[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 3");
    }
    a=1;
    for(int j=0;j<5;j++){
      if(num[j] != four[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 4");
    }
    a=1;
    for(int j=0;j<5;j++){
      if(num[j] != five[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 5");
    }
    a=1;
    for(int j=0;j<5;j++){
      if(num[j] != six[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 6");
    }
    a=1;
    for(int j=0;j<5;j++){
      if(num[j] != seven[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 7");
    }
    a=1;
    for(int j=0;j<5;j++){
      if(num[j] != eight[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 8");
    }
    a=1;
    for(int j=0;j<5;j++){
      if(num[j] != nine[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 9");
    }
    a=1;
    for(int j=0;j<5;j++){
      if(num[j] != zero[j]){
        a = 0;
        break;
      }
    }
    if(a==1){
       Serial.println("Received: 0");
    }
    a=1;
    Serial.println("Please send a number through the laser.");                                         // Initialises again so that a number can be received again. 
  }
  delay(100);
  count=0;
}
