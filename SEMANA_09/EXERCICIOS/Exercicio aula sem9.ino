#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define I2C_SDA 2
#define I2C_SCL 1

LiquidCrystal_I2C lcd(0x27, 16, 2);

String senha;
String input;
String novaSenha;

void setup() {
  Wire.begin(I2C_SDA, I2C_SCL);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.begin(9600);
  Serial.println("Digite uma nova senha de 4 dígitos:");

  pinMode(RGB_BUILTIN, OUTPUT);
  neopixelWrite(RGB_BUILTIN, 0, 0, 0);

  while (Serial.available() == 0) {}
  senha = Serial.readString();
}

void loop() {
  Serial.println("Selecione uma das opções");
  Serial.println("1 - Cadastrar nova senha");
  Serial.println("2 - Entrar com a senha cadastrada");
  while (Serial.available() == 0) {}
  input = Serial.readString();
  if (input.toInt() == 1) {
    Serial.print("Digite uma nova senha de 4 dígitos:");
    while (Serial.available() == 0) {}
    senha = Serial.readString();
  } else if (input.toInt() == 2) {
    Serial.print("Digite a senha cadastrada:");
    while (Serial.available() == 0) {}
    novaSenha = Serial.readString();
    if (senha == novaSenha) {
      correto();
      neopixelWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0);  // Green
      delay(3000);
      neopixelWrite(RGB_BUILTIN, 0, 0, 0);  // Off / black
      apagar();
    } else {
      incorreto();
      neopixelWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0);  // Red
      delay(3000);
      neopixelWrite(RGB_BUILTIN, 0, 0, 0);  // Off / black
      apagar();
    }
  }
}

void correto() {
  lcd.clear();
  lcd.print("Correto");
}
void incorreto() {
  lcd.clear();
lcd.print("Incorreto");
}
void apagar() {
  lcd.clear();
}