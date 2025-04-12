#define Pin12 12
#define Pin13 13
char caracter;

void setup() {
Serial.begin(9600);
pinMode(Pin12, OUTPUT);
pinMode(Pin13, OUTPUT);
}

void loop() {
if(Serial.available()) {
caracter = Serial.read();

if(caracter == 'a'){ 
  Serial.println("A");
  digitalWrite(Pin12, HIGH);
}
if(caracter == 'b'){ 
  Serial.println("B");
  digitalWrite(Pin12, LOW);
} 
if(caracter == 'c'){ 
  Serial.println("C");
  digitalWrite(Pin13, HIGH);
}
if(caracter == 'd'){ 
  Serial.println("D");
  digitalWrite(Pin13, LOW);
}
}

}