/*

Фабричный метод (Factory Method) – порождающий 
паттерн проектирования, который определяет общий 
интерфейс для создания объектов в родительском классе, 
предоставляя возможность создания объектов своим наследникам. 
В момент создания наследники могут определять, какой 
класс создавать. Taxi – продукт, определяет интерфейс 
объектов, создаваемых абстрактным методом. CarTaxi и 
LargeVanTaxi – конкретные продукты. TaxiCompany – создатель, 
объявляет фабричный метод factoryMethod, который возвращает 
объект типа Taxi. Он определяет интерфейс для создания объекта, 
но оставляет подклассам CargoTaxiCompany и PassengerTaxiCompany
решение о том, на основании какого класса создавать объект типа Taxi.

*/

interface Taxi {
    public void info();
}

class CarTaxi implements Taxi {
    public void info() { System.out.println("Забирает легковое такси"); }
}

class LargeVanTaxi implements Taxi {
    public void info() { System.out.println("Забирает большой фургон такси"); }
}

abstract class TaxiCompany {
    abstract public Taxi factoryMethod();
    public void pickup() {
        Taxi taxi = this.factoryMethod();
        taxi.info();
    }
}

class CargoTaxiCompany extends TaxiCompany {
    public Taxi factoryMethod() { return new LargeVanTaxi(); }
}

class PassengerTaxiCompany extends TaxiCompany {
    public Taxi factoryMethod() { return new CarTaxi(); }
}


public class Main {
    public static void main(String[] args) {
        PassengerTaxiCompany passengerTaxiCompany = new PassengerTaxiCompany();
        passengerTaxiCompany.pickup();
        CargoTaxiCompany cargoTaxiCompany = new CargoTaxiCompany();
        cargoTaxiCompany.pickup();
    }
}
