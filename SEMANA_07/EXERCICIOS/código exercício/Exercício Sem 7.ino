#include <iostream>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#define ledG1 38
#define ledR1 42
#define ledG2 17
#define ledR2 7

const char* ssid = "Esp32";
const char* password = "Gabriel123";

int score1 = 0;
int score2 = 0;

WebServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(ledG1, OUTPUT);
  pinMode(ledR1, OUTPUT);
  pinMode(ledG2, OUTPUT);
  pinMode(ledR2, OUTPUT);
  delay(1000);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Rede: ");
  Serial.println(ssid);
  Serial.print("Endereço IP: ");
  Serial.println(IP);

  Serial.println("");
  Serial.println("WiFi connected.");

  server.begin();

  server.on("/", handleRoot);
  server.on("/player1", handle1plr1);
  server.on("/player2", handle1plr2);

  server.on("/errado1plr1", errado1plr1);
  server.on("/certo1plr1", certo1plr1);
  server.on("/errado2plr1", errado2plr1);
  server.on("/certo2plr1", certo2plr1);
  server.on("/errado3plr1", errado3plr1);
  server.on("/certo3plr1", certo3plr1);

  server.on("/errado1plr2", errado1plr2);
  server.on("/certo1plr2", certo1plr2);
  server.on("/errado2plr2", errado2plr2);
  server.on("/certo2plr2", certo2plr2);
  server.on("/errado3plr2", errado3plr2);
  server.on("/certo3plr2", certo3plr2);

  server.on("/placar", placarFinal);
}


void handleRoot() {
  score1 = 0;
  score2 = 0;
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h2><a href=\"/player1\">player 1</a></h2><br>";
  html += "<h2><a href=\"/player2\">player 2</a></h2><br>";
  server.send(200, "text/html", html);
}

/////////////////////////////////////

//player 1

void handle1plr1() {  //primeira questão player 1
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Quem marcou o gol da vitória do Brasil na final da copa do mundo de 2002?</h1><br>";
  html += "<a href=\"/errado1plr1\">A. Romário</a><br>";
  html += "<a href=\"/errado1plr1\">B. Kaká</a><br>";
  html += "<a href=\"/certo1plr1\">C. Ronaldo</a><br>";
  html += "<a href=\"/errado1plr1\">D. Cafu</a><br>";
  html += "<a href=\"/errado1plr1\">E. Richarlison</a><br>";
  server.send(200, "text/html", html);
}

