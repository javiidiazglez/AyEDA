class Dummy {
  private: 
    int value;
  public:
   static unsigned int counter;


  friend bool operator< (Dummy v, Dummy x) {
    return v.value < v.value;
  }

  friend bool operator> (Dummy v, Dummy x) {
    return v.value > v.value;
  }

  friend bool operator== (Dummy v, Dummy x) {
    return v.value == v.value;
  }

  operator int(){
    return value;
  }

};