package fundamentals;

import fundamentals.Date;

public class Transaction implements Comparable<Transaction> {
    private final String who;
    private final Date when;
    private final double amount;

    public Transaction(String who, Date when, double amount) {
        this.who = who;
        this.when = when;
        this.amount = amount;
    }

    public Transaction(String transaction) {
        String[] fields = transaction.split(" +");
        who = fields[0];
        when = new Date(fields[1]);
        amount = Double.parseDouble(fields[2]);
    }

    public String who()
    { return who; }

    public Date when()
    { return when; }

    public double amount()
    { return amount; }

    public String toString() {
        return who + " " + when + " " + amount;
    }

    public boolean equals(Object x) {
        if (this == x) return true;
        if (x == null) return false;
        if (this.getClass() != x.getClass()) return false;
        Transaction that = (Transaction) x;
        if (this.who != that.who)       return false;
        if (this.when != that.when)     return false;
        if (this.amount != that.amount) return false;
        return true;
 
    }

    public int compareTo(Transaction that) {
        if (this.amount > that.amount) return 1;
        if (this.amount < that.amount) return -1;
        return 0;
    }
}
