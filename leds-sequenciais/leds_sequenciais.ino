const int led1 = 4;
const int led2 = 7;
const int led3 = 8;
const int led4 = 9;
const int led5 = 10;
const int led6 = 11;

const int botao = 2;

int leds[] = {led1, led2, led3, led4, led5, led6};

int modo = 0;
int etapa = 0;
int estadoAnterior = HIGH;

unsigned long tempoAnterior = 0;

void setup() {

  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(botao, INPUT_PULLUP);

  apagarTodos();
}

void apagarTodos() {

  for (int i = 0; i < 6; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void verificarBotao() {

  int estadoAtual = digitalRead(botao);

  if (estadoAtual == LOW && estadoAnterior == HIGH) {

    modo++;

    if (modo > 4) {
      modo = 1;
    }

    etapa = 0;
    tempoAnterior = millis();

    apagarTodos();

    delay(50);
  }

  estadoAnterior = estadoAtual;
}

void onda() {

  if (millis() - tempoAnterior >= 150) {

    tempoAnterior = millis();

    apagarTodos();

    digitalWrite(leds[etapa], HIGH);

    etapa++;

    if (etapa >= 6) {
      etapa = 0;
    }
  }
}

void perseguicao() {

  if (millis() - tempoAnterior >= 120) {

    tempoAnterior = millis();

    apagarTodos();

    digitalWrite(leds[etapa], HIGH);
    digitalWrite(leds[etapa + 1], HIGH);

    etapa++;

    if (etapa >= 5) {
      etapa = 0;
    }
  }
}

void centroPontas() {

  if (millis() - tempoAnterior >= 180) {

    tempoAnterior = millis();

    apagarTodos();

    if (etapa == 0) {

      digitalWrite(leds[2], HIGH);
      digitalWrite(leds[3], HIGH);

    }
    else if (etapa == 1) {

      digitalWrite(leds[1], HIGH);
      digitalWrite(leds[4], HIGH);

    }
    else if (etapa == 2) {

      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[5], HIGH);

    }
    else if (etapa == 3) {

      digitalWrite(leds[1], HIGH);
      digitalWrite(leds[4], HIGH);

    }
    else {

      digitalWrite(leds[2], HIGH);
      digitalWrite(leds[3], HIGH);
    }

    etapa++;

    if (etapa > 4) {
      etapa = 0;
    }
  }
}

void loop() {

  verificarBotao();

  if (modo == 1) {

    onda();

  }
  else if (modo == 2) {

    perseguicao();

  }
  else if (modo == 3) {

    centroPontas();

  }
  else {

    apagarTodos();
  }
}