#include "pinConfig.h"

void writePortB(uint8_t pin, uint8_t val) {
  if (val == 0) {
    PORTB &= ~(1 << pin);
  } else if (val == 1) {
    PORTB |= (1 << pin);
  }
}

void writePortC(uint8_t pin, uint8_t val) {
  if (val == 0) {
    PORTC &= ~(1 << pin);
  } else if (val == 1) {
    PORTC |= (1 << pin);
  }
}

void writePortD(uint8_t pin, uint8_t val) {
  if (val == 0) {
    PORTD &= ~(1 << pin);
  } else if (val == 1) {
    PORTD |= (1 << pin);
  }
}

void setPortB(uint8_t pin, uint8_t state, uint8_t mode) {
  if (state == INPUT) {
    DDRB &= ~(1 << pin);

  } else if (state == OUTPUT) {
    DDRB |= (1 << pin);
    writePortB(pin, mode);

  } else {
    return;
  }
}

void setPortC(uint8_t pin, uint8_t state, uint8_t mode) {
  if (state == INPUT) {
    DDRC &= ~(1 << pin);

  } else if (state == OUTPUT) {
    DDRC |= (1 << pin);
    writePortC(pin, mode);

  } else {
    return;
  }
}

void setPortD(uint8_t pin, uint8_t state, uint8_t mode) {
  if (state == INPUT) {
    DDRD &= ~(1 << pin);

  } else if (state == OUTPUT) {
    DDRD |= (1 << pin);
    writePortD(pin, mode);

  } else {
    return;
  }
}

// returns port using arduino pin number
uint8_t portCheck(uint8_t ardPin) {
  if (ardPin <= 7) {
    return CPORTD;
  } else if (ardPin > 7 && ardPin <= 13) {
    return CPORTB;
  } else if (ardPin > 13 && ardPin <= 19) {
    return CPORTC;
  } else {
    return PORTERROR;
  }
}

// returns portx pin number using arduino pin
uint8_t pinCheck(uint8_t ardPin) {
  if (ardPin <= 7) {
    return ardPin;
  } else if (ardPin > 7 && ardPin <= 13) {
    return ardPin - 8;
  } else if (ardPin > 13 && ardPin <= 19) {
    return ardPin - 14;
  } else {
    return PINERROR;
  }
}

void setPortPin(uint8_t ardPin, uint8_t state, uint8_t mode) {
  if (portCheck(ardPin) != PORTERROR && pinCheck(ardPin) != PINERROR) {
    switch (portCheck(ardPin)) {
    case CPORTB:
      setPortB(pinCheck(ardPin), state, mode);
      break;

    case CPORTC:
      setPortC(pinCheck(ardPin), state, mode);
      break;

    case CPORTD:
      setPortB(pinCheck(ardPin), state, mode);
      break;
    }
  }
}

uint8_t isOutput(uint8_t ardPin) {
  uint8_t help;
  switch (portCheck(ardPin)) {
  case CPORTB:
    help = DDRB;
    if (DDRB == (help |= (1 << pinCheck(ardPin)))) {
      return TRUE;
    } else {
      return FALSE;
    }
    break;

  case CPORTC:
    help = DDRC;
    if (DDRC == (help |= (1 << pinCheck(ardPin)))) {
      return TRUE;
    } else {
      return FALSE;
    }
    break;

  case CPORTD:
    help = DDRD;
    if (DDRD == (help |= (1 << pinCheck(ardPin)))) {
      return TRUE;
    } else {
      return FALSE;
    }
    break;

  default:
    return FALSE;
    break;
  }
}

uint8_t isInput(uint8_t ardPin) {
  uint8_t help;
  switch (portCheck(ardPin)) {
  case CPORTB:
    help = DDRB;
    if (DDRB == (help &= (1 << pinCheck(ardPin)))) {
      return TRUE;
    } else {
      return FALSE;
    }
    break;

  case CPORTC:
    help = DDRC;
    if (DDRC == (help &= (1 << pinCheck(ardPin)))) {
      return TRUE;
    } else {
      return FALSE;
    }
    break;

  case CPORTD:
    help = DDRD;
    if (DDRD == (help &= (1 << pinCheck(ardPin)))) {
      return TRUE;
    } else {
      return FALSE;
    }
    break;

  default:
    return FALSE;
    break;
  }
}

void writePinValue(uint8_t ardPin, uint8_t val) {
  if (isOutput(ardPin) == FALSE) {
    return;
  }
  switch (portCheck(ardPin)) {
  case CPORTB:
    writePortB(pinCheck(ardPin), val);
    break;

  case CPORTC:
    writePortC(pinCheck(ardPin), val);
    break;

  case CPORTD:
    writePortD(pinCheck(ardPin), val);
    break;
  }
}

uint8_t readPinValue(uint8_t ardPin) {
  if (!isInput(ardPin)) {
    return 0;
  }
  // clang-format off
  switch (portCheck(ardPin)) {
    case CPORTB: return (PINB & (1 << pinCheck(ardPin))) == 0 ? 0 : 1; break;
    case CPORTC: return (PINC & (1 << pinCheck(ardPin))) == 0 ? 0 : 1; break;
    case CPORTD: return (PIND & (1 << pinCheck(ardPin))) == 0 ? 0 : 1; break;

  default:
    return 0;
  }
  // clang-format on
}

// sets ardPins 6 (OC0A) and 5 (OC0B) as PWM output
// bits COM0B0, COM0B1, COM0A0, COM0A1 in TCCR0A are used for toggling OC0X
//
// bits CS00, CS01 CS02 in register TCCR0B = prescaler. 0b100 for 256
// prescaler = 256
// frequency = 16MHz - prescaler - 1
//
// bits WGM00, WGM01, WGM02 PWM mode. 0b111 for fast mode
//
//
//
// OCR0A and OCR0B for vals from 0 to 255
void setCounter0PWM() {
  setPortPin(6, OUTPUT, LOW);
  setPortPin(5, OUTPUT, LOW);
  TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << COM0B1);
  TCCR0B |= (1 << WGM02) | (1 << CS02);
  OCR0A = 0;
  OCR0B = 0;
}

void set0PWMVal(uint8_t valA, uint8_t valB) {
  OCR0A = valA;
  OCR0B = valB;
}
