#include "Arduino.h"
#include "VEML6040.h"

// Instanciation de l'objet VEML6040
VEML6040 colorSensor;

void setup() {
    // Initialisation de la communication série avec le moniteur série
    Serial.begin(9600);
    
    // Initialisation du capteur de couleur
    colorSensor.setIntegrationTime(IT_40MS); // Configuration du temps d'intégration
}

void loop() {
    // Lecture des valeurs de couleur
    float redValue = colorSensor.getRed();
    float greenValue = colorSensor.getGreen();
    float blueValue = colorSensor.getBlue();
    float whiteValue = colorSensor.getWhite();
    float xValue = colorSensor.getX();
    float yValue = colorSensor.getY();
    float zValue = colorSensor.getZ();
    float cie1931_X = colorSensor.getCIE1931_X();
    float cie1931_Y = colorSensor.getCIE1931_Y();
    int integrationTime = colorSensor.getIT();

    // Affichage des valeurs sur le moniteur série
    Serial.print("Red: ");
    Serial.println(redValue);
    Serial.print("Green: ");
    Serial.println(greenValue);
    Serial.print("Blue: ");
    Serial.println(blueValue);
    Serial.print("White: ");
    Serial.println(whiteValue);
    Serial.print("X: ");
    Serial.println(xValue);
    Serial.print("Y: ");
    Serial.println(yValue);
    Serial.print("Z: ");
    Serial.println(zValue);
    Serial.print("CIE1931_X: ");
    Serial.println(cie1931_X);
    Serial.print("CIE1931_Y: ");
    Serial.println(cie1931_Y);
    Serial.print("Integration Time: ");
    Serial.println(integrationTime);

    // Attente avant la prochaine lecture
    delay(1000);
}
