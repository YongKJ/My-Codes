package z2;
import java.io.*;
public class E3_Circle {
	final float PI=3.14159f; //声明常量
	float r;  //类成员变量，在整个类中有效
	public void setRadius(float r1) //r1是方法参数
	{
		r=r1;
	}
	public float getRadius()//获取半径
	{
		return r;
	}
	public float getArea()//求取面积
	{	
		return PI*r*r;
	}
	public static void main(String[] args) {
		Z2_2_Circle c1=new Z2_2_Circle( );//初始化一个圆
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//创建缓冲读对象
	    String str=null; //局部变量，在该方法中有效
        float rr;
	    System.out.println("请输入圆的半径:");
	    try {
			str=br.readLine();
		} catch (IOException e) { //e为异常处理参数			
			e.printStackTrace();
		}
	    rr=Float.parseFloat(str);//转换成实数
	    c1.setRadius(rr);
		float Area=c1.getArea();//计算面积
		System.out.println(" 圆的半径= "+c1.getRadius()+"  面积= "+Area);
	}
}