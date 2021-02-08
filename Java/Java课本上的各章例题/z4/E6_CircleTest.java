package z4;
import java.io.*;
import java.io.IOException;
interface Shape
{
	float PI=3.141596F; //常量
	float getArea();   //抽象方法，求面积 
	float getGirth();  //抽象方法，求周长
}
class Circle implements Shape
{
    public float radius;//半径
    public Circle()
    {
    	radius=1F;	
    }
    public Circle(float r)
    {
    	radius=r;
    }
    public float getArea()//接口方法的实现
	{
    	return radius*radius*PI;
	}
	public float getGirth()//接口方法的实现
    {
		return 2F*radius*PI;
    }
}
public class E6_CircleTest {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//创建缓冲读对象	    
        float r=0;
	    System.out.println("请输入圆的半径:");
	    try {
	    	String str=br.readLine();
			r=Float.parseFloat(str);//转换成实数
		} catch (IOException e) { //e为异常处理参数			
			e.printStackTrace();
		}	    
		Shape y=new Circle(r);
		System.out.println(" 圆的周长="+y.getGirth()+" ，圆的面积="+y.getArea());
	}
}