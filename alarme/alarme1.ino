const int pinoLDR = A0;     
const int pinoBotao = 12;   
const int pinoLed1 = 10;    
const int pinoLed2 = 11;    

const int limiteLuz = 500;

bool alarmeDisparado = false;
bool estadoPisca = false;
unsigned long tempoAnterior = 0;
const unsigned long intervaloPisca = 250; 

void setup() {
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);
  pinMode(pinoBotao, INPUT); 
  Serial.begin(9600);
}

void loop() {
  int leituraLuz = analogRead(pinoLDR);
  int estadoBotao = digitalRead(pinoBotao);

  if (estadoBotao == HIGH) {
    alarmeDisparado = false;
    desligarAlarme();
  } 
  else if (leituraLuz < limiteLuz) {
    alarmeDisparado = true;
  }

  if (alarmeDisparado) {
    unsigned long tempoAtual = millis();
    if (tempoAtual - tempoAnterior >= intervaloPisca) {
      tempoAnterior = tempoAtual;
      estadoPisca = !estadoPisca;

      digitalWrite(pinoLed1, estadoPisca);
      digitalWrite(pinoLed2, estadoPisca);
    }
  }
}

void desligarAlarme() {
  estadoPisca = false;
  digitalWrite(pinoLed1, LOW);
  digitalWrite(pinoLed2, LOW);
}