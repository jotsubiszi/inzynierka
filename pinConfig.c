#include "pinConfig.h"


void writePortB(uint8_t pin, uint8_t val){
    if(val == 0){
        PORTB &= ~(1 << pin);
    }else if(val == 1){
        PORTB |= (1 << pin);
    }
}

void writePortC(uint8_t pin, uint8_t val){
    if(val == 0){
        PORTC &= ~(1 << pin);
    }else if(val == 1){
        PORTC |= (1 << pin);
    }

}

void writePortD(uint8_t pin, uint8_t val){
    if(val == 0){
        PORTD &= ~(1 << pin);
    }else if(val == 1){
        PORTD |= (1 << pin);
    }

}

void setPortB(uint8_t pin, uint8_t state, uint8_t mode){
    // checks if we want to set our pin as output or as input then puts 0 or 1 in DDRB register
    if(state == input){
        DDRB &= ~(1 << pin);

    }else if(state == output){
        DDRB |= (1 << pin);

    }else{ 
        return;
    }
    
    writePortB(pin, mode);
}

void setPortC(uint8_t pin, uint8_t state, uint8_t mode){
    if(state == input){
        DDRC &= ~(1 << pin);

    }else if(state == output){
        DDRC |= (1 << pin);

    }else{ 
        return;
    }

    writePortC(pin, mode);
}

void setPortD(uint8_t pin, uint8_t state, uint8_t mode){
    if(state == input){
        DDRD &= ~(1 << pin);

    }else if(state == output){
        DDRD |= (1 << pin);

    }else{ 
        return;
    }

    writePortD(pin, mode);
}

// returns port using arduino pin number
uint8_t portCheck(uint8_t pin){
    if(pin <= 7){
        return portd;
    }else if(pin > 7 && pin <= 13){
        return portb;
    }else if(pin > 13 && pin <= 19){
        return portc;
   }else{
        return portError;
    }
}

// returns Port pin number
uint8_t pinCheck(uint8_t pin){
    if(pin <= 7){
        return pin;
    }else if(pin > 7 && pin <= 13){
        return pin - 8;
    }else if(pin > 13 && pin <= 19){
        return pin - 14;
    }else{
        return pinError;
    }
}

void setPortPin(uint8_t pin, uint8_t state, uint8_t mode){
    if(portCheck(pin) != portError && pinCheck(pin) != pinError){
        switch(portCheck(pin)){
            case portb:
            setPortB(pinCheck(pin), state, mode);
            break;
            
            case portc:
            setPortC(pinCheck(pin), state, mode);
            break;
            
            case portd:
            setPortB(pinCheck(pin), state, mode);
            break;
        }
    }
}

uint8_t isOutput(uint8_t pin){
    uint8_t help;
    switch(portCheck(pin)){
        case portb:
        help = DDRB;
        if(DDRB == (help |= (1 << pinCheck(pin)))){
            return true;
        }else{
            return false;
        }
        break;

        case portc:
        help = DDRC;
        if(DDRC == (help |= (1 << pinCheck(pin)))){
            return true;
        }else{
            return false;
        }
        break;

        case portd:
        help = DDRD;
        if(DDRD == (help |= (1 << pinCheck(pin)))){
            return true;
        }else{
            return false;
        }
        break;

        default:
        return false;
        break;
    }
}

uint8_t isInput(uint8_t pin){
    uint8_t help;
    switch(portCheck(pin)){
        case portb:
        help = DDRB;
        if(DDRB == (help &= (1 << pinCheck(pin)))){
            return true;
        }else{
            return false;
        }
        break;

        case portc:
        help = DDRC;
        if(DDRC == (help &= (1 << pinCheck(pin)))){
            return true;
        }else{
            return false;
        }
        break;

        case portd:
        help = DDRD;
        if(DDRD == (help &= (1 << pinCheck(pin)))){
            return true;
        }else{
            return false;
        }
        break;

        default:
        return false;
        break;
    }
}

void writePinValue(uint8_t pin, uint8_t val){
    if(isOutput(pin) == false){
       return;
    }
    switch(portCheck(pin)){
        case portb:
        writePortB(pinCheck(pin), val);
        break;

        case portc:
        writePortB(pinCheck(pin), val);
        break;

        case portd:
        writePortB(pinCheck(pin), val);
        break;
    }

}

uint8_t readPinValue(uint8_t pin){
    if(isInput(pin) == false){
        return 0;
    }
    switch(portCheck(pin)){
        case portb:
        return (PINB & (1 << pinCheck(pin))) == 0 ? 0 : 1;
        break;

        case portc:
        return (PINC & (1 << pinCheck(pin))) == 0 ? 0 : 1;
        break;

        case portd:
        return (PIND & (1 << pinCheck(pin))) == 0 ? 0 : 1;
        break;

        default:
        return 0;
    }
}

void setPinAsPWM(){

}
