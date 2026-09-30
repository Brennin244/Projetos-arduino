int vermelho_1 = 10;
int vermelho_2 = 11;
int amarelo_1 = 9;
int amarelo_2 = 12;
int verde_1 = 8;
int verde_2 = 13;

void setup() {
  pinMode(vermelho_1, OUTPUT);
  pinMode(amarelo_1, OUTPUT);
  pinMode(verde_1, OUTPUT);

  pinMode(vermelho_2, OUTPUT);
  pinMode(amarelo_2, OUTPUT);
  pinMode(verde_2, OUTPUT);
}

void loop() {
  cruzamento();
}

void cruzamento() {

  digitalWrite(vermelho_1, LOW);
  digitalWrite(amarelo_1, HIGH);
  digitalWrite(verde_1, LOW);

  digitalWrite(vermelho_2, LOW);
  digitalWrite(amarelo_2, HIGH);
  digitalWrite(verde_2, LOW);

  delay(2000);

  digitalWrite(amarelo_1, LOW);
  digitalWrite(vermelho_1, HIGH);

  digitalWrite(amarelo_2, LOW);
  digitalWrite(verde_2, HIGH);

  delay(5000);

  digitalWrite(verde_1, HIGH);
  digitalWrite(vermelho_1, LOW);

  digitalWrite(verde_2, LOW);
  digitalWrite(vermelho_2, HIGH);

  delay(5000);
}