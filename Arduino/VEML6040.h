#ifndef _VEML6040_H_
#define _VEML6040_H_

#include "Arduino.h"
#include "Wire.h"

class VEML6040 
{
public:
    VEML6040(); // Constructeur

    // Méthodes pour obtenir les valeurs de couleur
    float getRed();
    float getGreen();
    float getBlue();
    float getWhite();
    float getX();
    float getY();
    float getZ();
    float getCIE1931_X();
    float getCIE1931_Y();

    // Méthodes pour configurer le capteur
    void setIntegrationTime(uint8_t it_value);

    // Autres méthodes
    int getIT();

private:
    TwoWire *i2c; // Instance de la classe Wire pour la communication I2C
    uint8_t address; // Adresse I2C du capteur

    // Méthodes privées pour la communication I2C
    int readRegisters(uint8_t reg, uint8_t *data, int len);
    int writeRegister(uint8_t reg, uint8_t value);
};

#endif /* _VEML6040_H_ */
