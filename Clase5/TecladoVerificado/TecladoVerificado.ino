byte pinesFilas[] = {9, 8, 7, 6};    // Pines de las filas
byte pinesColumnas[] = {5, 4, 3};    // Pines de las columnas
char teclas[4][3] = {{'1', '2', '3'}, 
                     {'4', '5', '6'}, 
                     {'7', '8', '9'}, 
                     {'*', '0', '#'}};  // Matriz de teclas

String numeroIngresado = "";  // Variable para almacenar el número

const int ledVerde = 10;  // Pin del LED verde
const int ledRojo = 11;   // Pin del LED rojo

void setup()
{
  // Configurar los pines de las filas como salida
  for (int nL = 0; nL <= 3; nL++) {
     pinMode(pinesFilas[nL], OUTPUT);
     digitalWrite(pinesFilas[nL], HIGH);  // Inicia las filas en estado HIGH
  }

  // Configurar los pines de las columnas como entrada con PULLUP
  for (int nC = 0; nC <= 2; nC++) {  // Hasta 2
     pinMode(pinesColumnas[nC], INPUT_PULLUP);
  } 
  
  // Configurar los LEDs como salida
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  
  // Apaga los LEDs inicialmente
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRojo, LOW);
  
  Serial.begin(9600);
  Serial.println("Teclado 4x3");
  Serial.println();
}
 
void loop()
{
    // Barrido por las filas
    for (int nL = 0; nL <= 3; nL++)
    {
      digitalWrite(pinesFilas[nL], LOW);  // Activa la fila actual
      
      // Barrido en columnas buscando un LOW
      for (int nC = 0; nC <= 2; nC++) {  // Hasta 2 porque ahora son 3 columnas
        if (digitalRead(pinesColumnas[nC]) == LOW)
        {
          char teclaPresionada = teclas[nL][nC];  // Obtén la tecla presionada
          
          // Si la tecla es un número, guárdalo
          if (teclaPresionada >= '0' && teclaPresionada <= '9') {
            numeroIngresado += teclaPresionada;
            Serial.print("Número ingresado: ");
            Serial.println(numeroIngresado);
          }
          // Si la tecla es '#', verifica el número y reinicia
          else if (teclaPresionada == '#') {
            Serial.println("Número completo: " + numeroIngresado);
            // Verifica el número ingresado
            verificarNumero(numeroIngresado);
            
            // Reinicia el número ingresado
            numeroIngresado = "";
            Serial.println("Esperando nuevo número...");
          }
          
          // Espera hasta que la tecla se libere
          while(digitalRead(pinesColumnas[nC]) == LOW){}
        }
      }

      digitalWrite(pinesFilas[nL], HIGH);  // Apaga la fila actual
    }
   delay(10);
}

// Función para verificar o procesar el número ingresado
void verificarNumero(String numero) {
  Serial.print("Verificando el número: ");
  Serial.println(numero);
  
  // Compara el número con "456"
  if (numero == "123") {
    Serial.println("¡Número correcto!");
    digitalWrite(ledVerde, HIGH);  // Enciende el LED verde
    digitalWrite(ledRojo, LOW);    // Apaga el LED rojo
  } else {
    Serial.println("Número incorrecto.");
    digitalWrite(ledVerde, LOW);   // Apaga el LED verde
    digitalWrite(ledRojo, HIGH);   // Enciende el LED rojo
  }
}
