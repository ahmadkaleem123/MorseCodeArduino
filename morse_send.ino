int one [5] = {1,3,3,3,3};                /*Create arrays for each of the numbers based on their morse code representations. A 3 represents a long dash while a 1 represents a short dash. This is the time in seconds for which the light will blink. */ 
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
int laser = 13;
char state;
int first = 0;
void setup() {
  Serial.begin(9600);
  pinMode(laser, OUTPUT);
  Serial.println("Please give a number between 0 and 9 to send as morse code.");           /* Asks user to type a number on the computer to send as morse code. */
}

void loop() {
  
  if(Serial.available()>0)
  {
    state = Serial.read();
    switch(state) {                                                              /* A switch based on all of the possible cases. The value of the specific number's array is copied over to a new one called num.*/
    case '0':
      for (int j=0;j<5;j++){
        num[j] = zero[j];
      }
      first = 0;
      break;
      
    case '1':
      for (int j=0;j<5;j++){
        num[j] = one[j];
      }
      first = 0;
      break;
      
    case '2':
      for (int j=0;j<5;j++){
        num[j] = two[j];
      }
      first = 0;
      break;
      
    case '3':
      for (int j=0;j<5;j++){
        num[j] = three[j];
      }
      first = 0;
      break;
      
    case '4':
      for (int j=0;j<5;j++){
        num[j] = four[j];
      }
      first = 0;
      break;
      
    case '5':
      for (int j=0;j<5;j++){
        num[j] = five[j];
      }
      first = 0;
      break;
     
    case '6':
      for (int j=0;j<5;j++){
        num[j] = six[j];
      }
      first = 0;
      break;
      
    case '7':
      for (int j=0;j<5;j++){
        num[j] = seven[j];
      }
      first = 0;
      break;
      
    case '8':
      for (int j=0;j<5;j++){
        num[j] = eight[j];
      }
      first = 0;
      break;
      
    case '9':
      for (int j=0;j<5;j++){
        num[j] = nine[j];
      }
      first = 0;
      break;
    }
    if(first == 0){                                       /* Blinks the LED according to the array with timings for the integer sent according to morse code. The if statement in the beginning is so that the integer is only sent once since otherwise the code will be repeatedly sent. */
      for (int i=0;i<5;i++){
      digitalWrite(laser,HIGH);
      delay((num[i]*1000));
      digitalWrite(laser, LOW);
      delay(1000);
      }
      first = 1;
    } 
    
  }
  
  
  

}
