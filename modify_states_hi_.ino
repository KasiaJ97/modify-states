int state = 0;
int incomingByte = 0;

#define RLED 6 
#define GLED 5 
#define BLED 3 
#define BUZZER 8 

void setup() {
  Serial1.begin(9600); //Serial1 for my connection
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(BUZZER, OUTPUT); 
}

void loop() {
  Serial1.println(state);//to change it for blserial1/2/3...
  delay(500);
  if (Serial1.available() > 0) {
    incomingByte = Serial1.read();
    switch (state) {
      case 0: // state 0
        if (incomingByte == 'R') state = 1; // Start red
        else if (incomingByte == 'H') state = 10; // for hi
        else if (incomingByte == 'G') state = 20; //for green
        else if (incomingByte == 'B') state = 30; // blue
        else if (incomingByte == 'S') state = 40; // sound
        else if (incomingByte == 'D') state = 50; // danger
        break;

      // RED 
      case 1:
        if (incomingByte == 'E') state = 2;
        else state = 0;
       
        break;
      case 2:
        if (incomingByte == 'D') {
          analogWrite(RLED,25);
          analogWrite(GLED,255);
          analogWrite(BLED,255); //works after couple seconds RED
        delay(1000);
          state = 0;
        } else state = 0;
        break;

      // HI 
      case 10:
        if (incomingByte == 'I') {
          Serial.println("Hello!");
          state = 0;
        } else state = 0; //works
        break;

      // GREEN
      case 20:
        if (incomingByte == 'R') state = 21;
        else state = 0;
        break;
      case 21:
        if (incomingByte == 'E') state = 22;
        else state = 0;
        break;
      case 22:
        if (incomingByte == 'E') state = 23;
        else state = 0;
        break;
      case 23:
        if (incomingByte == 'N') {
          analogWrite(RLED,255);
          analogWrite(GLED,25);
          analogWrite(BLED,255);// Set LED to Green WORKS AFTER COPLE SECONDS
          state = 0;
        } else state = 0;
        break;

      // BLUE
      case 30:
        if (incomingByte == 'L') state = 31;
        else state = 0;
        break;
      case 31:
        if (incomingByte == 'U') state = 32;
        else state = 0;
        break;
      case 32:
        if (incomingByte == 'E') {
          analogWrite(RLED,255);
          analogWrite(GLED,255);
          analogWrite(BLED,0); // Set LED to Blue WORKS after some time
          delay(8000);
          state = 0;
        } else state = 0;
        break;

       //SOUND
      case 40:
        if (incomingByte == 'O') state = 41;
        else state = 0;
        break;
      case 41:
        if (incomingByte == 'U') state = 42;
        else state = 0;
        break;
      case 42:
        if (incomingByte == 'N') state = 43;
        else state = 0;
        break;
      case 43:
        if (incomingByte == 'D') {
          tone(BUZZER, 1000, 500); //  sound WORKS (short)
         delay(8000);
          state = 0;
        } else state = 0;
        break;

      // DANGER
      case 50:
        if (incomingByte == 'A') state = 51;
        else state = 0;
        break;
      case 51:
        if (incomingByte == 'N') state = 52;
        else state = 0;
        break;
      case 52:
        if (incomingByte == 'G') state = 53;
        else state = 0;
        break;
      case 53:
        if (incomingByte == 'E') state = 54;
        else state = 0;
    break;
    
      case 54:
      int ii = 0;
      if (incomingByte == 'R') state = 55; // do also the light transition digitalWrite, tone, delay use LOW and GIGH and ii>  use 1000 and 2000 sound
      else state = 0;

      while (ii<6) {
      tone(BUZZER, 1000, 500);
       analogWrite(RLED,0);
          analogWrite(GLED,255);
          analogWrite(BLED,255);
delay(500);
      tone(BUZZER, 2000, 500);
       analogWrite(RLED,255);
          analogWrite(GLED,255);
          analogWrite(BLED,255);
        delay(500);
      ii++;
      }
    break;     
          
    }}}