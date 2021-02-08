package z2;

import java.io.IOException;

public class E8_switchTest {
	
	public static void main(String[] args) {
		char w='0';
		System.out.print("请输入 0---6:");
		try {
			w=(char) System.in.read();
		} catch (IOException e) {			
			e.printStackTrace();
		}
		switch(w)
		{
			case '0':
				System.out.println("数字"+w+"代表星期日");
				break;
			case '1':
				System.out.println("数字"+w+"代表星期一");
				break;
			case '2':
				System.out.println("数字"+w+"代表星期二");
				break;
			case '3':
				System.out.println("数字"+w+"代表星期三");
				break;
			case '4':
				System.out.println("数字"+w+"代表星期四");
				break;
			case '5':
				System.out.println("数字"+w+"代表星期五");
				break;
			case '6':
				System.out.println("数字"+w+"代表星期六");
				break;
			default:
				System.out.println("你输入的数字"+w+"不正确！");
			}
		}
}