void errado1plr1() {  //2º questão player 1 , errou a 1º
  digitalWrite(ledR1, HIGH);
  delay(1000);
  digitalWrite(ledR1, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Qual foi o país ganhador da copa de 2010?</h1><br>";
  html += "<a href=\"/errado2plr1\">A. Holanda</a><br>";
  html += "<a href=\"/errado2plr1\">B. Bélgica</a><br>";
  html += "<a href=\"/errado2plr1\">C. Inglaterra</a><br>";
  html += "<a href=\"/errado2plr1\">D. Portugal</a><br>";
  html += "<a href=\"/certo2plr1\">E. Espanha</a><br>";
  server.send(200, "text/html", html);
}

void certo1plr1() {  //2º questão player 1 , acertou a 1º
  score1++;
  digitalWrite(ledG1, HIGH);
  delay(1000);
  digitalWrite(ledG1, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Qual foi o país ganhador da copa de 2010?</h1><br>";
  html += "<a href=\"/errado2plr1\">A. Holanda</a><br>";
  html += "<a href=\"/errado2plr1\">B. Bélgica</a><br>";
  html += "<a href=\"/errado2plr1\">C. Inglaterra</a><br>";
  html += "<a href=\"/errado2plr1\">D. Portugal</a><br>";
  html += "<a href=\"/certo2plr1\">E. Espanha</a><br>";
  server.send(200, "text/html", html);
}

void errado2plr1() {  //3º questão player 1, errou a 2º
  digitalWrite(ledR1, HIGH);
  delay(1000);
  digitalWrite(ledR1, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Quantos gols o Brasil possui em copas do mundo?</h1><br>";
  html += "<a href=\"/certo3plr1\">A. 232</a><br>";
  html += "<a href=\"/errado3plr1\">B. 187</a><br>";
  html += "<a href=\"/errado3plr1\">C. 326</a><br>";
  html += "<a href=\"/errado3plr1\">D. 314</a><br>";
  html += "<a href=\"/errado3plr1\">E. 253</a><br>";
  server.send(200, "text/html", html);
}

void certo2plr1() {  //3º questão player 1, acertou a 2º
  score1++;
  digitalWrite(ledG1, HIGH);
  delay(1000);
  digitalWrite(ledG1, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Quantos gols o Brasil possui em copas do mundo?</h1><br>";
  html += "<a href=\"/certo3plr1\">A. 232</a><br>";
  html += "<a href=\"/errado3plr1\">B. 187</a><br>";
  html += "<a href=\"/errado3plr1\">C. 326</a><br>";
  html += "<a href=\"/errado3plr1\">D. 314</a><br>";
  html += "<a href=\"/errado3plr1\">E. 253</a><br>";
  server.send(200, "text/html", html);
}

void errado3plr1() {  //tela final, errou a 3º
  digitalWrite(ledR1, HIGH);
  delay(1000);
  digitalWrite(ledR1, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h2><a href=\"/placar\">Placar final</a></h2><br>";
  server.send(200, "text/html", html);
}

void certo3plr1() {  //tela final, acertou a 3º
  score1++;
  digitalWrite(ledG1, HIGH);
  delay(1000);
  digitalWrite(ledG1, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h2><a href=\"/placar\">Placar final</a></h2><br>";
  server.send(200, "text/html", html);
}
////////////////////////////////////

//player 2

void handle1plr2() {  //primeira questão player 2
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Quem marcou o gol da vitória do Brasil na final da copa do mundo de 2002?</h1><br>";
  html += "<a href=\"/errado1plr2\">A. Romário</a><br>";
  html += "<a href=\"/errado1plr2\">B. Kaká</a><br>";
  html += "<a href=\"/certo1plr2\">C. Ronaldo</a><br>";
  html += "<a href=\"/errado1plr2\">D. Cafu</a><br>";
  html += "<a href=\"/errado1plr2\">E. Richarlison</a><br>";
  server.send(200, "text/html", html);
}

void errado1plr2() {  //2º questão player 2 , errou a 1º
  digitalWrite(ledR2, HIGH);
  delay(1000);
  digitalWrite(ledR2, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Qual foi o país ganhador da copa de 2010?</h1><br>";
  html += "<a href=\"/errado2plr2\">A. Holanda</a><br>";
  html += "<a href=\"/errado2plr2\">B. Bélgica</a><br>";
  html += "<a href=\"/errado2plr2\">C. Inglaterra</a><br>";
  html += "<a href=\"/errado2plr2\">D. Portugal</a><br>";
  html += "<a href=\"/certo2plr2\">E. Espanha</a><br>";
  server.send(200, "text/html", html);
}

void certo1plr2() {  //2º questão player 2 , acertou a 1º
  score2++;
  digitalWrite(ledG2, HIGH);
  delay(1000);
  digitalWrite(ledG2, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Qual foi o país ganhador da copa de 2010?</h1><br>";
  html += "<a href=\"/errado2plr2\">A. Holanda</a><br>";
  html += "<a href=\"/errado2plr2\">B. Bélgica</a><br>";
  html += "<a href=\"/errado2plr2\">C. Inglaterra</a><br>";
  html += "<a href=\"/errado2plr2\">D. Portugal</a><br>";
  html += "<a href=\"/certo2plr2\">E. Espanha</a><br>";
  server.send(200, "text/html", html);
}

void errado2plr2() {  //3º questão player 1, errou a 2º
  digitalWrite(ledR2, HIGH);
  delay(1000);
  digitalWrite(ledR2, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Quantos gols o Brasil possui em copas do mundo?</h1><br>";
  html += "<a href=\"/certo3plr2\">A. 232</a><br>";
  html += "<a href=\"/errado3plr2\">B. 187</a><br>";
  html += "<a href=\"/errado3plr2\">C. 326</a><br>";
  html += "<a href=\"/errado3plr2\">D. 314</a><br>";
  html += "<a href=\"/errado3plr2\">E. 253</a><br>";
  server.send(200, "text/html", html);
}

void certo2plr2() {  //3º questão player 1, acertou a 2º
  score2++;
  digitalWrite(ledG2, HIGH);
  delay(1000);
  digitalWrite(ledG2, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h1>Quantos gols o Brasil possui em copas do mundo?</h1><br>";
  html += "<a href=\"/certo3plr2\">A. 232</a><br>";
  html += "<a href=\"/errado3plr2\">B. 187</a><br>";
  html += "<a href=\"/errado3plr2\">C. 326</a><br>";
  html += "<a href=\"/errado3plr2\">D. 314</a><br>";
  html += "<a href=\"/errado3plr2\">E. 253</a><br>";
  server.send(200, "text/html", html);
}

void errado3plr2() {  //tela final, errou a 3º
  digitalWrite(ledR2, HIGH);
  delay(1000);
  digitalWrite(ledR2, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h2><a href=\"/placar\">Placar final</a></h2><br>";
  server.send(200, "text/html", html);
}

void certo3plr2() {  //tela final, acertou a 3º
  score2++;
  digitalWrite(ledG2, HIGH);
  delay(1000);
  digitalWrite(ledG2, LOW);
  String html = "";
  html += "<meta charset='UTF-8'>";
  html += "<h2><a href=\"/placar\">Placar final</a></h2><br>";
  server.send(200, "text/html", html);
}

void placarFinal() {
  if (score1 == score2) {
    String html = "";
    html += "<meta charset='UTF-8'>";
    html += "<h1>Empate</h1><br>";
    html += "<h1>Pontuação player 1:" + String(score1) + "</h1><br>";
    html += "<h1>Pontuação player 2:" + String(score2) + "</h1><br>";
    html += "<h1><a href=\"/\">Recomeçar</a></h1>";
    server.send(200, "text/html", html);
  } else if (score1 > score2) {
    String html = "";
    html += "<meta charset='UTF-8'>";
    html += "<h1>Player 1 Venceu!</h1><br>";
    html += "<h1>Pontuação player 1:" + String(score1) + "</h1><br>";
    html += "<h1>Pontuação player 2:" + String(score2) + "</h1><br>";
    html += "<h1><a href=\"/\">Recomeçar</a></h1>";
    server.send(200, "text/html", html);
  } else {
    String html = "";
    html += "<meta charset='UTF-8'>";
    html += "<h1>Player 2 Venceu!</h1><br>";
    html += "<h1>Pontuação player 1:" + String(score1) + "</h1><br>";
    html += "<h1>Pontuação player 2:" + String(score2) + "</h1><br>";
    html += "<h1><a href=\"/\">Recomeçar</a></h1>";
    server.send(200, "text/html", html);
  }
}

void loop() {
  server.handleClient();
  delay(2);
  //teste();
}

void teste() {
  Serial.println(score1);
  Serial.println("Player 1");
  Serial.println(score2);
  Serial.println("Player 2");
  delay(7000);
}