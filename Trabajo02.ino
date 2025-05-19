#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);  // Cambia 0x27 por 0x3F si es necesario

String mensaje = " Jhosep mi eterno hijo "; // Mensaje largo a desplazarse
int longitudMensaje;

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.clear();  // Asegura que la pantalla comienza en blanco
    longitudMensaje = mensaje.length();
}

void loop() {
    // Iniciar el mensaje desde fuera del área visible
    for (int posicion = 16; posicion >= 0; posicion--) {
        lcd.clear();
        lcd.setCursor(posicion, 0);  
        lcd.print(mensaje.substring(0, min(16, longitudMensaje))); // Imprime solo lo visible
        delay(300);
    }

    // Desplazamiento continuo de derecha a izquierda
    for (int i = 0; i <= longitudMensaje; i++) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(mensaje.substring(i, i + 16)); // Mueve el texto con desplazamiento
        delay(300);
    }
}
