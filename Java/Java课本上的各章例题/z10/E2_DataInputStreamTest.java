package z10;
import java.io.*;
public class E2_DataInputStreamTest {
	public static void main(String[] args) {
		byte[] byteData = new byte[10];
		DataInputStream dataIn = new DataInputStream(System.in); 
		System.out.print("请输入10字符： ");
		try {
			dataIn.read(byteData); //从键盘上输入数据放入字节数组中
		} catch (IOException e) {
			e.printStackTrace();
		} 
		for (int i = 0; i < byteData.length; i++)
			System.out.print(byteData[i] + "  ");//打印数组元素
	}
}