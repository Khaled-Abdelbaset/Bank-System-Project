/* Client -> pinCode:

  // string pinCode;
  // checkPinCode(pin);
  // pinCode = pin;

  void setPinCode(string pinCode)
  {
    checkPinCode(pinCode);
    this->pinCode = pinCode;
  }

  void checkPinCode(string pinCode) {
    if (pinCode.size() != 4) {
      throw PinCodeErrors();
    }
    for (int i = 0; i < pinCode.size(); i++) {
      if (!isdigit(pinCode[i])) {
        throw PinCodeErrors();
      }
    }
  }
  class PinCodeErrors {
  public:
    void pinError() {
      cout <<" Pin Code must be only 4 numeric characters!" << endl;
    }
  };

*/