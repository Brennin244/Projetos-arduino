const int carro1Vermelho = 4;
const int carro1Amarelo = 7;
const int carro1Verde = 8;

const int carro2Vermelho = 9;
const int carro2Amarelo = 10;
const int carro2Verde = 11;

const int pedestreVermelho = 13;
const int pedestreVerde = 12;

const int botao = 2;

const int tempoVerde = 5000;
const int tempoAmarelo = 2000;
const int tempoPedestre = 5000;

bool pedidoPedestre = false;

void setup() {
  pinMode(carro1Vermelho, OUTPUT);
  pinMode(carro1Amarelo, OUTPUT);
  pinMode(carro1Verde, OUTPUT);

  pinMode(carro2Vermelho, OUTPUT);
  pinMode(carro2Amarelo, OUTPUT);
  pinMode(carro2Verde, OUTPUT);

  pinMode(pedestreVermelho, OUTPUT);
  pinMode(pedestreVerde, OUTPUT);

  pinMode(botao, INPUT_PULLUP);

  digitalWrite(carro1Verde, HIGH);
  digitalWrite(carro2Vermelho, HIGH);
  digitalWrite(pedestreVermelho, HIGH);
}

void verificarBotao() {
  if (digitalRead(botao) == LOW) {
    pedidoPedestre = true;
  }
}

void esperar(unsigned long tempo) {
  unsigned long inicio = millis();

  while (millis() - inicio < tempo) {
    verificarBotao();
  }
}

void pedestre() {
  digitalWrite(carro1Vermelho, HIGH);
  digitalWrite(carro1Amarelo, LOW);
  digitalWrite(carro1Verde, LOW);

  digitalWrite(carro2Vermelho, HIGH);
  digitalWrite(carro2Amarelo, LOW);
  digitalWrite(carro2Verde, LOW);

  digitalWrite(pedestreVermelho, LOW);
  digitalWrite(pedestreVerde, HIGH);

  delay(tempoPedestre);

  digitalWrite(pedestreVerde, LOW);
  digitalWrite(pedestreVermelho, HIGH);

  pedidoPedestre = false;
}

void loop() {

  verificarBotao();

  digitalWrite(carro1Verde, HIGH);
  digitalWrite(carro1Amarelo, LOW);
  digitalWrite(carro1Vermelho, LOW);

  digitalWrite(carro2Verde, LOW);
  digitalWrite(carro2Amarelo, LOW);
  digitalWrite(carro2Vermelho, HIGH);

  digitalWrite(pedestreVermelho, HIGH);
  digitalWrite(pedestreVerde, LOW);

  esperar(tempoVerde);

  digitalWrite(carro1Verde, LOW);
  digitalWrite(carro1Amarelo, HIGH);

  esperar(tempoAmarelo);

  digitalWrite(carro1Amarelo, LOW);
  digitalWrite(carro1Vermelho, HIGH);

  if (pedidoPedestre) {
    pedestre();
    return;
  }

  digitalWrite(carro2Vermelho, LOW);
  digitalWrite(carro2Verde, HIGH);

  esperar(tempoVerde);

  digitalWrite(carro2Verde, LOW);
  digitalWrite(carro2Amarelo, HIGH);

  esperar(tempoAmarelo);

  digitalWrite(carro2Amarelo, LOW);
  digitalWrite(carro2Vermelho, HIGH);

  if (pedidoPedestre) {
    pedestre();
    return;
  }
}
