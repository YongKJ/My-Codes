package z10;
import java.io.*;
public class E1_FileInputStreamTest {
	public static void main(String[] args) throws IOException {
		FileInputStream input=new FileInputStream("z10/Z10_TestData.txt");
		System.out.println("文件的大小:"+input.available());
		int numberRead=0;
		byte[] buffer=new byte[512];  //一次取出的字节数大小,缓冲区大小 
		while ((numberRead=input.read(buffer))!=-1) {
			System.out.write(buffer, 0, numberRead);  
		}
		input.close();
	}
}