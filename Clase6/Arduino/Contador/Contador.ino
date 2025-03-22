const int ascdec = 7;  // Pin del LED verde
const int btn = 6; 
int cont = 0;

void setup() {
  pinMode(ascdec, OUTPUT);
  pinMode(btn, OUTPUT);

  digitalWrite(ascdec, LOW);
  digitalWrite(btn, LOW);
  Serial.begin(9600);

}

void loop() {
  for (int nL = 0; nL <= 9; nL++) {
     digitalWrite(btn, HIGH);  
     delay(500);
     digitalWrite(btn, LOW);  
     Serial.println(nL);
     delay(1000);
  }

  digitalWrite(ascdec, HIGH);

  
  for (int nL = 0; nL <= 9; nL++) {
     digitalWrite(btn, HIGH);  
     delay(500);
     digitalWrite(btn, LOW);  
     Serial.println(nL);
     delay(1000);
  }

}
