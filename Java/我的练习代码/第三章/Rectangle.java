 import java.io.*;
public class Rectangle{
	public float width;
	public float height;
	Rectangle(float x,float y){
		width=x;
		height=y;
	}
	public float getCir(){
		return width*2+height*2;
	}
	public float getArea(){
		return width*height;
	}
	public static void main(String[] args) {
		Rectangle a=new Rectangle(2,5);
		System.out.println("矩形周长为："+a.getCir());
		System.out.println("矩形面积为："+a.getArea());
	}
}