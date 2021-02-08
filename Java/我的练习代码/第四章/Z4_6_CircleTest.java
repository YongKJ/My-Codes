import java.io.*;
import java.io.IOException;
class Cirle implements Shape{
	public float radius;
	public Cirle(){
		radius=1F;
	}
	public Cirle(float r){
		radius=r;
	}
	public float getArea(){
		return radius*radius*PI;
	}
	public float getGirth(){
		return 2F*radius*PI;
	}
}
public class Z4_6_CircleTest{
	public static void main(String[] args) {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		float r=0;
		System.out.println("请输入圆的半径：");
		try{
			String str=br.readLine();
			r=Float.parseFloat(str);
		}catch(IOException e){
			e.printStackTrace();
		}
		Shape y=new Cirle(r);
		System.out.println("圆的周长="+y.getGirth()+"，圆的面积="+y.getArea());
	}
}