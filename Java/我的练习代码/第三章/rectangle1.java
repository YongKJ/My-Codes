public class rectangle1{
	double width,height;
	rectangle1(double x,double y){
		width=x;
		height=y;
	}
	void circum(){
		double a=(width+height)*2;
		System.out.println("�ܳ���"+a);
	}
	void area(){
		double b=width*height;
		System.out.println("�����"+b);
	}
	public static void main(String[] args){
		rectangle1 t=new rectangle1(1.1,2.2);
		t.circum();
		t.area();
	}
}