
const int ledVermelho = 11;
const int ledAmarelo  = 12;
const int ledAzul     = 13;
const int potenciometro = A0;

int leitura;
int velocidade;

void apagarLeds() {
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledAzul, LOW);
}

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(potenciometro, INPUT);

  apagarLeds();
}

void loop() {
  leitura = analogRead(potenciometro);

  velocidade = map(leitura, 0, 1023, 800, 100);

  if (leitura < 341) {
    digitalWrite(ledVermelho, HIGH);
    delay(velocidade);
    apagarLeds();

    digitalWrite(ledAmarelo, HIGH);
    delay(velocidade);
    apagarLeds();

    digitalWrite(ledAzul, HIGH);
    delay(velocidade);
    apagarLeds();

  } else if (leitura < 682) {
    digitalWrite(ledVermelho, HIGH);
    delay(velocidade);
    apagarLeds();

    digitalWrite(ledAmarelo, HIGH);
    delay(velocidade);
    apagarLeds();

    digitalWrite(ledAzul, HIGH);
    delay(velocidade);
    apagarLeds();

    digitalWrite(ledAmarelo, HIGH);
    delay(velocidade);
    apagarLeds();

  } else if (leitura < 1000) 
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAzul, HIGH);
    delay(velocidade);
    apagarLeds();

    digitalWrite(ledAmarelo, HIGH);
    delay(velocidade);
    apagarLeds();

  } else {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledAzul, HIGH);
    delay(200);

    apagarLeds();
    delay(200);
  }
}
