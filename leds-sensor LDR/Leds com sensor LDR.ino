
const int led1 = 4;
const int led2 = 7;
const int led3 = 8;
const int led4 = 11;
const int led5 = 10;

const int ldr = A0;

int leds[] = {led1, led2, led3, led4, led5};

int valorLdr = 0;
int quantidadeLeds = 0;

int limite1 = 850;
int limite2 = 750;
int limite3 = 650;
int limite4 = 550;
int limite5 = 250;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(ldr, INPUT);
}

void loop() {
  valorLdr = analogRead(ldr);

  Serial.println(valorLdr);

  if (valorLdr >= limite1) {
    quantidadeLeds = 0;
  }
  else if (valorLdr >= limite2) {
    quantidadeLeds = 1;
  }
  else if (valorLdr >= limite3) {
    quantidadeLeds = 2;
  }
  else if (valorLdr >= limite4) {
    quantidadeLeds = 3;
  }
  else if (valorLdr >= limite5) {
    quantidadeLeds = 4;
  }

  else {
    quantidadeLeds = 5;
  }

  for (int i = 0; i < 5; i++) {
    if (i < quantidadeLeds) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }

  delay(50);
}
