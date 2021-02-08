package z5;
import java.io.*;
public class E8_ThrowsExceptionTest {
	public static void main(String[] args) {
		try {
			ReadFileInfo();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	static void ReadFileInfo() throws IOException
	{
		FileInputStream input=new FileInputStream("TestData.txt");
		System.out.println("文件的大小:"+input.available());
		input.close();
	}
}