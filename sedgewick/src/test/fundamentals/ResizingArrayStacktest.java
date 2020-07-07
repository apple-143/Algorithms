package fundamentals;

import fundamentals.ResizingArrayStack;

class ResizingArrayStacktest {
    public static void main(String[] args) {
        ResizingArrayStack<String> a = new ResizingArrayStack<String>();

        a.push("hello1");
        a.push("hello2");
        a.push("hello3");
        System.out.println(a.pop());
        System.out.println(a.pop());
        System.out.println(a.pop());
    }
}
