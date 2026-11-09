
const int potenciometro = A0;

const int ledVerde = 12;
const int ledAmarelo = 11;
const int ledVermelho = 13;
const int ledAzul = 10;

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 500;

bool estadoAzul = false;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(potenciometro);

  int temperatura = map(leitura, 0, 1023, 0, 100);

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" graus C");

  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  if (temperatura < 40) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
    estadoAzul = false;
  }

  else if (temperatura < 60) {
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledAzul, LOW);
    estadoAzul = false;
  }

  else if (temperatura <= 80) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAzul, LOW);
    estadoAzul = false;
  }

  else {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, HIGH);

    unsigned long tempoAtual = millis();

    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;
      estadoAzul = !estadoAzul;
    }

    digitalWrite(ledAzul, estadoAzul);
  }

  delay(100);
}
