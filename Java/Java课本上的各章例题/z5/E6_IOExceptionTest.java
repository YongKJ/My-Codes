package z5;
import java.io.*;
public class E6_IOExceptionTest {
	public static void main(String[] args) {
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("note.txt");
			fis.close();		
		} catch (FileNotFoundException e) {
			System.out.println("异常信息："+e.getMessage());
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}