#include <iostream>
#include <vector>

class ElectronicDevice {
public:
    std::string model;
    std::string manufacturer;

    ElectronicDevice() {}
    ElectronicDevice(std::string model, std::string manufacturer) : model(model), manufacturer(manufacturer) {}
    ~ElectronicDevice() {}

    virtual ElectronicDevice* clone(int) {
        return this;
    };
    virtual void info() {};
};

class Smartphone : public ElectronicDevice {
public:
    int sims;

    Smartphone(ElectronicDevice& device, int sims) : sims(sims) {
        model = device.model;
        manufacturer = device.manufacturer;
    }
    ~Smartphone() {}

    Smartphone* clone(int sims) override {
        return new Smartphone(*this, sims);
    }

    void info() {
        std::cout << "Device: Smartphone\n\t" << manufacturer << " " << model << " has " << sims << " sim cards\n" << std::endl;
    }
};

class Laptop : public ElectronicDevice {
public:
    int ram;

    Laptop(ElectronicDevice device, int ram) : ram(ram) {
        model = device.model;
        manufacturer = device.manufacturer;
    }
    ~Laptop() {}

    Laptop* clone(int ram) override {
        return new Laptop(*this, ram);
    }


    void info() {
        std::cout << "Device: Laptop\n\t" << manufacturer << " " << model << " has " << ram << " GB RAM\n" << std::endl;
    }
};

class Tv : public ElectronicDevice {
public:
    int diag;

    Tv(ElectronicDevice device, int diag) : diag(diag){
        model = device.model;
        manufacturer = device.manufacturer;
    }
    ~Tv() {}

    Tv* clone(int diag) override {
        return new Tv(*this, diag);
    }


    void info() {
        std::cout << "Device: TV\n\t" << manufacturer << " " << model << " has diagonal " << diag << "\"\n" << std::endl;
    }
};

int main()
{
    ElectronicDevice prototype("unknown model", "unknown manufacturer");

    Smartphone phonePrototype{ prototype, 0 };
    phonePrototype.model = "A3000";
    phonePrototype.manufacturer = "Samsung";

    Laptop laptopPrototype{ prototype, 0 };
    laptopPrototype.model = "L900";
    laptopPrototype.manufacturer = "Lenovo";

    Tv tvPrototype{ prototype, 0 };
    tvPrototype.model = "TV500";
    tvPrototype.manufacturer = "Xiaomi";

    std::vector<ElectronicDevice*> devices;
    for (int i = 0; i < 5; ++i) {
        devices.push_back(phonePrototype.clone(i + 1));
        devices.push_back(laptopPrototype.clone(pow(2, i)));
        devices.push_back(tvPrototype.clone(15 + i));
    }

    for (ElectronicDevice* device : devices) {
        device->info();
    }

    for (ElectronicDevice* device : devices) {
        delete device;
    }
}
