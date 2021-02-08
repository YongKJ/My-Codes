package z10;
import java.io.*;
public class E6_FileReaderTest {
	public static void main(String[] args) throws IOException {
		String str;  
		FileReader file = new FileReader("z10/Z10_TestData.txt");
		BufferedReader reader = new BufferedReader(file);
		while ((str=reader.readLine())!=null) { 
			System.out.println(str);			
		}
		reader.close();
		file.close();
	}
}