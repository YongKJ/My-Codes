package z11;
import java.io.*;
import java.net.URL;
public class E2_ReadURLfileTest {
	public static void main(String[] args) throws IOException {
		URL url =new URL("http://www.sgu.edu.cn/");
		BufferedReader in =new BufferedReader(new InputStreamReader (url.openStream()));
		String str;
		while ((str=in.readLine())!=null)  System.out.println(str); //显示读出的行
		in.close();  //关闭输入流
	}
}