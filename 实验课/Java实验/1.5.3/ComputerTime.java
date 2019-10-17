//文件ComputerTime.java
import CalTime.vehicle.all.Common;
import java.lang.*;
public class ComputerTime {
    public static void main(String[] args) {
        System.out.println("交通工具：" + args[0]);
        System.out.println(" 参数A：" + args[1]);
        System.out.println(" 参数B：" + args[2]);
        System.out.println(" 参数C：" + args[3]);
        double A = Double.parseDouble(args[1]);
        double B = Double.parseDouble(args[2]);
        double C = Double.parseDouble(args[3]);
        double v, t;
        try {
            Common d = (Common)Class.forName("CalTime.vehicle." + args[0]).newInstance();
            //该语句的意思是动态加载CalTime.vehicle.Car类并创建一个实例对象,假设输入的参数是Car,用接口Common定义的引用d指向该对象
            v = d.runTimer(A, B, C);
            t = 1000 / v;
            System.out.println("平均速度：" + v + " km/h");
            System.out.println("运行时间：" + t + " 小时");
        } catch(Exception e) {
            System.out.println("class not found");
        }
    }
}
