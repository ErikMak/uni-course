/*

Одиночка (Singleton) – порождающий паттерн проектирования, 
гарантирующий существование только одного объекта класса, 
и к которому предоставляется глобальная точка доступа. 
Паттерн применяется, когда необходимо гарантировать наличие 
только одного объекта какого-либо класса или предоставлять 
глобальную точку доступа к объекту. Паттерн состоит из приватного
статичного поля, содержащего одиночный объект instance, 
приватного конструктора и статичного создающего метода getInstance, 
который также используется для получения объекта. Паттерн 
реализуется с применением “ленивой инициализации”, т.е. 
объект создается в момент обращения к нему, а не заранее. 

*/

class Singleton {
    private static Singleton instance;
    public int value;
    private Singleton (int value) {
        this.value = value;
    };

    public static Singleton getInstance(int value) {
        if (instance == null) {
            instance = new Singleton(value);
        }

        return instance;
    }
}


public class Main {
    public static void main(String[] args) {
        Singleton singleton = Singleton.getInstance(14);
        Singleton another_signleton = Singleton.getInstance(20);

        System.out.println(singleton.value);
        System.out.println(another_signleton.value);
    }
}
