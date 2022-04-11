#ifndef ARDUINO_MULTIWIFI_H_
#define ARDUINO_MULTIWIFI_H_

#include <vector>

class MultiWiFi {
    public:

    void add(const char* ssid, const char *pass = NULL) {
        Network_t network;
        network.ssid = String(ssid);
        if (pass != nullptr)
            network.pass = String(pass);
        
        this->networks.push_back(network);
    };

    int run(unsigned long connectTimeout = 5000) {
        uint8_t status = WiFi.status();

        if (status == WL_CONNECTED)
            return status;
        
        auto scanResult = WiFi.scanNetworks();
        if (scanResult < 0)
            return -1;

        for (auto network : this->networks) {
            for (size_t i = 0; i < scanResult; i++) {
                // SSID() is implemented with different return types so we wrap
                // it into String()
                if (String(WiFi.SSID(i)) == network.ssid) {
                    WiFi.begin(network.ssid.c_str(), network.pass.c_str());
                    status = WiFi.status();

                    auto startTime = millis();
                    while (status == WL_IDLE_STATUS && (millis() - startTime) <= connectTimeout) {
                        delay(10);
                        status = WiFi.status();
                    }
                    
                    if (status == WL_CONNECTED)
                        break;
                }
            }
            if (status == WL_CONNECTED)
                break;
        }

        return status;
    };

    private:
    struct Network_t {
        String ssid;
        String pass;
    };
    std::vector<Network_t> networks;
};

#endif
