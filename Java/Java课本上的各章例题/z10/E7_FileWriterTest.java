package z10;
import java.io.*;
public class E7_FileWriterTest {
	public static void main(String[] args) throws IOException {
		String str;
		InputStreamReader readString = new InputStreamReader(System.in);
		BufferedReader reader = new BufferedReader(readString);
		FileWriter file = new FileWriter("z10/Z10_TestData.txt");
		BufferedWriter writer=new BufferedWriter(file);
		System.out.println("请输入要保存的行，输入‘#’号结束。");
		while (!(str=reader.readLine()).equals("#")) { 
			writer.write(str + "\n");			
		}
		writer.flush();
		reader.close();
		file.close();
	}
}