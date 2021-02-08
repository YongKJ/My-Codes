package z10;
import java.io.*;
public class E5_PrintStreamTest {
	public static void main(String[] args) throws FileNotFoundException {
		File f=new File("z10/Z10_TestData.txt");
		PrintStream ps=new PrintStream(new FileOutputStream(f));
		int StudentID=100101;
		String name="张三";
		Boolean sex=true;
		float score=89f;
		ps.println(StudentID);
		ps.println(name); 
		ps.println(sex);
		ps.println(score);
		ps.close();
	}
}