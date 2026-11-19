const int PINO_BOTAO = 2;
const int PINO_LED   = 9;
const int PINO_POT   = A0;
const int PINO_LDR   = A1;

int modoOperacao = 0;
int ultimoEstadoBotao = HIGH;
unsigned long ultimoDebounce = 0;
const unsigned long tempoDebounce = 200;

const int LIMIAR_ESCURO = 400;

void setup() {
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP);
}

void loop() {
  int leituraBotao = digitalRead(PINO_BOTAO);

  if (leituraBotao == LOW && ultimoEstadoBotao == HIGH && (millis() - ultimoDebounce > tempoDebounce)) {
    modoOperacao = !modoOperacao;
    ultimoDebounce = millis();
  }
  ultimoEstadoBotao = leituraBotao;

  if (modoOperacao == 0) {
    int valorPot = analogRead(PINO_POT);
    int brilhoLed = map(valorPot, 0, 1023, 0, 255);
    analogWrite(PINO_LED, brilhoLed);
  } 
  else {
    int valorLdr = analogRead(PINO_LDR);
    
    if (valorLdr < LIMIAR_ESCURO) {
      analogWrite(PINO_LED, 255);
    } else {
      analogWrite(PINO_LED, 0);
    }
  }

  delay(20);
}