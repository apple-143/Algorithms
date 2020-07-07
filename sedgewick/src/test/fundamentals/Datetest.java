package fundamentals;

import fundamentals.Date;

public class Datetest {
    public static void main(String[] args) {
        Date a = new Date(10, 24, 1991);
        System.out.println(a);

        Date b = new Date("5/22/1939");
        System.out.println(b);
    }
}
