import java.util.*;
public class InputDouble {
    public static void main(String agrs[]) {
        double a, b, c;
        Scanner reader = new Scanner(System.in);
        System.out.println("从键盘输入一个浮点数");
        a = reader.nextFloat();
        b = a * a;
        c = a * a * a;
        System.out.println(b);
        System.out.println(c);
    }
}
