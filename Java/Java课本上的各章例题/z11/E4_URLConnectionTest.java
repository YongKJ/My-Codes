package z11;
import java.io.*;
import java.net.*;
public class E4_URLConnectionTest {	
	public static void main(String[] args) throws IOException {
		URL url =new URL("http://www.sgu.edu.cn/");
		URLConnection con = url.openConnection();
		InputStream inStrm = con.getInputStream();
		BufferedReader in =new BufferedReader(new InputStreamReader (inStrm));
		String str;
		while ((str=in.readLine())!=null)  System.out.println(str); //显示读出的行
		in.close();  //关闭输入流
	}
}