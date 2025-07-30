import java.util.Scanner;

//TIP 要<b>运行</b>代码，请按 <shortcut actionId="Run"/> 或
// 点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
//遗憾贯穿人生始终
public class Main {
    public static void main(String[] args) {

        S s = new S();
        V v = new V();
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int h=sc.nextInt();
        float area = s.s(r);
        System.out.println(s.s(r));
        System.out.println(v.v(area,h));


    }
}