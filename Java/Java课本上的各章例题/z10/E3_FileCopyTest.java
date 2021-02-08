package z10;
import java.io.*; 
public class E3_FileCopyTest {
	public static void main(String[] args) throws IOException {
		byte[] buffer=new byte[512]; //输出缓冲区
		int numberRead=0;
		FileInputStream input=null;
		FileOutputStream out =null; 
		input=new FileInputStream("z10/Z10_teaching1.jpg");
		out=new FileOutputStream("z10/Z10_teaching2.jpg"); 
		while ((numberRead=input.read(buffer))!=-1) {
			out.write(buffer, 0, numberRead);
		}
		System.out.print("文件拷贝完成！ ");
		input.close();
		out.close(); 
	}
}