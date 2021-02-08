import java.util.*;
public class ScannerTest{
	public static void main(String[] args){
		Scanner s=new Scanner(System.in);
		System.out.print("请输入你的姓名：");
		String name=s.nextLine();
		System.out.print("请输入你的年龄：");
		int age=s.nextInt();
		System.out.println("姓名："+name+"\t年龄："+age);
		s.close();
		System.out.println(1111);//换行打印
		System.out.print(1111+"\n");//不换行打印
		//System.out.write(2222);//字节输出
		System.out.printf("+%.3f\n", 3.14);//按格式输出
		System.out.println();
	}
}
/*
1.使用Scanner类：

(1)使用java.util包。  import java.util.*;

(2)构造Scanner类对象，它附属于标准输入流System.in。   
Scanner s = new Scanner(System.in); 

(3)常用的next()方法系列：       
nextInt():输入整数    nextLine():输入字符串     
nextDouble():输入双精度数     next():输入字符串（以空格作为分隔符）。


1.System.out.println(); 是最常用的输出语句，它会把括号里的内容
转换成字符串输出到输出窗口（控制台），并且换行，当输出的是一个基
本数据类型时，会自动转换成字符串，如果输出的是一个对象，会自动调
用对象的toString();方法，将返回值输出到控制台

2.System.out.print(); 与第一个很相似，区别就是上一个输出后会换
行，而这个命令输出后并不换行。

3.System.out.printf(); 这个方法延续了C语言的输出方式，通过格式
化文本和参数列表输出。

 */
