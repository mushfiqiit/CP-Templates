ll turnOn(ll x, int pos) {
    return N | (1LL<<pos);
}

bool isOn(ll x ,int pos) {
    return (bool)(x & (1LL<<pos));
}
